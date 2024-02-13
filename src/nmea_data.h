#ifndef RAW_H
#define RAW_H

#include <stdbool.h>

typedef enum {
    NMEA_SENTENCE_RMC,
    NMEA_SENTENCE_GGA,
    NMEA_SENTENCE_OTHER
} NMEA_Sentence_Type;

typedef struct {
    char time_raw[11];
} nmea_time;

typedef struct {
    char date_raw[7];
} nmea_date;

typedef struct {
    char location[13];
    char cardinal;
} nmea_location_raw;

typedef struct {
    nmea_location_raw latitude_raw;
    nmea_location_raw longitude_raw;
} nmea_location;

typedef struct {
    char speed_raw[5];
} nmea_speed;

typedef struct {
    char course_raw[7];
} nmea_course;

typedef struct {
    char hdop_raw[5];
} nmea_hdop;

typedef struct {
    char altitude_raw[6];
} nmea_altitude;

typedef struct {
    nmea_time Time;
    nmea_date Date;
    nmea_location Location;
    nmea_speed Speed;
    nmea_course Course;
    nmea_hdop HDOP;
    nmea_altitude Altitude;
} nmea_data;

bool NMEA_Process(char c);

const char* getTime(void);
const char* getDate(void);
const char* getLatitude(void);
char getLatitudeCardinal(void);
const char* getLongitude(void);
char getLongitudeCardinal(void);
const char* getSpeed(void);
const char* getCourse(void);
const char* getHDOP(void);
const char* getAltitude(void);

#endif /* RAW_H */