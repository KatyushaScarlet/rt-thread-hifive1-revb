#include <led.h>
#include <platform.h>
#include <hifive1.h>
#include <gpio.h>

void led_init(void){

    GPIO_REG(GPIO_IOF_EN) &= ~(1UL << RED_LED_OFFSET) ;
    GPIO_REG(GPIO_IOF_EN) &= ~(1UL << GREEN_LED_OFFSET) ;
    GPIO_REG(GPIO_IOF_EN) &= ~(1UL << BLUE_LED_OFFSET) ;

    GPIO_REG(GPIO_OUTPUT_EN) |= (1UL << RED_LED_OFFSET);
    GPIO_REG(GPIO_OUTPUT_EN) |= (1UL << GREEN_LED_OFFSET);
    GPIO_REG(GPIO_OUTPUT_EN) |= (1UL << BLUE_LED_OFFSET);

}

static void _led_set(rt_uint8_t offset, rt_uint8_t val){
    if(val){
        GPIO_REG(GPIO_OUTPUT_VAL) &= ~(1UL<< offset);
    }else{
        GPIO_REG(GPIO_OUTPUT_VAL) |= (1UL << offset);
    }
}

void led_set(rt_uint8_t led, rt_uint8_t val){
    rt_uint32_t bit ;

    switch(led){
        case LED_RED: 
            _led_set(RED_LED_OFFSET, val);
            break;
        case LED_BLUE:
            _led_set(BLUE_LED_OFFSET, val);
            break;
        case LED_GREEN: 
            _led_set(GREEN_LED_OFFSET, val);
            break;
        default:
            break; // Nothing if a wrong led num is given
    }

}

static void _led_toggle(rt_uint8_t offset){
    GPIO_REG(GPIO_OUTPUT_VAL) ^= (1UL << offset);
}

void led_toggle(rt_uint8_t led){
    switch(led){
        case LED_RED:
            _led_toggle(RED_LED_OFFSET);
        case LED_BLUE:
            _led_toggle(BLUE_LED_OFFSET);
        case LED_GREEN:
            _led_toggle(GREEN_LED_OFFSET);
        default:
            break; // Nothing if a wrong led num is given
    }
}
