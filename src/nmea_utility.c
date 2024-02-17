#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "nmea_utility.h"
#include "nmea_global.h"
#include "nmea_protocol/0183/gga.h"
#include "nmea_protocol/0183/rmc.h"

char Term[NMEA_MAX_FIELD_SIZE];
nmea_sentence_type Type = NMEA_SENTENCE_OTHER;
static uint8_t curTermNumber = 0, curTermOffset = 0;
static bool isNMEASentence = false;
static bool isChecksumTerm = false;
static uint8_t parity = 0;

bool isFix = false;

static int8_t hex2dec(char hex) {
    if      (hex >= '0' && hex <= '9') return (int8_t) (hex - '0');
    else if (hex >= 'A' && hex <= 'F') return (int8_t) (hex - 'A' + 10);
    else if (hex >= 'a' && hex <= 'f') return (int8_t) (hex - 'a' + 10);
    
    return -1;
}

static bool endTermHandler(nmea_data* data) {
    if(isChecksumTerm) {
        isChecksumTerm = false;

        uint8_t checksum = (uint8_t) (16 * hex2dec(Term[0]) + hex2dec(Term[1]));
        if(checksum == parity) {
            return !(Type == NMEA_SENTENCE_OTHER);
        }

        return false;
    }

    if (curTermNumber == NMEA_FIELD_MESSAGE_ID) {
        Type = NMEA_SENTENCE_OTHER;
        if      (strcmp(Term + 2, "RMC") == 0) Type = NMEA_SENTENCE_RMC;
        else if (strcmp(Term + 2, "GGA") == 0) Type = NMEA_SENTENCE_GGA;

        if(Type == NMEA_SENTENCE_OTHER) return false;
    }

    if (Type == NMEA_SENTENCE_RMC) saveFieldNMEA_RMC(data, curTermNumber);
    if (Type == NMEA_SENTENCE_GGA) saveFieldNMEA_GGA(data, curTermNumber);

    return false;
}

bool NMEA_Parser_Process(nmea_data* data, char c) {
    if (c == '$') isNMEASentence = true;
    if (!isNMEASentence) return false;
    if (c == '\r' || c == '\n') isNMEASentence = false;

    switch (c) {
        case ',':
            parity ^= (uint8_t) c;
        case '*':
        case '\r':
        case '\n':
            Term[curTermOffset] = '\0';
            bool isValidSentence = endTermHandler(data);
            curTermNumber++;
            curTermOffset = 0;
            isChecksumTerm = (c == '*');
            return isValidSentence;
            break;
        
        case '$':
            Type = NMEA_SENTENCE_OTHER;
            Term[0] = '\0';
            curTermNumber = curTermOffset = 0;
            isChecksumTerm = false;
            parity = 0;
            isFix = false;
            break;

        default:
            Term[curTermOffset++] = c;
            if(!isChecksumTerm) parity ^= (uint8_t) c;
            break;
    }

    return false;
}

const char* NMEA_Parser_getRawTime(nmea_data* data) { return data->Time.time_raw; }
const char* NMEA_Parser_getRawDate(nmea_data* data) { return data->Date.date_raw; }
const char* NMEA_Parser_getRawLatitude(nmea_data* data) { return data->Location.latitude_raw.location; }
char NMEA_Parser_getRawLatitudeCardinal(nmea_data* data) { return data->Location.latitude_raw.cardinal; }
const char* NMEA_Parser_getRawLongitude(nmea_data* data) { return data->Location.longitude_raw.location; }
char NMEA_Parser_getRawLongitudeCardinal(nmea_data* data) { return data->Location.longitude_raw.cardinal; }
const char* NMEA_Parser_getRawSpeed(nmea_data* data) { return data->Speed.speed_raw; }
const char* NMEA_Parser_getRawCourse(nmea_data* data) { return data->Course.course_raw; }
const char* NMEA_Parser_getRawHDOP(nmea_data* data) { return data->HDOP.hdop_raw; }
const char* NMEA_Parser_getRawAltitude(nmea_data* data) { return data->Altitude.altitude_raw; }