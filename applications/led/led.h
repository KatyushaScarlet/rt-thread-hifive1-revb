#ifndef __LED_H__
#define __LED_H__

#include <rtthread.h>

#define LED_RED 0 
#define LED_BLUE 1 
#define LED_GREEN 2 
#define LED_NUMBER 3 

#define LED_ON 1 
#define LED_OFF 0

void led_init(void);
void led_set(rt_uint8_t led, rt_uint8_t val);
void led_toggle(rt_uint8_t led);

#endif // !__LED_H__
