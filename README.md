# open-ponic

An open source project to manage an aquaponic system with a raspberry pi.

## Requirements

### Materials

This is a rough draft of what materials I am using

- Shelves -- structure to hold all components
- Fish tank (40 gallon) -- for fish
- planter boxes with drain holes -- house the vegetation
- Bucket -- Act as a reservoir and filter
- Piping -- Move the water to all the parts
- PVC pass through -- Move water between the reservoir and planters
- Pumps -- Move the water
- Temp sensors -- ensure appropriate temps for each phase
- Solenoid flow switch -- control the path of water
- raspberry pi 3

### Install

#### apt installs

`sudo apt install cmake -y`
`sudo apt install lm-sensors -y`
`sudo apt install libsensors4-dev -y`

#### updated raspi-config file

so that we are using the custom pin 10 for gpio 1-wire
`nanao /boot/firmware/config.txt`
`dtoverlay=w1.gpio,gpiopin=10`

`sudo shutdown -r now`

<!-- directions here -->

### Build

`cd build`
`cmake ..`
`make`