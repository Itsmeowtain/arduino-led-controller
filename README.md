## arduino-led-controller

An 8-LED array on an Arduino Uno, controlled by two potentiometers. Pot 0 (A0) picks the mode by splitting its range into thirds, and Pot 1 (A1) controls what that mode does.

Modes

Single light: one LED lit, chosen by Pot 1’s position across eight zones.
Volume display: LEDs fill from left to right as Pot 1 increases.
Light wave: a wave sweeps across the array, with speed from 30 to 300 ms set by Pot 1.

Concepts: arrays, for loops, helper functions, analogRead(), map()

Hardware: Arduino Uno, 8 LEDs with resistors (about 12 mA bias), 2 potentiometers

Built for ECE 1004 Lab at Virginia Tech.

# IMPORTANT: Authorship and use
Written by Daniel Tikhonov for ECE 1004 (Virginia Tech), Fall 2026. This repo is a record of my own coursework and is shared for reference only. If you’re a current student in this course, please don’t copy it; the Honor Code applies.

Topics to add: arduino, embedded-systems, c, potentiometer, led
