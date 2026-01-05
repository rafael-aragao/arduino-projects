# Carrinho Controlado via Bluetooth

Projeto de carrinho robótico controlado remotamente por **Bluetooth**, utilizando
Arduino e ponte H para acionamento dos motores.

---

## Descrição
Este projeto permite controlar um carrinho robótico por meio de um aplicativo
no celular, enviando comandos via Bluetooth para o Arduino, que interpreta
essas informações e aciona os motores.

O carrinho pode se movimentar para frente, para trás, virar à esquerda,
virar à direita e parar.

---

## Objetivo
- Aplicar conceitos de **comunicação sem fio**
- Trabalhar com **controle de motores DC**
- Integrar **hardware e software** com Arduino
- Desenvolver um projeto com foco em **robótica educacional**

---

## Componentes utilizados
- Arduino UNO (ou compatível)
- Módulo Bluetooth HC-05 ou HC-06
- Ponte H L298N ou L293D
- 2 Motores DC
- Chassi com rodas
- Bateria / Fonte de alimentação
- Jumpers e protoboard (se necessário)

---

## Funcionamento
1. O celular envia comandos via Bluetooth
2. O módulo Bluetooth recebe os dados
3. O Arduino interpreta os comandos recebidos
4. A ponte H controla o sentido de rotação dos motores
5. O carrinho executa o movimento correspondente

---

## Lógica do código
- Leitura dos dados recebidos pela comunicação serial
- Interpretação de caracteres de comando (ex: F, B, L, R, S)
- Acionamento dos pinos da ponte H conforme o comando recebido

Exemplo de comandos:
- `F` → Frente  
- `B` → Trás  
- `L` → Esquerda  
- `R` → Direita  
- `S` → Parar  

---

## Como executar
1. Abrir o arquivo `.ino` na Arduino IDE
2. Conectar o Arduino ao computador
3. Selecionar a placa e a porta correta
4. Fazer o upload do código
5. Alimentar o circuito
6. Conectar o celular ao módulo Bluetooth
7. Enviar comandos pelo aplicativo

---

## Imagens / Esquema
As imagens do carrinho e do esquema de ligação estão disponíveis
na pasta **`imagens/`** deste projeto.

---

## Possíveis melhorias
- Adição de sensor ultrassônico para evitar colisões
- Controle de velocidade por PWM
- Integração com aplicativo personalizado
- Funcionamento híbrido (Bluetooth + modo autônomo)

