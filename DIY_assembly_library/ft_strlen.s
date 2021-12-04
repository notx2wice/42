; 1st arg           Stack           EBX               RDI            RDI
; 2nd arg           Stack           ECX               RSI            RSI
; 3rd arg           Stack           EDX               RDX            RDX
; 4th arg           Stack           ESI               RCX            R10
; 5th arg           Stack           EDI               R8             R8
; 6th arg           Stack           EBP               R9  

segment .text
	global _ft_strlen
; RBX, RSI, RDI, RBP
; ft_strlen(arg0 = rdi = char *s)
_ft_strlen:
	mov 	rax, 0	; rax레지스터에 0을 저장한다.
	jmp 	count	; count로 이동

count:
	cmp 	BYTE [rdi + rax], 0
	;cmp는 아래의 명령과 같이 쓰인다 cmp의 결과를 아래에서 사용함.
	;명령어       명령어 기능                           아래 명령어들이 확인하는 플래그 레지스터
	;JE/JZ		Jump Equal or Jump Zero				ZF
	;JNE/JNZ	Jump not Equal or Jump Not Zero		ZF
	;JG/JNLE	Jump Greater or Jump Not Less/Equal	OF, SF, ZF
	;JGE/JNL	Jump Greater/Equal or Jump Not Less	OF, SF
	;JL/JNGE	Jump Less or Jump Not Greater/Equal	OF, SF
	;JLE/JNG	Jump Less/Equal or Jump Not Greater	OF, SF, ZF
	;cmp가 플래그 레지스터에 값을 저장해둔 것을 보고 아래의 je가 참 거짓을 판단.
	je 		exit					; so exit and return rax
	inc	 	rax						; increment rax ( = rax++ )
	jmp 	count					; jump to count and redo the test with rax + 1

;data type (자료형)	크기
;BYTE	부호 없는 1 byte
;WORD	부호 없는 2 byte
;DWORD	부호 없는 4 byte
;QWORD	부호 없는 8 byte

;je 	jump equal
exit:
	ret			; ret 리턴명령어 각 레지스터의 값을 리턴 한다.
;함수 반환값에 사용되는 rax를 리턴하는 결과를 만든다.
;- 범용 레지스터

;RAX : 산술 연산 및 함수 반환값에 사용
;RBX : 메모리 주소 지정(데이터 포인터 용도), RSI,RDI와 함께 사용됨
;RCX : 쉬프트 연산 및 loop counter로 사용
;RDX : 산술 연산 및 I/O 명령에서 사용
;RSI : 문자열 관련 Instruction 사용 시, Source
;RDI : 문자열 관련 Instruction 사용 시, Destination
;RBP : 현재 함수의 Base Pointer
;RSP : 현재 스택 최상위를 가리킴, Push/Pop에 의해 항상 바뀜.
;RIP : 다음에 수행 될 코드 영역을 가리키고 있음.