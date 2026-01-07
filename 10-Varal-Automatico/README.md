# Varal Automático com Arduino

Projeto de automação residencial que utiliza um sensor de água para detectar chuva e um servo motor para recolher ou estender um varal automaticamente.

---

## Objetivo do Projeto
- Automatizar tarefas domésticas
- Introduzir sensores analógicos
- Trabalhar controle de atuadores (servo motor)
- Aplicação prática de automação residencial
- Projeto educacional com Arduino

---

## Objetivos de Desenvolvimento Sustentável (ODS)
- **ODS 11 – Cidades e Comunidades Sustentáveis**  
  Uso de automação para melhorar a qualidade de vida.
- **ODS 9 – Indústria, Inovação e Infraestrutura**  
  Aplicação de tecnologia em soluções inteligentes.
- **ODS 4 – Educação de Qualidade**  
  Aprendizagem prática com eletrônica e programação.

---

## Componentes Utilizados
- Arduino UNO ou Nano
- Sensor de água (sensor de chuva)
- Servo motor
- Jumpers
- Protoboard
- Fonte de alimentação

---

## Ligações

### Sensor de Água
| Sensor | Arduino |
|------|--------|
| VCC | 5V |
| GND | GND |
| Sinal | A0 |

### Servo Motor
| Servo | Arduino |
|------|--------|
| VCC | 5V |
| GND | GND |
| Sinal | D9 |

---

## Funcionamento
1. O sensor de água realiza a leitura da umidade.
2. Quando a chuva é detectada, o valor lido ultrapassa o limite configurado.
3. O servo motor gira para recolher o varal.
4. Quando não há chuva, o servo retorna à posição inicial, estendendo o varal.

---

## Ajustes Importantes
- O valor da variável `limiteAgua` pode variar conforme o sensor utilizado.
- Recomenda-se testar o sensor em ambiente seco e molhado para calibração.

---

## Possíveis Melhorias
- Adicionar display LCD ou OLED
- Enviar notificações via Bluetooth ou Wi-Fi
- Sensor de luminosidade para controle noturno
- Controle manual por aplicativo
- Versão IoT (ESP32)

---

## Autor
**Rafael Aragão**  
Projeto educacional de automação residencial com Arduino

