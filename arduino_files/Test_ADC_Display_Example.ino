// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorValue = 0;

void setup()
{
  pinMode(A3, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()                           // this is the code that "runs forever"
{
  // read the input on analog pin 0:
  sensorValue = analogRead(A3);
  // set the cursor to column 0, line 0:
  lcd.setCursor(0, 0);
  // print out the value at LCD Display:
  lcd.print(sensorValue);
  // print out the value at Serial Monitor:
  Serial.println(sensorValue);
  lcd.clear(); 
}
