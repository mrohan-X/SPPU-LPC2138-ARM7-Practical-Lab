
#include <LPC213x.h>
#include <stdio.h>

#define PREINT_VALUE 90
#define PREFRAC_VALUE 18112

void UART0_Init(void)
{
    PINSEL0 = (PINSEL0 & ~0x0F) | 0x05;

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

void RTC_Init(void)
{
    CCR = 0x02;
    CCR = 0x00;

    PREINT = PREINT_VALUE;
    PREFRAC = PREFRAC_VALUE;

    SEC = 41;
    MIN = 10;
    HOUR = 13;

    DOM = 1;
    DOW = 0;
    DOY = 305;
    MONTH = 11;
    YEAR = 2026;

    CCR = 0x01;
}

void Display_Time(void)
{
    char output[100];

    sprintf(output,
        "Date: %02d/%02d/%04d  Time: %02d:%02d:%02d IST\r\n",
        (int)DOM, (int)MONTH, (int)YEAR,
        (int)HOUR, (int)MIN, (int)SEC);

    UART0_SendString(output);
}

int main(void)
{
    unsigned int previous_sec = 255;

    UART0_Init();
    RTC_Init();

    UART0_SendString("\r\nLPC2138 REAL TIME CLOCK\r\n");
    UART0_SendString("INDIAN STANDARD TIME\r\n");

    while (1)
    {
        if (SEC != previous_sec)
        {
            previous_sec = SEC;
            Display_Time();
        }
    }
}
