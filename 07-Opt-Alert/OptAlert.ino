/*
  Projeto: Opt-Alert – Sistema Inteligente de Alerta por Inclinação
  Plataforma: Arduino Nano (ATmega328P)

  Descrição:
  Sistema de monitoramento de inclinação utilizando acelerômetro MMA845X.
  Quando o ângulo de inclinação ultrapassa o limite configurado, o sistema
  aciona um LED e um buzzer como alerta visual e sonoro.

  🌍 Objetivos de Desenvolvimento Sustentável (ODS)
  - ODS 3: Saúde e Bem-Estar
  - ODS 9: Indústria, Inovação e Infraestrutura
  - ODS 11: Cidades e Comunidades Sustentáveis

  Autor: Rafael Aragão
*/

#include <Wire.h>

// =======================
// ENDEREÇOS I2C DO SENSOR
// =======================
#define ADDR_1 0x1C
#define ADDR_2 0x1D

// =======================
// DEFINIÇÃO DE PINOS (ARDUINO NANO)
// =======================
const int LED_PIN    = 4; // LED de alerta
const int BUZZER_PIN = 3; // Buzzer de alerta

// =======================
// PARÂMETROS DO SISTEMA
// =======================
#define LIMITE_ANGULO 45  // Ângulo limite em graus

byte mmaAddr = 0;        // Endereço I2C do acelerômetro

// =======================
// SETUP
// =======================
void setup() {
  Serial.begin(9600);

  // Inicializa I2C
  // Arduino Nano:
  // SDA → A4 | SCL → A5
  Wire.begin();
  delay(500);

  // Configuração dos atuadores
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("🔍 Procurando sensor MMA845X...");

  // Detecção automática do endereço I2C
  if (checkAddress(ADDR_1)) {
    mmaAddr = ADDR_1;
    Serial.println("✅ Sensor encontrado no endereço 0x1C");
  } 
  else if (checkAddress(ADDR_2)) {
    mmaAddr = ADDR_2;
    Serial.println("✅ Sensor encontrado no endereço 0x1D");
  } 
  else {
    Serial.println("❌ Sensor MMA845X não encontrado!");
    Serial.println("Verifique conexões (3.3V, GND, SDA=A4, SCL=A5)");
    while (true); // Para o sistema
  }

  // Coloca o sensor em modo ativo
  Wire.beginTransmission(mmaAddr);
  Wire.write(0x2A);  // CTRL_REG1
  Wire.write(0x01);  // Ativa o sensor
  Wire.endTransmission();

  Serial.println("✅ Sistema Opt-Alert iniciado!");
}

// =======================
// LOOP PRINCIPAL
// =======================
void loop() {
  int16_t x, y, z;

  // Solicita leitura do acelerômetro
  Wire.beginTransmission(mmaAddr);
  Wire.write(0x01);  // OUT_X_MSB
  Wire.endTransmission(false);
  Wire.requestFrom(mmaAddr, 6, true);

  x = (Wire.read() << 8 | Wire.read()) >> 2;
  y = (Wire.read() << 8 | Wire.read()) >> 2;
  z = (Wire.read() << 8 | Wire.read()) >> 2;

  // Converte para "g"
  float fx = (float)x / 4096.0;
  float fy = (float)y / 4096.0;
  float fz = (float)z / 4096.0;

  // Calcula ângulos de inclinação
  float pitch = atan2(fx, sqrt(fy * fy + fz * fz)) * 180.0 / PI;
  float roll  = atan2(fy, sqrt(fx * fx + fz * fz)) * 180.0 / PI;

  // Exibe dados no Monitor Serial
  Serial.print("Pitch: ");
  Serial.print(pitch, 1);
  Serial.print("° | Roll: ");
  Serial.print(roll, 1);
  Serial.print("° -> ");

  // =======================
  // SISTEMA DE ALERTA
  // =======================
  if (abs(pitch) > LIMITE_ANGULO) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("⚠️ Inclinação perigosa detectada!");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("OK");
  }

  delay(300);
}

// =======================
// FUNÇÃO: VERIFICAR ENDEREÇO I2C
// =======================
bool checkAddress(byte address) {
  Wire.beginTransmission(address);
  return (Wire.endTransmission() == 0);
}
