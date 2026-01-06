/*
  Projeto: Estacionamento Inteligente com Arduino
  Descrição: Sistema automatizado para controle de entrada e saída de veículos,
             utilizando sensores ultrassônicos, servomotores e display LCD
             para exibição do número de vagas disponíveis.

  🌍 Objetivos de Desenvolvimento Sustentável (ODS)
  - ODS 9: Indústria, Inovação e Infraestrutura
    Uso de tecnologia para automação e melhoria de sistemas urbanos.
  - ODS 11: Cidades e Comunidades Sustentáveis
    Contribui para organização, mobilidade urbana e uso eficiente de espaços.
  - ODS 12: Consumo e Produção Responsáveis
    Otimização do uso de vagas e redução de congestionamentos desnecessários.

  Autor: Rafael Aragão
*/

#include <LiquidCrystal.h>
#include <Servo.h>

// =======================
// CONFIGURAÇÃO DO LCD
// =======================
// Pinos do LCD: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// =======================
// CONFIGURAÇÃO DOS SERVOS
// =======================
Servo servoEntrada;
Servo servoSaida;

const int SERVO_ENTRADA_PIN = 9;
const int SERVO_SAIDA_PIN   = 10;

// =======================
// CONFIGURAÇÃO DOS SENSORES ULTRASSÔNICOS
// =======================
const int TRIG_ENTRADA = 6;
const int ECHO_ENTRADA = 7;

const int TRIG_SAIDA = 8;
const int ECHO_SAIDA = 13;

// =======================
// VARIÁVEIS DE CONTROLE
// =======================
int vagasDisponiveis = 10;       // Total de vagas no estacionamento
const int DISTANCIA_MINIMA = 10; // Distância (cm) para detectar veículo

// =======================
// SETUP
// =======================
void setup() {
  // Inicialização do LCD
  lcd.begin(16, 2);
  atualizarLCD();

  // Inicialização dos servos
  servoEntrada.attach(SERVO_ENTRADA_PIN);
  servoSaida.attach(SERVO_SAIDA_PIN);

  servoEntrada.write(0);  // Cancela de entrada fechada
  servoSaida.write(90);   // Cancela de saída fechada

  // Configuração dos sensores
  pinMode(TRIG_ENTRADA, OUTPUT);
  pinMode(ECHO_ENTRADA, INPUT);
  pinMode(TRIG_SAIDA, OUTPUT);
  pinMode(ECHO_SAIDA, INPUT);

  // Comunicação serial
  Serial.begin(9600);
  Serial.println("Sistema de Estacionamento Inteligente iniciado");
}

// =======================
// LOOP PRINCIPAL
// =======================
void loop() {
  int distanciaEntrada = medirDistancia(TRIG_ENTRADA, ECHO_ENTRADA);
  int distanciaSaida   = medirDistancia(TRIG_SAIDA, ECHO_SAIDA);

  // Debug no Monitor Serial
  Serial.print("Entrada: ");
  Serial.print(distanciaEntrada);
  Serial.print(" cm | Saída: ");
  Serial.print(distanciaSaida);
  Serial.println(" cm");

  // =======================
  // CONTROLE DE ENTRADA
  // =======================
  if (vagasDisponiveis > 0 &&
      distanciaEntrada > 0 &&
      distanciaEntrada <= DISTANCIA_MINIMA) {

    Serial.println("Veículo detectado na ENTRADA");
    servoEntrada.write(90);   // Abre cancela
    delay(3000);              // Tempo para passagem
    servoEntrada.write(0);    // Fecha cancela

    vagasDisponiveis--;
    atualizarLCD();
  }

  // =======================
  // CONTROLE DE SAÍDA
  // =======================
  if (distanciaSaida > 0 &&
      distanciaSaida <= DISTANCIA_MINIMA) {

    Serial.println("Veículo detectado na SAÍDA");
    servoSaida.write(0);      // Abre cancela
    delay(3000);              // Tempo para passagem
    servoSaida.write(90);     // Fecha cancela

    vagasDisponiveis++;
    atualizarLCD();
  }

  delay(500); // Evita leituras excessivas
}

// =======================
// FUNÇÃO: MEDIR DISTÂNCIA
// =======================
int medirDistancia(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH);
  int distancia = duracao * 0.034 / 2;

  return distancia;
}

// =======================
// FUNÇÃO: ATUALIZAR LCD
// =======================
void atualizarLCD() {
  lcd.clear();
  lcd.print("Vagas: ");
  lcd.print(vagasDisponiveis);

  if (vagasDisponiveis == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Estacion. Lotado");
  }
}
