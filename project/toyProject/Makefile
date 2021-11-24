# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} stateMachine.o buzzer.o wdInterruptHandler.o p1_interrupt_handler.o led.o switches.o buttonMain.o toggle_green.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

buttonMain.c: buzzer.h

led.o: led.c led.h

toggle_green.o: stateMachine.h 

p1_interrupt_handler.o: switches.h

wdInterruptHandler.o: stateMachine.h

buzzer.c: buzzer.h

stateMachine.o: led.h stateMachine.h

switches.o: led.h switches.h

clean:
	rm -f *.o *.elf

