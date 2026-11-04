# Experiment 03: GLCD Interfacing Using ARM7 LPC2138

## Subject Details
- **Subject:** Microcontrollers and Applications
- **Course:** Third Year (TE)
- **Branch:** Electronics and Telecommunication Engineering (ENTC)
- **University:** Savitribai Phule Pune University (SPPU)

## Aim
To interface a Graphic LCD (GLCD) with the ARM7 LPC2138 microcontroller and display graphical images using Embedded C programming.

## Scope of Experiment
This experiment covers GLCD interfacing, display control and graphical image rendering using the ARM7 LPC2138 microcontroller.

## Controller
**ARM7 LPC2138**

## Hardware Requirements
- ARM7 LPC2138 Microcontroller
- AMPIRE 128×64 Graphic LCD (GLCD)
- 10 kΩ Resistor
- 10 kΩ Potentiometer for contrast adjustment
- Connecting wires
- +3.3V and +5V power supplies

## Software Requirements
- Keil µVision 4
- Proteus 8 Professional

## Communication Interface
**GLCD Parallel Interface using LPC2138 GPIO pins**

The microcontroller communicates with the GLCD using 8-bit data lines and control signals.

## GLCD Pin Connections

### Data Connections

| GLCD Pin | Signal | LPC2138 Port Pin | Physical Pin |
|---:|---|---|---:|
| 9 | DB0 | P0.16 | 46 |
| 10 | DB1 | P0.17 | 47 |
| 11 | DB2 | P0.18 | 53 |
| 12 | DB3 | P0.19 | 54 |
| 13 | DB4 | P0.20 | 55 |
| 14 | DB5 | P0.21 | 1 |
| 15 | DB6 | P0.22 | 2 |
| 16 | DB7 | P0.23 | 58 |

### Control Connections

| GLCD Pin | Signal | LPC2138 Port Pin | Physical Pin |
|---:|---|---|---:|
| 1 | CS1 | P1.21 | 44 |
| 2 | CS2 | P1.20 | 48 |
| 6 | RS | P1.24 | 32 |
| 7 | R/W | P1.23 | 36 |
| 8 | E | P1.22 | 40 |
| 17 | RST | P1.19 | 4 |

### Power Connections

| GLCD Pin | Signal | Connection |
|---:|---|---|
| 3 | GND | GND |
| 4 | VCC | +5V |
| 5 | V0 | Potentiometer wiper |
| 18 | Vout | Potentiometer outer terminal |

### Contrast Adjustment
- Connect one outer terminal of the 10 kΩ potentiometer to GLCD Vout.
- Connect the middle terminal (wiper) to GLCD V0.
- Connect the other outer terminal to GND.
- Adjust the potentiometer to obtain proper display contrast.

### LPC2138 Power and Reset Connections
- Connect the LPC2138 supply pins according to the circuit schematic.
- Connect the RST pin through a 10 kΩ pull-up resistor to +3.3V.
- Connect all required VSS pins to GND.

## Description
A Graphic LCD (GLCD) is an electronic display used to display graphical information, images, symbols and text.

In this experiment, the AMPIRE 128×64 GLCD is interfaced with the ARM7 LPC2138 microcontroller. Embedded C programming is used to control the display and render graphical images on the screen.

## Working Principle
1. Initialize the LPC2138 microcontroller.
2. Configure the GLCD data and control pins.
3. Initialize the GLCD display.
4. Select the required display area using CS1 and CS2.
5. Send graphical data through the 8-bit data lines.
6. Control the display using RS, R/W and E signals.
7. Display the programmed graphical image on the screen.

## Project Structure

| Folder | Contents |
|---|---|
| `Source-Code` | Embedded C source code |
| `Keil-Project` | Keil project files |
| `Proteus` | Proteus simulation files |
| `HEX` | Compiled HEX file |
| `Schematic` | Circuit diagram images |
| `Output` | GLCD display screenshots |

## How to Run
1. Download or clone this repository.
2. Open the Keil project in Keil µVision 4.
3. Build the project to generate the HEX file.
4. Open the Proteus simulation project.
5. Load the generated HEX file into the LPC2138 microcontroller.
6. Verify the microcontroller clock configuration.
7. Run the simulation.
8. Observe the graphical output on the GLCD.

## Expected Output
The GLCD displays the programmed graphical image successfully.

## Result
The AMPIRE 128×64 Graphic LCD was successfully interfaced with the ARM7 LPC2138 microcontroller, and graphical output was displayed.

## Learning Outcomes
- Understanding GLCD interfacing.
- Learning GLCD data and control signal configuration.
- Understanding graphical data representation.
- Developing Embedded C programs for graphical displays.
- Simulating microcontroller-based display applications.

## Author
**SPPU TE-ENTC Practical Collection**

**Repository:** SPPU-LPC2138-ARM7-Practical-Lab

---

*This experiment is documented for educational purposes to help engineering students learn Microcontrollers and Applications practicals.*
