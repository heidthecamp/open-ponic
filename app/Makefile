all: openponic

openponic: main.c lights.c pump.c thermometer.c ph_sensor.c
	gcc -o openponic $^

clean:
	rm -f openponic
# Clean up the mess
