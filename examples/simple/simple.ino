#include <WEMOS_DHT12.h>

DHT12 dht12;

void setup() {

  Serial.begin(115200);

}

void loop() {

  if(dht12.get()==0){
    Serial.print("Temperature in Celsius : ");
    Serial.println(dht12.cTemp);
    Serial.print("Temperature in Fahrenheit : ");
    Serial.println(dht12.fTemp);
    Serial.print("Relative Humidity : ");
    Serial.println(dht12.humidity);
    Serial.println();
  }
  delay(1000);

}
