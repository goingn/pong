################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ballctrl.c \
../src/paddlectrl.c \
../src/pong.c \
../src/splash.c \
../src/timer.c 

OBJS += \
./src/ballctrl.o \
./src/paddlectrl.o \
./src/pong.o \
./src/splash.o \
./src/timer.o 

C_DEPS += \
./src/ballctrl.d \
./src/paddlectrl.d \
./src/pong.d \
./src/splash.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


