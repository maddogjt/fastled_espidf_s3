#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "FastLED.h"

static const char *TAG = "example";

#define LEDS_GPIO 36

static uint8_t s_led_state = 0;

#define NUM_LEDS 8

CRGB leds[NUM_LEDS + 1];

static void update_leds(void)
{
    fill_rainbow(leds, NUM_LEDS + 1, s_led_state);
    FastLED.show();
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured for FastLED!");
    FastLED.addLeds<WS2812, LEDS_GPIO>(leds + 1, NUM_LEDS);
    FastLED.addLeds<WS2812, CONFIG_ONBOARD_LED_GPIO>(leds, 1);
    FastLED.clear(true);
}

extern "C" {

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_led();
    FastLED.setBrightness(32);

    while (1)
    {
        update_leds();
        /* Toggle the LED state */
        s_led_state += 1;
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}

}