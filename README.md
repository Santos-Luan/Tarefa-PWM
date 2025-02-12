# Controle de Servo Motor com Raspberry Pi Pico W

## 📌 Descrição
Este projeto controla um servo motor utilizando o Raspberry Pi Pico por meio de sinais PWM. O servo motor é movimentado suavemente entre os ângulos de 0° e 180°. O projeto também inclui a integração com um LED RGB conectado à GPIO 12, que pisca para indicar o estado do servo.

## 🚀 Funcionalidades
- Gera um sinal PWM na GPIO 22 com frequência de 50Hz.
- Posiciona o servo em 0°, 90° e 180° com pausas de 5 segundos.
- Movimentação suave entre os limites do servo.
- Pisca um LED RGB para indicar a movimentação do servo.

## 🛠 Requisitos
- Raspberry Pi Pico
- Servo motor compatível com PWM
- LED RGB
- Software:
  - VS Code + extensões do Pico SDK
  - SDK do Raspberry Pi Pico instalado
  - Ferramenta BitDogLab (para simulação e testes)

## 📦 Instalação e Uso
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio
   ```
2. Compile e carregue o código no Raspberry Pi Pico utilizando o SDK.
3. Conecte os componentes conforme o esquema:
   - Servo Motor no **GPIO 22**
   - LED RGB no **GPIO 12**
4. Execute o código e observe a movimentação do servo e o comportamento do LED RGB.

## 🔍 Observações com o BitDogLab
Ao testar com a ferramenta BitDogLab, o LED RGB pisca quando o servo atinge posições-chave e ao finalizar um ciclo de movimento, indicando sincronização com o sinal PWM.

### 🎥 Assista ao Vídeo Explicativo
Confira o vídeo explicativo sobre o funcionamento do código:  
[Vídeo Explicativo - Funcionamento do Código](https://drive.google.com/file/d/1CNSWe37zMgwGwhgmhl3TLUuyrtTbUR1s/view?usp=drivesdk)


