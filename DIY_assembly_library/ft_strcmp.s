segment .text
	global _ft_strcmp
;int			ft_strcmp(const char *s1 = rdi, const char *s2 =rsi)
_ft_strcmp:
	mov 	rax, 0		; rax 초기화
	push	rdi
	push	rsi
	jmp		compa		; call compa

compa:
	mov		al, BYTE [rdi]  ; 범용 중에 8비트
	mov		bl, BYTE [rsi]
	cmp		al, 0			; 널을 발견하면 비교 중지
	je		exit			; jump to exit_end
	cmp		bl, 0			; 널을 발견하면 비교 중지
	je		exit			; jump to exit
	cmp 	al, bl			; compare al and bl
	jne 	exit			; jne 두 값이 다르면 리턴으로 이동
	inc 	rdi				; increment the rdi pointer
	inc 	rsi				; increment the rsi pointer
	jmp 	compa			; 반복

exit:
	movzx	rax, al			; rax 에 s1의 마지막 확인 문자열을 기록
	push	rbx						; movzx 여분의 자리를 0비트로 채움 24(0) + al(8)
	movzx	rbx, bl			; rbx 에 s2의 마지막 확인 문자열을 기록
	sub		rax, rbx		; rax = rax - rbx
	pop		rbx
	pop		rsi
	pop		rdi
	ret						; rax값이 리턴되는거!!! 알징!!!