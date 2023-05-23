
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
                IMPORT  mymain
					
				IMPORT  my_memcpy
				
				IMPORT |Image$$ER_IROM1$$Base|
				IMPORT |Image$$ER_IROM1$$Length|
				IMPORT |Load$$ER_IROM1$$Base|

				LDR R0, = |Image$$ER_IROM1$$Base|    ; DEST
				LDR R1, = |Load$$ER_IROM1$$Base|     ; SORUCE
				LDR R2, = |Image$$ER_IROM1$$Length|  ; LENGTH
				LDR SP, =(0x20000000+0x10000)
				BL my_memcpy

				IMPORT |Image$$RW_IRAM1$$Base|
				IMPORT |Image$$RW_IRAM1$$Length|
				IMPORT |Load$$RW_IRAM1$$Base|
				
				IMPORT  my_memset
				IMPORT |Image$$RW_IRAM1$$ZI$$Base|
				IMPORT |Image$$RW_IRAM1$$ZI$$Length|
					
				LDR R0, = |Image$$RW_IRAM1$$Base|    ; DEST
				LDR R1, = |Load$$RW_IRAM1$$Base|     ; SORUCE
				LDR R2, = |Image$$RW_IRAM1$$Length|  ; LENGTH
				BL my_memcpy
				
				LDR R0, = |Image$$RW_IRAM1$$ZI$$Base|    ; DEST
				MOV R1,#0   							 ; SET_VALUE
				LDR R2, = |Image$$RW_IRAM1$$ZI$$Length|  ; LENGTH
				BL my_memset
				BL mymain

                ENDP 
                
                 END

