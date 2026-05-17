#define LANE_A_RED    2
#define LANE_A_YELLOW 3
#define LANE_A_GREEN  4
#define LANE_B_RED    5
#define LANE_B_YELLOW 6
#define LANE_B_GREEN  7

#define MAX_GREEN_TIME 30
#define MIN_GREEN_TIME 5
#define YELLOW_TIME    3

int laneA_cars = 2;
int laneB_cars = 2;
String serialData = "";

void setup() {
  Serial.begin(9600);
  pinMode(LANE_A_RED,    OUTPUT);
  pinMode(LANE_A_YELLOW, OUTPUT);
  pinMode(LANE_A_GREEN,  OUTPUT);
  pinMode(LANE_B_RED,    OUTPUT);
  pinMode(LANE_B_YELLOW, OUTPUT);
  pinMode(LANE_B_GREEN,  OUTPUT);
  setAllRed();
  delay(2000);
}

void loop() {
  readSerialData();
  int total = laneA_cars + laneB_cars;
  if (total == 0) total = 1;
  int greenA = (laneA_cars * MAX_GREEN_TIME) / total;
  int greenB = (laneB_cars * MAX_GREEN_TIME) / total;
  if (greenA < MIN_GREEN_TIME) greenA = MIN_GREEN_TIME;
  if (greenB < MIN_GREEN_TIME) greenB = MIN_GREEN_TIME;
  runGreenCycle(LANE_A_RED, LANE_A_YELLOW, LANE_A_GREEN,
                LANE_B_RED, LANE_B_YELLOW, LANE_B_GREEN, greenA);
  delay(500);
  readSerialData();
  total = laneA_cars + laneB_cars;
  if (total == 0) total = 1;
  greenB = (laneB_cars * MAX_GREEN_TIME) / total;
  if (greenB < MIN_GREEN_TIME) greenB = MIN_GREEN_TIME;
  runGreenCycle(LANE_B_RED, LANE_B_YELLOW, LANE_B_GREEN,
                LANE_A_RED, LANE_A_YELLOW, LANE_A_GREEN, greenB);
  delay(500);
}

void runGreenCycle(int activeRed, int activeYellow, int activeGreen,
                   int waitRed,   int waitYellow,   int waitGreen,
                   int greenTime) {
  digitalWrite(activeRed,    LOW);
  digitalWrite(activeYellow, LOW);
  digitalWrite(activeGreen,  HIGH);
  digitalWrite(waitRed,      HIGH);
  digitalWrite(waitYellow,   LOW);
  digitalWrite(waitGreen,    LOW);
  for (int t = greenTime; t > 0; t--) {
    delay(1000);
    readSerialData();
  }
  digitalWrite(activeGreen,  LOW);
  digitalWrite(activeYellow, HIGH);
  delay(YELLOW_TIME * 1000);
  digitalWrite(activeYellow, LOW);
  digitalWrite(activeRed,    HIGH);
}

void setAllRed() {
  digitalWrite(LANE_A_RED,    HIGH);
  digitalWrite(LANE_A_YELLOW, LOW);
  digitalWrite(LANE_A_GREEN,  LOW);
  digitalWrite(LANE_B_RED,    HIGH);
  digitalWrite(LANE_B_YELLOW, LOW);
  digitalWrite(LANE_B_GREEN,  LOW);
}

void readSerialData() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      if (serialData.length() > 0) {
        int commaIndex = serialData.indexOf(',');
        if (commaIndex > 0) {
          int newA = serialData.substring(0, commaIndex).toInt();
          int newB = serialData.substring(commaIndex + 1).toInt();
          if (newA >= 0 && newA <= 10) laneA_cars = newA;
          if (newB >= 0 && newB <= 10) laneB_cars = newB;
        }
        serialData = "";
      }
    } else {
      serialData += c;
    }
  }
}