

# ML-Driven Self-Adaptive Differential Amplifier



## Project Overview
This project focuses on designing a **self-adaptive differential amplifier circuit** that compensates for environmental variations like voltage and temperature changes. Using a combination of **BJT-based differential amplifier design** and **machine learning** integrated with an Arduino board, the system dynamically adjusts resistor values to ensure consistent gain and performance.

---

## Contents of the Project
1. **Introduction**  
   - Explains the role and importance of differential amplifiers in signal processing and noise rejection.
2. **Applications**  
   - Includes usage in audio systems, biomedical devices (e.g., ECG), and noise-canceling headphones.
3. **Challenges Addressed**  
   - Mitigating temperature and voltage variations using ML predictions.
4. **Proposed Solution**  
   - Implementation of a machine learning-driven system using a **linear regression model** to predict optimal resistor values based on voltage and temperature conditions.

---

## Technical Details
### Circuit Design
- **Core**: Differential amplifier with two **BC547B** transistors.
- **Components**:
  - **Q1 and Q2**: Transistors for differential operation.
  - **Biasing Resistors**: Ensure proper operating points.
  - **Voltage and Temperature Sensors**: Measure environmental parameters.

### Software & Hardware
- **Software Tools**:  
  - **LTSpice**: Circuit simulation.  
  - **Python**: Training the linear regression model.  
  - **Arduino IDE**: Implementing ML predictions on hardware.
- **Hardware Components**:
  - Arduino Uno, DHT11 temperature sensor, and voltage sensor.

### Machine Learning
- Trained a **linear regression model** on 12,221 data points generated via LTSpice.
- **Model Equation**:  
  `Gain = 4.1623 * DC + 0.0058 * Temp - 14.6694`
- **Result**: Accurate gain predictions based on environmental conditions.

---

## Results
- **Amplifier Performance**:  
  - Gain measurement aligns with ML predictions.
  - Noise rejection meets expected standards.
- **Arduino Integration**:  
  - Successfully implemented real-time ML-based gain adjustments.

---

## Contribution
| Team Member       | Contribution |
|-------------------|--------------|
| **Kashik P S**    | ML model development, data generation in LTSpice. |
| **Sravani**       | Circuit design, simulation, hardware testing. |
| **Ved Prakash**   | Sensor calibration, simulation, hardware testing. |
| **Rohan Kumar**   | ML integration, Arduino coding, hardware testing. |

---

## Resources
Find project code, videos, and additional resources:  
[Project Resources Link](https://1drv.ms/f/s!Ak3U5l5YbRRMgR9WnQs5xU5rS0Q0?e=G4tV4y)

---

## Observations and Challenges
- **Temperature Impact**: Gain prediction at different temperatures (e.g., 27°C, 40°C).  
- **Voltage Sensor Calibration**: Limited by DC-only capability.  
- **Data Generation**: Time-intensive simulation for ML training.

---

This README provides an overview of the **ML-Driven Self-Adaptive Differential Amplifier** project, highlighting its goals, methods, and results. For further details, refer to the linked resources or contact the contributors.

--- 

