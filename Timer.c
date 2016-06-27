
#define SYSCLOCK  16000000 //16Mhz

#define TIMER_ENABLE_PWM    (TCCR2A |= _BV(COM2B1)) //Clear OC2B on Compare Match when up-counting. 
					  	    //Set OC2B on Compare Match when down-counting.
#define TIMER_DISABLE_PWM   (TCCR2A &= ~(_BV(COM2B1)))

//设置载波频率
#define TIMER_CONFIG_KHZ(val) ({ \
	const uint8_t pwmval = SYSCLOCK / 2000 / (val); \ // = 16Mhz / (2 * 38khz) = 16000000 / (2 * 38000)
	TCCR2A               = _BV(WGM20); \ //Mode 5 PWM,Phase Correct TOP is OCRA
	TCCR2B               = _BV(WGM22) | _BV(CS20); \ //No prescaling
	OCR2A                = pwmval; \
	OCR2B                = pwmval / 3; \
})
