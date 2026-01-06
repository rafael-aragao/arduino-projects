# Estacionamento Inteligente com Arduino e Display LCD I2C

Projeto de **estacionamento inteligente** que controla automaticamente a **entrada e saída de veículos**, exibindo em tempo real a **quantidade de vagas disponíveis** em um **display LCD com módulo I2C**, utilizando Arduino, sensores ultrassônicos e servomotores.

---

## Descrição
O sistema utiliza **sensores ultrassônicos** para detectar a presença de veículos na entrada e na saída do estacionamento. Ao identificar um veículo, o Arduino aciona automaticamente uma **cancela controlada por servomotor** e atualiza o número de vagas disponíveis em um **display LCD I2C**, reduzindo a quantidade de fios e facilitando a montagem do circuito.

O projeto possui caráter **educacional e demonstrativo**, sendo ideal para estudos de **automação urbana, robótica educacional e cidades inteligentes**.

---

## Objetivo
- Automatizar o controle de acesso a estacionamentos
- Monitorar vagas disponíveis em tempo real
- Reduzir congestionamentos internos
- Trabalhar conceitos de:
  - Sensores de distância
  - Atuadores (servomotores)
  - Comunicação I2C
  - Automação e mobilidade urbana
- Aplicar tecnologia em soluções para cidades inteligentes

---

## Objetivos de Desenvolvimento Sustentável (ODS)

Este projeto está alinhado aos seguintes **Objetivos de Desenvolvimento Sustentável da ONU**:

- **ODS 9 – Indústria, Inovação e Infraestrutura**  
  Uso da tecnologia para modernizar sistemas de mobilidade urbana.

- **ODS 11 – Cidades e Comunidades Sustentáveis**  
  Organização do espaço urbano, redução de tráfego e melhor aproveitamento das vagas.

- **ODS 12 – Consumo e Produção Responsáveis**  
  Uso eficiente da infraestrutura existente, evitando desperdício de recursos.

---

## Componentes Utilizados
- Arduino UNO  
- 2 Sensores Ultrassônicos (HC-SR04)  
- 2 Servomotores  
- Display LCD 16x2 com módulo I2C  
- Jumpers  
- Protoboard  

---

## Esquema de Conexões

### Display LCD I2C
- VCC → 5V do Arduino  
- GND → GND do Arduino  
- SDA → A4  
- SCL → A5  

### Sensores Ultrassônicos
**Entrada**
- TRIG → Pino 6  
- ECHO → Pino 7  

**Saída**
- TRIG → Pino 8  
- ECHO → Pino 13  

### Servomotores
- Servo Entrada → Pino 9  
- Servo Saída → Pino 10  

---

## Funcionamento
1. O sistema monitora continuamente os sensores ultrassônicos.
2. Ao detectar um veículo na entrada, verifica se há vagas disponíveis.
3. Caso haja vagas, a cancela de entrada é aberta e o número de vagas é reduzido.
4. Ao detectar um veículo na saída, a cancela é aberta e o número de vagas é incrementado.
5. O display LCD I2C exibe em tempo real a quantidade de vagas disponíveis.
6. Quando não há vagas, o sistema informa **“Estacionamento Lotado”**.

---

## Como Executar
1. Instale a biblioteca **LiquidCrystal_I2C** na Arduino IDE
2. Abra o arquivo `.ino`
3. Conecte o Arduino ao computador
4. Selecione a placa e a porta corretas
5. Faça o upload do código
6. Alimente o circuito e observe o funcionamento

---

##  Possíveis Melhorias
- Integração com aplicativo ou sistema web (IoT)
- Registro de dados de entrada e saída
- Painel externo de vagas disponíveis
- Leitura por RFID ou QR Code
- Integração com sistema de pagamento

---

## Autor
**Rafael Aragão**  
Professor de Robótica Educacional  

🔗 LinkedIn: https://www.linkedin.com/in/aragao-rafael/

