START
MOV R0, 23
MOV R1, 5
MOV [R0], R1
MOV R0, 24
MOV R1, 6
MOV [R0], R1
MOV R0, 25
IN R1
MOV [R0], R1
MOV R0, 3
MOV R1, 0
MOV [R0], R1
MOV R0, [25]
MOV R1, 15
GT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L1
MOV R0, 3
MOV R1, 10
MOV [R0], R1
L1:
L2:
MOV R0, [25]
MOV R1, 10
LT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L3
MOV R0, [25]
OUT R0
MOV R0, 25
MOV R1, [25]
MOV R2, 1
ADD R1, R2
MOV [R0], R1
JMP L2
L3:
MOV R0, 2
MOV R1, [23]
MOV R2, [24]
MOV R3, [25]
MUL R2, R3
ADD R1, R2
MOV [R0], R1
MOV R0, [2]
OUT R0
HALT