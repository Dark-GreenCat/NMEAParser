#ifndef __NMEA_COMMON_H
#define __NMEA_COMMON_H

#include "parser/nmea_data.h"
#include "parser/nmea_converter.h"
#include "parser/nmea_decoder.h"

#define NMEA_FIELD_MESSAGE_ID       0

extern char Term[NMEA_MAX_FIELD_SIZE];
extern nmea_data NMEA_Data;
extern bool isFix;

#endif /* __NMEA_COMMON_H */