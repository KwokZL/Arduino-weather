#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 =8 , d5 = 7, d6 = 4, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Adafruit_BMP085.h>

/*************************************************** 
  This is an example for the BMP085 Barometric Pressure & Temp Sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> https://www.adafruit.com/products/391

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here

Adafruit_BMP085 bmp;
  
void setup() {
  

  pinMode(11,OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  if (!bmp.begin()) {
	Serial.println("未能初始化！");
	while (1) {}
  }
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(11,LOW);
}
  
void loop() {
    Serial.print("温度 = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("气压 = ");
    Serial.print(bmp.readPressure()/100);
    Serial.println(" hPa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("海拔高度 = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" 米");

    Serial.print("海平面压力（计算） = ");
    Serial.print(bmp.readSealevelPressure()/100);
    Serial.println(" hPa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("实际高度 = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" 米");
    
    Serial.println();
    lcd.setCursor(1, 0);
    lcd.print("TEMP: ");
    lcd.print(bmp.readTemperature());
    lcd.print(" *C");
    
    if(bmp.readPressure()/100<1013){
       lcd.setCursor(0, 1);
        lcd.print("Rain Or Cloudly");
          if(millis()<3000){
          digitalWrite(11,HIGH);
          delay(1000);
          digitalWrite(11,LOW);
          delay(1000);
          digitalWrite(11,HIGH);
          delay(1000);
          digitalWrite(11,LOW);
          delay(1000);
          digitalWrite(11,HIGH);
          delay(1000);
          digitalWrite(11,LOW);
          delay(1000);
          digitalWrite(11,HIGH);
          delay(1000);
          digitalWrite(11,LOW);
          delay(1000);
          digitalWrite(11,HIGH);
          delay(1000);
          digitalWrite(11,LOW);
          
            }
          
          
        
        
      }else{
        lcd.setCursor(6, 1);
        lcd.print("Sunny");
        }
    
    delay(1000);
}
