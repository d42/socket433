#!/usr/bin/env python3
import argparse
import sys
from itertools import chain

import serial


def parse_options():
    parser = argparse.ArgumentParser()
    parser.add_argument("--start", type=int, nargs="+", default=())
    parser.add_argument("--stop", type=int, nargs="+", default=())

    return parser.parse_args(sys.argv[1:])


def main():
    options = parse_options()
    ser = serial.Serial('/dev/ttyACM0', 9600)

    for i in chain([i << 4 | 1 for i in options.start],
                   [i << 4 | 0 for i in options.stop]):
        ser.write(i.to_bytes(1, 'little'))

if __name__ == '__main__':
    main()
