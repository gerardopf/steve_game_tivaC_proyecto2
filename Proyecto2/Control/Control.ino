//Realizado por: 
//Javier Alejandro Pérez Marín 20183
//Gerardo Paz Fuentes 20173
#include <HardwareSerial.h>
#define BT1 18
#define BUZZ 19

int tiempo = 0;

void jump(void);

HardwareSerial SerialPort(2); // use UART2

void setup() {
  
  SerialPort.begin(9600, SERIAL_8N1, 16, 17); 
  
  //Salidas
  pinMode(BUZZ, OUTPUT); //Se define pin 19 como output para buzzer

  //Entradas
  pinMode(BT1, INPUT_PULLUP); //Se define pin 18 como input en pull up

  //Interrupciones
  attachInterrupt(digitalPinToInterrupt(BT1), jump, RISING); //Se define interrupción para pulsación de botón

}

void loop() {
  if (tiempo){
    digitalWrite(BUZZ, HIGH);
    delay(25);
    tiempo = 0;
    SerialPort.write(1);
  }
  else
    digitalWrite(BUZZ, LOW);
}

void jump() {
  tiempo = 1;  
}
