//Jakub Krueger 19267452

int valu[3]; //array for sensors. 

//Digital Inputs:
const int buttonPin1 = 2; // digital pin 2
int buttonState1 = 0; // the state of the button press

const int buttonPin2 = 4; // digital pin 4
int buttonState2 = 0; // the state of the button press

const int buttonPin3 = 7;  // digital pin 7
int buttonState3 = 0; // the state of the button press

int knobValue = 0; // value of potentiometer
int light = 0; // value of A0 analog pin which is used to change the brightness of the 3 LED's.

void setup() {
  Serial.begin(57600); // set up serial communication
  pinMode(buttonPin1, INPUT); // digital pin 2 is set as input
  pinMode(buttonPin2, INPUT); // digital pin 4 is set as input
  pinMode(buttonPin3, INPUT); // digital pin 7 is set as input
  pinMode(11, OUTPUT); // digital pin 11 is set as output
  pinMode(10, OUTPUT); // digital pin 10 is set as output
  pinMode(9, OUTPUT); // digital pin 9 is set as output

}

void loop() {
  for(int i = 0; i < 3; i++){ // reads analog inputs one by one and sends the value to max.
  valu[i] = analogRead(i); 
  Serial.print(valu[i]);
  Serial.print(" ");
  }
  light = analogRead(A0); // A0 input is being assigned to a variable.
  
  
  
  buttonState1 = digitalRead(buttonPin1); // digital pin 2 is being read and it's data is sent to max.
  Serial.print(buttonState1);
  Serial.print(" ");

  buttonState2 = digitalRead(buttonPin2); // digital pin 4 is being read and it's data is sent to max.
  Serial.print(buttonState2);
  Serial.print(" ");

  buttonState3 = digitalRead(buttonPin3); // digital pin 7 is being read and it's data is sent to max.
  Serial.print(buttonState3);

  if(buttonState1 == HIGH) // when an individual button is pressed, its corresponding LED is turned on.
  {

  analogWrite(11, light/4); // using pulse width modulation, the LED's brightness will vary depnding on the value that's read from the potentiometer
  } else {
    digitalWrite(11, 0);
  }

  if(buttonState2 == HIGH)
  {

  analogWrite(10, light/4);
  } else {
    digitalWrite(10, 0);
  }

  
 if(buttonState3 == HIGH)
  {

  analogWrite(9, light/4);
  } else {
    digitalWrite(9, 0);
  }

  Serial.println();
  delay(5);
}
