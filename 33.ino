// Project 33 - Touchscreen control of two LEDs

int x, y;

const int ledY = 9;  // brightness from Y-axis
const int ledX = 10;  // brightness from X-axis

// -------- Read X Axis --------
int readX()
{
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);

  digitalWrite(A1, LOW);  // X- to GND
  digitalWrite(A3, HIGH);  // X+ to 5V
  delay(5);

  return analogRead(A0);
}

// -------- Read Y Axis --------
int readY()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);

  digitalWrite(A0, LOW);  // Y- to GND
  digitalWrite(A2, HIGH);  // Y+ to 5V
  delay(5);

  return analogRead(A1);
}

// -------- Setup --------
void setup()
{
  Serial.begin(9600);
  pinMode(ledX, OUTPUT);
  pinMode(ledY, OUTPUT);
}

// -------- Loop --------
void loop()
{
  x = readX();
  y = readY();

  int brightnessX = map(x, 0, 1023, 0, 255);
  int brightnessY = map(y, 0, 1023, 0, 255);

  brightnessX = constrain(brightnessX, 0, 255);
  brightnessY = constrain(brightnessY, 0, 255);

  analogWrite(ledX, brightnessX);
  analogWrite(ledY, brightnessY);

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("  LED X: ");
  Serial.print(brightnessX);

  Serial.print("  Y: ");
  Serial.print(y);
  Serial.print("  LED Y: ");
  Serial.println(brightnessY);

  delay(200);
}

