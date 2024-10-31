// Pin definitions for motor and joystick control
#define dir3 7       // Motor 2 direction control pin 1
#define dir4 8       // Motor 2 direction control pin 2
#define en2 9        // Motor 2 enable (PWM) pin for speed control
#define dir1 5       // Motor 1 direction control pin 1
#define dir2 6       // Motor 1 direction control pin 2
#define en1 11       // Motor 1 enable (PWM) pin for speed control
#define pinX A0      // Joystick X-axis analog pin (horizontal control)
#define pinY A1      // Joystick Y-axis analog pin (vertical control)
const int centerPos = 512;
const int maxAnalogVal = 1023;

// Dead zone ranges to prevent unintentional movement
const int rangeX = 4;    // Dead zone range for X-axis
const int rangeY = 8;    // Dead zone range for Y-axis

void setup() {
    // Set motor pins as outputs
    pinMode(dir1, OUTPUT);
    pinMode(dir2, OUTPUT);
    pinMode(en1, OUTPUT);
    pinMode(dir3, OUTPUT);
    pinMode(dir4, OUTPUT);
    pinMode(en2, OUTPUT);

    // Set joystick pins as inputs
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);

    // Initialize serial communication for debugging joystick values
    Serial.begin(9600);
}

void loop() {
    int valX = 0;    // Stores raw joystick X-axis value
    int valY = 0;    // Stores raw joystick Y-axis value

    // Read joystick X-axis value (horizontal control)
    valX = analogRead(pinX);
    Serial.println(valX);  // Print X-axis value to serial monitor for debugging

    // Read joystick Y-axis value (vertical control)
    valY = analogRead(pinY);
    Serial.println(valY);  // Print Y-axis value to serial monitor for debugging

    //****You can also map() function for mapping the wanted values. l divided readed values with 4 for simplicity.

    // Control Motor 1 based on joystick X-axis
    if (valX >= (512 - rangeX) && valX <= (centerPos + rangeX)) {
        // Joystick is centered (within dead zone) - stop motor
        analogWrite(en1, 0);               // Stop motor by setting PWM to 0
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, LOW);
    }
    else if (valX > (centerPos + rangeX)) {
        // Joystick is pushed to the right - move motor forward
        digitalWrite(dir1, HIGH);
        digitalWrite(dir2, LOW);
        analogWrite(en1, valX / 4);        // Adjust speed based on joystick position
    }
    else if (valX < (centerPos - rangeX)) {
        // Joystick is pushed to the left - move motor backward
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(en1, (-(valX - maxAnalogVal) / 4)); // Adjust speed based on joystick position
    }

    // Control Motor 2 based on joystick Y-axis
    if (valY >= (centerPos - rangeY) && valY <= (centerPos + rangeY)) {
        // Joystick is centered (within dead zone) - stop motor
        analogWrite(en2, 0);               // Stop motor by setting PWM to 0
        digitalWrite(dir3, LOW);
        digitalWrite(dir4, LOW);
    }
    else if (valY > (centerPos + rangeY)) {
        // Joystick is pushed upward - move motor forward
        digitalWrite(dir3, HIGH);
        digitalWrite(dir4, LOW);
        analogWrite(en2, valY / 4);        // Adjust speed based on joystick position
    }
    else if (valY < (centerPos - rangeY)) {
        // Joystick is pushed downward - move motor backward
        digitalWrite(dir3, LOW);
        digitalWrite(dir4, HIGH);
        analogWrite(en2, (-(valY - maxAnalogVal) / 4)); // Adjust speed based on joystick position
    }
}

