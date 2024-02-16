#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "nmea_utility.h"
#include "nmea_protocol/0183/gga.h"
#include "nmea_protocol/0183/rmc.h"

char Term[NMEA_MAX_FIELD_SIZE];
nmea_sentence_type Type = NMEA_SENTENCE_OTHER;
static uint8_t curTermNumber = 0, curTermOffset = 0;
static bool isNMEASentence = false;
static bool isChecksumTerm = false;
static uint8_t parity = 0;

nmea_data NMEA_Data;
bool isFix = false;

static int8_t hex2dec(char hex) {
    if      (hex >= '0' && hex <= '9') return (int8_t) (hex - '0');
    else if (hex >= 'A' && hex <= 'F') return (int8_t) (hex - 'A' + 10);
    else if (hex >= 'a' && hex <= 'f') return (int8_t) (hex - 'a' + 10);
    
    return -1;
}

static bool endTermHandler() {
    if(isChecksumTerm) {
        isChecksumTerm = false;

        uint8_t checksum = (uint8_t) (16 * hex2dec(Term[0]) + hex2dec(Term[1]));
        if(checksum == parity) {
            return true;
        }

        return false;
    }

    if (curTermNumber == NMEA_FIELD_MESSAGE_ID) {
        Type = NMEA_SENTENCE_OTHER;
        if      (strcmp(Term + 2, "RMC") == 0) Type = NMEA_SENTENCE_RMC;
        else if (strcmp(Term + 2, "GGA") == 0) Type = NMEA_SENTENCE_GGA;
    }

    if (Type == NMEA_SENTENCE_RMC) saveFieldNMEA_RMC(curTermNumber);
    if (Type == NMEA_SENTENCE_GGA) saveFieldNMEA_GGA(curTermNumber);

    return false;
}

bool NMEA_Parser_Process(char c) {
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
            bool isValidSentence = endTermHandler();
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

const char* NMEA_Parser_getTime() { return NMEA_Data.Time.time_raw; }
const char* NMEA_Parser_getDate() { return NMEA_Data.Date.date_raw; }
const char* NMEA_Parser_getLatitude() { return NMEA_Data.Location.latitude_raw.location; }
char NMEA_Parser_getLatitudeCardinal() { return NMEA_Data.Location.latitude_raw.cardinal; }
const char* NMEA_Parser_getLongitude() { return NMEA_Data.Location.longitude_raw.location; }
char NMEA_Parser_getLongitudeCardinal() { return NMEA_Data.Location.longitude_raw.cardinal; }
const char* NMEA_Parser_getSpeed() { return NMEA_Data.Speed.speed_raw; }
const char* NMEA_Parser_getCourse() { return NMEA_Data.Course.course_raw; }
const char* NMEA_Parser_getHDOP() { return NMEA_Data.HDOP.hdop_raw; }
const char* NMEA_Parser_getAltitude() { return NMEA_Data.Altitude.altitude_raw; }