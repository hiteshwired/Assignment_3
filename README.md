# STM32 Character LCD Driver

A bare-metal embedded C exercise for the STM32L476RG (Nucleo-64) that implements
a driver for a character LCD (HD44780-style) and uses it to display text.

## What it does

- `lcd.c/.h` provides the LCD library: initialization sequence, command writes,
  single-character output, and string output.
- `main.c` initializes the display and writes the target output (a two-line
  message), built incrementally from a one-character test up to full strings.

## Hardware

- STM32L476RG (Nucleo-64)
- Character LCD module (HD44780-compatible)

## Build

Generated from STM32CubeMX with a CMake build. Build with the included CMake
presets and an `arm-none-eabi` toolchain, or open in STM32CubeIDE, then flash.

---

## Academic honesty & licensing

Coursework from an embedded systems course at Cal Poly, San Luis Obispo. The
`lcd.c/.h` driver and `main.c` application logic are my own work. The project also
bundles STMicroelectronics' STM32L4xx HAL/CMSIS drivers and CubeMX-generated
files, which are under ST's own license terms and are **not** mine to relicense.

Shared as a learning reference only. It is intentionally not released under an
open-source license, and you should not submit it as your own work for a graded
assignment.
