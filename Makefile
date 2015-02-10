PROJECT_DIR       = /home/daz/projects/swiatlo
BOARD_TAG = micro
USER_LIB_PATH := lib/
AVRDUDE_OPTS := -V -D -v -v -v
ISP_PORT = /dev/ttyACM0


include /usr/share/arduino/Arduino.mk
