################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/List.c" \
"../Sources/Mutex.c" \
"../Sources/Port.c" \
"../Sources/Task.c" \
"../Sources/main.c" \
"../Sources/queue.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/List.c \
../Sources/Mutex.c \
../Sources/Port.c \
../Sources/Task.c \
../Sources/main.c \
../Sources/queue.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/List_c.obj \
./Sources/Mutex_c.obj \
./Sources/Port_c.obj \
./Sources/Task_c.obj \
./Sources/main_c.obj \
./Sources/queue_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/List_c.obj" \
"./Sources/Mutex_c.obj" \
"./Sources/Port_c.obj" \
"./Sources/Task_c.obj" \
"./Sources/main_c.obj" \
"./Sources/queue_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/List_c.d \
./Sources/Mutex_c.d \
./Sources/Port_c.d \
./Sources/Task_c.d \
./Sources/main_c.d \
./Sources/queue_c.d \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/List_c.d" \
"./Sources/Mutex_c.d" \
"./Sources/Port_c.d" \
"./Sources/Task_c.d" \
"./Sources/main_c.d" \
"./Sources/queue_c.d" \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/List_c.obj \
./Sources/Mutex_c.obj \
./Sources/Port_c.obj \
./Sources/Task_c.obj \
./Sources/main_c.obj \
./Sources/queue_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Events.args" -ObjN="Sources/Events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/List_c.obj: ../Sources/List.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/List.args" -ObjN="Sources/List_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mutex_c.obj: ../Sources/Mutex.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Mutex.args" -ObjN="Sources/Mutex_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Port_c.obj: ../Sources/Port.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Port.args" -ObjN="Sources/Port_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Task_c.obj: ../Sources/Task.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Task.args" -ObjN="Sources/Task_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/queue_c.obj: ../Sources/queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/queue.args" -ObjN="Sources/queue_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


