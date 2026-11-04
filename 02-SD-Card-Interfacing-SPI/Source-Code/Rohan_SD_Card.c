#include <LPC213x.h>

#define CS_PIN (1 << 7)

void UART0_Init(void)
{
    PINSEL0 = (PINSEL0 & ~0x0F) | 0x05;

    U0LCR = 0x83;
    U0DLM = 0;
    U0DLL = 20;
    U0LCR = 0x03;
    U0FCR = 0x07;
}

void UART_SendChar(char c)
{
    while (!(U0LSR & 0x20));
    U0THR = c;
}

void UART_SendString(char *s)
{
    while (*s)
        UART_SendChar(*s++);
}

void UART_Hex(unsigned char value)
{
    char hex[] = "0123456789ABCDEF";

    UART_SendString("0x");
    UART_SendChar(hex[value >> 4]);
    UART_SendChar(hex[value & 0x0F]);
}

void SPI0_Init(void)
{
    PINSEL0 &= ~(0x3F << 8);
    PINSEL0 |= (0x15 << 8);

    IO0DIR |= CS_PIN;
    IO0SET = CS_PIN;

    S0SPCCR = 8;
    S0SPCR = 0x20;
}

unsigned char SPI_Transfer(unsigned char data)
{
    S0SPDR = data;

    while (!(S0SPSR & 0x80));

    return S0SPDR;
}

void SD_Select(void)
{
    IO0CLR = CS_PIN;
}

void SD_Deselect(void)
{
    IO0SET = CS_PIN;
    SPI_Transfer(0xFF);
}

unsigned char SD_Command(unsigned char cmd,
                         unsigned long arg,
                         unsigned char crc)
{
    unsigned char response;
    unsigned int i;

    SD_Deselect();
    SD_Select();

    SPI_Transfer(0x40 | cmd);
    SPI_Transfer((unsigned char)(arg >> 24));
    SPI_Transfer((unsigned char)(arg >> 16));
    SPI_Transfer((unsigned char)(arg >> 8));
    SPI_Transfer((unsigned char)arg);
    SPI_Transfer(crc);

    response = 0xFF;

    for (i = 0; i < 10; i++)
    {
        response = SPI_Transfer(0xFF);

        if (!(response & 0x80))
            break;
    }

    return response;
}

int SD_Init(void)
{
    unsigned int i;
    unsigned char response;
    unsigned char cardType;

    UART_SendString("\r\nStarting SD initialization\r\n");

    SD_Deselect();

    for (i = 0; i < 10; i++)
        SPI_Transfer(0xFF);

    /* CMD0 */
    response = SD_Command(0, 0, 0x95);

    UART_SendString("CMD0: ");
    UART_Hex(response);
    UART_SendString("\r\n");

    SD_Deselect();

    if (response != 0x01)
    {
        UART_SendString("CMD0 FAILED\r\n");
        return 0;
    }

    /* CMD8 */
    response = SD_Command(8, 0x000001AA, 0x87);

    UART_SendString("CMD8: ");
    UART_Hex(response);
    UART_SendString("\r\n");

    if (response == 0x01)
    {
        SPI_Transfer(0xFF);
        SPI_Transfer(0xFF);
        SPI_Transfer(0x01);
        SPI_Transfer(0xAA);

        SD_Deselect();

        cardType = 2;
        UART_SendString("SD V2 RESPONSE\r\n");
    }
    else if (response == 0x04 || response == 0x05)
    {
        SD_Deselect();

        cardType = 1;
        UART_SendString("LEGACY SD RESPONSE\r\n");
    }
    else
    {
        SD_Deselect();

        UART_SendString("CMD8 ERROR\r\n");
        return 0;
    }

    /* ACMD41 */
    for (i = 0; i < 100; i++)
    {
        response = SD_Command(55, 0, 0x01);

        UART_SendString("CMD55: ");
        UART_Hex(response);
        UART_SendString("\r\n");

        SD_Deselect();

        if (cardType == 2)
            response = SD_Command(41, 0x40000000, 0x01);
        else
            response = SD_Command(41, 0, 0x01);

        UART_SendString("ACMD41: ");
        UART_Hex(response);
        UART_SendString("\r\n");

        SD_Deselect();

        if (response == 0x00)
        {
            UART_SendString("SD CARD INITIALIZED SUCCESSFULLY\r\n");
            return 1;
        }
    }

    UART_SendString("ACMD41 FAILED\r\n");
    return 0;
}

int main(void)
{
    UART0_Init();
    SPI0_Init();

    UART_SendString("\r\nLPC2138 SD CARD SPI SYSTEM\r\n");

    if (SD_Init())
        UART_SendString("INITIALIZATION SUCCESS\r\n");
    else
        UART_SendString("INITIALIZATION FAILED\r\n");

    while (1);
}