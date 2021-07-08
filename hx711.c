#include "hx711.h"
#include "hx711Config.h"
#if (_HX711_USE_FREERTOS == 1)
#include "cmsis_os.h"
#define hx711_delay(x)    osDelay(x)
#else
#define hx711_delay(x)    HAL_Delay(x)
#endif

//#############################################################################################
void hx711_delay_us(uint32_t delay)
{
  while (delay > 0)
  {
    delay--;
    __nop(); __nop(); __nop(); __nop();    
  }
}
//#############################################################################################
void  hx711_init(void)
{
  GPIO_InitTypeDef  gpio = {0};
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pin = _HX711_SCK_PIN;
  HAL_GPIO_Init(_HX711_SCK_GPIO, &gpio);
  gpio.Mode = GPIO_MODE_INPUT;
  gpio.Pull = GPIO_PULLUP;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pin = _HX711_DI_PIN;
  HAL_GPIO_Init(_HX711_DI_GPIO, &gpio);
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_SET);
  hx711_delay(10);
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_RESET);
  hx711_delay(10);  
  hx711_valueAve(10);
}
//#############################################################################################
int32_t hx711_value(void)
{
  uint32_t data = 0;
  uint32_t  startTime = HAL_GetTick();
  while(HAL_GPIO_ReadPin(_HX711_DI_GPIO, _HX711_DI_PIN) == GPIO_PIN_SET)
  {
    hx711_delay(1);
    if(HAL_GetTick() - startTime > 150)
      return 0;
  }
  for(int8_t i=0; i<24 ; i++)
  {
    HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_SET);   
    hx711_delay_us(1);
    HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_RESET);
    hx711_delay_us(1);
    data = data << 1;    
    if(HAL_GPIO_ReadPin(_HX711_DI_GPIO, _HX711_DI_PIN) == GPIO_PIN_SET)
      data ++;
  }
  data = data ^ 0x800000; 
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_SET);   
  hx711_delay_us(1);
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_RESET);
  hx711_delay_us(1);
  return data;    
}
//#############################################################################################
int32_t hx711_valueAve(uint16_t sample)
{
  int64_t  ave = 0;
  for(uint16_t i=0 ; i<sample ; i++)
    ave += hx711_value();
  return (int32_t)(ave / sample);
}
//#############################################################################################
