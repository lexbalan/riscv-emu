	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0"
	.file	"main.c"
	.globl	main
	.p2align	2
	.type	main,@function
main:
	addi	sp, sp, -16
	sw	ra, 12(sp)
	sw	s0, 8(sp)
	addi	s0, sp, 16
	li	a0, 0
	sw	a0, -12(s0)
	sw	a0, -16(s0)
	j	.LBB0_1
.LBB0_1:
	lbu	a0, -16(s0)
	andi	a0, a0, 1
	li	a1, 0
	beq	a0, a1, .LBB0_3
	j	.LBB0_2
.LBB0_2:
	lw	a0, -16(s0)
	addi	a0, a0, 48
	lui	a1, 983232
	sb	a0, 16(a1)
	j	.LBB0_3
.LBB0_3:
	lw	a0, -16(s0)
	addi	a0, a0, 1
	sw	a0, -16(s0)
	lw	a0, -16(s0)
	li	a1, 11
	blt	a0, a1, .LBB0_5
	j	.LBB0_4
.LBB0_4:
	j	.LBB0_6
.LBB0_5:
	j	.LBB0_1
.LBB0_6:
	#APP
	ebreak	
	#NO_APP
	li	a0, 0
	lw	ra, 12(sp)
	lw	s0, 8(sp)
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main

	.ident	"Homebrew clang version 14.0.6"
	.section	".note.GNU-stack","",@progbits
	.addrsig
