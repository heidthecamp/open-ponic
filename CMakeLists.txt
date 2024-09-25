cmake_minimum_required(VERSION 3.26)

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
