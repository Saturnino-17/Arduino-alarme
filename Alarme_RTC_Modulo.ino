/* Projeto desenvolvido por:
                             João Arthur Oliveira Barbosa
                             João Victor da Silva Saturnino
*/
#include <stdio.h>
#include <DS1302.h>


namespace {

const int kCePin   = 8;  // Chip Enable
const int kIoPin   = 7;  // Input/Output
const int kSclkPin = 6;  // Serial Clock


DS1302 rtc(kCePin, kIoPin, kSclkPin);

#define buzzer 5

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Domingo";
    case Time::kMonday: return "Segunda-feira";
    case Time::kTuesday: return "Terça-feira";
    case Time::kWednesday: return "Quarta-feira";
    case Time::kThursday: return "Quinta-feira";
    case Time::kFriday: return "Sexta-feira";
    case Time::kSaturday: return "Sábado";
  }
  return "(Dia desconhecido)";
}

void printTime() {
  
  Time t = rtc.time();

  //Nomeia o dia da semana.
  const String day = dayAsString(t.day);

  char buf[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);


  Serial.println(buf);
}

void alarmePrincipal() {
  digitalWrite(buzzer, HIGH);
  delay(5000);
  digitalWrite(buzzer, LOW);
  delay(10);
  }

void alarmeSecundario() {
  digitalWrite(buzzer, HIGH);
  delay(2500);
  digitalWrite(buzzer, LOW);
  delay(10);
  } 

}  

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  rtc.writeProtect(false);
  rtc.halt(false);

  // Define a data e hora atuais
 
  Time t(2018, 1, 8, 15, 34, 50, Time::kMonday);

  
  rtc.time(t);
}

void loop() {
  printTime();
  delay(1000);
  Time t = rtc.time();

  // HORÁRIOS: MATUTINO
  
  if(t.hr == 7 && t.min == 00 && t.sec == 00){
    alarmePrincipal();
    Serial.println("1 HORARIO!");
  }
  else if(t.hr == 7 && t.min == 45 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("2 HORARIO!");
  }
  else if(t.hr == 8 && t.min == 30 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("1 INTERVALO!");
  }
  else if(t.hr == 8 && t.min == 50 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("3 HORARIO!");
  }
  else if(t.hr == 9 && t.min == 35 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("4 HORARIO!");
  }
  else if(t.hr == 10 && t.min == 20 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("2 INTERVALO!");
  }
  else if(t.hr == 10 && t.min == 30 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("5 HORARIO!");
  }
  else if(t.hr == 11 && t.min == 15 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("6 HORARIO!");
  }
  else if(t.hr == 12 && t.min == 00 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("INTERVALO ALMOÇO!");
  }

  // HORÁRIOS: VESPERTINO

  if(t.hr == 13 && t.min == 00 && t.sec == 00){
    alarmePrincipal();
    Serial.println("1 HORARIO! ");
  }
  else if(t.hr == 13 && t.min == 45 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("2 HORARIO! ");
  }
  else if(t.hr == 14 && t.min == 30 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("1 INTERVALO!");
  }
  else if(t.hr == 14 && t.min == 50 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("3 HORARIO!");
  }
  else if(t.hr == 15 && t.min == 35 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("4 HORARIO!");
  }
  else if(t.hr == 16 && t.min == 20 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("2 INTERVALO!");
  }
  else if(t.hr == 16 && t.min == 30 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("5 HORARIO!");
  }
  else if(t.hr == 17 && t.min == 15 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("6 HORARIO!");
  }
  else if(t.hr == 18 && t.min == 00 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("INTERVALO JANTAR!");
  }

   // HORÁRIOS: NOTURNO

   if(t.hr == 18 && t.min == 50 && t.sec == 00){
     alarmePrincipal();
     Serial.println("1 HORARIO!");
   }
   else if(t.hr == 19 && t.min == 35 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("2 HORARIO!");
  }
  else if(t.hr == 20 && t.min == 20 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("1 INTERVALO!");
  }
  else if(t.hr == 20 && t.min == 30 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("3 HORARIO!");
  }
  else if(t.hr == 21 && t.min == 15 && t.sec == 00) {
    alarmeSecundario();
    Serial.println("4 HORARIO!");
  }
  else if(t.hr == 22 && t.min == 00 && t.sec == 00) {
    alarmePrincipal();
    Serial.println("SAIDA!");
  }
} 
