## HX711 Library for STM32

* http://www.github.com/NimaLTD   
* https://www.instagram.com/github.nimaltd/   
* https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw   

1. Select 2 pins on CubeMX for clock and data pins.
2. Select `General peripheral Initalizion as a pair of '.c/.h' file per peripheral` on project settings.
3. Config `hx711Config.h`.
4. Call `HX711_init()`. 
5. After init, you can read value.
