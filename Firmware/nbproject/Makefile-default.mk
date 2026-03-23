#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/drivers/uart.c mcc_generated_files/pin_manager.c mcc_generated_files/mcc.c mcc_generated_files/traps.c mcc_generated_files/clock.c mcc_generated_files/reset.c mcc_generated_files/system.c mcc_generated_files/interrupt_manager.c mcc_generated_files/tmr1.c mcc_generated_files/uart1.c mcc_generated_files/tmr2.c mcc_generated_files/tmr5.c adc_temp.c exchange.c fixed_t.c obs_timerow.c pid.c TimeTick.c uart_demo_v2.c main.c UstawieniaPinow.c ADC1.c printf.c errors.c Compare_PWM.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/drivers/uart.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/mcc_generated_files/tmr5.o ${OBJECTDIR}/adc_temp.o ${OBJECTDIR}/exchange.o ${OBJECTDIR}/fixed_t.o ${OBJECTDIR}/obs_timerow.o ${OBJECTDIR}/pid.o ${OBJECTDIR}/TimeTick.o ${OBJECTDIR}/uart_demo_v2.o ${OBJECTDIR}/main.o ${OBJECTDIR}/UstawieniaPinow.o ${OBJECTDIR}/ADC1.o ${OBJECTDIR}/printf.o ${OBJECTDIR}/errors.o ${OBJECTDIR}/Compare_PWM.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/drivers/uart.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/reset.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/tmr1.o.d ${OBJECTDIR}/mcc_generated_files/uart1.o.d ${OBJECTDIR}/mcc_generated_files/tmr2.o.d ${OBJECTDIR}/mcc_generated_files/tmr5.o.d ${OBJECTDIR}/adc_temp.o.d ${OBJECTDIR}/exchange.o.d ${OBJECTDIR}/fixed_t.o.d ${OBJECTDIR}/obs_timerow.o.d ${OBJECTDIR}/pid.o.d ${OBJECTDIR}/TimeTick.o.d ${OBJECTDIR}/uart_demo_v2.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/UstawieniaPinow.o.d ${OBJECTDIR}/ADC1.o.d ${OBJECTDIR}/printf.o.d ${OBJECTDIR}/errors.o.d ${OBJECTDIR}/Compare_PWM.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/drivers/uart.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/mcc_generated_files/uart1.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/mcc_generated_files/tmr5.o ${OBJECTDIR}/adc_temp.o ${OBJECTDIR}/exchange.o ${OBJECTDIR}/fixed_t.o ${OBJECTDIR}/obs_timerow.o ${OBJECTDIR}/pid.o ${OBJECTDIR}/TimeTick.o ${OBJECTDIR}/uart_demo_v2.o ${OBJECTDIR}/main.o ${OBJECTDIR}/UstawieniaPinow.o ${OBJECTDIR}/ADC1.o ${OBJECTDIR}/printf.o ${OBJECTDIR}/errors.o ${OBJECTDIR}/Compare_PWM.o

