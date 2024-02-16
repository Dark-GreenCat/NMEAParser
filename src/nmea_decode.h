#ifndef __NMEA_DECODE_H
#define __NMEA_DECODE_H

#include <stdbool.h>
#include "nmea_common.h"

void decodeTime(nmea_time* time);
void decodeDate(nmea_date* date);
void decodeLocation(nmea_location* location_raw);
void decodeSpeed(nmea_speed* speed);
void decodeCourse(nmea_course* course);
void decodeHDOP(nmea_hdop* hdop);
void decodeAltitude(nmea_altitude* altitude);

#endif /* __NMEA_DECODE_H */