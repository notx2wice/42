; syscall의 리턴 값은 레지스터 rax에 담기며, 값은 error를 가리키는 -errno의 범위는 -4095부터 -1 사이 입니다.
; ft_write (fd = rdi, address rsi, size = rdx)
;_ft_write:
; write함수와 매칭되는 값 0x2000004
;참고로 그냥 4이 아닌 0x200004인 이유는 macos에선 syscall에 클래스를 두기 때문.
;macosx나 bsd는 system call 번호를 여러 ‘class'로 나눠뒀다.
;read나 write는 syscall_class_unix에 속하기 때문에 upper bits 를 2로 설정한다. 
;즉 unix system call 의 system call 은 (0x2000000 + unix syscall #)가 된다.
;syscall 함수는 rax에 error value를 리턴한다. 
;오류가 있을 경우 작은 음수 (-1 ~ -4095)를 내뱉는다고 한다. 
;이는 unsigned int 값을 벗어나는 연산 결과이므로, carry flag가 참이 된다. 
;따라서 jc(carry flag가 1일 때 점프)를 활용하면 에러 처리 구문(_err)로 넘어갈 수 있다.
section .text
extern ___error
	global _ft_write

_ft_write:
	mov rax, 0x2000004
	syscall
	jc err
	ret

err:
	push rax		;syscall write가 실패하면 뱉은 에러 번호가 저장 되어있다.
	call ___error	;___errno가 에러 번호가 저장 되어야 할곳의 주소를 rax에 리턴하기 때문에 
					;위에서 스택에 저장하여 에러 번호를 저장 하여 둔것
	pop qword[rax]	;ft_write.s:42: error: instruction not supported in 64-bit mode
	mov rax, -1		;각괄호[]는 그 안에 있는 값을 주소로 인식하여, 그 주소가 가리키는 곳을 찾아가라는 의미이다
	ret				;qword 는 뒤의 주소를 64bit체제에 맞게 변환하여 준다.
;일단 리눅스와 비교를 해보면 Mac에서는 pdf에서 사용하라고 한 ___error 함수를 사용하는게 맞다.
;그리고 syscall이 실패했을 경우 linux에서는 errno * -1 rax에 들어오지만
;freebsd계열은 rax에 바로 errno가 들어온다. (알아본 결과 모든 시스템 콜이 이렇게 되는건 아니라고 한다.)
;어쨋은 리눅스에서 neg rax 를 지워주고 __errno_handling 함수 대신 ___error 함수를 이용하면 끝!