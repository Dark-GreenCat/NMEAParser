#ifndef __NMEA_DATA_H
#define __NMEA_DATA_H

#include <stdbool.h>

#define NMEA_TIME_FIELD_SIZE            11
#define NMEA_DATE_FIELD_SIZE            7
#define NMEA_LOCATION_FIELD_SIZE        13
#define NMEA_SPEED_FIELD_SIZE           5
#define NMEA_COURSE_FIELD_SIZE          7
#define NMEA_HDOP_FIELD_SIZE            5
#define NMEA_ALTITUDE_FIELD_SIZE        6

typedef enum {
    NMEA_SENTENCE_RMC,
    NMEA_SENTENCE_GGA,
    NMEA_SENTENCE_OTHER
} nmea_sentence_type;

typedef struct {
    char time_raw[NMEA_TIME_FIELD_SIZE];
} nmea_time;

typedef struct {
    char date_raw[NMEA_DATE_FIELD_SIZE];
} nmea_date;

typedef struct {
    char location[NMEA_LOCATION_FIELD_SIZE];
    char cardinal;
} nmea_location_raw;

typedef struct {
    nmea_location_raw latitude_raw;
    nmea_location_raw longitude_raw;
} nmea_location;

typedef struct {
    char speed_raw[NMEA_SPEED_FIELD_SIZE];
} nmea_speed;

typedef struct {
    char course_raw[NMEA_COURSE_FIELD_SIZE];
} nmea_course;

typedef struct {
    char hdop_raw[NMEA_HDOP_FIELD_SIZE];
} nmea_hdop;

typedef struct {
    char altitude_raw[NMEA_ALTITUDE_FIELD_SIZE];
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

bool NMEA_Parser_Process(char c);

const char* NMEA_Parser_getTime(void);
const char* NMEA_Parser_getDate(void);
const char* NMEA_Parser_getLatitude(void);
char NMEA_Parser_getLatitudeCardinal(void);
const char* NMEA_Parser_getLongitude(void);
char NMEA_Parser_getLongitudeCardinal(void);
const char* NMEA_Parser_getSpeed(void);
const char* NMEA_Parser_getCourse(void);
const char* NMEA_Parser_getHDOP(void);
const char* NMEA_Parser_getAltitude(void);

#endif /* __NMEA_DATA_H */