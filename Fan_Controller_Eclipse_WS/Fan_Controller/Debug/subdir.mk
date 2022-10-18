################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DcMotor.c \
../adc.c \
../fan_controller.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../pwm.c 

OBJS += \
./DcMotor.o \
./adc.o \
./fan_controller.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./pwm.o 

C_DEPS += \
./DcMotor.d \
./adc.d \
./fan_controller.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


