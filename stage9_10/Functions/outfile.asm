START
MOV BP, 0
MOV SP, -1
CALL main
HALT
gcd:
PUSH BP
MOV BP, SP
MOV R0, 1
MOV R1, SP
ADD R1, R0 
MOV SP, R1
MOV R0, -3
MOV R1, BP
ADD R0, R1
MOV R0, [R0]
MOV R1, 0
EQ R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L1
MOV R0, 1
MOV R1, BP
ADD R0, R1
MOV R1, -4
MOV R2, BP
ADD R1, R2
MOV R1, [R1]
MOV [R0], R1
JMP L2
L1:
MOV R0, 1
MOV R1, BP
ADD R0, R1
PUSH R0
MOV R2, -3
MOV R3, BP
ADD R2, R3
MOV R2, [R2]
PUSH R2
MOV R2, -4
MOV R3, BP
ADD R2, R3
MOV R2, [R2]
MOV R3, -3
MOV R4, BP
ADD R3, R4
MOV R3, [R3]
MOD R2, R3
PUSH R2
PUSH R1
CALL gcd
POP R1
POP R2
POP R2
POP R0
MOV [R0], R1
L2:
MOV R1, 1
MOV R2, BP
ADD R1, R2
MOV R1, [R1]
MOV R2, -2
MOV R3, BP
ADD R2, R3
MOV [R2], R1
MOV R1, 1
MOV R2, SP
SUB R2, R1 
MOV SP, R2
POP BP
RET
main:
PUSH BP
MOV BP, SP
MOV R1, 3
MOV R2, SP
ADD R2, R1 
MOV SP, R2
MOV R1, 1
MOV R2, BP
ADD R1, R2
IN R2
MOV [R1], R2
MOV R1, 2
MOV R2, BP
ADD R1, R2
IN R2
MOV [R1], R2
MOV R1, 3
MOV R2, BP
ADD R1, R2
PUSH R1
PUSH R0
MOV R3, 1
MOV R4, BP
ADD R3, R4
MOV R3, [R3]
PUSH R3
MOV R3, 2
MOV R4, BP
ADD R3, R4
MOV R3, [R3]
PUSH R3
PUSH R2
CALL gcd
POP R2
POP R3
POP R3
POP R0
POP R1
MOV [R1], R2
MOV R1, 3
MOV R2, BP
ADD R1, R2
MOV R1, [R1]
OUT R1
MOV R2, 0
MOV R3, -2
MOV R4, BP
ADD R3, R4
MOV [R3], R2
MOV R2, 3
MOV R3, SP
SUB R3, R2 
MOV SP, R3
POP BP
RET
