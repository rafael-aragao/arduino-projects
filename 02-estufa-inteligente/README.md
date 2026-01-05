# Estufa Inteligente com Arduino

Projeto de **estufa inteligente com irrigação automática**, desenvolvido com Arduino,
capaz de monitorar a **umidade do solo** e acionar automaticamente uma **bomba de água**
quando necessário.

---

## Descrição
A Estufa Inteligente utiliza um **sensor de umidade do solo** para verificar as
condições da terra. Quando o solo está seco, o sistema aciona um **relé**, ligando
uma bomba d’água para irrigação. Assim que o solo atinge um nível adequado de
umidade, a bomba é desligada automaticamente.

O projeto possui caráter **educacional**, sendo ideal para aulas de **robótica
educacional, automação e sustentabilidade**.

---

## 🎯 Objetivo
- Automatizar o processo de irrigação
- Evitar desperdício de água
- Trabalhar conceitos de:
  - Sensores analógicos
  - Atuadores (relé)
  - Tomada de decisão com Arduino
  - Sustentabilidade e tecnologia
- Alinhar o projeto aos **ODS 4 (Educação de Qualidade)** e **ODS 15 (Vida Terrestre)**

---

## Componentes Utilizados
- Arduino UNO  
- Sensor de Umidade do Solo + Módulo  
- Módulo Relé  
- Bombinha de Água (5V)  
- Fonte externa (5V, 9V ou 12V)  
- Jumpers  

---

## Esquema de Conexões

### Sensor de Umidade do Solo
- VCC → 5V do Arduino  
- GND → GND do Arduino  
- A0 → Pino A0 do Arduino  

### Módulo Relé
- VCC → 5V do Arduino  
- GND → GND do Arduino  
- IN → Pino 8 do Arduino  

### Bombinha de Água
- Fio positivo → + da fonte externa  
- Fio negativo → COM do relé  
- NO do relé → – da fonte externa  

---

## Funcionamento
1. O Arduino realiza a leitura do valor analógico do sensor de umidade do solo.
2. O valor é comparado com um **limite configurável**.
3. Se o solo estiver seco, o relé é acionado e a bomba liga.
4. Quando o solo estiver úmido, a bomba é desligada automaticamente.
5. As leituras são exibidas no **Monitor Serial**.

---

## Lógica do Código
- Leitura do sensor via `analogRead()`
- Definição de um valor limite para solo seco
- Estrutura condicional (`if / else`) para tomada de decisão
- Acionamento do relé por saída digital
- Atualização periódica a cada 1 segundo

---

## Como Executar
1. Abrir o arquivo `.ino` na Arduino IDE
2. Conectar o Arduino ao computador
3. Selecionar a placa e a porta corretas
4. Fazer o upload do código
5. Alimentar o circuito
6. Acompanhar as leituras pelo Monitor Serial

---

## Imagens / Esquema
As imagens do protótipo e do esquema de ligação estão disponíveis na pasta
**`imagens/`** deste projeto.

---

## Autor
**Rafael Aragão**  
Professor de Robótica Educacional  
Licenciatura em Matemática e Pedagogia  

LinkedIn: https://www.linkedin.com/in/aragao-rafael/

---

## Possíveis Melhorias
- Inclusão de display LCD ou OLED
- Registro de dados (Data Logger)
- Integração com IoT
- Alimentação por energia solar
