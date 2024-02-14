# NMEA Parser

The NMEA Parser is a library for parsing NMEA sentences and extracting the data they contain. It is designed to be easy to use and provide accurate results.

## Getting Started

To use the NMEA Parser, simply include the `nmea_parser.h` header file in your source code and build with the `src/nmea_data.c` file.

## Features

The NMEA Parser includes the following features:

* Parses NMEA 0183 sentences and extracts the data they contain
* Supports multiple NMEA sentence types, including GGA and RMC
* Provides accurate results even in the presence of noise or invalid data
* Easy to use and integrate into your application

## Limitations

The current version of the NMEA Parser only supports GGA and RMC sentence types. However, it can be easily extended to support other sentence types by adding additional parsing logic.

## Usage

To use the NMEA Parser, follow these steps:

1. Include the `nmea_parser.h` header file in your source code:
```
#include "nmea_parser.h"
```
2. Use the `NMEA_Parser_Process()` function to parse NMEA sentences char by char and extract the data they contain:
```
char* sentence_rmc = "+QGNSSRD: $GNRMC,100234.000,A,2102.5194,N,10547.2117,E,0.66,166.83,061223,,,A*70\r\n";

for (int i = 0; sentence_rmc[i] != '\0'; i++) {
    if (NMEA_Parser_Process(sentence_rmc[i])) {
        printf("Time: %s\n", getTime());
        printf("Date: %s\n", getDate());
        printf("Latitude: %s %c\n", getLatitude(), getLatitudeCardinal());
        printf("Longitude: %s %c\n", getLongitude(), getLongitudeCardinal());
        printf("Speed: %s\n", getSpeed());
        printf("Course: %s\n", getCourse());
        printf("HDOP: %s\n", getHDOP());
        printf("Altitude: %s\n", getAltitude());
        printf("\n");
    }
}
```
3. Build your application with the `src/nmea_data.c` file:
```
gcc -o my_app my_app.c src/nmea_data.c
```
---

## Guide to Extend Your Protocol

The NMEA Parser Library is designed to be extensible, allowing developers to add their own protocols and data structures to the library. This section provides a guide on how to extend the library with your own protocol.


### 1. Define Your Protocol

To extend the NMEA Parser Library with your own protocol, you'll need to define a new struct that contains the data fields specific to your protocol. This struct should be defined in a header file that you'll include in your application.

For example, let's say you have a new protocol that includes a new field for a device ID, and you want to add it to the `nmea_data` struct. You can define a new struct like this:
```c
typedef struct {
    char device_id[5];
} my_protocol_data;
```
### 2. Modify the `nmea_data` Struct

Next, you'll need to modify the `nmea_data` struct in `nmea_data.h` to include your new protocol's data fields. For example:
```c
typedef struct {
    // Existing fields...
    // Add new field for device ID
    my_protocol_data device_id;
} nmea_data;
```
### 3. Defining Your Protocol's Function Pointer

In order to handle your protocol's data fields, you'll need to define a new function pointer in `your_protocol.h`. This function pointer will be used to process the data extracted from the NMEA sentence.

#### Shared Variables

You should be aware of the two shared variables in `nmea_common.h` that are used to store temporary values (Term) and parse results (NMEA_Data). These variables are used throughout the library to store and manipulate data.
```c
#define NMEA_MAX_FIELD_SIZE     15

extern char Term[NMEA_MAX_FIELD_SIZE];
extern nmea_data NMEA_Data;
```

Here's an example of how you can define your protocol's function pointer:
```c
#define YOUR_PROTOCOL_FIELD_INDEX   1
static inline void saveFieldNMEA_YOUR_PROTOCOL(uint8_t field_index) {
    // Handle your protocol's data fields
    // You should read data from string Term[] and paste to variable NMEA_Data
    switch (field_index) {
        case YOUR_PROTOCOL_FIELD_INDEX:
            strcpy(NMEA_Data.device_id.device_id, Term);
            break;

        default:
            break;
    }
}
```
By following these steps, you'll be able to extend the NMEA Parser Library with your own protocol and handle the data fields specific to your protocol.
### 4. Modify the `endTermHandler()` Function

In `nmea_data.c`, modify the `endTermHandler()` function to call your new protocol's function pointer. For example:
```c
static bool endTermHandler() {
    // Existing code...

    if (curTermNumber == NMEA_FIELD_MESSAGE_ID) {
        Type = NMEA_SENTENCE_OTHER;
        if      (strcmp(Term + 2, "RMC") == 0) Type = NMEA_SENTENCE_RMC;
        else if (strcmp(Term + 2, "GGA") == 0) Type = NMEA_SENTENCE_GGA;
        
        // Add a new case for your protocol
        else if (strcmp(Term + 2, "xxx") == 0) Type = NMEA_SENTENCE_YOUR_PROTOCOL;
    }

    if (Type == NMEA_SENTENCE_RMC) saveFieldNMEA_RMC(curTermNumber);
    if (Type == NMEA_SENTENCE_GGA) saveFieldNMEA_GGA(curTermNumber);
    
    // Add a new case for your protocol
    if (Type == NMEA_SENTENCE_YOUR_PROTOCOL) saveFieldNMEA_YOUR_PROTOCOL(curTermNumber);
}
```
Sure, here are the revised steps in markdown format:

### 5. Adding Custom Functionality

In addition to the existing functionality provided by the NMEA Parser Library, you may wish to add your own custom functions to handle specific requirements or use cases. To do this, you can freely add your own function prototypes and definitions in the `nmea_data.h` and `nmea_data.c` files.

When adding custom functionality, it's important to keep in mind that the library uses shared variables to save data, which are declared in `nmea_common.h`. You can access and modify these shared variables in any source file that includes them, but it's generally recommended to limit the scope of your custom functions to `nmea_data.c` only.

Here's an example of how you can add your own function:
```c
// In nmea_data.h
void my_own_function(void);

// In nmea_data.c
void my_own_function(void) {
    // Function implementation goes here
}
```

If you intend for your functions to be accessible throughout the library, simply include them in the `nmea_common.h` header file
```c
// In nmea_common.h
void my_own_function(void) {
    // Function implementation goes here
}
```
By following these steps, you can extend the NMEA Parser Library with your own custom functionality, while still maintaining the integrity and consistency of the existing codebase.

That's it! With these steps, you've successfully extended the NMEA Parser Library with your own protocol. You can now use the `NMEA_Parser_Process()` function to parse your new protocol and extract the data fields from the sentence.

Note that this is just a basic example, and you may need to modify the library's source code further to handle your specific protocol requirements.
## Support

If you have any questions or issues with the NMEA Parser, please contact me at [tranquanghuy3008@outlook.com](mailto:tranquanghuy3008@outlook.com).