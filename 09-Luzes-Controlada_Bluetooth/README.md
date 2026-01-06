# Casa Iluminada – Controle de Luzes via Bluetooth

Projeto de automação residencial simples utilizando Arduino e módulo Bluetooth (HC-05 ou HC-06), permitindo controlar as luzes de uma casa através de um aplicativo no celular.

---

## Objetivo do Projeto
- Introduzir conceitos de automação residencial
- Trabalhar comunicação serial via Bluetooth
- Desenvolver lógica de controle com Arduino
- Aplicação prática para aulas de robótica e tecnologia

---

## Objetivos de Desenvolvimento Sustentável (ODS)
- **ODS 7 – Energia Acessível e Limpa**  
  Uso consciente da energia elétrica por meio do controle inteligente.
- **ODS 11 – Cidades e Comunidades Sustentáveis**  
  Aplicação de automação em ambientes residenciais.
- **ODS 4 – Educação de Qualidade**  
  Projeto educacional para aprendizagem prática.

---

## Componentes Utilizados
- Arduino UNO ou Nano
- Módulo Bluetooth HC-05 ou HC-06
- 4 LEDs
- 4 resistores (220Ω)
- Jumpers
- Protoboard
- Aplicativo Bluetooth (ex: Serial Bluetooth Terminal)

---

## Ligações

### LEDs
| LED | Pino Arduino |
|----|-------------|
| LED 1 | D2 |
| LED 2 | D3 |
| LED 3 | D4 |
| LED 4 | D5 |

Cada LED deve ser ligado em série com um resistor de 220Ω ao GND.

### Bluetooth (HC-05 / HC-06)
| Módulo | Arduino |
|------|--------|
| VCC | 5V |
| GND | GND |
| TX | RX |
| RX | TX (com divisor de tensão) |

---

## Comandos do Aplicativo Bluetooth

| Comando | Ação |
|------|------|
| 1 | Liga LED 1 |
| 2 | Desliga LED 1 |
| 3 | Liga LED 2 |
| 4 | Desliga LED 2 |
| 5 | Liga LED 3 |
| 6 | Desliga LED 3 |
| 7 | Liga LED 4 |
| 8 | Desliga LED 4 |

---

## Funcionamento
1. O aplicativo envia um caractere via Bluetooth.
2. O Arduino recebe o comando pela comunicação serial.
3. O LED correspondente é ligado ou desligado.
4. O sistema responde imediatamente ao comando enviado.

---

## Possíveis Melhorias
- Botão para ligar/desligar todas as luzes
- Feedback de status no aplicativo
- Controle por cômodos
- Integração com sensores de presença
- Versão com ESP32 e Bluetooth BLE
- Controle via Wi-Fi (IoT)

---

## Autor
**Rafael Aragão**  
Projeto educacional de automação residencial com Arduino

