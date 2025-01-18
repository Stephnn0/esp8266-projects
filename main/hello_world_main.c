/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "driver/gpio.h"
#include "esp_log.h"


#define LED_PIN 14  // Define the GPIO pin for the LED

void app_main(void)
{

    gpio_config_t io_conf;

    io_conf.intr_type = GPIO_INTR_DISABLE;  // No interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;        // Set as output mode
    io_conf.pin_bit_mask = (1ULL << LED_PIN);  // Set the pin bit mask for GPIO15
    io_conf.pull_up_en = 0;                 // Disable pull-up resistor
    io_conf.pull_down_en = 0;               // Disable pull-down resistor
    gpio_config(&io_conf);                  // Apply configuration

    // Turn on the LED (set GPIO to HIGH)
    gpio_set_level(LED_PIN, 1);

    // Log message to confirm the LED is on
    ESP_LOGI("LED Control", "LED turned on!");



   // esp_chip_info_t chip_info;
  //  esp_chip_info(&chip_info);
  //  printf("model is %d :", chip_info.model);
  //  printf("This is ESP8266 chip with %d CPU cores, WiFi, ", chip_info.cores);
  //  printf("silicon revision %d, ", chip_info.revision);
  //  printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024), 
  //		    (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

  //  for (int i = 5; i >= 0; i--) {
  //      printf("Restarting in %d seconds...\n", i);
  //      vTaskDelay(500 / portTICK_PERIOD_MS);
  //  }
   // printf("Restarting now.\n");
  //  fflush(stdout);
  //  esp_restart();
}
