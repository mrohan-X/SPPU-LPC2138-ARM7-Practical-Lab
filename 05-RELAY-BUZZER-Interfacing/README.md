# Experiment 05: Relay and Buzzer Interfacing

## Subject Details
- **Subject:** Microcontrollers and Applications
- **Course:** Third Year (TE)
- **Branch:** Electronics and Telecommunication Engineering
- **University:** Savitribai Phule Pune University (SPPU)

## Aim
To interface and simulate a relay and buzzer circuit and study its operation using Proteus software.

## Scope of Experiment
- To understand the working of a switching circuit.
- To study the operation of an optocoupler and BC547 transistor.
- To observe the switching behavior of an LED and buzzer.
- To analyze the circuit response for different logic input conditions.

## Controller
Logic Input (HIGH/LOW) in Proteus simulation.

## Hardware Requirements
- Optocoupler (NPN)
- BC547 Transistor
- Buzzer
- LED
- 100Ω Resistor
- 1kΩ Resistor
- 12V DC Supply
- Connecting Wires

## Software Requirements
- Proteus 8 Professional

## Description
This experiment demonstrates the operation of a switching circuit using an optocoupler and BC547 transistor. The circuit is designed and simulated in Proteus to control the LED and buzzer according to the applied logic input.

## Working Principle
The circuit operates based on the logic input applied to it. The optocoupler and transistor act as switching elements to control the output devices.

- When the logic input is HIGH (1), the LED turns ON and the buzzer remains OFF.
- When the logic input is LOW (0), the LED turns OFF and the buzzer turns ON.

## Project Structure
```text
05-Relay-Buzzer-Interfacing/
│
├── README.md
├── Proteus/
├── Schematic/
└── Output/
```

## How to Run
1. Open Proteus 8 Professional.
2. Open the project file from the Proteus folder.
3. Run the simulation.
4. Apply HIGH (1) logic input and observe the output.
5. Apply LOW (0) logic input and observe the output.

## Expected Output
| Logic Input | LED | Buzzer |
|---|---|---|
| HIGH (1) | ON | OFF |
| LOW (0) | OFF | ON |

## Result
The relay and buzzer interfacing circuit was successfully simulated in Proteus, and its operation was observed for different logic input conditions.

## Learning Outcomes
- Understood the working of switching circuits.
- Learned the operation of an optocoupler and transistor.
- Studied LED and buzzer interfacing.
- Observed output changes for different logic inputs.
