#include <Adafruit_SSD1306.h>

#define BUTTON_PIN 7  // Button connected to pin D7

bool isJumping = false;
int dinoY = 40;
int velocity = 0;
const int gravity = 2;
const int groundY = 40;
int cactusX = 128;
int score = 0;

int switchState = 0;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
    pinMode(BUTTON_PIN, INPUT);  // Configure button pin as input

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        while (1);  // Stop if OLED initialization fails
    }

    display.clearDisplay();
}

void loop() {
    static bool buttonPressed = false;

    // Jump only if button is pressed and dino is on the ground
    if (digitalRead(BUTTON_PIN) == HIGH && !buttonPressed && dinoY == groundY) {
        buttonPressed = true;
        isJumping = true;
        velocity = -10;
        delay(50);  // Debounce delay
    }

    // Reset button press state when released
    if (digitalRead(BUTTON_PIN) == LOW) {
        buttonPressed = false;
    }

    // Update jump physics
    if (isJumping) {
        dinoY += velocity;
        velocity += gravity;
        if (dinoY >= groundY) {
            dinoY = groundY;
            isJumping = false;
        }
    }

    // Move cactus left
    cactusX -= 3;
    if (cactusX < -10) {
        cactusX = 128;
        score++;  // Increase score when cactus is avoided
    }

    // Draw game elements
    display.clearDisplay();
    display.fillRect(10, dinoY, 10, 10, SSD1306_WHITE);        // Dino
    display.fillRect(cactusX, groundY, 10, 15, SSD1306_WHITE); // Cactus
    display.drawLine(0, 58, 128, 58, SSD1306_WHITE);           // Ground

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Score: ");
    display.print(score);

    display.display();

    // Collision detection
    if (cactusX < 20 && cactusX > 5 && dinoY == groundY) {
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(20, 20);
        display.print("Game Over");
        display.display();

        // Wait for button press to restart the game
        while (1) {
            switchState = digitalRead(BUTTON_PIN);
            if (switchState == HIGH) {
                // Reset game state
                cactusX = 128;
                dinoY = groundY;
                velocity = 0;
                isJumping = false;
                score = 0;
                return;
            }
        }
    }

    delay(50);  // Frame delay for smooth animation
}
