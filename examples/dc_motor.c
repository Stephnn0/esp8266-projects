#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Define GPIO pins for motor control
#define MOTOR_IN1 5  // Connect to IN1 on L293D
#define MOTOR_IN2 4  // Connect to IN2 on L293D
#define MOTOR_ENA 0  // Optional, connect to ENA on L293D if used

void app_main(void) {
    // Configure motor control pins as output
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << MOTOR_IN1) | (1ULL << MOTOR_IN2) | (1ULL << MOTOR_ENA),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);

    // Move motor forward
    gpio_set_level(MOTOR_IN1, 1);
    gpio_set_level(MOTOR_IN2, 0);
    gpio_set_level(MOTOR_ENA, 1); // Enable motor
    vTaskDelay(2000 / portTICK_PERIOD_MS);  // Wait for 2 seconds

    // Move motor backward
    gpio_set_level(MOTOR_IN1, 0);
    gpio_set_level(MOTOR_IN2, 1);
    gpio_set_level(MOTOR_ENA, 1); // Enable motor
    vTaskDelay(2000 / portTICK_PERIOD_MS);  // Wait for 2 seconds

    // Stop motor
    gpio_set_level(MOTOR_IN1, 0);
    gpio_set_level(MOTOR_IN2, 0);
    gpio_set_level(MOTOR_ENA, 0); // Disable motor

    while (1) {
        // Keep running the program to prevent it from exiting
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

