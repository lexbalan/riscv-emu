	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0"
	.file	"main.c"
	.globl	main
	.p2align	2
	.type	main,@function
main:
	addi	sp, sp, -32
	sw	ra, 28(sp)
	sw	s0, 24(sp)
	addi	s0, sp, 32
	li	a0, 0
	sw	a0, -28(s0)
	sw	a0, -12(s0)
	li	a0, 10
	sw	a0, -16(s0)
	li	a0, 5
	sw	a0, -20(s0)
	lw	a0, -20(s0)
	lw	a1, -16(s0)
	sub	a0, a0, a1
	sw	a0, -24(s0)
	lui	a0, %hi(.L.str.1)
	addi	a0, a0, %lo(.L.str.1)
	lui	a1, 74565
	addi	a1, a1, 1663
	call	printf
	lw	a0, -28(s0)
	lw	ra, 28(sp)
	lw	s0, 24(sp)
	addi	sp, sp, 32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main

	.type	a,@object
	.section	.sdata,"aw",@progbits
	.globl	a
	.p2align	2
a:
	.word	305419896
	.size	a, 4

	.type	b,@object
	.globl	b
	.p2align	2
b:
	.word	2779096485
	.size	b, 4

	.type	.L.str,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello world!"
	.size	.L.str, 13

	.type	str,@object
	.section	.sdata,"aw",@progbits
	.globl	str
	.p2align	2
str:
	.word	.L.str
	.size	str, 4

	.type	.L.str.1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.1:
	.asciz	"Hello World!! 0x%x\n"
	.size	.L.str.1, 20

	.ident	"Homebrew clang version 14.0.6"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
