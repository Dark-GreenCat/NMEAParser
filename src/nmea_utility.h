#ifndef __NMEA_UTILITY_H
#define __NMEA_UTILITY_H

#include "nmea_common.h"

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

#endif