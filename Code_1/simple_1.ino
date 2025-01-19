// приём команд с пульта
// приёмник подключать на прерывание по FALLING

#include <NecDecoder.h>
NecDecoder ir;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  // подключил на D2, прерывание 0
  attachInterrupt(0, irIsr, FALLING);
}

// в прерывании вызываем tick()
void irIsr() {
  ir.tick();
}

void loop() {
  // если пакет успешно принят
  if (ir.available()) {      
    if(ir.readPacket() == 16730805) //кнопка движения вниз
    {
        analogWrite(5, 0);
        analogWrite(3, 64);
    }
    if(ir.readPacket() == 16718055) //кнопка движения вверх
    {
        analogWrite(5, 64);
        analogWrite(3, 0);
    }
    if(ir.readPacket() == 16726215) //кнопка ок
    {
        analogWrite(5, 0);
        analogWrite(3, 0);
    }
  }
}