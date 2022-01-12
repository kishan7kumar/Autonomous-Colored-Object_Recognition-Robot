
// program for AUTONOMOUS COLORED OBJECT RECOGNIZING BOT**************************

#include <Servo.h> // for servo motor
Servo myservo;     // for servo motor
int pos = 0;       //  position for servo motor

// defining for Colour sensor TCS3200
#define S0 4 //pins of color sensor
#define S1 5 //pins of color sensor
#define S2 7 //pins of color sensor
#define S3 6 //pins of color sensor
#define sensorOut 8
int frequency1 = 0; // for red diode
int frequency2 = 0; // for green diode
int frequency3 = 0; // for blue diode

// defining my motor 1
const int in1 = 2;
const int in2 = 3;

// defining my motor 2
const int in3 = 10;
const int in4 = 11;

// defines pins numbers for ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;
// defines variables for ultrasonic sensor
long duration;
int distance;

void setup()

{

    //for servo motor
    myservo.attach(9);

    // pins for color sensor
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);
    digitalWrite(S0, HIGH); // Setting frequency-scaling to 20% of color sensor
    digitalWrite(S1, LOW);
    //Serial.begin(9600);              // for displaying results on laptop screen

    // for motor control
    pinMode(in1, OUTPUT); // motor 1
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT); // motor 2
    pinMode(in4, OUTPUT);

    // for ultrasonic sensor
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
                              //Serial.begin(9600);            // for displaying in the monitor
}

void loop()

{
    detectdistance();
    left(); //keep searching 360 degrees

    // if object found
    if (distance <= 40) // object found within range of 40 cm
    {
        forward(); // move towards object
        detectdistance();
        if (distance > 3 && distance <= 13) // if object is 13cm away
        {
            halt(); // bot stops
            delay(1000);
            //left();                 // to correct its gripper position wrt to object
            //delay(100);
            // halt();
            //delay(500);

            detectcolor(); // calling detectcolor function to detect color using tcs 3200
            delay(5000);   // wait for 2 second to detect color

            if (frequency1 > 30 && frequency1 < 270) // settting condition for checking if object has RED color
            {

                myservo.write(-80); // open up the gripper
                delay(2000);
                forward();
                delay(190);
                halt();
                delay(2000);       // wait for 2 second
                myservo.write(80); // close the gripper
                delay(2000);       //wait for 2 second

                //  as red color is detected now bot goes backward to original location
                // bot reverses
                backward();
                delay(2000); // bot goes back for 3 second
                left();      // take left to place the object
                delay(2000); // take left for 2 seconds
                             // now bot stops
                halt();      // bot stops for 1 second
                delay(1000);

                // bot keeps the object in ground
                forward(); // move little forward
                delay(400);
                halt();
                delay(1000);
                myservo.write(-80); // grips opens object dropped
                delay(2000);
                backward(); // go little back
                delay(700);
                halt(); // stop
                delay(1000);
                myservo.write(80); // grips closed
                delay(2000);       // wait for 2 second

                right();     // come in centre again by taking right
                delay(4000); // take right for 4 seconds
                halt();
                delay(5000); // wait for 5 second to start process again

            } // if condtion closed of colour process

            else // if red color was not detected then go back to original location

            {
                backward(); // go back to original location
                delay(2000);

                right(); // searching position
                delay(2000);

                // turn motors off
                halt();
                delay(5000);

            } //else condition closed of colour process

        } //   if closed of near distance
    }     // if closed of search process

} // void loop function closed

// ALL USED FUNCTIONS DEFINED HERE

void detectcolor()
{

    //Setting red filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    frequency1 = pulseIn(sensorOut, LOW); // Reading the output frequency of red color

    //Setting Green filtered photodiodes to be read
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    frequency2 = pulseIn(sensorOut, LOW); // Reading the output frequency of green color

    //Setting Blue filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    frequency3 = pulseIn(sensorOut, LOW); // Reading the output frequency o blue color
}

void detectdistance()
{

    digitalWrite(trigPin, LOW); // Clears the trigPin
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
    distance = duration * 0.034 / 2;   // Calculating the distance
                                       //Serial.print("Distance: ");         // Prints the distance on the Serial Monitor
                                       // Serial.println(distance);
}

void forward()
{
    digitalWrite(in1, HIGH); // turn on motor 1 forward direction
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW); // turn on motor 2 froward direction
    digitalWrite(in4, HIGH);
}

void halt()
{
    digitalWrite(in1, LOW); // turn on motor 1 off
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW); // turn on motor 2 off
    digitalWrite(in4, LOW);
}

void backward()
{
    digitalWrite(in1, LOW); // turn on motor 1 reverse direction
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH); // turn on motor 2 reverse  direction
    digitalWrite(in4, LOW);
}

void left()
{
    digitalWrite(in1, LOW); // turn on motor 1 forward direction
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW); // turn on motor 2 reverse direction
    digitalWrite(in4, HIGH);
}
void right()
{
    digitalWrite(in1, LOW); // turn on motor 1 reverse direction
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW); // turn on motor 2 froward direction
    digitalWrite(in4, HIGH);
}
