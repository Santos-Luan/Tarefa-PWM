#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define PWM_GPIO 22
#define LED_GPIO 12
#define PWM_FREQ 50      // 50Hz -> Período de 20ms
#define DOWN_PULSE 500   // 0 graus -> 500us
#define MID_PULSE 1470   // 90 graus -> 1470us
#define UP_PULSE 2400    // 180 graus -> 2400us
#define STEP 5           // Passo de incremento do PWM em us
#define DELAY 10         // Tempo de atraso entre incrementos (ms)
#define WAIT_TIME 5000   // Tempo de espera em cada posição (ms)

void set_PWM_pulse(uint gpio, uint pulse_us)
{
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint wrap = pwm_hw->slice[slice_num].top;
    pwm_set_gpio_level(gpio, (pulse_us * wrap) / 20000); // Ajuste proporcional
}

void setup_pwm()
{
    gpio_set_function(PWM_GPIO, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_GPIO);
    pwm_set_wrap(slice_num, 12500);   // 12500 para 50Hz (20ms período)
    pwm_set_clkdiv(slice_num, 64.0f); // Reduz a frequência para ajuste fino
    pwm_set_enabled(slice_num, true);
}

void setup_led()
{
    gpio_init(LED_GPIO);
    gpio_set_dir(LED_GPIO, GPIO_OUT);
}

void led_blink(int times, int delay_ms)
{
    for (int i = 0; i < times; i++)
    {
        gpio_put(LED_GPIO, 1);
        sleep_ms(delay_ms);
        gpio_put(LED_GPIO, 0);
        sleep_ms(delay_ms);
    }
}

int main()
{
    stdio_init_all();
    setup_pwm();
    setup_led();

    // Movimentos iniciais
    set_PWM_pulse(PWM_GPIO, UP_PULSE); // 180 graus
    sleep_ms(WAIT_TIME);
    led_blink(2, 500); // Indicar posição

    set_PWM_pulse(PWM_GPIO, MID_PULSE); // 90 graus
    sleep_ms(WAIT_TIME);
    led_blink(2, 500); // Indicar posição

    set_PWM_pulse(PWM_GPIO, DOWN_PULSE); // 0 graus
    sleep_ms(WAIT_TIME);
    led_blink(2, 500); // Indicar posição

    // Oscilação suave entre os pontos
    while (true)
    {
        for (int pulse = DOWN_PULSE; pulse <= UP_PULSE; pulse += STEP)
        {
            set_PWM_pulse(PWM_GPIO, pulse);
            sleep_ms(DELAY);
        }
        led_blink(3, 500); // Piscar LED RGB para indicar ciclo completo
        for (int pulse = UP_PULSE; pulse >= DOWN_PULSE; pulse -= STEP)
        {
            set_PWM_pulse(PWM_GPIO, pulse);
            sleep_ms(DELAY);
        }
        led_blink(3, 500); // Piscar LED RGB novamente
    }
}
