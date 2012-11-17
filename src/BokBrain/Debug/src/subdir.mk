################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BokBrain.cpp \
../src/NNet.cpp \
../src/Neuron.cpp 

OBJS += \
./src/BokBrain.o \
./src/NNet.o \
./src/Neuron.o 

CPP_DEPS += \
./src/BokBrain.d \
./src/NNet.d \
./src/Neuron.d 


# Each subdirectory must supply rules for building sources it contributes
src/BokBrain.o: ../src/BokBrain.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/BokBrain.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/NNet.o: ../src/NNet.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/NNet.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Neuron.o: ../src/Neuron.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/Neuron.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


