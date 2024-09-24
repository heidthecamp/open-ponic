all:
	make relay
	make lights
	make pump
	make thermometer
	make ph_sensor
	make main

relay: relay.c
	gcc -c relay.c -o relay.o

lights: lights.c relay.o
	gcc -c lights.c -o lights.o
# Make the lights

pump: pump.c relay.o
	gcc -c pump.c -o pump.o

thermometer: thermometer.c
	gcc -c thermometer.c -o thermometer.o

ph_sensor: ph_sensor.c
	gcc -c ph_sensor.c -o ph_sensor.o

main: main.c lights.o pump.o thermometer.o ph_sensor.o
	gcc -c main.c -o openponic

clean:
	rm -f *.o
	rm -f openponic
# Clean up the mess
