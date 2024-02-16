#ifndef NMEA_CONVERTER_H
#define NMEA_CONVERTER_H

#include <stdint.h>
#include "nmea_data.h"

char* NMEA_Parser_getSubstring(char* destination, const char* source, uint32_t start_index, uint32_t size);
int32_t NMEA_Parser_strtoi32(const char* str);
int32_t NMEA_Parser_strntoi32(const char* str, uint32_t start_index, uint32_t size);
uint32_t NMEA_Parser_strtou32(const char* str);
int32_t NMEA_Parser_strntou32(const char* str, uint32_t start_index, uint32_t size);
char* NMEA_Parser_numtostr(int number, int decimal_places, char* result);
char* NMEA_Parser_nmeafloattostr(nmea_float number, char* result);

#endif