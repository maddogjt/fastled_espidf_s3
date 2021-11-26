cmake_minimum_required(VERSION 3.5)

set(srcs
		"FastLEDArduinoShim.cpp"
		"FastLED/src/FastLED.cpp"
		"FastLED/src/bitswap.cpp"
		"FastLED/src/colorpalettes.cpp"
		"FastLED/src/colorutils.cpp"
		"FastLED/src/hsv2rgb.cpp"
		"FastLED/src/lib8tion.cpp"
		"FastLED/src/noise.cpp"
		"FastLED/src/platforms.cpp"
		"FastLED/src/power_mgt.cpp"
		"FastLED/src/wiring.cpp"
		# "hal/esp32-hal-misc.c"
		# "hal/esp32-hal-gpio.c"
# remove the following if you want I2S instead of RMT hardware, just put a pound in front
		"FastLED/src/platforms/esp/32/clockless_rmt_esp32.cpp"
		)

# everything needs the ESP32 flag, not sure why this won't work
# going to hack by adding the ESP32 define in the h file
	#`target_compile_options(${COMPONENT_LIB} PRIVATE "-DESP32")

idf_component_register(SRCS "${srcs}"
			 INCLUDE_DIRS "." "FastLED/src")

target_compile_definitions(${COMPONENT_LIB} PUBLIC ESP32)

