	.file	"assoc.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZNSt11char_traitsIcE7compareEPKcS2_m,"axG",@progbits,_ZNSt11char_traitsIcE7compareEPKcS2_m,comdat
	.weak	_ZNSt11char_traitsIcE7compareEPKcS2_m
	.type	_ZNSt11char_traitsIcE7compareEPKcS2_m, @function
_ZNSt11char_traitsIcE7compareEPKcS2_m:
.LFB275:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcmp
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE275:
	.size	_ZNSt11char_traitsIcE7compareEPKcS2_m, .-_ZNSt11char_traitsIcE7compareEPKcS2_m
	.section	.text._ZnwmPv,"axG",@progbits,_ZnwmPv,comdat
	.weak	_ZnwmPv
	.type	_ZnwmPv, @function
_ZnwmPv:
.LFB378:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE378:
	.size	_ZnwmPv, .-_ZnwmPv
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,"axG",@progbits,_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,comdat
	.weak	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.type	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE, @function
_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE:
.LFB1570:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1570:
	.size	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE, .-_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.section	.text._ZNSt4pairISsiEC1IivEERKSsOT_,"axG",@progbits,_ZNSt4pairISsiEC1IivEERKSsOT_,comdat
	.align 2
	.weak	_ZNSt4pairISsiEC1IivEERKSsOT_
	.type	_ZNSt4pairISsiEC1IivEERKSsOT_, @function
_ZNSt4pairISsiEC1IivEERKSsOT_:
.LFB1572:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSsC1ERKSs
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1572:
	.size	_ZNSt4pairISsiEC1IivEERKSsOT_, .-_ZNSt4pairISsiEC1IivEERKSsOT_
	.section	.text._ZNSt4pairISsiED2Ev,"axG",@progbits,_ZNSt4pairISsiED5Ev,comdat
	.align 2
	.weak	_ZNSt4pairISsiED2Ev
	.type	_ZNSt4pairISsiED2Ev, @function
_ZNSt4pairISsiED2Ev:
.LFB1574:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1574:
	.size	_ZNSt4pairISsiED2Ev, .-_ZNSt4pairISsiED2Ev
	.weak	_ZNSt4pairISsiED1Ev
	.set	_ZNSt4pairISsiED1Ev,_ZNSt4pairISsiED2Ev
	.text
	.align 2
	.globl	_ZN5AssocixERKSs
	.type	_ZN5AssocixERKSs, @function
