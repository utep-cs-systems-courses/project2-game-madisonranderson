	.arch msp430g2553
	.p2align 1,0

	
	.text
	.global toggle_green

toggle_green:
	cmp #0, &red_led_state
	jz out
	xor #1, &green_led_state
out:
	mov #1, r12
	pop r0
