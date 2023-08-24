

EXTERN  print2:PROC;引用外部函数
EXTERN  g_iValue:DQ;引用外部变量
EXTERN  RealSlateHandleReleasePtr:DQ;引用外部函数
EXTERN  RealSlateHandleClickedPtr:DQ;引用外部函数
EXTERN  RealSlateHandlePressedPtr:DQ;引用外部函数
EXTERN  Game_AutoPlayMapMovePtr:DQ;引用外部函数
EXTERN  UISleepModePanel_OnClosePtr:DQ;引用外部函数
EXTERN  AutoPlay2_changePlayStatePtr:DQ;引用外部函数
EXTERN  AutoPlay2_FinishPtr:DQ;引用外部函数

EXTERN  HyperRunController_SetImpossibleAutoMoveEbPtr:DQ;引用外部函数
EXTERN  HyperRunController_PlayHyperRunEhPtr:DQ;引用外部函数
EXTERN  AutoPlay2_SingleCombatPtr:DQ;引用外部函数

EXTERN  Game_PickTargetPtr:DQ;引用外部函数


.DATA

val1 DQ ?;自己定义变量


.CODE



fake_UButton_SlateHandleReleased PROC

    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDI, RDX


    MOV RAX, RealSlateHandleReleasePtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_UButton_SlateHandleReleased ENDP




fake_UButton_SlateHandleClicked PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDX, RDX

    MOV RAX, RealSlateHandleClickedPtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_UButton_SlateHandleClicked ENDP

fake_UISleepModePanel_OnClose PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDX, RDX

    MOV RAX, UISleepModePanel_OnClosePtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_UISleepModePanel_OnClose ENDP

fake_AutoPlay2_Finish PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDX, RDX

    MOV RAX, AutoPlay2_FinishPtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_AutoPlay2_Finish ENDP



fake_AutoPlay2_changePlayState PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDX, RDX
    MOV r8, r8
    MOV RAX, AutoPlay2_changePlayStatePtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_AutoPlay2_changePlayState ENDP


fake_HyperRunController_SetImpossibleAutoMoveEb PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDX, RDX

    MOV RAX, HyperRunController_SetImpossibleAutoMoveEbPtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_HyperRunController_SetImpossibleAutoMoveEb ENDP



fake_HyperRunController_PlayHyperRunEh PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX
    MOV RDX, RDX

    MOV RAX, HyperRunController_PlayHyperRunEhPtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_HyperRunController_PlayHyperRunEh ENDP


fake_AutoPlay2_SingleCombat PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX

    MOV RAX, AutoPlay2_SingleCombatPtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_AutoPlay2_SingleCombat ENDP



fake_Game_PickTarget PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

   sub   rsp, 880h

    MOV RCX, RCX
    MOV RDX, RDX
    MOV r8, r8
    xor     r8d, r8d
    MOV RAX, Game_PickTargetPtr
    CALL RAX

    add  rsp, 880h

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_Game_PickTarget ENDP




fake_UButton_SlateHandlePressed PROC

    
    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    MOV RCX, RCX

    MOV RAX, RealSlateHandlePressedPtr
    CALL RAX

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax

    ret 

fake_UButton_SlateHandlePressed ENDP


fake_Game_AutoPlayMapMove PROC

   ; movaps xmm3, xmm0


    push rax
    push rcx
    push rdx
    push rbx
    push rbp
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    sub     rsp, 880h



    mov     r14b, 1
    mov     rax, 0

    mov     [rsp+28], r14b
    mov     [rsp+20], rax
    mov     [rsp+30], rax
    mov     [rsp+38], rax

    MOV RAX, Game_AutoPlayMapMovePtr
    ;CALL print2 ;调用func.cpp中的外部函数
    call RAX

    add     rsp, 880h


    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8

    pop rdi    
    pop rsi    
    pop rbp    
    pop rbx    
    pop rdx    
    pop rcx
    pop rax



    ret 

fake_Game_AutoPlayMapMove ENDP



func2 PROC

CALL print2 ;调用func.cpp中的外部函数

ret

FUNC2 ENDP

END

func2 PROC

CALL print2 ;调用func.cpp中的外部函数

ret

FUNC2 ENDP

END