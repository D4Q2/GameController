#include <XInput.h>


void setup() {
  // put your setup code here, to run once:
  XInput.setAutoSend(false);
  XInput.begin();

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Left Trigger - 0
  XInput.setTrigger(TRIGGER_LEFT, digitalRead(0) * -255 + 255);
  // Left Button - 1
  XInput.setButton(BUTTON_LB, !digitalRead(1));
  // Back Button - 2
  XInput.setButton(BUTTON_BACK, !digitalRead(2));
  // Up DPad - 3 Down DPad - 5 Left DPad - 4 Right DPad - 6
  XInput.setDpad(!digitalRead(3), !digitalRead(5), !digitalRead(4), !digitalRead(6));
  // Right Trigger - 7
  XInput.setTrigger(TRIGGER_RIGHT, digitalRead(7) * -255 + 255);
  // Right Button - 8
  XInput.setButton(BUTTON_RB, !digitalRead(8));
  // B Button - 9
  XInput.setButton(BUTTON_B, !digitalRead(9));
  // A Button - 10
  XInput.setButton(BUTTON_A, !digitalRead(10));
  // Y Button - 14
  XInput.setButton(BUTTON_Y, !digitalRead(14));
  // Menu Button - 15
  XInput.setButton(BUTTON_START, !digitalRead(15));
  // X Button - 16
  XInput.setButton(BUTTON_X, !digitalRead(16));

  // A2, A3 LEFT
  int leftXAxis = (analogRead(A3)-512) * 64;
  int leftYAxis = (analogRead(A2)-512) * 64;
  XInput.setJoystick(JOY_LEFT, leftXAxis, leftYAxis);
  // A0, A1 RIGHT
  int rightXAxis = (analogRead(A1)-512) * 64;
  int rightYAxis = (analogRead(A0)-512) * 64;
  XInput.setJoystick(JOY_RIGHT, rightXAxis, rightYAxis);

  XInput.send();
}
