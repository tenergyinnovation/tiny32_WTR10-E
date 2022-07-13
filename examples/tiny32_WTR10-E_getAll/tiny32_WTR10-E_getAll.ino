/***********************************************************************
 * Project      :     tiny32_WTR10-E_getAll(SHT20)
 * Description  :     Get value from WTR10-E temperture and Humidity sensor
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     06/06/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32.h>

tiny32 mcu; //define object

uint8_t id = 1; //Address of WTR10-E sensor module, You can change here if it differance

float temperature, humidity;



void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_WTR10-E_getAll ****\r\n");
  mcu.library_version();
  mcu.WTR10_E_begin(RXD3,TXD3);
  mcu.buzzer_beep(2); //buzzer 2 beeps
}

void loop()
{
  
  if(mcu.WTR10_E(id,temperature,humidity))
  {
    Serial.printf("Temperature[%d] => %.1f C\r\n",id,temperature);
    Serial.printf("Humidity[%d] => %.1f%c\r\n",id,humidity,37);
  }
  else
  {
    Serial.printf("Error: Can't get data from WTR10-E sensor!!!");
  }

  Serial.println("-------------------------------");
  vTaskDelay(1000);

}