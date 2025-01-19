//#include <IRremote.hpp>

#include "IRremote.hpp"
decode_results res;
void setup() {
  Serial.begin(115200); // выставляем скорость COM порта
  IrReceiver.begin(2); // запускаем прием
  Serial.println("Ready for IR recieve");
}

void loop() {
  if ( IrReceiver.decode()) 
  { // если данные пришли
    Serial.print("Command = ");
    Serial.println( IrReceiver.decodedIRData.command, HEX ); // печатаем данные
    IrReceiver.resume(); // принимаем следующую команду
  }
  delay(100);
}