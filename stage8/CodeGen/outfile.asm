START
MOV R0, 0
IN R1
MOV [R0], R1
MOV R0, 101
MOV R1, 0
MOV [R0], R1
L1:
MOV R0, [101]
MOV R1, [0]
LT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L2
MOV R0, [101]
MOV R1, 1
ADD R0, R1
IN R1
MOV [R0], R1
MOV R0, 101
MOV R1, [101]
MOV R2, 1
ADD R1, R2
MOV [R0], R1
JMP L1
L2:
MOV R0, 101
MOV R1, 0
MOV [R0], R1
L3:
MOV R0, [101]
MOV R1, [0]
LT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L4
MOV R0, 102
MOV R1, [101]
MOV R2, 1
ADD R1, R2
MOV [R0], R1
L5:
MOV R0, [102]
MOV R1, [0]
LT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L6
MOV R0, [101]
MOV R1, 1
ADD R0, R1
MOV R0, [R0]
MOV R1, [102]
MOV R2, 1
ADD R1, R2
MOV R1, [R1]
GT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L7
MOV R0, 103
MOV R1, [101]
MOV R2, 1
ADD R1, R2
MOV R1, [R1]
MOV [R0], R1
MOV R0, [101]
MOV R1, 1
ADD R0, R1
MOV R1, [102]
MOV R2, 1
ADD R1, R2
MOV R1, [R1]
MOV [R0], R1
MOV R0, [102]
MOV R1, 1
ADD R0, R1
MOV R1, [103]
MOV [R0], R1
L7:
MOV R0, 102
MOV R1, [102]
MOV R2, 1
ADD R1, R2
MOV [R0], R1
JMP L5
L6:
MOV R0, 101
MOV R1, [101]
MOV R2, 1
ADD R1, R2
MOV [R0], R1
JMP L3
L4:
MOV R0, 101
MOV R1, 0
MOV [R0], R1
L8:
MOV R0, [101]
MOV R1, [0]
LT R0, R1
MOV R1, 0
NE R0, R1
JZ R0, L9
MOV R0, [101]
MOV R1, 1
ADD R0, R1
MOV R0, [R0]
OUT R0
MOV R0, 101
MOV R1, [101]
MOV R2, 1
ADD R1, R2
MOV [R0], R1
JMP L8
L9:
HALT
