
#define HOME_PIN 5
#define GET_HOME PINB & 0b00001000
#define HOME_SPEED -2000
#define HOME_LATCH_SPEED 200
#define HOME_POSITION 0

#define SCALE 1600
#define ROW_STEP  SCALE
#define WASH_STEP (SCALE/4)


void setup() {
  // put your setup code here, to run once:
  pinMode(HOME_PIN, INPUT_PULLUP);
  home();
}


void home() {
  stepper.setSpeed(HOME_SPEED);
  while (not GET_HOME) {
    stepper.runSpeed();
  }

  stepper.setSpeed(HOME_LATCH_SPEED);
  while (GET_HOME) {
    stepper.runSpeed();
  }
  stepper.setCurrentPosition(0);
  stepper.setSpeed(0);
  for (int i = 0; i < 10000; i++)
    stepper.runSpeed();
}

void move(long n) {
  stepper.runToNewPosition(stepper1.currentPosition() + n);
}
void move_to(long n) {
  stepper.runToNewPosition(n);
}

void wash(int n = 100) {
  for (int i = 0; i < n; i++) {
    stepper.move(WASH_STEP);
    stepper.move(-WASH_STEP);
  }
}

void next_row() {
  stepper.move(ROW_STEP);
}

void goto_row(int n) {
  stepper.move_to(n*ROW_STEP);
}


void loop() {
  // put your main code here, to run repeatedly:

}
