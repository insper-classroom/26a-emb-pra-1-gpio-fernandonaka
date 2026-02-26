/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */



const int BTN_PIN = 10;
const int LED_PIN_R = 11;

const int bobina1 = 16;
const int bobina2 = 17;
const int bobina3 = 18;
const int bobina4 = 19;

int main() {
  //int led_r_state = 0;
  //int i = 0;
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(bobina1);
  gpio_set_dir(bobina1, GPIO_OUT);
  gpio_put(bobina1, 0);

  gpio_init(bobina2);
  gpio_set_dir(bobina2, GPIO_OUT);
  gpio_put(bobina2, 0);

  gpio_init(bobina3);
  gpio_set_dir(bobina3, GPIO_OUT);
  gpio_put(bobina3, 0);

  gpio_init(bobina4);
  gpio_set_dir(bobina4, GPIO_OUT);
  gpio_put(bobina4, 0);

  while(true) {
    if (!gpio_get(BTN_PIN)) {
      sleep_ms(20);
      gpio_put(LED_PIN_R, 1);
      int i = 0;

      while (i < 512) {
        gpio_put(bobina1, 1);
        sleep_ms(4);

        gpio_put(bobina1, 0);
        gpio_put(bobina2, 1);
        sleep_ms(4);

        gpio_put(bobina2, 0);
        gpio_put(bobina3, 1);
        sleep_ms(4);

        gpio_put(bobina3, 0);
        gpio_put(bobina4, 1);
        sleep_ms(4);
        gpio_put(bobina4, 0);

        i++;
      }
      gpio_put(bobina1, 0);
      gpio_put(bobina2, 0);
      gpio_put(bobina3, 0);
      gpio_put(bobina4, 0);

      gpio_put(LED_PIN_R, 0);
      sleep_ms(500);
    }
    sleep_ms(10);
  }
}



// int main() {
//   int led_r_state = 0;
//   stdio_init_all();

//   gpio_init(BTN_PIN);
//   gpio_set_dir(BTN_PIN, GPIO_IN);
//   gpio_pull_up(BTN_PIN);

//   gpio_init(LED_PIN_R);
//   gpio_set_dir(LED_PIN_R, GPIO_OUT);


//   while (true) {
//     if (gpio_get(BTN_PIN) == 0){
//       //led_r_state = !led_r_state;
//       gpio_put(LED_PIN_R, 1);
//     }
//     else {
//       gpio_put(LED_PIN_R, 0);
//     }

//   }


// }

