
                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
				EXPORT  __Vectors
					
__Vectors       DCD     0                  
                DCD     Reset_Handler              ; Reset Handler

				AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler   PROC
				EXPORT  Reset_Handler             [WEAK]
				
				;ʹ��GPIOB
				LDR R0,=0x40021018
				LDR R1,[R0]
				ORR	R1,R1,#8
				STR R1,[R0]
	
				;����GPIOB0Ϊ�������
				LDR R0,=0x40010C00
				LDR R1,[R0]
				ORR	R1,R1,#1
				STR R1,[R0]
				
				LDR R0,=0x40010C0C
loop
				;����GPIOB0����ߵ�ƽ
				LDR R1,[R0]
				ORR	R1,R1,#1
				STR R1,[R0]
				LDR R2,=100000
				BL delay
				;����GPIOB0����͵�ƽ
				BIC	R1,R1,#1
				STR R1,[R0]
				LDR R2,=100000
				BL delay
				B loop
				
delay			SUBS R2,R2,#1
				BNE delay
				MOV PC,LR
				
                ENDP 
                
                 END

