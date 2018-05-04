################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\RadlTrailer.ino 

CPP_SRCS += \
..\A123Module.cpp \
..\AnalogInput.cpp \
..\Lights.cpp \
..\adc.cpp \
..\bridge.cpp \
..\pwm.cpp \
..\sloeber.ino.cpp 

LINK_OBJ += \
.\A123Module.cpp.o \
.\AnalogInput.cpp.o \
.\Lights.cpp.o \
.\adc.cpp.o \
.\bridge.cpp.o \
.\pwm.cpp.o \
.\sloeber.ino.cpp.o 

INO_DEPS += \
.\RadlTrailer.ino.d 

CPP_DEPS += \
.\A123Module.cpp.d \
.\AnalogInput.cpp.d \
.\Lights.cpp.d \
.\adc.cpp.d \
.\bridge.cpp.d \
.\pwm.cpp.d \
.\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
A123Module.cpp.o: ..\A123Module.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

AnalogInput.cpp.o: ..\AnalogInput.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Lights.cpp.o: ..\Lights.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

RadlTrailer.o: ..\RadlTrailer.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

adc.cpp.o: ..\adc.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

bridge.cpp.o: ..\bridge.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

pwm.cpp.o: ..\pwm.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR   -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\mega" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\ArduinoJson\5.13.1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\EEPROM\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Timer1\src" -I"C:\Users\kzm\eclipse\cpp-oxygen\eclipse\arduinoPlugin\libraries\Adafruit_NeoPixel\1.1.6" -I"C:\Users\kzm\Arduino\libraries\MCP2515_lib-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


