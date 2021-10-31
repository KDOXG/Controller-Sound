SETCHAR_H:		; Função que lê o botão do usuário e salva no registrador R0 a entrada em ASCII
SETLOOP1:		clr p1.0					; Le da linha 1 em nivel baixo
				jnb p1.4, SET1				; Verifica se pressionou botao linha 1 coluna 1
				jnb p1.5, SET2				; == linha 1 coluna 2
				jnb p1.6, SET3				; == linha 1 coluna 3
				jnb p1.7, SET4				; == linha 1 coluna 4
				setb p1.0					; Para de ler a linha 1
				ljmp SETLOOP2				; Passa para linha 2
				
SET1:			mov R0, #0					; Passa 1 para display
				jnb p1.4, $					; Espera soltar o botao
				ret				
SET2:			mov R0, #1					; Passa 2 para display
				jnb p1.5, $					; Espera
				ret				
SET3:			mov R0, #2					; Passa 3 para display
				jnb p1.6, $					; Espera
				ret				
SET4:			mov R0, #3					; Passa 4 para display
				jnb p1.7, $					; Espera
				ret				
				
SETLOOP2:		clr p1.1					; Le da linha 2 em nivel baixo
				jnb p1.4, SET5				; Verifica se pressionou botao linha 2 coluna 1
				jnb p1.5, SET6				; == linha 2 coluna 2
				jnb p1.6, SET7				; == linha 2 coluna 3
				jnb p1.7, SET8				; == linha 2 coluna 4
				setb p1.1					; Para de ler a linha 2
				ljmp SETLOOP3				; Passa para linha 3
				
SET5:			mov R0, #4					; Passa 5 para display
				jnb p1.4, $					; Espera soltar o botao
				ret				
SET6:			mov R0, #5					; Passa 6 para display
				jnb p1.5, $					; Espera
				ret				
SET7:			mov R0, #6					; Passa 7 para display
				jnb p1.6, $					; Espera
				ret				
SET8:			mov R0, #7					; Passa 8 para display
				jnb p1.7, $					; Espera
				ret				
				
SETLOOP3:		clr p1.2					; Le da linha 3 em nivel baixo
				jnb p1.4, SET9				; Verifica se pressionou botao linha 3 coluna 1
				jnb p1.5, SET0				; == linha 3 coluna 2
				jnb p1.6, SETA				; == linha 3 coluna 3
				jnb p1.7, SET_B				; == linha 3 coluna 4
				setb p1.2					; Para de ler a linha 3
				ljmp SETLOOP4				; Passa para linha 4
				
SET9:			mov R0, #8					; Passa 9 para display
				jnb p1.4, $					; Espera soltar o botao
				ret				
SET0:			mov R0, #9					; Passa 0 para display
				jnb p1.5, $					; Espera
				ret				
SETA:			mov R0, #10					; Passa A para display
				jnb p1.6, $					; Espera
				ret				
SET_B:			mov R0, #11					; Passa B para display
				jnb p1.7, $					; Espera
				ret				
				
SETLOOP4:		clr p1.3					; Le da linha 4 em nivel baixo
				jnb p1.4, SETC				; Verifica se pressionou botao linha 4 coluna 1
				jnb p1.5, SETD				; == linha 4 coluna 2
				jnb p1.6, SETE				; == linha 4 coluna 3
				jnb p1.7, SETF				; == linha 4 coluna 4
				setb p1.3					; Para de ler a linha 4
				ljmp SETLOOP1				; Volta para linha 1
;ljmp IN
SETC:			mov R0, #12					; Passa C para display
				jnb p1.4, $					; Espera soltar o botao
				ret				
SETD:			mov R0, #13					; Passa D para display
				jnb p1.5, $					; Espera
				ret				
SETE:			mov R0, #14					; Passa E para display
				jnb p1.6, $					; Espera
				ret				
SETF:			mov R0, #15					; Passa F para display
				jnb p1.7, $					; Espera
				ret				