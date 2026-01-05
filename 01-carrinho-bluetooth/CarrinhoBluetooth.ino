#include <SoftwareSerial.h>

// Definição dos pinos do motor
#define IN1 6
#define IN2 7
#define IN3 10
#define IN4 11

SoftwareSerial bluetoothSerial(2, 3); // RX, TX

void setup() {
  // Inicializa a comunicação serial para o monitor serial e para o módulo Bluetooth
  Serial.begin(9600); // Serial para depuração
  bluetoothSerial.begin(9600);

  // Define os pinos como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Verifica se há comandos recebidos do módulo Bluetooth
  if (bluetoothSerial.available() > 0) {
    char command = bluetoothSerial.read();
    Serial.print("Comando Recebido: ");
    Serial.println(command); // Imprime o comando recebido para depuração
    executeCommand(command);
  }

  // Verifica se há comandos recebidos via monitor serial
  if (Serial.available() > 0) {
    char command = Serial.read();
    Serial.print("Comando Recebido do Monitor Serial: ");
    Serial.println(command); // Imprime o comando recebido para depuração
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case '1': // Avança
      moveForward();
      break;
    case '2': // Recuar
      moveBackward();
      break;
    case '4': // Virar à esquerda
      turnLeft();
      break;
    case '3': // Virar à direita
      turnRight();
      break;
    case 'S': // Parar
      stopMoving();
      break;
  }
}

void moveForward() {
  Serial.println("Movendo para Frente");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  Serial.println("Movendo para Trás");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  Serial.println("Virando à Esquerda");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  Serial.println("Virando à Direita");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMoving() {
  Serial.println("Parando");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
