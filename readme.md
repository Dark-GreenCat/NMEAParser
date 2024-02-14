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
## Support

If you have any questions or issues with the NMEA Parser, please contact me at [tranquanghuy3008@outlook.com](mailto:tranquanghuy3008@outlook.com).