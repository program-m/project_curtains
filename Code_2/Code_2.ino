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
  bool GerkonHigh = digitalRead(7);
  bool GerkonDown = digitalRead(8);
  //Serial.println(a);
  if (ir.available()) {    
    Serial.println(ir.readPacket());  
    if(ir.readPacket() == 16730805 && !GerkonDown) //кнопка движения вниз
    {
        analogWrite(5, 0);
        analogWrite(3, 100);
    }
    if(ir.readPacket() == 16718055 && !GerkonHigh) //кнопка движения вверх
    {
        analogWrite(5, 100);
        analogWrite(3, 0);
    }
    if(ir.readPacket() == 16726215) //кнопка ок
    {
        analogWrite(5, 0);
        analogWrite(3, 0);
    }
  }
  if (GerkonHigh){
    analogWrite(5, 0);
  }
  if (GerkonDown){
    analogWrite(3, 0);
  }
}