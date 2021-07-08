#ifndef HX711_H_
#define HX711_H_


/*
  Author:     Nima Askari
  WebSite:    http://www.github.com/NimaLTD
  Instagram:  http://instagram.com/github.NimaLTD
  Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw
  
  Version:    1.0.1
  
  
  Reversion History:
  
  (1.0.1):
  Change delay_us function
  (1.0.0):
  First Release.
*/

#include "main.h"

void        hx711_init(void);
int32_t     hx711_value(void);
int32_t     hx711_valueAve(uint16_t sample);

#endif 
