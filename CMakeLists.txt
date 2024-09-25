cmake_minimum_required(VERSION 3.25)

project(openponic)

add_executable(
    openponic
    app/main.c
    app/lights.c
    app/ph_sensor.c
    app/pin_io.c
    app/pump.c
    app/relay.c
    app/thermometer.c
)

target_link_libraries(
    openponic
    pigpio
    sensors
)