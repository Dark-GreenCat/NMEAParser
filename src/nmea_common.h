#ifndef __NMEA_COMMON_H
#define __NMEA_COMMON_H

#include <string.h>
#include "nmea_data.h"

#define NMEA_MAX_FIELD_SIZE         15
#define NMEA_FIELD_MESSAGE_ID       0

extern char Term[NMEA_MAX_FIELD_SIZE];
extern nmea_data NMEA_Data;
extern bool isFix;

void setTime(nmea_time* time, char* term) {
    strcpy(time->time_raw, term);
}

void setDate(nmea_date* date, char* term) {
    strcpy(date->date_raw, term);
}

void setLocation(nmea_location_raw* location_raw, char* term) {
    strcpy(location_raw->location, term);
}

void setCardinal(nmea_location_raw* location_raw, char* term) {
    location_raw->cardinal = *term;
}

void setSpeed(nmea_speed* speed, char* term) {
    strcpy(speed->speed_raw, term);
}

void setCourse(nmea_course* course, char* term) {
    strcpy(course->course_raw, term);
}

void setHDOP(nmea_hdop* hdop, char* term) {
    strcpy(hdop->hdop_raw, term);
}

void setAltitude(nmea_altitude* altitude, char* term) {
    strcpy(altitude->altitude_raw, term);
}

#endif /* __NMEA_COMMON_H */