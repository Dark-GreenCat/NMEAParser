#ifndef __NMEA_COMMON_H
#define __NMEA_COMMON_H

#include <string.h>
#include "nmea_data.h"

#define NMEA_MAX_FIELD_SIZE         15
#define NMEA_FIELD_MESSAGE_ID       0

extern char Term[NMEA_MAX_FIELD_SIZE];
extern nmea_data NMEA_Data;
extern bool isFix;

char* NMEA_Parser_getSubstring(char* destination, const char* source, uint32_t start_index, uint32_t size);
int32_t NMEA_Parser_strtoi32(const char* str);
int32_t NMEA_Parser_strntoi32(const char* str, uint32_t start_index, uint32_t size);
uint32_t NMEA_Parser_strtou32(const char* str);
int32_t NMEA_Parser_strntou32(const char* str, uint32_t start_index, uint32_t size);
char* NMEA_Parser_numtostr(int number, int decimal_places, char* result);
char* NMEA_Parser_nmeafloattostr(nmea_float number, char* result);

void setTime(nmea_time* time, char* term);
void setDate(nmea_date* date, char* term);
void setLocation(nmea_location_raw* location_raw, char* term);
void setCardinal(nmea_location_raw* location_raw, char* term);
void setSpeed(nmea_speed* speed, char* term);
void setCourse(nmea_course* course, char* term);
void setHDOP(nmea_hdop* hdop, char* term);
void setAltitude(nmea_altitude* altitude, char* term);

#endif /* __NMEA_COMMON_H */