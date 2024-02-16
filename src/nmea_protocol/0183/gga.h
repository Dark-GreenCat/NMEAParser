#ifndef __GGA_H
#define __GGA_H

#include <stdint.h>
#include "../../nmea_common.h"

#define GGA_FIELD_TIME                  1
#define GGA_FIELD_LATITUDE              2
#define GGA_FIELD_LATITUDE_CARDINAL     3
#define GGA_FIELD_LONGITUDE             4
#define GGA_FIELD_LONGITUDE_CARDINAL    5
#define GGA_FIELD_FIX_STATUS            6
#define GGA_FIELD_HDOP                  8
#define GGA_FIELD_ALTITUDE              9

static inline void saveFieldNMEA_GGA(uint8_t field_index) {
    switch (field_index) {
        case GGA_FIELD_TIME:
            setRawTime(&NMEA_Data.Time, Term);
            break;

        case GGA_FIELD_LATITUDE:
            setRawLocation(&NMEA_Data.Location.latitude_raw, Term);
            break;

        case GGA_FIELD_LATITUDE_CARDINAL:
            setRawLocationCardinal(&NMEA_Data.Location.latitude_raw, Term);
            break;

        case GGA_FIELD_LONGITUDE:
            setRawLocation(&NMEA_Data.Location.longitude_raw, Term);
            break;

        case GGA_FIELD_LONGITUDE_CARDINAL:
            setRawLocationCardinal(&NMEA_Data.Location.longitude_raw, Term);
            break;
        
        case GGA_FIELD_FIX_STATUS:
            isFix = (*Term > '0');
            break;

        case GGA_FIELD_HDOP:
            setRawHDOP(&NMEA_Data.HDOP, Term);
            break;

        case GGA_FIELD_ALTITUDE:
            setRawAltitude(&NMEA_Data.Altitude, Term);
            break;

        default:
            break;
    }
}

#endif /* __GGA_H */