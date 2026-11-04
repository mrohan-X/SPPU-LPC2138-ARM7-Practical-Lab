# Experiment 01: RTC Interfacing Using ARM7 LPC2138

## Subject Details
- **Subject:** Microcontrollers and Applications
- **Course:** Third Year (TE)
- **Branch:** Electronics and Telecommunication Engineering (ENTC)
- **University:** Savitribai Phule Pune University (SPPU)

## Aim
To interface the internal Real-Time Clock (RTC) of the ARM7 LPC2138 microcontroller and display date and time using UART0 communication.

## Controller
**ARM7 LPC2138**

## Hardware Requirements
- ARM7 LPC2138 Microcontroller
- 12 MHz Crystal
- 32.768 kHz RTC Crystal
- Capacitors
- Connecting wires

## Software Requirements
- Keil µVision 4
- Proteus 8 Professional

## Communication Interface
**UART0**

| Signal | LPC2138 Pin |
|---|---|
| TXD0 | P0.0 (Physical Pin 19) |
| RXD0 | P0.1 (Physical Pin 21) |

## Crystal Connections
- Main crystal: 12 MHz
- RTC crystal: 32.768 kHz
- RTC crystal pins: RTCX1 and RTCX2

## Description
The Real-Time Clock (RTC) is an internal peripheral of the LPC2138 microcontroller used to maintain date and time.

It uses a separate 32.768 kHz crystal to keep track of seconds, minutes, hours, days, months and years.

In this experiment, the RTC is configured through its internal registers. UART0 is used to transmit the RTC values to the Virtual Terminal in Proteus.

## Working Principle
1. Initialize the LPC2138 microcontroller.
2. Configure the internal RTC peripheral.
3. Load the initial date and time into the RTC registers.
4. The RTC continuously updates the time using the 32.768 kHz crystal.
5. UART0 transmits the date and time information.
6. The Virtual Terminal displays the received information.

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
7. Observe the date and time on the Virtual Terminal.

## Expected Output
The Virtual Terminal displays the date and time maintained by the LPC2138 internal RTC.

## Result
The internal RTC of the ARM7 LPC2138 was successfully interfaced, and date and time information was displayed on the Virtual Terminal using UART0.

## Learning Outcomes
- Understanding the internal RTC peripheral of LPC2138.
- Learning RTC register configuration.
- Understanding crystal-based timekeeping.
- Interfacing UART0 with a Virtual Terminal.
- Developing and simulating Embedded C programs.

## Author
**SPPU TE-ENTC Practical Collection**

**Repository:** SPPU-LPC2138-ARM7-Practical-Lab

---

*This repository is created for educational purposes to help engineering students learn Microcontrollers and Applications practicals.*
