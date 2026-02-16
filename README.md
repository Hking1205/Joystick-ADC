Code was written for STM32F303re/STM32F3xx, but is also compatible with other STM32 Microcontrollers.

🎮 Analog Joystick (ADC Input Module)

This module provides 2-axis analog position sensing using potentiometers, making it ideal for robotics control systems, RC transmitters, and embedded human-machine interfaces.

It outputs analog voltages proportional to stick position, which can be read using microcontroller ADCs such as those on STM32 devices.


🔧 Key Features

Dual-axis analog output (X and Y)

Optional push-button (Z-axis switch)

Compatible with 3.3V and 5V systems

Smooth analog control for precise input

Simple ADC-based integration


⚙️ Electrical Characteristics
Parameter	Value
Supply Voltage	3.3V – 5V
Output Type	Analog voltage (potentiometer divider)
Axes	X, Y (+ optional push button)
Typical Center Voltage	~Vcc / 2
Interface	ADC + GPIO (button)


📡 STM32 Integration

Fully compatible with STM32 MCUs including:

STM32F303RE

STM32F333xx

Any STM32 with ≥ 2 ADC channels

Typical mapping:

VRx → ADC channel (e.g., PA0 / ADC1_IN1)

VRy → ADC channel (e.g., PA1 / ADC1_IN2)

SW → Digital input with pull-up/down



🧠 ADC Interpretation

Joystick outputs are read as normalized ADC values:

Left / Down → ~0–30%

Center → ~50%

Right / Up → ~70–100%

Example (12-bit ADC):

0 → full left/down

~2048 → center

4095 → full right/up


🧪 Typical Use Cases

Drone remote controllers (throttle, roll, pitch)

Robotic arm manual control

Gamepad-style embedded interfaces

Menu navigation on OLED/UIs

Dual-stick RC transmitters


⚠️ Notes

Use ADC calibration for accurate center detection

Add small dead zone filtering (~±5%) to prevent jitter

Optional: apply moving average or low-pass filtering

If you want, I can also generate:

STM32 HAL ADC driver (JoystickADC.c/h)

Mapping to normalized float values (-1 to +1)

Version tailored for your RC STM32Fxx controller repo 🎮🚁
