//Braço robôtico automático e manual. 16º projeto.linguagem utilizada c++
#include <Servo.h>

int fasedoservo;
int fasedobotao;

Servo servo_2; // SERVO MOTAR BRAÇO

Servo servo_3; // SERVO MOTAR MÃO



void setup()
{
  fasedoservo=1;

  servo_2.attach(2, 500, 2500); // SERVO MOTAR BASE
  servo_3.attach(3, 500, 2500);// SERVO MOTAR MÃO

  pinMode(A0,INPUT);//BRAÇO

  pinMode(7,INPUT_PULLUP); //MODO ALTOMÁTICO
  pinMode(8,INPUT_PULLUP); //MÃO
  pinMode(10,INPUT_PULLUP);//MOTOR (BASE) FRENTE
  pinMode(11,INPUT_PULLUP);//MOTOR (BASE) RÉ
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
}

void loop()
{
  
if (digitalRead(7)==LOW){
  servo_2.write(120); // SERVO MOTAR BRAÇO
  servo_3.write(0);// SERVO MOTAR MÃO
 delay(1000);
  servo_2.write(120); // SERVO MOTAR BRAÇO
  delay(500);
  servo_3.write(100);// SERVO MOTAR MÃO
 delay(500);
  servo_2.write(90); // SERVO MOTAR BRAÇO
   analogWrite(5,60);  //MOTOR (BASE)
   digitalWrite(6,LOW);
 delay(760);
   digitalWrite(5,LOW);  //MOTOR (BASE)
   digitalWrite(6,LOW);
  servo_2.write(120); // SERVO MOTAR BRAÇO
  delay(1000);
  servo_3.write(0);// SERVO MOTAR MÃO
 delay(1000);
  servo_2.write(90); // SERVO MOTAR BRAÇO
  delay(150);
 analogWrite(6,60);
   digitalWrite(5,LOW);
   delay(760);
}else{
  

  if (digitalRead(11)==LOW){ //MOTOR (BASE)
  analogWrite(5,60);
   digitalWrite(6,LOW);
  }else {
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   if (digitalRead(10)==LOW){ //MOTOR (BASE)
   analogWrite(6,60);
   digitalWrite(5,LOW);
  }
  }

  servo_2.write(map(analogRead(A0), 0, 1023, 0, 179)); // SERVO MOTAR BRAÇO

  fasedobotao = digitalRead(8); // SERVO MOTAR MÃO
  if (fasedobotao==LOW){

    if (fasedoservo <2 ){
      fasedoservo=fasedoservo+1;
    }else {
    fasedoservo=1;
    }

    if (fasedoservo==1){
      servo_3.write(100);
      delay(600);
    }
      if(fasedoservo==2){
      servo_3.write(0);
      delay(600);
      }
  }
  }
}
