
/* Universidade de São Paulo
Juliana Witzke de Brito - Pesquisa FAPESP 


Sensor de luz - mede de forma qualitativa diferentes intensidades de luz 
(Usando sensor LDR (resistor dependente da luz) */

int trigPin = 8;
int echoPin = 7;
int pinoLED = 3;
int pinoLDR = A0;
int valorLDR = 0;

//Motor Normal
const int motorPin1  = 2;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Servo Motor
const int motorPin3  = 4;  // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293


float v=331.5+0.6*20; // (Velocidade do som a 0 ºC multiplicada pela temperatura ambiente) m/s

void setup ()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (pinoLED, OUTPUT);

/*------------MOTOR NORMAL ------------*/
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    // Gira o Motor A no sentido horário por 2 segundos
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000); 
    
    // Gira o Motor A no sentido anti-horário por 2 segundos
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000);
    
    /*------------SERVO MOTOR ------------*/
    // Gira o Motor B no sentido horário por 2 segundos
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(2000); 
    
    // Gira o Motor B no sentido anti-horário por 2 segundos
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(2000);  

    // Para motores
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  Serial.begin(9600);

  
}

float distanceCm(){
  //Envia pulso de som
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  //Escuta eco
  float tUs = pulseIn(echoPin, HIGH); // microssegundos
  float t = tUs/1000.0/2.0; // segundos
  float d = t*v; // metros
  return d*100; // centímetros
}

void loop ()
{
  //LDR - SENSOR LUMINOSIDADE
  valorLDR = analogRead(pinoLDR);
  Serial.print("Valor no LDR = ");
  Serial.println(valorLDR);
  delay(15);
  delay(valorLDR);
  if (valorLDR > 1000) digitalWrite (pinoLED, HIGH); // coloca 5 Volts (HIGH) no pino do LED
  if (valorLDR < 1000) digitalWrite (pinoLED, LOW); // coloca 0 Volts no pino do LED
 

  //ULTRASSONICO - SENSOR DISTÂNCIA
  int distancia = distanceCm();
  distancia = distancia/1000;
  Serial.print("Distância = "); 
  Serial.print(distancia, DEC);
  Serial.println(" Centímetros");
  delay(1000); // tempo em milisegundos


}



