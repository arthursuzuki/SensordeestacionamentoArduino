//projeto de sensor de estacionamento
#define trig 2 //entrada trig do sensor ultrasonico
#define echo 3 // entrada echo do sensor ultrasonico
#define red 4 // led vermelho
#define green 5 // led verde
#define yellow 6 // led amarelo
#define buzzer 7 // buzzer
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT); // definindo a porta como uma saida de dados
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(echo, INPUT); // definindo a porta como uma entrada de dados
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duracao = pulseIn(echo, HIGH);
  int distancia = duracao / 58;
  Serial.print("distancia: ");
  Serial.println(distancia);
  delay(100);

  if(distancia<=30){
    digitalWrite(green,HIGH);
    delay(2);
    digitalWrite(green, LOW);

  }
  else if (distancia>=20) {
    digitalWrite(yellow, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(900);
    digitalWrite(yellow,LOW);
    digitalWrite(buzzer,LOW);

  }
  else if (distancia>=10){
    digitalWrite(yellow, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(700);
    digitalWrite(yellow, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if(distancia>=5){
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
  }
  else {
  digitalWrite(red, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(red, LOW);
  digitalWrite(buzzer, LOW);
  }
}


