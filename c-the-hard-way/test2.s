	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 14, 0
	.globl	_mygets                         ; -- Begin function mygets
	.p2align	2
_mygets:                                ; @mygets
	.cfi_startproc
; %bb.0:
	stp	x20, x19, [sp, #-32]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x0
	mov	x20, #0
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getchar
	cmn	w0, #1
	b.eq	LBB0_4
; %bb.2:                                ;   in Loop: Header=BB0_1 Depth=1
	cmp	w0, #10
	b.eq	LBB0_5
; %bb.3:                                ;   in Loop: Header=BB0_1 Depth=1
	strb	w0, [x19, x20]
	add	x20, x20, #1
	b	LBB0_1
LBB0_4:
	cbz	x20, LBB0_7
LBB0_5:
	strb	wzr, [x19, x20]
LBB0_6:
	mov	x0, x19
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp], #32             ; 16-byte Folded Reload
	ret
LBB0_7:
	mov	x19, #0
	b	LBB0_6
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, #0
Lloh0:
	adrp	x8, ___stack_chk_guard@GOTPAGE
Lloh1:
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
Lloh2:
	ldr	x8, [x8]
	str	x8, [sp, #8]
	mov	x20, sp
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	bl	_getchar
	cmn	w0, #1
	b.eq	LBB1_4
; %bb.2:                                ;   in Loop: Header=BB1_1 Depth=1
	cmp	w0, #10
	b.eq	LBB1_5
; %bb.3:                                ;   in Loop: Header=BB1_1 Depth=1
	strb	w0, [x20, x19]
	add	x19, x19, #1
	b	LBB1_1
LBB1_4:
	cbz	x19, LBB1_6
LBB1_5:
	mov	x8, sp
	strb	wzr, [x8, x19]
LBB1_6:
	mov	x0, sp
	bl	_puts
	ldr	x8, [sp, #8]
Lloh3:
	adrp	x9, ___stack_chk_guard@GOTPAGE
Lloh4:
	ldr	x9, [x9, ___stack_chk_guard@GOTPAGEOFF]
Lloh5:
	ldr	x9, [x9]
	cmp	x9, x8
	b.ne	LBB1_8
; %bb.7:
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
LBB1_8:
	bl	___stack_chk_fail
	.loh AdrpLdrGotLdr	Lloh0, Lloh1, Lloh2
	.loh AdrpLdrGotLdr	Lloh3, Lloh4, Lloh5
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
