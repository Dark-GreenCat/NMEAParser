#ifndef __NMEA_DATA_H
#define __NMEA_DATA_H

#include <stdbool.h>
#include <stdint.h>

#define NMEA_MAX_FIELD_SIZE             15

#define NMEA_TIME_FIELD_SIZE            11
#define NMEA_DATE_FIELD_SIZE            7
#define NMEA_LOCATION_FIELD_SIZE        13
#define NMEA_SPEED_FIELD_SIZE           NMEA_MAX_FIELD_SIZE
#define NMEA_COURSE_FIELD_SIZE          NMEA_MAX_FIELD_SIZE
#define NMEA_HDOP_FIELD_SIZE            NMEA_MAX_FIELD_SIZE
#define NMEA_ALTITUDE_FIELD_SIZE        NMEA_MAX_FIELD_SIZE

typedef enum {
    NMEA_SENTENCE_RMC,
    NMEA_SENTENCE_GGA,
    NMEA_SENTENCE_OTHER
} nmea_sentence_type;

typedef struct {
    int32_t value;
    uint8_t decimal_places;
} nmea_float;

typedef struct {
    char time_raw[NMEA_TIME_FIELD_SIZE];
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
    uint16_t miliseconds;
} nmea_time;

typedef struct {
    char date_raw[NMEA_DATE_FIELD_SIZE];
    uint8_t day;
    uint8_t month;
    uint8_t year;
} nmea_date;

typedef struct {
    char location[NMEA_LOCATION_FIELD_SIZE];
    char cardinal;
} nmea_location_raw;

typedef struct {
    nmea_location_raw latitude_raw;
    nmea_location_raw longitude_raw;

    nmea_float latitude;
    nmea_float longitude;
} nmea_location;

typedef struct {
    char speed_raw[NMEA_SPEED_FIELD_SIZE];

    nmea_float speed_knot;
} nmea_speed;

typedef struct {
    char course_raw[NMEA_COURSE_FIELD_SIZE];

    nmea_float course_degree;
} nmea_course;

typedef struct {
    char hdop_raw[NMEA_HDOP_FIELD_SIZE];

    nmea_float hdop;
} nmea_hdop;

typedef struct {
    char altitude_raw[NMEA_ALTITUDE_FIELD_SIZE];

    nmea_float altitude_meter;
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

void setRawTime(nmea_time* time, char* term);
void setRawDate(nmea_date* date, char* term);
void setRawLocation(nmea_location_raw* location_raw, char* term);
void setRawLocationCardinal(nmea_location_raw* location_raw, char* term);
void setRawSpeed(nmea_speed* speed, char* term);
void setRawCourse(nmea_course* course, char* term);
void setRawHDOP(nmea_hdop* hdop, char* term);
void setRawAltitude(nmea_altitude* altitude, char* term);

#endif /* __NMEA_DATA_H */