Code was written for STM32F303re/STM32F3xx, but is also compatible with other STM32 Microcontrollers.
<br>
🎮 Analog Joystick (ADC Input Module)<br>
This module provides 2-axis analog position sensing using potentiometers, making it ideal for robotics control systems, RC transmitters, and embedded human-machine interfaces.
It outputs analog voltages proportional to stick position, which can be read using microcontroller ADCs such as those on STM32 devices.
<br><br>
🔧 Key Features<br>
Dual-axis analog output (X and Y)
Optional push-button (Z-axis switch)
Compatible with 3.3V and 5V systems
Smooth analog control for precise input
Simple ADC-based integration
<br><br>
⚙️ Electrical Characteristics<br>
Parameter	Value
Supply Voltage	3.3V – 5V<br>
Output Type	Analog voltage (potentiometer divider)<br>
Axes	X, Y (+ optional push button)<br>
Typical Center Voltage	~Vcc / 2<br>
Interface	ADC + GPIO (button)<br>
<br><br>
📡 STM32 Integration<br>
Fully compatible with STM32 MCUs including:
STM32F303RE, STM32F333xx
<br>
Any STM32 with ≥ 2 ADC channels
Typical mapping:
VRx → ADC channel (e.g., PA0 / ADC1_IN1)<br>
VRy → ADC channel (e.g., PA1 / ADC1_IN2)<br>
SW → Digital input with pull-up/down<br>
<br><br>
🧠 ADC Interpretation<br>
Joystick outputs are read as normalized ADC values:<br>
Left / Down → ~0–30%<br>
Center → ~50%<br>
Right / Up → ~70–100%<br>
Example (12-bit ADC):<br>
0 → full left/down<br>
~2048 → center<br>
4095 → full right/up<br>
<br><br>
🧪 Typical Use Cases
Drone remote controllers (throttle, roll, pitch)<br>
Robotic arm manual control<br>
Gamepad-style embedded interfaces<br>
Menu navigation on OLED/UIs<br>
Dual-stick RC transmitters<br>
<br><br>
⚠️ Notes
Use ADC calibration for accurate center detection<br>

Add small dead zone filtering (~±5%) to prevent jitter<br>
Optional: apply moving average or low-pass filtering<br>

