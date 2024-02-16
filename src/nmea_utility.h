#ifndef __NMEA_UTILITY_H
#define __NMEA_UTILITY_H

#include "nmea_core.h"

// This header file provides utility functions for processing NMEA data.

// Processes the incoming character 'c' and updates the NMEA data structure 'data' accordingly.
// Returns true if a complete NMEA sentence is parsed and processed successfully, false otherwise.
bool NMEA_Parser_Process(nmea_data* data, char c);

// Returns the raw time string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawTime(nmea_data* data);

// Returns the raw date string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawDate(nmea_data* data);

// Returns the raw latitude string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawLatitude(nmea_data* data);

// Returns the raw latitude cardinal direction (N/S) from the NMEA data structure 'data'.
char NMEA_Parser_getRawLatitudeCardinal(nmea_data* data);

// Returns the raw longitude string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawLongitude(nmea_data* data);

// Returns the raw longitude cardinal direction (E/W) from the NMEA data structure 'data'.
char NMEA_Parser_getRawLongitudeCardinal(nmea_data* data);

// Returns the raw speed string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawSpeed(nmea_data* data);

// Returns the raw course string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawCourse(nmea_data* data);

// Returns the raw HDOP (Horizontal Dilution of Precision) string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawHDOP(nmea_data* data);

// Returns the raw altitude string from the NMEA data structure 'data'.
const char* NMEA_Parser_getRawAltitude(nmea_data* data);

#endif