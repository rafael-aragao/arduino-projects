/* 
  Projeto Estufa - ODS 4 e 15
  Desenvolvido por Professor Rafael Aragão
    
  Funcionalidade: 
  - Liga a bombinha d'água quando o solo está seco
  - Desliga quando o solo está úmido
*/

const int sensorUmidade = A0;   // Pino do sensor de umidade
const int rele = 8;              // Pino do relé que controla a bomba
int leituraUmidade = 0;          // Variável para armazenar a leitura do sensor

void setup() { 
  // Inicializa a comunicação serial
  Serial.begin(9600); 
  
  // Configura o pino do relé como saída
  pinMode(rele, OUTPUT); 
  
  // Garante que o relé comece desligado (ativo em LOW)
  digitalWrite(rele, HIGH); 
  
  // Mensagem de inicialização no monitor serial
  Serial.println("Sistema de irrigação automática iniciado!"); 
  
  // Atraso de 1 segundo antes de começar
  delay(1000); 
}

void loop() { 
  // Lê o valor do sensor de umidade (valor analógico entre 0 e 1023)
  leituraUmidade = analogRead(sensorUmidade); 
  
  // Exibe o valor lido no monitor serial
  Serial.print("Leitura do sensor: ");
  Serial.println(leituraUmidade); 
  
  // --- Ajuste do limite para o solo seco ---
  // Quanto maior o valor, mais seco está o solo.
  // Ajuste o valor conforme o seu sensor (ex: 500 ou 600)
  int limiteSeco = 600; 
  
  // Se o valor lido for maior que o limite, o solo está seco
  if (leituraUmidade > limiteSeco) { 
    Serial.println("Solo seco → Ligando bomba!"); 
    digitalWrite(rele, HIGH);  // Liga a bomba (relé ativo em HIGH)
  } 
  else { 
    Serial.println("Solo úmido → Desligando bomba!"); 
    digitalWrite(rele, LOW);   // Desliga a bomba (relé ativo em LOW)
  }
  
  // Separador para facilitar a leitura no monitor serial
  Serial.println("-----------------------------"); 
  
  // Atraso de 1 segundo antes de realizar a próxima leitura
  delay(1000); 
}
