
// oled 128x32
// sda - A4
// sck - A5

// DS18B20
// data pin - 4

#include <Arduino.h>
#include <U8x8lib.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8X8_SH1106_128X32_VISIONOX_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE); 


#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600); 
  u8x8.begin();
  u8x8.setPowerSave(0);
  sensors.begin();
}

void loop(void)
{
  sensors.requestTemperatures();  
  u8x8.setFont(u8x8_font_inb21_2x4_n);
  char result[8]; 
  dtostrf(sensors.getTempCByIndex(0), 2, 1, result); 

  u8x8.drawString(0,1,result);
  delay(2000);
}
