# Prototyping IoT Applications with Raspberry Pi and IFTTT

## Materials

- Raspberry Pi 2 Model B: 1
- USB Wi-Fi module (e.g. ): 1
- SD card with [Raspbian Jessie (May 2016)](https://www.raspberrypi.org/downloads/raspbian/) installed: 1
- Arduino Uno: 1
- USB cable (A to B): 1

## Preparation

- [x] Set a unique host name to identify your RasPi by name (e.g. team-a, team-b, team-c...)
- [x] Enable Samba to edit files from your PC
- [x] Install TightVNC Server by entering `$ sudo apt-get install tightvncserver` then launch by entering `$ vncserver`
- [x] Download and extract Arduino IDE 1.6.9 for **Linux ARM (experimental)** from [the official website](https://www.arduino.cc/en/Main/Software)
- [ ] Download a [VNC Viewer](https://www.realvnc.com/download/) (Windows only)

## What's the Difference between Arduino and Raspberry Pi?

- An article (including discussions) at Make:, [Raspberry Pi or Arduino? One Simple Rule to Choose the Right Board](http://makezine.com/2015/12/04/admittedly-simplistic-guide-raspberry-pi-vs-arduino/), might be helpful
- Arduino:
  - is a microcontroller (a simple computer that can run one program at a time, over and over again) board
  - can access virtually all kinds of sensors and actuators
  - has great resources especially for hardware and communities on the Internet
- Raspberry Pi:
  - is a general-purpose computer
  - can run many applications such as Processing, Arduino IDE and so on
  - has great resources especially for Linux based technologies and communities on the Internet
- Let's think that we can use Raspberry Pi **AND** Arduino, instead of Raspberry Pi **VS.** Arduino

| | [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno) | [Raspberry Pi 2 Model B](https://www.raspberrypi.org/products/raspberry-pi-2-model-b/) |
|:--|:--|:--|
| Processor | ATmega328P (8 bit) | ARM Cortex-A7 CPU (32 bit, quad-core) |
| Clock speed | 16 MHz | 900 MHz |
| OS | - | Raspbian, Windows 10 IoT Core and so on |
| RAM | 2 KB | 1 GB |
| Digital I/O Pins | 14 | 28 |
| PWM Digital I/O Pins | 6 | 2 (1 is shared with the audio output) |
| Analog Input Pins | 6 | - |
| HDMI port | - | 1 |
| Ethernet port | - | 1 |
| USB port (host) | - | 4 |
| Analog audio | - | 1 |
| Operating Voltage | 5 V | 3.3 V |
| Price | $24.95 | $39.95 |

## Demo

- [AlexaPi](https://github.com/sammachin/AlexaPi) (by Sam Machin) and IFTTT
  - [Installing Alexa Voice Service to Raspberry Pi](https://youtu.be/frH9HaQTFL8)
- [Google Cloud Vision API](https://cloud.google.com/vision/) with [Node-RED](http://nodered.org/)
  - [What is Cloud Vision API?](https://youtu.be/eve8DkkVdhI)
  - [How to build a smart RasPi Bot with Cloud Vision and Speech API - Google I/O 2016](https://www.youtube.com/watch?v=HpPyhsC4q9M)
  - [Google Cloud Vision API | LABEL_DETECTION on a Raspberry Pi with a Webcam](http://flows.nodered.org/flow/4079e89b8afbcb8f70cea5d75e5120f8)
  - Preparation
    - Install fswebcam with `sudo apt-get install fswebcam`
    - Try taking a picture with `fswebcam image.jpg`

## References

- [The comprehensive Raspberry Pi GPIO Pinout guide](http://pinout.xyz/)
- [Project: Raspberry Pi + Alexa Voice Service](https://github.com/amzn/alexa-avs-raspberry-pi)
- [Node-RED](http://nodered.org/)
- [Dennis Schultz's Blog | Part 4: Adding in the camera](https://dennisschultz.wordpress.com/2015/06/29/my-internet-of-things-and-mobilefirst-adventure-part-5-adding-in-the-camera/)
- [Webcam captures image and tweets it to Twitter account](http://flows.nodered.org/flow/3acea22db01b2b76d46d)
- [ELECOM UCAM-C0220FB](http://www2.elecom.co.jp/multimedia/pc-camera/ucam-c0220fb/)
- [Node-RED | Raspberry Pi](http://nodered.org/docs/hardware/raspberrypi)
- [Raspberry Pi - Arduino Serial Communication](http://www.instructables.com/id/Raspberry-Pi-Arduino-Serial-Communication/) by AdrieSentosa
