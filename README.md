# Controlling-Dc-Motors-via-Joystick
This project demonstrates how to control two DC motors using a joystick with Arduino.It allows each motor to move in two directions, with smooth speed control. This setup can be used for various robotics applications, where directional control and speed adjustment are essential.

Components Used

Arduino UNO: Serves as the primary microcontroller for handling motor control based on joystick input.
Joystick Module: Equipped with vertical (VRY) and horizontal (VRX) axes to provide bidirectional control signals.
L293D Motor Driver IC: Enables bidirectional control of two DC motors, allowing for forward and reverse motion.
DC Motors (x2): Each motor is independently controlled to achieve variable speed and direction.
Hanmatek HM305 Adjustable Power Supply: Provides a stable 5V power output to meet the current demands of both DC motors. 

Joystick Module:

Vertical Axis (VRY): Controls Motor 1.
Horizontal Axis (VRX): Controls Motor 2.
The joystick button configuration is used to simplify directional control.
Connected directly to the 5V pin on the Arduino to ensure stable readings.

L293D Motor Driver:

Drives two DC motors independently in two directions.
The motor driver sheet is shared in another file.

Power Supply:

Set to 5V, with adequate current to handle the power requirements of both motors. (5V and 2A Power Supply is enough). 
Motors are known to draw high current; Ensure the power supply can meet these demands.

Troubleshooting

If motors do not respond correctly, check the wiring and ensure the power supply is adequate.
Verify motor driver connections to both the Arduino and the motors.
