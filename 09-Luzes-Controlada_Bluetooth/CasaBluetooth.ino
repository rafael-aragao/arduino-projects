/* 
  -------------------------------------------------------
  Projeto: Casa Iluminada - Iluminação via Bluetooth
  Descrição: Controle de 4 LEDs através de comandos
             recebidos por Bluetooth (HC-05 / HC-06).

  Comandos do aplicativo:
  1 -> Liga LED 1     | 2 -> Desliga LED 1
  3 -> Liga LED 2     | 4 -> Desliga LED 2
  5 -> Liga LED 3     | 6 -> Desliga LED 3
  7 -> Liga LED 4     | 8 -> Desliga LED 4

  Autor: Rafael Aragão
  -------------------------------------------------------
*/

// =======================
// DEFINIÇÃO DOS PINOS
// =======================
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

// =======================
// VARIÁVEL DE COMANDO
// =======================
char comando;

// =======================
// SETUP
// =======================
void setup() {
  // Configura os LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Inicia comunicação serial (Bluetooth)
  Serial.begin(9600);
}

// =======================
// LOOP PRINCIPAL
// =======================
void loop() {

  // Verifica se há dados recebidos via Bluetooth
  if (Serial.available() > 0) {

    comando = Serial.read();

    // --------- LIGAR LEDs ----------
    if (comando == '1') digitalWrite(led1, HIGH);
    if (comando == '3') digitalWrite(led2, HIGH);
    if (comando == '5') digitalWrite(led3, HIGH);
    if (comando == '7') digitalWrite(led4, HIGH);

    // --------- DESLIGAR LEDs ----------
    if (comando == '2') digitalWrite(led1, LOW);
    if (comando == '4') digitalWrite(led2, LOW);
    if (comando == '6') digitalWrite(led3, LOW);
    if (comando == '8') digitalWrite(led4, LOW);
  }
}
