	.arch msp430g2553
	.p2align 1,0

	
	.text
	.global toggle_green

toggle_green:
	mov #1, &green_led_state
	mov #1, r12
	pop r0
