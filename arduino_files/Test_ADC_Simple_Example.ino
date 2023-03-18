
int ledPinGreen = 9;                  // LED connected to digital pin 9
int ledPinYellow = 10;                // LED connected to digital pin 10
int ledPinRed = 11;                   // LED connected to digital pin 11

int monitorPin = 6;                   // used to scope the PWM output
int analogPin = A3;                   // potentiometer output connected to analog pin 3
int val = 0;                          // variable to store the read value

void setup()                          //define inputs and outputs
{
  Serial.begin(9600);
  pinMode(analogPin, INPUT);          // sets the pin as input
  pinMode(ledPinGreen, OUTPUT);       // sets the pin as output
  pinMode(ledPinYellow, OUTPUT);      // sets the pin as output
  pinMode(ledPinRed, OUTPUT);         // sets the pin as output
}

void loop()                           // this is the code that "runs forever"
{
  val = analogRead(analogPin);        //read the input pin

  // analogRead ranges 0 to 1023
  // analogWrite ranges 0 to 255, thus the division by 4 of val
  
  if (val > 900)                      // high voltage - Red LED turns on
  {
    analogWrite(ledPinRed, val/4);    // write to Red LED
    analogWrite(ledPinYellow, 0);     // disable Yellow LED
    analogWrite(ledPinGreen, 0);      // disable Green LED
    analogWrite(monitorPin, val/4);   // used to scope the PWM output
    }
  else if (val > 700 && val <= 900)   // approaching high voltage - Yellow LED turns on
  {
    analogWrite(ledPinRed, 0);        // disable Red LED
    analogWrite(ledPinYellow, val/4); // write to Yellow LED
    analogWrite(ledPinGreen, 0);      // disable Green LED
    analogWrite(monitorPin, val/4);   // used to scope the PWM output
    }
  else if (val > 100 && val <= 700)   // low voltage - Green LED turns on
  {
    analogWrite(ledPinRed, 0);        // disable Red LED
    analogWrite(ledPinYellow, 0);     // disable Yellow LED
    analogWrite(ledPinGreen, val/4);  // write to Green LED
    analogWrite(monitorPin, val/4);   // used to scope the PWM output
    }
  else                                // little to no voltage input
  {
    analogWrite(ledPinRed, 0);        // disable Red LED
    analogWrite(ledPinYellow, 0);     // disable Yellow LED
    analogWrite(ledPinGreen, 0);      // disable Green LED
    analogWrite(monitorPin, val/4);   // used to scope the PWM output
    }
}
