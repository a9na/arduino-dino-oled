# Arduino Dino OLED Game 🦖🕹️📟

A fun and simple recreation of the Chrome Dino game on a 128x64 OLED display using an Arduino Uno and a single button.

## Features
- Smooth Dino jump animation
- Basic gravity physics
- Moving cactus obstacle
- Collision detection
- Score tracking
- Button-controlled gameplay and restart

## Hardware Required
- Arduino Uno (or compatible board)
- 0.96" I2C OLED Display (SSD1306)
- Push Button
- 10KΩ resistor
- Breadboard & jumper wires

## Wiring

### OLED Screen (I2C)
| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SCL      | A5          |
| SDA      | A4          |

### Button (4-pin module style)
| Button Pin | Arduino Pin |
|------------|-------------|
| 1          | GND (with 10KΩ to 2) |
| 2          | 5V          |
| 3          | D7          |
| 4          | Empty       |

## Installation

1. Install [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) and [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library) libraries via Arduino Library Manager.
2. Upload the code in `dino_game.ino` to your Arduino.
3. Press the button to jump over the cactus and avoid collision.
4. Score increases every time you avoid a cactus. Press the button after "Game Over" to restart.