# Source Files
SOURCEFILES=mcc_generated_files/drivers/uart.c mcc_generated_files/pin_manager.c mcc_generated_files/mcc.c mcc_generated_files/traps.c mcc_generated_files/clock.c mcc_generated_files/reset.c mcc_generated_files/system.c mcc_generated_files/interrupt_manager.c mcc_generated_files/tmr1.c mcc_generated_files/uart1.c mcc_generated_files/tmr2.c mcc_generated_files/tmr5.c adc_temp.c exchange.c fixed_t.c obs_timerow.c pid.c TimeTick.c uart_demo_v2.c main.c UstawieniaPinow.c ADC1.c printf.c errors.c Compare_PWM.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EV128GM106
MP_LINKER_FILE_OPTION=,--script=p33EV128GM106.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/drivers/uart.o: mcc_generated_files/drivers/uart.c  .generated_files/flags/default/82944ba2ef5b7ccf02e0e71c6b153462809f7b9c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/uart.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/uart.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/67c352df9da0dcc738e96dd59d9248d62264f08e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/298794317c6ad9f0ca1c80a47bf573d032f2b0d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/default/b1be7d285b7bd4b376a955c7a9f7e0753c08dab4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/2802afff8324a2821aa3ea4d30511d20bd85647a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/flags/default/df05a0e60cc91c787a94f82567d786cee4285fe4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/65706358652baa208831510cc7458bfda9bb74b6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/85055b5222ce09d9067827927fda9399e339c485 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/4e6174743996ffb76a14dbbfd142b55e320abc1b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/flags/default/741df412fac0e615e6662a7b1127fcc448833fba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/flags/default/9561b8ab3c2fa68b0fa1cab5ed86845266a0db8f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr5.o: mcc_generated_files/tmr5.c  .generated_files/flags/default/30ce48e6508370cd9af32a73968f9c2e91efdd66 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr5.c  -o ${OBJECTDIR}/mcc_generated_files/tmr5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr5.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc_temp.o: adc_temp.c  .generated_files/flags/default/3c91364193aca5639e74c09c4fc061c7c1833fa7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc_temp.o.d 
	@${RM} ${OBJECTDIR}/adc_temp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc_temp.c  -o ${OBJECTDIR}/adc_temp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc_temp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/exchange.o: exchange.c  .generated_files/flags/default/4418867cbdea833a06c573d98d1315d40008d2bb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exchange.o.d 
	@${RM} ${OBJECTDIR}/exchange.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  exchange.c  -o ${OBJECTDIR}/exchange.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/exchange.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/fixed_t.o: fixed_t.c  .generated_files/flags/default/2c63e0c9c4209db853b653831fefb92e573b3885 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fixed_t.o.d 
	@${RM} ${OBJECTDIR}/fixed_t.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fixed_t.c  -o ${OBJECTDIR}/fixed_t.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/fixed_t.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/obs_timerow.o: obs_timerow.c  .generated_files/flags/default/f82ff07dacdbc0d86f83d934215cc323396b2e35 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/obs_timerow.o.d 
	@${RM} ${OBJECTDIR}/obs_timerow.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  obs_timerow.c  -o ${OBJECTDIR}/obs_timerow.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/obs_timerow.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pid.o: pid.c  .generated_files/flags/default/a06642b85219ab7f050d86d9906d2457f352b618 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pid.o.d 
	@${RM} ${OBJECTDIR}/pid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pid.c  -o ${OBJECTDIR}/pid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pid.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TimeTick.o: TimeTick.c  .generated_files/flags/default/e4bfd04464ee88290690279f3069006929eaca80 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TimeTick.o.d 
	@${RM} ${OBJECTDIR}/TimeTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TimeTick.c  -o ${OBJECTDIR}/TimeTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TimeTick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart_demo_v2.o: uart_demo_v2.c  .generated_files/flags/default/bfa563e066a93b488c6f1a463db5ccf95c4be71c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart_demo_v2.o.d 
	@${RM} ${OBJECTDIR}/uart_demo_v2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_demo_v2.c  -o ${OBJECTDIR}/uart_demo_v2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart_demo_v2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/466a77e794b8e32a5739192b085469c701fd9f04 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UstawieniaPinow.o: UstawieniaPinow.c  .generated_files/flags/default/26e1edfa8a799690bbacdc3be439211b899cecb2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UstawieniaPinow.o.d 
	@${RM} ${OBJECTDIR}/UstawieniaPinow.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UstawieniaPinow.c  -o ${OBJECTDIR}/UstawieniaPinow.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UstawieniaPinow.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC1.o: ADC1.c  .generated_files/flags/default/42e12ad2f719b7a0958bb1ca61756975d7a775e7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC1.o.d 
	@${RM} ${OBJECTDIR}/ADC1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC1.c  -o ${OBJECTDIR}/ADC1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/printf.o: printf.c  .generated_files/flags/default/d0535341b06f3fd09576b47c1f6a633ac919590d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/printf.o.d 
	@${RM} ${OBJECTDIR}/printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  printf.c  -o ${OBJECTDIR}/printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/printf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/errors.o: errors.c  .generated_files/flags/default/b860a64d575f0783688046d4c265225cdb821789 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/errors.o.d 
	@${RM} ${OBJECTDIR}/errors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  errors.c  -o ${OBJECTDIR}/errors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/errors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Compare_PWM.o: Compare_PWM.c  .generated_files/flags/default/a533770f3dcd2c1744c1ae3277a275077f9b99f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Compare_PWM.o.d 
	@${RM} ${OBJECTDIR}/Compare_PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Compare_PWM.c  -o ${OBJECTDIR}/Compare_PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Compare_PWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/drivers/uart.o: mcc_generated_files/drivers/uart.c  .generated_files/flags/default/fb347d9ca4b2b5dd0d7503afeca91fbae08c74e1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/uart.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/drivers/uart.c  -o ${OBJECTDIR}/mcc_generated_files/drivers/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/30ee28ba0ce984fb6d4e875520ba0bcfc6e07673 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/fb459d3a7bc76cd0b08c94ce0e1559c3c86f5ab9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/default/c78094b75aab14252cc229cc095361eadd006b67 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/85ca840a16846b6c39ebf06249c7300498c1e3eb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/reset.o: mcc_generated_files/reset.c  .generated_files/flags/default/207145301213b21fae277570669d0fb7d22f99e8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/reset.c  -o ${OBJECTDIR}/mcc_generated_files/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/46ae1ce64ae156b2f044cf7caefef21b88543946 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/9cdad69d05e9750acc7211a32926bf3a4ef905a7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/f35d044954bee19f802a1b93e16a207a65976381 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart1.o: mcc_generated_files/uart1.c  .generated_files/flags/default/d32a118a9a5494b44fb01d19448dbc28c55a69cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/flags/default/f5131e36063ad975fda5a3085edfc83f06a93e87 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr5.o: mcc_generated_files/tmr5.c  .generated_files/flags/default/2be91ecde226aa76d237b96cc9735e719efc642 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr5.c  -o ${OBJECTDIR}/mcc_generated_files/tmr5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr5.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc_temp.o: adc_temp.c  .generated_files/flags/default/6c7d4984cdc7fa99808c383410aa2ef62f5f260a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc_temp.o.d 
	@${RM} ${OBJECTDIR}/adc_temp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc_temp.c  -o ${OBJECTDIR}/adc_temp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc_temp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/exchange.o: exchange.c  .generated_files/flags/default/3a7b12a36043339098370791942d3a9927913b11 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/exchange.o.d 
	@${RM} ${OBJECTDIR}/exchange.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  exchange.c  -o ${OBJECTDIR}/exchange.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/exchange.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/fixed_t.o: fixed_t.c  .generated_files/flags/default/734da0013a61cb75cfe1e2c14fac27d3e002dbf8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fixed_t.o.d 
	@${RM} ${OBJECTDIR}/fixed_t.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fixed_t.c  -o ${OBJECTDIR}/fixed_t.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/fixed_t.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/obs_timerow.o: obs_timerow.c  .generated_files/flags/default/7a42f19026dcd80e8bfc3ba0d5c26884b51f883 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/obs_timerow.o.d 
	@${RM} ${OBJECTDIR}/obs_timerow.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  obs_timerow.c  -o ${OBJECTDIR}/obs_timerow.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/obs_timerow.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pid.o: pid.c  .generated_files/flags/default/e6ce24f1fb0a60609601b7dd78c05c477afb7fd7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pid.o.d 
	@${RM} ${OBJECTDIR}/pid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pid.c  -o ${OBJECTDIR}/pid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pid.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TimeTick.o: TimeTick.c  .generated_files/flags/default/e39552af00ce3bc62f2b56ec1804e17dadd58923 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TimeTick.o.d 
	@${RM} ${OBJECTDIR}/TimeTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TimeTick.c  -o ${OBJECTDIR}/TimeTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TimeTick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart_demo_v2.o: uart_demo_v2.c  .generated_files/flags/default/2104a6ef7c8feb0250c67194f48893a5847e8562 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart_demo_v2.o.d 
	@${RM} ${OBJECTDIR}/uart_demo_v2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_demo_v2.c  -o ${OBJECTDIR}/uart_demo_v2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart_demo_v2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/f21fdfca4de58caa4f2bc328188a7cee80f5f299 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UstawieniaPinow.o: UstawieniaPinow.c  .generated_files/flags/default/8364ff989484b1187d35652c7627cd954cb75c8f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UstawieniaPinow.o.d 
	@${RM} ${OBJECTDIR}/UstawieniaPinow.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UstawieniaPinow.c  -o ${OBJECTDIR}/UstawieniaPinow.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UstawieniaPinow.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC1.o: ADC1.c  .generated_files/flags/default/9ed30d90ce4966189afa3941373e4f834b3a74ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC1.o.d 
	@${RM} ${OBJECTDIR}/ADC1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC1.c  -o ${OBJECTDIR}/ADC1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/printf.o: printf.c  .generated_files/flags/default/4c13d07636cbeca16caa51cfbc30dd65fd6c3d52 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/printf.o.d 
	@${RM} ${OBJECTDIR}/printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  printf.c  -o ${OBJECTDIR}/printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/printf.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/errors.o: errors.c  .generated_files/flags/default/29a9ab1aeef85ceb4c7b60a0de182dd14613cf0c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/errors.o.d 
	@${RM} ${OBJECTDIR}/errors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  errors.c  -o ${OBJECTDIR}/errors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/errors.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Compare_PWM.o: Compare_PWM.c  .generated_files/flags/default/b202225421f9a527d3946d1115240f431d90a70f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Compare_PWM.o.d 
	@${RM} ${OBJECTDIR}/Compare_PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Compare_PWM.c  -o ${OBJECTDIR}/Compare_PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Compare_PWM.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/SM.BZ.0002.006_Reg_Temp.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
