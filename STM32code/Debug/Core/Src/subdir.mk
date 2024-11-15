################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AS5048A_P.c \
../Core/Src/Bill_Matrix_P.c \
../Core/Src/Delta_Robot_P.c \
../Core/Src/ESP8266EX_WIFI_P.c \
../Core/Src/HD44780U_P.c \
../Core/Src/ICM-40627_P.c \
../Core/Src/Inverz_Kinematika_P.c \
../Core/Src/MPU-6050_P.c \
../Core/Src/Menu_P.c \
../Core/Src/PCF8574T_P.c \
../Core/Src/PID.c \
../Core/Src/SSD1306_OLED_P.c \
../Core/Src/Stepper_Motor_P.c \
../Core/Src/main.c \
../Core/Src/stm32h5xx_hal_msp.c \
../Core/Src/stm32h5xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h5xx.c 

OBJS += \
./Core/Src/AS5048A_P.o \
./Core/Src/Bill_Matrix_P.o \
./Core/Src/Delta_Robot_P.o \
./Core/Src/ESP8266EX_WIFI_P.o \
./Core/Src/HD44780U_P.o \
./Core/Src/ICM-40627_P.o \
./Core/Src/Inverz_Kinematika_P.o \
./Core/Src/MPU-6050_P.o \
./Core/Src/Menu_P.o \
./Core/Src/PCF8574T_P.o \
./Core/Src/PID.o \
./Core/Src/SSD1306_OLED_P.o \
./Core/Src/Stepper_Motor_P.o \
./Core/Src/main.o \
./Core/Src/stm32h5xx_hal_msp.o \
./Core/Src/stm32h5xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h5xx.o 

C_DEPS += \
./Core/Src/AS5048A_P.d \
./Core/Src/Bill_Matrix_P.d \
./Core/Src/Delta_Robot_P.d \
./Core/Src/ESP8266EX_WIFI_P.d \
./Core/Src/HD44780U_P.d \
./Core/Src/ICM-40627_P.d \
./Core/Src/Inverz_Kinematika_P.d \
./Core/Src/MPU-6050_P.d \
./Core/Src/Menu_P.d \
./Core/Src/PCF8574T_P.d \
./Core/Src/PID.d \
./Core/Src/SSD1306_OLED_P.d \
./Core/Src/Stepper_Motor_P.d \
./Core/Src/main.d \
./Core/Src/stm32h5xx_hal_msp.d \
./Core/Src/stm32h5xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h5xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H533xx -c -I../Core/Inc -I"C:/Users/win10/Documents/Projects/Delta_Robot_v2/STM32code/Core/Src" -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/AS5048A_P.cyclo ./Core/Src/AS5048A_P.d ./Core/Src/AS5048A_P.o ./Core/Src/AS5048A_P.su ./Core/Src/Bill_Matrix_P.cyclo ./Core/Src/Bill_Matrix_P.d ./Core/Src/Bill_Matrix_P.o ./Core/Src/Bill_Matrix_P.su ./Core/Src/Delta_Robot_P.cyclo ./Core/Src/Delta_Robot_P.d ./Core/Src/Delta_Robot_P.o ./Core/Src/Delta_Robot_P.su ./Core/Src/ESP8266EX_WIFI_P.cyclo ./Core/Src/ESP8266EX_WIFI_P.d ./Core/Src/ESP8266EX_WIFI_P.o ./Core/Src/ESP8266EX_WIFI_P.su ./Core/Src/HD44780U_P.cyclo ./Core/Src/HD44780U_P.d ./Core/Src/HD44780U_P.o ./Core/Src/HD44780U_P.su ./Core/Src/ICM-40627_P.cyclo ./Core/Src/ICM-40627_P.d ./Core/Src/ICM-40627_P.o ./Core/Src/ICM-40627_P.su ./Core/Src/Inverz_Kinematika_P.cyclo ./Core/Src/Inverz_Kinematika_P.d ./Core/Src/Inverz_Kinematika_P.o ./Core/Src/Inverz_Kinematika_P.su ./Core/Src/MPU-6050_P.cyclo ./Core/Src/MPU-6050_P.d ./Core/Src/MPU-6050_P.o ./Core/Src/MPU-6050_P.su ./Core/Src/Menu_P.cyclo ./Core/Src/Menu_P.d ./Core/Src/Menu_P.o ./Core/Src/Menu_P.su ./Core/Src/PCF8574T_P.cyclo ./Core/Src/PCF8574T_P.d ./Core/Src/PCF8574T_P.o ./Core/Src/PCF8574T_P.su ./Core/Src/PID.cyclo ./Core/Src/PID.d ./Core/Src/PID.o ./Core/Src/PID.su ./Core/Src/SSD1306_OLED_P.cyclo ./Core/Src/SSD1306_OLED_P.d ./Core/Src/SSD1306_OLED_P.o ./Core/Src/SSD1306_OLED_P.su ./Core/Src/Stepper_Motor_P.cyclo ./Core/Src/Stepper_Motor_P.d ./Core/Src/Stepper_Motor_P.o ./Core/Src/Stepper_Motor_P.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32h5xx_hal_msp.cyclo ./Core/Src/stm32h5xx_hal_msp.d ./Core/Src/stm32h5xx_hal_msp.o ./Core/Src/stm32h5xx_hal_msp.su ./Core/Src/stm32h5xx_it.cyclo ./Core/Src/stm32h5xx_it.d ./Core/Src/stm32h5xx_it.o ./Core/Src/stm32h5xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h5xx.cyclo ./Core/Src/system_stm32h5xx.d ./Core/Src/system_stm32h5xx.o ./Core/Src/system_stm32h5xx.su

.PHONY: clean-Core-2f-Src

