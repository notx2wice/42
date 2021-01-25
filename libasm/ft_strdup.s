segment .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
; 말록은 rdi의 값을 읽어 크기를 배정하기 때문에 rdi의 값을 스택에 저장한다.
; call malloc, 말록은 새로만든 공간의 주소를 rax에  넣어 준다
; r9레지스터에 저장 해놓았던 src주소를 넣어둔다.
; strcpy는 rdi rsi레지스터를 사용하기 때문에  rdi에 dst인 rax값을 넣는다.
; rsi 에는 스택에 서 받아왔던 src주소를 넣어준다.
; ft_strcpy (rdi, rsi), rdi <- rsi
_ft_strdup:
	call	_ft_strlen
	add		rax, 1
	push	rdi
	mov		rdi, rax
	call	_malloc
	pop		r9
	mov		rdi, rax
	push	rsi
	mov		rsi, r9
	call	_ft_strcpy
	mov		rdi, r9
	pop		rsi
	ret

