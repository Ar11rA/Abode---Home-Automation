/*================================= EG LABS =======================================
The code for saving a text in the EEPROM and read it back when powered up
 
 The circuit:
 * LED attached from pin 6 to ground through a 1K resistor
 
 LCD:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD pin 3
 * LED anode attached to digital output 6
 * LED cathode attached to ground through a 1K resistor
//================================= EG LABS =======================================*/
 
 
#include <EEPROM.h>
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);               // initialize the LCD library with the numbers of the interface pins
int address = 0;                                     // the variable which holds the address in the eeprom
int read_value = 0;                                  // the variable which holds the data which is read from the eeprom
char serial_in_data;                                 // the variable which holds serial input data
int led = 6;                                         // variable which holds the pin number at which the LED is connected
int i;
void setup()
{
  pinMode(led, OUTPUT);                               // initialize the led pin as an output.
  lcd.begin(12, 2);  
lcd.setCursor(0,0);      // set up the LCD's number of columns and rows: 
  lcd.print("ENGINEERS GARAGE");                      
  lcd.setCursor(0, 1);   
  lcd.print(" SERIAL  EEPROM ");
  Serial.begin(9600);                                 // initialize the serial port with baud rate 9600
  Serial.println();
  Serial.println("PREVIOUS TEXT IN EEPROM :-");
  for(address = 0; address < 1024; address ++)        // read the entire EEPROM memory
  {  
    read_value = EEPROM.read(address);
    Serial.write(read_value);
  }
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("WRITE THE NEW TEXT : ");
  
  for(address = 0; address < 1024; address ++)        // fill the entire eeprom memory with white spaces
    EEPROM.write(address, ' ');                 
  
  for(address = 0; address < 1024; )                  // write the incoming serial data to the EEPROM
  {
    if(Serial.available())
    {
      serial_in_data = Serial.read();  
      Serial.write(serial_in_data); 
      EEPROM.write(address, serial_in_data); 
      address ++;
      digitalWrite(led, HIGH);       
      delay(100);
      digitalWrite(led, LOW);
    }
  }
}
 
void loop()
{
  //---- blink LED -----//
  digitalWrite(led, HIGH);       
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
  //---- blink LED -----//
}
 
