#ifndef DASHBOARD_HPP
#define DASHBOARD_HPP
#include <Arduino.h>
#include <WS2812Serial.h>
#include "Metro.h"

#include <KS2eVCUgpios.hpp>
#include "parameters.hpp"

class Dashboard
{

private:
    WS2812Serial * leds;
    Metro *timer;
    uint8_t enableLights[3] = {0, 7, 7};
    uint8_t waitingRtdLights[3] = {2, 7, 7};
    uint8_t rtdLights[3] = {3, 7, 7};
    int led_color_;
    bool ledsdirection=true; //true is up, false is down

public:
    Dashboard(WS2812Serial *leds, Metro *pm100tim) : leds(leds), timer(pm100tim) {}
    void colorWipe(int color, int wait_us);
    void DashLedsBrightness();
    void init_dashboard();
    void DashLedscolorWipe();
    void set_dashboard_led_color(int color);
};

#endif