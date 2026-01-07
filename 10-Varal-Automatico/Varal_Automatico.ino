#include <Servo.h>

/*
  -------------------------------------------------------
  Projeto: Varal Automático
  Descrição: Sistema que recolhe ou estende o varal
             automaticamente ao detectar chuva,
             utilizando um sensor de água e um servo motor.

  Autor: Rafael Aragão
  -------------------------------------------------------
*/

// =======================
// DEFINIÇÃO DE PINOS
// =======================
const int sensorAguaPin = A0;   // Pino do sensor de água
const int limiteAgua    = 500;  // Limite para detectar presença de água
const int servoPin      = 9;    // Pino do servo motor

// =======================
// OBJETO SERVO
// =======================
Servo meuServo;

// =======================
// SETUP
// =======================
void setup() {

  // Inicializa o servo
  meuServo.attach(servoPin);

  // Configura o pino do sensor como entrada
  pinMode(sensorAguaPin, INPUT);

  // Inicia a comunicação serial
  Serial.begin(9600);
  Serial.println("Sistema de Varal Automatico iniciado");
}

// =======================
// LOOP PRINCIPAL
// =======================
void loop() {

  // Leitura do sensor de água
  int valorSensor = analogRead(sensorAguaPin);

  // Exibe o valor no monitor serial
  Serial.print("Valor do sensor: ");
  Serial.println(valorSensor);

  // Verifica se há presença de água
  if (valorSensor > limiteAgua) {
    // Detectou chuva: recolhe o varal
    meuServo.write(90);
  } else {
    // Sem chuva: estende o varal
    meuServo.write(0);
  }

  delay(500); // Intervalo entre leituras
}
