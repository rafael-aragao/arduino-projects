# Piano Eletrônico com Arduino

Projeto de um piano eletrônico simples utilizando Arduino, botões e um buzzer.
Cada botão representa uma nota musical, permitindo a execução de sons básicos.

---

## Objetivo do Projeto
- Introduzir conceitos de eletrônica e programação
- Trabalhar lógica de programação
- Explorar frequências sonoras e música
- Aplicação educacional e didática

---

## Objetivos de Desenvolvimento Sustentável (ODS)
- **ODS 4 – Educação de Qualidade**
  Uso da tecnologia para aprendizagem prática.
- **ODS 9 – Indústria, Inovação e Infraestrutura**
  Integração entre hardware e software.

---

## Componentes Utilizados
- Arduino UNO ou Nano
- 1 Buzzer passivo
- 7 Botões
- Jumpers
- Protoboard

---

## Notas Musicais
| Nota | Frequência (Hz) |
|-----|----------------|
| Dó  | 262 |
| Ré  | 294 |
| Mi  | 330 |
| Fá  | 349 |
| Sol | 392 |
| Lá  | 440 |
| Si  | 493 |

---

## Ligações
### Buzzer
- (+) → D6  
- (–) → GND  

### Botões
- Um terminal → GND  
- Outro terminal → D7 a D13  

*(Entradas configuradas com INPUT_PULLUP)*

---

## Funcionamento
- Ao pressionar um botão, o Arduino gera a frequência correspondente no buzzer.
- Apenas uma nota é tocada por vez.
- Ao soltar o botão, o som é interrompido.

---

## Possíveis Melhorias
- Adicionar display LCD/OLED
- Criar oitavas adicionais
- Tocar músicas automáticas
- Versão com ESP32 + aplicativo
- Teclado capacitivo

---

## Autor
**Rafael Aragão**  
Projeto educacional com Arduino

