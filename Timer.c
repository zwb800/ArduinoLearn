
//设置载波频率
#define TIMER_CONFIG_KHZ(val) ({ \
	const uint8_t pwmval = SYSCLOCK / 2000 / (val); \
	TCCR2A               = _BV(WGM20); \
	TCCR2B               = _BV(WGM22) | _BV(CS20); \
	OCR2A                = pwmval; \
	OCR2B                = pwmval / 3; \
})
