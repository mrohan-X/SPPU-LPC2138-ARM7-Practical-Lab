
#include <LPC213x.h>
#include <stdio.h>
#include <string.h>

void UART0_Init(void)
{
    PINSEL0 = (PINSEL0 & ~0x0000000F) | 0x00000005;

    U0LCR = 0x83;
    U0DLM = 0;
    U0DLL = 20;
    U0LCR = 0x03;

    U0FCR = 0x07;
}

void UART0_SendChar(char ch)
{
    while (!(U0LSR & 0x20));
    U0THR = ch;
}

void UART0_SendString(char *str)
{
    while (*str)
        UART0_SendChar(*str++);
}

/* Convert NMEA coordinate to decimal degrees x 1000000 */
long ConvertCoordinate(char *value)
{
    long raw = 0;
    long degrees;
    long minutes;
    int i = 0;

    while (value[i] != '\0' && value[i] != '.')
    {
        if (value[i] >= '0' && value[i] <= '9')
            raw = raw * 10 + (value[i] - '0');
        i++;
    }

    i++;

    while (value[i] != '\0')
    {
        if (value[i] >= '0' && value[i] <= '9')
            raw = raw * 10 + (value[i] - '0');
        i++;
    }

    /* Remove excess decimal scaling if needed */
    degrees = raw / 1000000;
    minutes = raw % 1000000;

    return degrees * 1000000L +
           (minutes * 1000000L) / 600000L;
}

void PrintCoordinate(char *label, long coordinate)
{
    char output[40];
    long whole, fraction;

    if (coordinate < 0)
    {
        UART0_SendChar('-');
        coordinate = -coordinate;
    }

    whole = coordinate / 1000000L;
    fraction = coordinate % 1000000L;

    sprintf(output, "%s%ld.%06ld\r\n",
            label, whole, fraction);

    UART0_SendString(output);
}

void Process_GPS(char *sentence)
{
    char *field[15];
    char *token;
    int count = 0;
    long latitude, longitude;

    UART0_SendString("ENTERED GPS FUNCTION\r\n");

    token = strtok(sentence, ",");

    while (token != NULL && count < 15)
    {
        field[count++] = token;
        token = strtok(NULL, ",");
    }

    UART0_SendString("FIELDS PROCESSED\r\n");

    if (count > 5 && strstr(field[0], "GGA") != NULL &&
        field[2][0] != '\0' && field[4][0] != '\0')
    {
        UART0_SendString("GPS DATA VALID\r\n");

        latitude = ConvertCoordinate(field[2]);
        longitude = ConvertCoordinate(field[4]);

        if (field[3][0] == 'S')
            latitude = -latitude;

        if (field[5][0] == 'W')
            longitude = -longitude;

        UART0_SendString("\r\nGPS LOCATION\r\n");

        PrintCoordinate("Latitude: ", latitude);
        PrintCoordinate("Longitude: ", longitude);

        UART0_SendString("--------------------\r\n");
    }
    else
    {
        UART0_SendString("GPS DATA INVALID\r\n");
    }
}

int main(void)
{
    char test_gps[] =
    "$GPGGA,123519,1831.2240,N,07351.4020,E,1,10,0.9,560.0,M,46.9,M,,";

    UART0_Init();

    UART0_SendString("\r\nLPC2138 GPS SYSTEM STARTED\r\n");
    UART0_SendString("TESTING GPS DATA...\r\n");

    Process_GPS(test_gps);

    UART0_SendString("TEST COMPLETED\r\n");

    while (1);
}
