#ifndef HX711_H_
#define HX711_H_

/*
  Author:     Nima Askari
  WebSite:    http://www.github.com/NimaLTD
  Instagram:  http://instagram.com/github.NimaLTD
  Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw
  
  Version:    1.0.0
  
  
  Reversion History:
  
  (1.0.0)
  First Release.
*/

#include "gpio.h"

void        HX711_init(void);
int32_t     HX711_value(void);
int32_t     HX711_valueAve(uint16_t sample);

#endif 
