# ⚡ Smart Shock Protection & Auto-Sensing Outlet  
### _A Low-Voltage Optocoupler & Shunt-Based Zero-Standby Mains Safety System_

![Arduino](https://img.shields.io/badge/Arduino-ATmega328P-blue?logo=arduino)
![C++](https://img.shields.io/badge/Language-C++-blue?logo=cplusplus)
![Circuit Design](https://img.shields.io/badge/Domain-Circuit%20Design-green)
![Embedded Safety](https://img.shields.io/badge/Focus-Embedded%20Safety-red)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## 🎥 Video Demonstration  
[![Watch Demo](https://img.shields.io/badge/YouTube-Watch%20Demo-red?logo=youtube)](https://www.youtube.com/watch?v=YOUR_VIDEO_LINK)

---

## 📑 Table of Contents
- [Abstract & Problem Statement](#-abstract--problem-statement)
- [Power-on-Demand Concept](#-the-power-on-demand-concept)
- [State Machine & Implementation](#-state-machine--detailed-implementation)
- [Functional Block Diagram](#-functional-block-diagram)
- [Pin Mapping](#-complete-pin-mapping)
- [Hardware & BOM](#-hardware-components--bom)
- [Firmware Logic](#-firmware--algorithmic-flow)
- [Safety Considerations](#-safety-engineering-considerations)
- [Applications & Future Scope](#-applications--future-scope)
- [License](#-license)

---

## 🧠 Abstract & Problem Statement

Traditional electrical outlets expose **live 230V AC continuously**, posing serious risks:
- ⚠️ Electric shock hazards (especially for children)
- ⚠️ Accidental contact with live terminals
- ⚠️ Reactive protection (RCCB/GFCI trips **after** fault)

> 💡 **Problem:** Existing systems react *after* danger occurs.

> 🚀 **Solution:** A **preventative smart outlet** that only energizes when a valid load is detected.

---

## ⚡ The "Power-on-Demand" Concept

This system ensures:
- 🔌 **Zero mains voltage at socket in idle state**
- 🔍 Detects appliance insertion using **safe 5V sensing**
- ⚡ Activates 230V only when required
- 🛑 Instantly disconnects when load is removed

> 🛡️ **Result:** No exposed high voltage unless a valid appliance is connected.

---

## 🔄 State Machine & Detailed Implementation

### 🟢 **State 0: Standby / Idle**
- Relay: **De-energized (NC active)**
- Socket Voltage: **0V AC**
- Sensing: **5V DC via Optocoupler**
- Arduino monitors input on **A1**

---

### 🔁 **Transition: Load Detection (0 → 1)**
- Appliance completes 5V sensing loop
- Optocoupler LED turns ON
- Arduino detects signal at **A1**

---

### 🔴 **State 1: Active Mode**
- Arduino sets **Pin 0 LOW**
- Relay switches to **NO (230V AC)**
- Load receives mains power

---

### 🔍 **Continuous Monitoring**
- Shunt resistor measures current
- Arduino reads via **A3**
- Ensures load is still connected

---

### 🔁 **Transition: Disconnect (1 → 0)**
- Current drops below threshold
- Arduino sets **Pin 0 HIGH**
- Relay returns to **NC (safe mode)**

---

## 🔧 Functional Block Diagram

    +----------------------+
    |     Arduino Uno      |
    |                      |
    |  A1 <--- Optocoupler |
    |  A3 <--- Shunt Sense |
    |  D0 ---> Relay Ctrl  |
    +----------+-----------+
               |
               v
    +----------------------+
    |   Relay Module       |
    |   NC / NO / COM      |
    +----+----------+------+
         |          |
    5V DC Path   230V AC Path
         |          |
         +----+-----+
              |
         +----v----+
         | Socket  |
         +---------+
              |
            Load

---

## 🔌 Complete Pin Mapping

| Component              | Connection                     |
|-----------------------|--------------------------------|
| Arduino A1            | Optocoupler Output            |
| Arduino A3            | Shunt Voltage Sensing         |
| Arduino D0            | Relay Trigger (Active LOW)    |
| Relay NC              | 5V DC Sensing Line            |
| Relay NO              | 230V AC Mains                 |
| Relay COM             | Output to Socket              |
| 5V Supply             | Optocoupler Input Circuit     |
| Shunt Resistor        | Series with Load (AC Path)    |

---

## 🧰 Hardware Components & BOM

| Component              | Specification                  |
|-----------------------|-------------------------------|
| Arduino Uno/Nano      | ATmega328P                    |
| Relay Module          | 5V Single Channel (Active LOW)|
| Optocoupler           | PC817                         |
| Shunt Resistor        | Low-ohm, High-watt (≥5W)      |
| Power Supply          | 5V DC Regulated               |
| Socket Outlet         | 230V Rated                    |
| Misc Components       | Resistors, PCB, Wires         |

---

## 💻 Firmware / Algorithmic Flow

### 🔄 Connection Detection Logic


---

### 🔍 Current Monitoring Logic


---

### ⚙️ Noise Handling

- Peak detection for AC waveform
- Moving average filtering
- Multi-sample validation

---

## ⚠️ Safety Engineering Considerations

- 🔌 **Inductive Loads:** Add snubber circuits
- ⚡ **Zero-Cross Noise:** Use filtering algorithms
- 🔥 **Shunt Heating:** Proper wattage rating required
- 🧲 **Isolation:** Optocoupler ensures galvanic isolation
- 🛑 **Fail-safe Design:** Default state = No mains

---

## 🌍 Applications & Future Scope

### 🎯 Applications
- Child-safe smart outlets
- Industrial safety systems
- Smart homes & automation

### 🚀 Future Enhancements
- 🌐 IoT Integration (WiFi/Bluetooth)
- 📊 Current sensing via **ACS712**
- ⚡ Surge & ARC fault detection
- 📱 Mobile monitoring dashboard

---

## 📜 License

This project is licensed under the **MIT License**.

> ✅ Free to use, modify, and distribute with proper attribution.

---

## 🙌 Contribution

Feel free to:
- ⭐ Star this repo
- 🍴 Fork and improve
- 🛠️ Suggest enhancements

---

## 🎥 LinkedIn Video Demonstration  

[![Watch on LinkedIn](https://img.shields.io/badge/LinkedIn-Watch%20Demo-blue?logo=linkedin)](https://lnkd.in/p/dysdAfeV)

> 📌 Click the badge above to watch the full working demo of the project on LinkedIn.

## 💡 Final Thought

> _"The safest electricity is the one that is not present unless needed."_ ⚡

---


