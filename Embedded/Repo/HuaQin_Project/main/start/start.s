.text				@声明当前为代码段     GNU 汇编语言 
.global _start		@声明 _start 全局符号
_start:				@汇编程序入口
	@设置异常向量表
	b rest
	ldr pc, _undefined_instruction
	ldr pc, _software_interrupt
	ldr pc, _prefetch_abort
	ldr pc, _data_abort
	ldr pc, _no_used
	ldr pc, _irq
	ldr pc, _fiq
	
_undefined_instruction: .word _undefined_instruction
_software_interrupt: .word _software_interrupt
_prefetch_abort: .word _prefetch_abort
_data_abort: .word _data_abort
_no_used: .word _no_used
_irq: .word irq
_fiq: .word _fiq


rest:
	@告诉ARM核异常向量表的位置
	ldr r0, =_start
	mcr p15,0,r0,c12,c0,0
	@设置栈
	ldr r0, stack_top
	/*设置SVC模式的栈*/
	mov sp, r0
	sub r0, r0, #128*4
	/*设置IRQ模式的栈*/
	msr cpsr_c, #0xd2
	mov sp, r0
	sub r0, r0, #128*4 
	/*设置USR模式的栈*/
	msr cpsr_c, #0x10
	mov sp, r0

	bl main
	
stop:				@死循环 防止程序跑飞
	b stop	

irq:
	sub lr, lr, #4	
	stmfd sp!,{r0-r12, lr}
	.weak do_irq
	ldmfd sp!,{r0-r12, pc}^
	
stack_top: .word (stack+512*4)

.data
stack:
	.space 512*4 , 0XFFFFFFFF


.end				@声明汇编程序结束
	
