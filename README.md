## HX711 Library for STM32

* http://www.github.com/NimaLTD   
* https://www.instagram.com/github.nimaltd/   
* https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw   

* Select 2 pins on CubeMX for clock and data pins.
* Config `hx711Config.h`.
* Call `hx711_init()`. 
* After init, you can read value.

Example
```
#include "hx711.h"

hx711_t loadcell;
float weight;
.
.
int main()
{
  hx711_init(&loadcell, HX711_CLK_GPIO_Port, HX711_CLK_Pin, HX711_DATA_GPIO_Port, HX711_DATA_Pin);
  hx711_coef_set(&loadcell, 354.5); // read afer calibration
  hx711_tare(&loadcell, 10);
  while (1)
  {
    HAL_Delay(500);
    weight = hx711_weight(&loadcell, 10);
  }
}

```
