# Experiment 04: GPS Interfacing Using ARM7 LPC2138

## Subject Details
- **Subject:** Microcontrollers and Applications
- **Course:** Third Year (TE)
- **Branch:** Electronics and Telecommunication Engineering (ENTC)
- **University:** Savitribai Phule Pune University (SPPU)

## Aim
To interface a GPS module with the ARM7 LPC2138 microcontroller using UART communication and obtain geographical location information such as latitude and longitude.

## Scope of Experiment
This experiment covers GPS data reception, processing of GPS information and extraction of geographical coordinates using UART communication.

## Controller
**ARM7 LPC2138**

## Hardware Requirements
- ARM7 LPC2138 Microcontroller
- GPS Module (VGPS in Proteus)
- MAX232 IC
- 12 MHz Crystal
- 22 pF Capacitors
- 1 µF Capacitors for MAX232
- 10 kΩ Resistor
- Virtual Terminal
- Connecting wires
- Power supply

## Software Requirements
- Keil µVision 4
- Proteus 8 Professional

## Communication Interface
**UART Serial Communication**

UART is used to receive GPS data and transmit the processed latitude and longitude values to the Virtual Terminal.

## Pin Connections

### LPC2138 to Virtual Terminal

| Signal | LPC2138 Pin | Physical Pin |
|---|---|---|
| TXD0 | P0.0 | 19 |
| RXD0 | P0.1 | 21 |

### GPS and Serial Communication
- GPS module data is received through the UART interface.
- MAX232 is used for RS-232 voltage-level conversion.
- UART serial data is processed by the LPC2138 microcontroller.

## Description
The Global Positioning System (GPS) is a satellite-based navigation system used to determine geographical location.

A GPS receiver provides location information in the form of serial data, which includes latitude, longitude and other navigation details.

In this experiment, the GPS module is interfaced with the ARM7 LPC2138 microcontroller using UART communication. The received GPS data is processed to extract latitude and longitude values, which are displayed on the Virtual Terminal.

## Working Principle
1. Initialize the LPC2138 microcontroller.
2. Configure UART communication.
3. Receive serial data from the GPS module.
4. Process the received GPS data.
5. Extract latitude and longitude information.
6. Validate the processed GPS information.
7. Display the geographical coordinates on the Virtual Terminal.

## Project Structure

| Folder | Contents |
|---|---|
| `Source-Code` | Embedded C source code |
| `Keil-Project` | Keil project files |
| `Proteus` | Proteus simulation files |
| `HEX` | Compiled HEX file |
| `Schematic` | Circuit diagram images |
| `Output` | GPS output screenshots |

## How to Run
1. Download or clone this repository.
2. Open the Keil project in Keil µVision 4.
3. Build the project to generate the HEX file.
4. Open the Proteus simulation project.
5. Load the generated HEX file into the LPC2138 microcontroller.
6. Configure and run the GPS simulation.
7. Observe the processed GPS coordinates on the Virtual Terminal.

## Expected Output
The Virtual Terminal displays the GPS processing status and geographical coordinates.

Example output:

```text
ENTERED GPS FUNCTION
FIELDS PROCESSED
GPS DATA VALID

GPS LOCATION
Latitude: 17.997846
Longitude: 72.997707

TEST COMPLETED
```

## Result
The GPS module was successfully interfaced with the ARM7 LPC2138 microcontroller using UART communication, and latitude and longitude information were processed and displayed on the Virtual Terminal.

## Learning Outcomes
- Understanding GPS interfacing.
- Learning UART serial communication.
- Understanding GPS data processing.
- Extracting latitude and longitude information.
- Interfacing serial communication devices with ARM7.
- Developing and simulating Embedded C programs.

## Author
**SPPU TE-ENTC Practical Collection**

**Repository:** SPPU-LPC2138-ARM7-Practical-Lab

---

*This experiment is documented for educational purposes to help engineering students learn Microcontrollers and Applications practicals.*
