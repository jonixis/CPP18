--- /Users/joni/Documents/UZH/7. Semester HS18/APC++/CPP18/52_Swap/swap.s	Fri Oct 19 12:29:02 2018
+++ /Users/joni/Documents/UZH/7. Semester HS18/APC++/CPP18/52_Swap/c_swap.s	Fri Oct 19 12:28:26 2018
@@ -1,8 +1,8 @@
 	.section	__TEXT,__text,regular,pure_instructions
 	.build_version macos, 10, 14
-	.globl	__Z4swapRiS_            ## -- Begin function _Z4swapRiS_
+	.globl	__Z6c_swapPiS_          ## -- Begin function _Z6c_swapPiS_
 	.p2align	4, 0x90
-__Z4swapRiS_:                           ## @_Z4swapRiS_
+__Z6c_swapPiS_:                         ## @_Z6c_swapPiS_
 	.cfi_startproc
 ## %bb.0:
 	pushq	%rbp
@@ -46,7 +46,7 @@
 	movl	$66, -24(%rbp)
 	movq	%rax, %rdi
 	movq	%rcx, %rsi
-	callq	__Z4swapRiS_
+	callq	__Z6c_swapPiS_
 	xorl	%eax, %eax
 	addq	$32, %rsp
 	popq	%rbp
