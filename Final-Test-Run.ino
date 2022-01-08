
#include <Servo.h>
Servo myservo;


#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
 int frequency1 = 0;
 int frequency2 = 0;
 int frequency3 = 0;

 int pos = 0;

// defining my motor 1
const int in1 = 9;
const int in2 = 10;

// defining my motor 2
const int in3 = 11;
const int in4 = 12;

// defining Ultrasonic sensor pin  numbers
const int trigPin = 13;
const int echoPin = 2;

// defining variables for Ultrasonic sensor
long duration;
int distance;

void setup()
{ 
  myservo.attach(3);
  
  // for color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
  
  // for motor control  
  // motor 1
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // motor 2
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // for ultrasonic sensor
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication for Serial monitor display
}
 
 void loop() 
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
//Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

// turn on motor 1 forward direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
// turn on motor 2 froward direction
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);



if (distance < 2)
{
  // turn motor off
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency1= pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency2 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
    // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency3 = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor

   
    if ( frequency1<40 && frequency1>0)
  { //Serial.println(" red");
    
    myservo.write(200);              // tell servo to go to position in variable 'pos'
    delay(5000); 
    // turn on motor 1 reverse direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
// turn on motor 2 reverse  direction
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(4000);
  
  // turn motor off
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(3000);
  myservo.write(0);
  delay(3000);
    
    }    
}
}

 
 
