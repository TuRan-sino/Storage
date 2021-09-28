.text				@������ǰΪ�����     GNU ������� 
.global _start		@���� _start ȫ�ַ���
_start:				@���������
	@�����쳣������
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
	@����ARM���쳣�������λ��
	ldr r0, =_start
	mcr p15,0,r0,c12,c0,0
	@����ջ
	ldr r0, stack_top
	/*����SVCģʽ��ջ*/
	mov sp, r0
	sub r0, r0, #128*4
	/*����IRQģʽ��ջ*/
	msr cpsr_c, #0xd2
	mov sp, r0
	sub r0, r0, #128*4 
	/*����USRģʽ��ջ*/
	msr cpsr_c, #0x10
	mov sp, r0

	bl main
	
stop:				@��ѭ�� ��ֹ�����ܷ�
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


.end				@�������������
	
