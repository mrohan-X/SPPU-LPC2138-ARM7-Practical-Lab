# Experiment 02: SD Card Interfacing Using SPI with ARM7 LPC2138

## Subject Details
- **Subject:** Microcontrollers and Applications
- **Course:** Third Year (TE)
- **Branch:** Electronics and Telecommunication Engineering (ENTC)
- **University:** Savitribai Phule Pune University (SPPU)

## Aim
To interface an SD card with the ARM7 LPC2138 microcontroller using the SPI communication protocol and successfully initialize the SD card.

## Controller
**ARM7 LPC2138**

## Hardware Requirements
- ARM7 LPC2138 Microcontroller
- SD Card
- 12 MHz Crystal
- Connecting wires
- 3.3V Power Supply

## Software Requirements
- Keil µVision 4
- Proteus 8 Professional

## Communication Interface
**SPI0 (Serial Peripheral Interface)**

| SD Card Signal | LPC2138 Signal | Physical Pin |
|---|---|---|
| CLK | P0.4 / SCK0 | 27 |
| DO | P0.5 / MISO0 | 29 |
| DI | P0.6 / MOSI0 | 30 |
| CS | P0.7 / GPIO | 31 |

## Description
An SD card is a removable storage device used to store digital data.

In this experiment, the SD card is interfaced with the ARM7 LPC2138 microcontroller using SPI communication.

The SPI protocol uses four signals: Clock (SCK), Master In Slave Out (MISO), Master Out Slave In (MOSI), and Chip Select (CS).

The microcontroller sends initialization commands to the SD card and checks its response.

## Working Principle
1. Initialize UART0 for displaying messages on the Virtual Terminal.
2. Configure SPI0 in master mode.
3. Set the SD card Chip Select pin to HIGH.
4. Send initial clock pulses to the SD card.
5. Send CMD0 to reset the card and enter SPI idle state.
6. Send CMD8 to identify the card response.
7. Send CMD55 and ACMD41 commands to initialize the card.
8. Check the response received from the SD card.
9. Display the initialization status on the Virtual Terminal.

## SPI Communication
- **SPI Mode:** Master
- **SPI Peripheral:** SPI0
- **Chip Select:** GPIO P0.7
- **Initialization Clock:** 375 kHz (with the configured 12 MHz clock and default peripheral clock division)

## Project Structure

| Folder | Contents |
|---|---|
| `Source-Code` | Embedded C source code |
| `Keil-Project` | Keil project files |
| `Proteus` | Proteus simulation files |
| `HEX` | Compiled HEX file |
| `Schematic` | Circuit diagram images |
| `Output` | Simulation output screenshots |

## How to Run
1. Download or clone this repository.
2. Open the Keil project in Keil µVision 4.
3. Build the project to generate the HEX file.
4. Open the Proteus simulation project.
5. Load the generated HEX file into the LPC2138 microcontroller.
6. Run the simulation.
7. Observe the SD card initialization messages on the Virtual Terminal.

## Expected Output
The Virtual Terminal displays the SD card initialization status.

Successful initialization should display:

```text
LPC2138 SD CARD SPI SYSTEM
Starting SD initialization
CMD0: 0x01
CMD8: 0x04
LEGACY SD RESPONSE
CMD55: 0x01
ACMD41: 0x00
SD CARD INITIALIZED SUCCESSFULLY
INITIALIZATION SUCCESS
```

## Result
The SD card was successfully interfaced with the ARM7 LPC2138 microcontroller using SPI communication and initialized successfully in Proteus simulation.

## Learning Outcomes
- Understanding SPI communication.
- Learning SPI0 configuration in LPC2138.
- Understanding SD card initialization commands.
- Interfacing external storage devices with a microcontroller.
- Developing and simulating Embedded C programs.

## Author
**SPPU TE-ENTC Practical Collection**

**Repository:** SPPU-LPC2138-ARM7-Practical-Lab

---

*This experiment is documented for educational purposes to help engineering students learn Microcontrollers and Applications practicals.*
