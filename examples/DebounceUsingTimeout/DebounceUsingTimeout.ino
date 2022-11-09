// Debounce button using a timeout and delay function

#include <AsyncTimer.h>

#define BUTTON_PIN 4

AsyncTimer t;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
}

unsigned short timeoutId = 0;
bool buttonEnabled = true;

void loop() {
  t.handle();

  if (digitalRead(BUTTON_PIN) == HIGH) {
    if (buttonEnabled) {
      Serial.println("Button pressed!");
      buttonEnabled = false;
      timeoutId = t.setTimeout(
          []() {
            buttonEnabled = true;
            timeoutId = 0;
          },
          50);
    }
    if (timeoutId != 0) {
      t.reset(timeoutId);
    }
  }
}
