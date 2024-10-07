
# MICROCONTROLLER - MICROPROCESSOR, LABORATORY 2

This is the second lab to get familiar with Timer Interrupt through a variety of exercises focused on LED Scanning.


## 1. Schematic for this lab

I simulated the source code on an STM32F103C6 using Proteus 8. The schematic looks like this:

![Proteus Schematic](./images/Proteus_Schematic_LAB2.png)

The pin assignments are listed in the table below:

| PIN      | PIN LABEL      | FOR EXERCISE                   |
|:---------|:---------------|:------------------------------:|
| PA0      | not in use     | `-\|-\|-\|-\|-\|-\|-\|-\|-\|-` |
| PA1      | EN_0           | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PA2      | EN_1           | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PA3      | EN_2           | `-\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PA4      | EN_3           | `-\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PA5      | LED_RED        | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PA6      | DOT            | `-\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PA7      | not in use     | `-\|-\|-\|-\|-\|-\|-\|-\|-\|-` |
| PA8      | ENM0           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA9      | ENM1           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA10     | ENM2           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA11     | ENM3           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA12     | ENM4           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA13     | ENM5           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA14     | ENM6           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PA15     | ENM7           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB0      | SEG_0          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB1      | SEG_1          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB2      | SEG_2          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB3      | SEG_3          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB4      | SEG_4          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB5      | SEG_5          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB6      | SEG_6          | `1\|2\|3\|4\|5\|-\|-\|-\|-\|-` |
| PB7      | not in use     | `-\|-\|-\|-\|-\|-\|-\|-\|-\|-` |
| PB8      | ROW0           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB9      | ROW1           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB10     | ROW2           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB11     | ROW3           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB12     | ROW4           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB13     | ROW5           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB14     | ROW6           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |
| PB15     | ROW7           | `-\|-\|-\|-\|-\|-\|-\|-\|9\|10` |

## 2. How to run the exercises source code?

Each exercises is implemented in separeta source file (.c) and header file (.h), which are placed in `./Core/Src/` and `./Core/Inc/` respectively. I recommend 2 ways to run the code:

NOTE: A source code file may be dependent on another source code files. Please check the #include in source file (.c) to know which source files is neccesary for an exercise.

### 2.1. Clone this Project and Run:
If you clone this project to your local device, you only need to change `RUN_EXERCISE` in `./Core/Src/main.c` to the exercise number you want to run (from `1` to `10`).

```c
#define RUN_EXERCISE 10
```

### 2.2. Download specific exercise file:
1. Ensure that all hardware connections are correct as described above.

2. Download the header and source files for the specific exercise you want to run, place them in the appropriate directories, and include the header in `./Core/Src/main.c` as follows:
```c
#include "exercise-.h"
```

3. Run the code. Each exercises has two main functions: `exercise-_init()` ensure all necessary pins are available; and `exercise-_run()` to execute the exercise requirements.. You should place these functions within the `while` loop in the `main()` function.