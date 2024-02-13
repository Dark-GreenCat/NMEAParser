#include <stdio.h>
#include "nmea_parser.h"

int main() {
    // char sentence[] = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    char* sentence_rmc = "+QGNSSRD: $GNRMC,100234.000,A,2102.5194,N,10547.2117,E,0.66,166.83,061223,,,A*70\r\n";
    char* sentence_gga = "AT+GNSSRD?: $GNGGA,100236.000,2102.5239,N,10547.2110,E,1,5,2.98,50.0,M,-20.9,M,,*58\r\n";

    for (int i = 0; sentence_rmc[i] != '\0'; i++) {
        if (NMEA_Process(sentence_rmc[i])) {
            printf("Time: %s\n", getTime());
            printf("Date: %s\n", getDate());
            printf("Latitude: %s %c\n", getLatitude(), getLatitudeCardinal());
            printf("Longitude: %s %c\n", getLongitude(), getLongitudeCardinal());
            printf("Speed: %s\n", getSpeed());
            printf("Course: %s\n", getCourse());
            printf("HDOP: %s\n", getHDOP());
            printf("Altitude: %s\n", getAltitude());
            printf("\n");
        }
    }

    for (int i = 0; sentence_gga[i] != '\0'; i++) {
        if (NMEA_Process(sentence_gga[i])) {
            printf("Time: %s\n", getTime());
            printf("Date: %s\n", getDate());
            printf("Latitude: %s %c\n", getLatitude(), getLatitudeCardinal());
            printf("Longitude: %s %c\n", getLongitude(), getLongitudeCardinal());
            printf("Speed: %s\n", getSpeed());
            printf("Course: %s\n", getCourse());
            printf("HDOP: %s\n", getHDOP());
            printf("Altitude: %s\n", getAltitude());
            printf("\n");
        }
    }

    return 0;
}