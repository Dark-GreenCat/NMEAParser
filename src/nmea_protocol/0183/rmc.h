#ifndef RMC_H
#define RMC_H

#include <stdint.h>
#include "../../nmea_data.h"
#include "../../nmea_common.h"

#define RMC_FIELD_TIME 1
#define RMC_FIELD_DATA_VALID 2
#define RMC_FIELD_LATITUDE 3
#define RMC_FIELD_LATITUDE_CARDINAL 4
#define RMC_FIELD_LONGITUDE 5
#define RMC_FIELD_LONGITUDE_CARDINAL 6
#define RMC_FIELD_SPEED 7
#define RMC_FIELD_COURSE 8
#define RMC_FIELD_DATE 9

static inline void saveFieldNMEA_RMC(uint8_t field_index) {
    switch (field_index) {
        case RMC_FIELD_TIME:
            setTime(&NMEA_Data.Time, Term);
            break;
        
        case RMC_FIELD_DATA_VALID:
            isFix = (*Term == 'A');
            break;

        case RMC_FIELD_LATITUDE:
            setLocation(&NMEA_Data.Location.latitude_raw, Term);
            break;

        case RMC_FIELD_LATITUDE_CARDINAL:
            setCardinal(&NMEA_Data.Location.latitude_raw, Term);
            break;

        case RMC_FIELD_LONGITUDE:
            setLocation(&NMEA_Data.Location.longitude_raw, Term);
            break;

        case RMC_FIELD_LONGITUDE_CARDINAL:
            setCardinal(&NMEA_Data.Location.longitude_raw, Term);
            break;

        case RMC_FIELD_SPEED:
            setSpeed(&NMEA_Data.Speed, Term);
            break;

        case RMC_FIELD_COURSE:
            setCourse(&NMEA_Data.Course, Term);
            break;

        case RMC_FIELD_DATE:
            setDate(&NMEA_Data.Date, Term);
            break;

        default:
            break;
    }
}

#endif /* RMC_H */