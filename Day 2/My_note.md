Arduino uses 10-bits ADC (analogue to digital converter). I.e, 2^10 = 1024 bits (from 0 to 1023).
The analgue inputs received through analogue pins e.g A0 therefore need to be converted from 10-bits back to the original analogue values using this formula O = (N/1023)*voltage source value e.g 5v, 3.1v, etc.
