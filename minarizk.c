void main(){	% main function

int x;	% create variable of type integer name x UART1_Init(9600);	% Initialize UART module at boad rate 9600 bps Delay_ms(100);	% set a delay of 100 ms
ANSELA	=	0xFF;	%	set	all	pins	in	PORT	A	as	analog pins
ANSELB	=	0;	%	set	all	pins	in	PORT	B	as	digital pins
ANSELC	=	0;	%	set	all	pins	in	PORT	C	as	digital pins
ANSELD	=	0;	%	set	all	pins	in	PORT	D	as	digital pins
TRISA	=	0xFF;	%	set	all	pins	in	PORT	A	as	input pins
TRISB	=	0;	%	set	all	pins	in	PORT	B	as	output pins
TRISC	=	0;	%	set	all	pins	in	PORT	C	as	output pins
TRISD	=	0;	%	set	all	pins	in	PORT	D	as	output pins

while(1)	% open while loop

{

x = ADC_Read(1);	% analog value of pin Ra1 (LDR) is converted to

digital value and stored in variable x

if(x < 1500)	% if value of x exceeds 1500 execute condition

{

UART1_Write_Text("The lights are turned off") ; % display following on UART terminal

UART_write(13);	% back slash

UART_write(10);	% space

PORTD = 0xFF;	% set value 1 to all pins in PORT D

PORTC = 0x00;	% set value 0 to all pins in PORT C

}
 





else	% if first condition is not satisfied execute following

{

UART1_Write_Text ("The lights are turned on");% display following on UART terminal

UART_write(13);	% back slash

UART_write(10);	% space

PORTD = 0x00;	% set value 0 to all pins in PORT D

PORTC = 0xFF;	% set value 1 to all pins in PORT C

}

}

}