_ZN5AssocixERKSs:
.LFB1568:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1568
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv
	movq	%rax, -80(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv
	movq	%rax, -96(%rbp)
	jmp	.L11
.L14:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_
	testb	%al, %al
	je	.L12
	movq	-32(%rbp), %rax
	addq	$8, %rax
	jmp	.L17
.L12:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv
.L11:
	leaq	-96(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_
	testb	%al, %al
	jne	.L14
	movl	$0, -36(%rbp)
	leaq	-36(%rbp), %rdx
	movq	-112(%rbp), %rcx
	leaq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairISsiEC1IivEERKSsOT_
.LEHE0:
	movq	-104(%rbp), %rax
	leaq	-64(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB1:
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_
.LEHE1:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt4pairISsiED1Ev
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
.LEHB2:
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv
	addq	$8, %rax
	jmp	.L17
.L16:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt4pairISsiED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume
.LEHE2:
.L17:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1568:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1568:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1568-.LLSDACSB1568
.LLSDACSB1568:
	.uleb128 .LEHB0-.LFB1568
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1568
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L16-.LFB1568
	.uleb128 0
	.uleb128 .LEHB2-.LFB1568
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1568:
	.text
	.size	_ZN5AssocixERKSs, .-_ZN5AssocixERKSs
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv,comdat
	.align 2
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv
	.type	_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv, @function
_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv:
.LFB1631:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1631:
	.size	_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv, .-_ZNSt6vectorISt4pairISsiESaIS1_EE5beginEv
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE3endEv,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv,comdat
	.align 2
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv
	.type	_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv, @function
_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv:
.LFB1632:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1632:
	.size	_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv, .-_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv
	.section	.text._ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_,"axG",@progbits,_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_,comdat
	.weak	_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_
	.type	_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_, @function
_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_:
.LFB1633:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv
	movq	(%rax), %rax
	cmpq	%rax, %rbx
	setne	%al
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1633:
	.size	_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_, .-_ZN9__gnu_cxxneIPSt4pairISsiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_
	.section	.text._ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv,"axG",@progbits,_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv
	.type	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv, @function
_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv:
.LFB1634:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1634:
	.size	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv, .-_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEppEv
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv:
.LFB1635:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1635:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv
	.section	.text._ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_,"axG",@progbits,_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_,comdat
	.weak	_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_
	.type	_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_, @function
_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_:
.LFB1636:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSs4sizeEv
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSs4sizeEv
	cmpq	%rax, %rbx
	jne	.L29
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSs4sizeEv
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSs4dataEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSs4dataEv
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11char_traitsIcE7compareEPKcS2_m
	testl	%eax, %eax
	jne	.L29
	movl	$1, %eax
	jmp	.L30
.L29:
	movl	$0, %eax
.L30:
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1636:
	.size	_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_, .-_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKSbIS3_St11char_traitsIS3_ESaIS3_EESC_
	.section	.text._ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_,"axG",@progbits,_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_,comdat
	.weak	_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_
	.type	_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_, @function
_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_:
.LFB1638:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1638:
	.size	_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_, .-_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_,comdat
	.align 2
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_
	.type	_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_, @function
_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_:
.LFB1637:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1637:
	.size	_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_, .-_ZNSt6vectorISt4pairISsiESaIS1_EE9push_backEOS1_
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE4backEv,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv,comdat
	.align 2
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv
	.type	_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv, @function
_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv:
.LFB1639:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	$1, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE3endEv
	movq	%rax, -16(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl
	movq	%rax, -32(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEdeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1639:
	.size	_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv, .-_ZNSt6vectorISt4pairISsiESaIS1_EE4backEv
	.section	.text._ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_,"axG",@progbits,_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC5ERKS3_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_
	.type	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_, @function
_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_:
.LFB1685:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1685:
	.size	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_, .-_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	.set	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC1ERKS3_,_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC2ERKS3_
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv:
.LFB1687:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1687:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEE4baseEv
	.section	.text._ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB1690:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1690:
	.size	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_,comdat
	.align 2
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_
	.type	_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_, @function
_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_:
.LFB1689:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, %rdx
	je	.L43
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	leaq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L42
.L43:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
.L42:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1689:
	.size	_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_, .-_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIJS1_EEEvDpOT_
	.set	_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIJS1_EEEvDpOT_,_ZNSt6vectorISt4pairISsiESaIS1_EE12emplace_backIIS1_EEEvDpOT_
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl, @function
_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl:
.LFB1691:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	salq	$4, %rax
	negq	%rax
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	leaq	-8(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1691:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl, .-_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairISsiESt6vectorIS2_SaIS2_EEEmiERKl
	.section	.text._ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_,"axG",@progbits,_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_,comdat
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_
	.type	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_, @function
_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_:
.LFB1721:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1721:
	.size	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_, .-_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_JS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_
	.set	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_JS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_,_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_
	.section	.rodata
.LC0:
	.string	"vector::_M_emplace_back_aux"
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,comdat
	.align 2
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.type	_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_, @function
_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_:
.LFB1722:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1722
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rax
	movl	$.LC0, %edx
	movl	$1, %esi
	movq	%rax, %rdi
.LEHB3:
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm
.LEHE3:
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movq	-56(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB4:
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE9constructIS1_IS1_EEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS2_PT_DpOS5_
	movq	$0, -24(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rcx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rsi
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rdi
	call	_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_
.LEHE4:
	movq	%rax, -24(%rbp)
	addq	$16, -24(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB5:
	call	_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	sarq	$4, %rax
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	(%rax), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m
.LEHE5:
	movq	-56(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-56(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-32(%rbp), %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, 16(%rax)
	jmp	.L55
.L53:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	cmpq	$0, -24(%rbp)
	jne	.L50
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB6:
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_
	jmp	.L51
.L50:
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E
.L51:
	movq	-56(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m
	call	__cxa_rethrow
.LEHE6:
.L54:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Unwind_Resume
.LEHE7:
.L55:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1722:
	.section	.gcc_except_table
	.align 4
.LLSDA1722:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT1722-.LLSDATTD1722
.LLSDATTD1722:
	.byte	0x1
	.uleb128 .LLSDACSE1722-.LLSDACSB1722
.LLSDACSB1722:
	.uleb128 .LEHB3-.LFB1722
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB1722
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L53-.LFB1722
	.uleb128 0x1
	.uleb128 .LEHB5-.LFB1722
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB1722
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L54-.LFB1722
	.uleb128 0
	.uleb128 .LEHB7-.LFB1722
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE1722:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1722:
	.section	.text._ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,"axG",@progbits,_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_,comdat
	.size	_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_, .-_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.weak	_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_
	.set	_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIJS1_EEEvDpOT_,_ZNSt6vectorISt4pairISsiESaIS1_EE19_M_emplace_back_auxIIS1_EEEvDpOT_
	.section	.text._ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_,"axG",@progbits,_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_,comdat
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_
	.type	_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_, @function
_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_:
.LFB1725:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1725:
	.size	_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_, .-_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_JS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_
	.set	_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_JS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_JDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_,_ZNSt16allocator_traitsISaISt4pairISsiEEE12_S_constructIS1_IS1_EEENSt9enable_ifIXsrNS3_18__construct_helperIT_IDpT0_EEE5valueEvE4typeERS2_PS7_DpOS8_
	.section	.text._ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc,comdat
	.align 2
	.weak	_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc, @function
_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc:
.LFB1726:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv
	movq	%rax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	subq	%rax, %rbx
	movq	%rbx, %rdx
	movq	-48(%rbp), %rax
	cmpq	%rax, %rdx
	setb	%al
	testb	%al, %al
	je	.L58
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt20__throw_length_errorPKc
.L58:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	movq	%rax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	movq	%rax, -32(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3maxImERKT_S2_S2_
	movq	(%rax), %rax
	addq	%rbx, %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	cmpq	-24(%rbp), %rax
	ja	.L59
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv
	cmpq	-24(%rbp), %rax
	jnb	.L60
.L59:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv
	jmp	.L61
.L60:
	movq	-24(%rbp), %rax
.L61:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1726:
	.size	_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc, .-_ZNKSt6vectorISt4pairISsiESaIS1_EE12_M_check_lenEmPKc
	.section	.text._ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm,"axG",@progbits,_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm
	.type	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm, @function
_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm:
.LFB1727:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L64
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv
	jmp	.L65
.L64:
	movl	$0, %eax
.L65:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1727:
	.size	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm, .-_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE11_M_allocateEm
	.section	.text._ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv,"axG",@progbits,_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	.type	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv, @function
_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv:
.LFB1728:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	sarq	$4, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1728:
	.size	_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv, .-_ZNKSt6vectorISt4pairISsiESaIS1_EE4sizeEv
	.section	.text._ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv:
.LFB1729:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1729:
	.size	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	.section	.text._ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_,"axG",@progbits,_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_,comdat
	.weak	_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_
	.type	_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_, @function
_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_:
.LFB1730:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1730:
	.size	_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_, .-_ZSt34__uninitialized_move_if_noexcept_aIPSt4pairISsiES2_SaIS1_EET0_T_S5_S4_RT1_
	.section	.text._ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_,"axG",@progbits,_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_,comdat
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_
	.type	_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_, @function
_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_:
.LFB1731:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1731:
	.size	_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_, .-_ZNSt16allocator_traitsISaISt4pairISsiEEE7destroyIS1_EEvRS2_PT_
	.section	.text._ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E,"axG",@progbits,_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E,comdat
	.weak	_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E
	.type	_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E, @function
_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E:
.LFB1732:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPSt4pairISsiEEvT_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1732:
	.size	_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E, .-_ZSt8_DestroyIPSt4pairISsiES1_EvT_S3_RSaIT0_E
	.section	.text._ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m,"axG",@progbits,_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m
	.type	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m, @function
_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m:
.LFB1733:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L75
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m
.L75:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1733:
	.size	_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m, .-_ZNSt12_Vector_baseISt4pairISsiESaIS1_EE13_M_deallocateEPS1_m
	.section	.text._ZNSt4pairISsiEC2EOS0_,"axG",@progbits,_ZNSt4pairISsiEC5EOS0_,comdat
	.align 2
	.weak	_ZNSt4pairISsiEC2EOS0_
	.type	_ZNSt4pairISsiEC2EOS0_, @function
_ZNSt4pairISsiEC2EOS0_:
.LFB1738:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSsC1EOSs
	movq	-16(%rbp), %rax
	movl	8(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1738:
	.size	_ZNSt4pairISsiEC2EOS0_, .-_ZNSt4pairISsiEC2EOS0_
	.weak	_ZNSt4pairISsiEC1EOS0_
	.set	_ZNSt4pairISsiEC1EOS0_,_ZNSt4pairISsiEC2EOS0_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_
	.type	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_, @function
_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_:
.LFB1736:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$16, %edi
	call	_ZnwmPv
	testq	%rax, %rax
	je	.L78
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairISsiEC1EOS0_
.L78:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1736:
	.size	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_, .-_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_
	.weak	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_JS2_EEEvPT_DpOT0_
	.set	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_JS2_EEEvPT_DpOT0_,_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE9constructIS2_IS2_EEEvPT_DpOT0_
	.section	.text._ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv,"axG",@progbits,_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv
	.type	_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv, @function
_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv:
.LFB1740:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1740
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1740:
	.section	.gcc_except_table
.LLSDA1740:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1740-.LLSDACSB1740
.LLSDACSB1740:
.LLSDACSE1740:
	.section	.text._ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv,"axG",@progbits,_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv,comdat
	.size	_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv, .-_ZNKSt6vectorISt4pairISsiESaIS1_EE8max_sizeEv
	.section	.text._ZSt3maxImERKT_S2_S2_,"axG",@progbits,_ZSt3maxImERKT_S2_S2_,comdat
	.weak	_ZSt3maxImERKT_S2_S2_
	.type	_ZSt3maxImERKT_S2_S2_, @function
_ZSt3maxImERKT_S2_S2_:
.LFB1741:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jnb	.L84
	movq	-16(%rbp), %rax
	jmp	.L85
.L84:
	movq	-8(%rbp), %rax
.L85:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1741:
	.size	_ZSt3maxImERKT_S2_S2_, .-_ZSt3maxImERKT_S2_S2_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv
	.type	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv, @function
_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv:
.LFB1742:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv
	cmpq	-16(%rbp), %rax
	setb	%al
	testb	%al, %al
	je	.L87
	call	_ZSt17__throw_bad_allocv
.L87:
	movq	-16(%rbp), %rax
	salq	$4, %rax
	movq	%rax, %rdi
	call	_Znwm
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1742:
	.size	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv, .-_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE8allocateEmPKv
	.section	.text._ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_,"axG",@progbits,_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_,comdat
	.weak	_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_
	.type	_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_, @function
_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_:
.LFB1743:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt13move_iteratorIPSt4pairISsiEEC1ES2_
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1743:
	.size	_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_, .-_ZSt32__make_move_if_noexcept_iteratorIPSt4pairISsiESt13move_iteratorIS2_EET0_T_
	.section	.text._ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E,"axG",@progbits,_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E,comdat
	.weak	_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E
	.type	_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E, @function
_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E:
.LFB1744:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -8(%rbp)
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1744:
	.size	_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E, .-_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt4pairISsiEES3_S2_ET0_T_S6_S5_RSaIT1_E
	.section	.text._ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_,"axG",@progbits,_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_,comdat
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_
	.type	_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_, @function
_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_:
.LFB1745:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1745:
	.size	_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_, .-_ZNSt16allocator_traitsISaISt4pairISsiEEE10_S_destroyIS1_EENSt9enable_ifIXsrNS3_16__destroy_helperIT_EE5valueEvE4typeERS2_PS7_
	.section	.text._ZSt8_DestroyIPSt4pairISsiEEvT_S3_,"axG",@progbits,_ZSt8_DestroyIPSt4pairISsiEEvT_S3_,comdat
	.weak	_ZSt8_DestroyIPSt4pairISsiEEvT_S3_
	.type	_ZSt8_DestroyIPSt4pairISsiEEvT_S3_, @function
_ZSt8_DestroyIPSt4pairISsiEEvT_S3_:
.LFB1746:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1746:
	.size	_ZSt8_DestroyIPSt4pairISsiEEvT_S3_, .-_ZSt8_DestroyIPSt4pairISsiEEvT_S3_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m
	.type	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m, @function
_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m:
.LFB1747:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1747:
	.size	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m, .-_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE10deallocateEPS2_m
	.section	.text._ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_,"axG",@progbits,_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_,comdat
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_
	.type	_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_, @function
_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_:
.LFB1758:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1758:
	.size	_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_, .-_ZNSt16allocator_traitsISaISt4pairISsiEEE8max_sizeERKS2_
	.section	.text._ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	.type	_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv, @function
_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv:
.LFB1759:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1759:
	.size	_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv, .-_ZNKSt12_Vector_baseISt4pairISsiESaIS1_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv,"axG",@progbits,_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv
	.type	_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv, @function
_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv:
.LFB1760:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movabsq	$1152921504606846975, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1760:
	.size	_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv, .-_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv
	.section	.text._ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_,"axG",@progbits,_ZNSt13move_iteratorIPSt4pairISsiEEC5ES2_,comdat
	.align 2
	.weak	_ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_
	.type	_ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_, @function
_ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_:
.LFB1762:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1762:
	.size	_ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_, .-_ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_
	.weak	_ZNSt13move_iteratorIPSt4pairISsiEEC1ES2_
	.set	_ZNSt13move_iteratorIPSt4pairISsiEEC1ES2_,_ZNSt13move_iteratorIPSt4pairISsiEEC2ES2_
	.section	.text._ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_,"axG",@progbits,_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_,comdat
	.weak	_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_
	.type	_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_, @function
_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_:
.LFB1764:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1764:
	.size	_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_, .-_ZSt18uninitialized_copyISt13move_iteratorIPSt4pairISsiEES3_ET0_T_S6_S5_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_
	.type	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_, @function
_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_:
.LFB1765:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt4pairISsiED1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1765:
	.size	_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_, .-_ZN9__gnu_cxx13new_allocatorISt4pairISsiEE7destroyIS2_EEvPT_
	.section	.text._ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_,"axG",@progbits,_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_,comdat
	.weak	_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_
	.type	_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_, @function
_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_:
.LFB1766:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	jmp	.L107
.L108:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt11__addressofISt4pairISsiEEPT_RS2_
	movq	%rax, %rdi
	call	_ZSt8_DestroyISt4pairISsiEEvPT_
	addq	$16, -8(%rbp)
.L107:
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jne	.L108
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1766:
	.size	_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_, .-_ZNSt12_Destroy_auxILb0EE9__destroyIPSt4pairISsiEEEvT_S5_
	.section	.text._ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_,"axG",@progbits,_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_,comdat
	.weak	_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_
	.type	_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_, @function
_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_:
.LFB1775:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx13new_allocatorISt4pairISsiEE8max_sizeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1775:
	.size	_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_, .-_ZNSt16allocator_traitsISaISt4pairISsiEEE11_S_max_sizeIKS2_EENSt9enable_ifIXsrNS3_16__maxsize_helperIT_EE5valueEmE4typeERS8_
	.section	.text._ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_,comdat
	.weak	_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_
	.type	_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_, @function
_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_:
.LFB1776:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1776
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -48(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L112
.L113:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt11__addressofISt4pairISsiEEPT_RS2_
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt13move_iteratorIPSt4pairISsiEEppEv
	addq	$16, -24(%rbp)
.L112:
	leaq	-64(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB8:
	call	_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_
.LEHE8:
	testb	%al, %al
	jne	.L113
	movq	-24(%rbp), %rax
	jmp	.L119
.L117:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	-24(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB9:
	call	_ZSt8_DestroyIPSt4pairISsiEEvT_S3_
	call	__cxa_rethrow
.LEHE9:
.L118:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB10:
	call	_Unwind_Resume
.LEHE10:
.L119:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1776:
	.section	.gcc_except_table
	.align 4
.LLSDA1776:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT1776-.LLSDATTD1776
.LLSDATTD1776:
	.byte	0x1
	.uleb128 .LLSDACSE1776-.LLSDACSB1776
.LLSDACSB1776:
	.uleb128 .LEHB8-.LFB1776
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L117-.LFB1776
	.uleb128 0x1
	.uleb128 .LEHB9-.LFB1776
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L118-.LFB1776
	.uleb128 0
	.uleb128 .LEHB10-.LFB1776
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
.LLSDACSE1776:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1776:
	.section	.text._ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_,"axG",@progbits,_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_,comdat
	.size	_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_, .-_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt4pairISsiEES5_EET0_T_S8_S7_
	.section	.text._ZSt11__addressofISt4pairISsiEEPT_RS2_,"axG",@progbits,_ZSt11__addressofISt4pairISsiEEPT_RS2_,comdat
	.weak	_ZSt11__addressofISt4pairISsiEEPT_RS2_
	.type	_ZSt11__addressofISt4pairISsiEEPT_RS2_, @function
_ZSt11__addressofISt4pairISsiEEPT_RS2_:
.LFB1777:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1777:
	.size	_ZSt11__addressofISt4pairISsiEEPT_RS2_, .-_ZSt11__addressofISt4pairISsiEEPT_RS2_
	.section	.text._ZSt8_DestroyISt4pairISsiEEvPT_,"axG",@progbits,_ZSt8_DestroyISt4pairISsiEEvPT_,comdat
	.weak	_ZSt8_DestroyISt4pairISsiEEvPT_
	.type	_ZSt8_DestroyISt4pairISsiEEvPT_, @function
_ZSt8_DestroyISt4pairISsiEEvPT_:
.LFB1778:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt4pairISsiED1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1778:
	.size	_ZSt8_DestroyISt4pairISsiEEvPT_, .-_ZSt8_DestroyISt4pairISsiEEvPT_
	.section	.text._ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_,"axG",@progbits,_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_,comdat
	.weak	_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_
	.type	_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_, @function
_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_:
.LFB1779:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_
	xorl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1779:
	.size	_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_, .-_ZStneIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_
	.section	.text._ZNSt13move_iteratorIPSt4pairISsiEEppEv,"axG",@progbits,_ZNSt13move_iteratorIPSt4pairISsiEEppEv,comdat
	.align 2
	.weak	_ZNSt13move_iteratorIPSt4pairISsiEEppEv
	.type	_ZNSt13move_iteratorIPSt4pairISsiEEppEv, @function
_ZNSt13move_iteratorIPSt4pairISsiEEppEv:
.LFB1780:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1780:
	.size	_ZNSt13move_iteratorIPSt4pairISsiEEppEv, .-_ZNSt13move_iteratorIPSt4pairISsiEEppEv
	.section	.text._ZNKSt13move_iteratorIPSt4pairISsiEEdeEv,"axG",@progbits,_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv,comdat
	.align 2
	.weak	_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv
	.type	_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv, @function
_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv:
.LFB1781:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRSt4pairISsiEEONSt16remove_referenceIT_E4typeEOS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1781:
	.size	_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv, .-_ZNKSt13move_iteratorIPSt4pairISsiEEdeEv
	.section	.text._ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_,"axG",@progbits,_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_,comdat
	.weak	_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_
	.type	_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_, @function
_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_:
.LFB1782:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt4pairISsiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$16, %edi
	call	_ZnwmPv
	testq	%rax, %rax
	je	.L129
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairISsiEC1EOS0_
.L129:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1782:
	.size	_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_, .-_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_
	.weak	_ZSt10_ConstructISt4pairISsiEJS1_EEvPT_DpOT0_
	.set	_ZSt10_ConstructISt4pairISsiEJS1_EEvPT_DpOT0_,_ZSt10_ConstructISt4pairISsiEIS1_EEvPT_DpOT0_
	.section	.text._ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_,"axG",@progbits,_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_,comdat
	.weak	_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_
	.type	_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_, @function
_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_:
.LFB1783:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv
	cmpq	%rax, %rbx
	sete	%al
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1783:
	.size	_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_, .-_ZSteqIPSt4pairISsiEEbRKSt13move_iteratorIT_ES7_
	.section	.text._ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv,"axG",@progbits,_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv,comdat
	.align 2
	.weak	_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv
	.type	_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv, @function
_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv:
.LFB1784:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1784:
	.size	_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv, .-_ZNKSt13move_iteratorIPSt4pairISsiEE4baseEv
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1785:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L136
	cmpl	$65535, -8(%rbp)
	jne	.L136
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L136:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1785:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN5AssocixERKSs, @function
_GLOBAL__sub_I__ZN5AssocixERKSs:
.LFB1786:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1786:
	.size	_GLOBAL__sub_I__ZN5AssocixERKSs, .-_GLOBAL__sub_I__ZN5AssocixERKSs
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN5AssocixERKSs
	.section	.rodata
	.align 8
	.type	_ZZL18__gthread_active_pvE20__gthread_active_ptr, @object
	.size	_ZZL18__gthread_active_pvE20__gthread_active_ptr, 8
_ZZL18__gthread_active_pvE20__gthread_active_ptr:
	.quad	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.weakref	_ZL28__gthrw___pthread_key_createPjPFvPvE,__pthread_key_create
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
