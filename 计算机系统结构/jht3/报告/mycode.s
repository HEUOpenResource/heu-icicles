.data
input_txet:	.asciiz	"Please enter a number, and this program will calculate the product of all multiples of 5 that are less than or equal to the number you enter."
.align	 2
input_number:	.word	0

output_input_number_text:
		.asciiz	"The input number is:%d\n"
.align	 2
output_number_arglist:
		.word	output_input_number_text
input_number_arg:
		.word	0

output_mul_num_text:
		.asciiz	"%d is not bigger than %d\n"
.align	 2
output_mul_num_arglist:
		.word	output_mul_num_text
output_mul_num_arg_1:
		.word	0
output_mul_num_arg_2:
		.word	0		

output_ans_text:
		.asciiz	"The ans is %d\n"
.align	 2
output_ans_arglist:
		.word	output_ans_text
output_ans_arg:
		.word	0

.text
.global	main
main:
	addi	r1,r0,input_txet
	jal	InputUnsigned
	sw	input_number,R1
	sw	input_number_arg,R1
	addi	r14,r0,output_number_arglist
	trap	5
	lw	r1,input_number
	addi	r2,r0,5
	addi	r4,r0,1
loop:
	sle	r3,r2,r1
	beqz	r3,over
	multu	r4,r4,r2
	sw	output_mul_num_arg_1,r2
	sw	output_mul_num_arg_2,r1
	addi	r14,r0,output_mul_num_arglist
	trap	5
	lw	r1,input_number
	addi	r2,r2,5
	j	loop
over:	
	sw	output_ans_arg,r4
	addi	r14,r0,output_ans_arglist
	trap	5
	trap	0