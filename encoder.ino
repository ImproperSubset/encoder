/* Arduino New Rotary Encoder Debounce
 
Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...

You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/

// Rotary Encoder Module connections
const int PinCLK = 2;  // CLOCK signal
const int PinDT = 3;   // DATA signal

// Variables to debounce Rotary Encoder
long TimeOfLastDebounce = 0;
int DelayofDebounce = 0.01;

// Store previous Pins state
int PreviousCLK;
int PreviousDATA;

int displaycounter = 0;  // Store current counter value

void setup() {
  // Put current pins state in variables
  PreviousCLK = digitalRead(PinCLK);
  PreviousDATA = digitalRead(PinDT);

  Serial.begin(9600);
  delay(500);
}

void loop() {
  rotate(10);
  Serial.println("Down!");
  rotate(-10);
  Serial.println("Up!");
}

void rotate(int clicks) {
  int target = displaycounter + clicks;

  while (displaycounter != target) {
    // If enough time has passed check the rotary encoder
    if ((millis() - TimeOfLastDebounce) > DelayofDebounce) {

      check_rotary();  // Rotary Encoder check routine below

      PreviousCLK = digitalRead(PinCLK);
      PreviousDATA = digitalRead(PinDT);

      TimeOfLastDebounce = millis();  // Set variable to current millis() timer
    }
  }
}


// Check if Rotary Encoder was moved
void check_rotary() {

  if ((PreviousCLK == 0) && (PreviousDATA == 1)) {
    if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 0)) {
      displaycounter++;
      Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 1)) {
      displaycounter--;
      Serial.println(displaycounter);
    }
  }

  if ((PreviousCLK == 1) && (PreviousDATA == 0)) {
    if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 1)) {
      displaycounter++;
      Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 0)) {
      displaycounter--;
      Serial.println(displaycounter);
    }
  }

  if ((PreviousCLK == 1) && (PreviousDATA == 1)) {
    if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 1)) {
      displaycounter++;
      Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 0)) {
      displaycounter--;
      Serial.println(displaycounter);
    }
  }

  if ((PreviousCLK == 0) && (PreviousDATA == 0)) {
    if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 0)) {
      displaycounter++;
      Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 1)) {
      displaycounter--;
      Serial.println(displaycounter);
    }
  }
}
