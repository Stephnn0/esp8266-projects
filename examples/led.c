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
}

