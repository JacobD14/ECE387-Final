// Jacob Decker
// ECE387 - Final Individual Project - Push Up Counter

/* 
 * Set your goal amount of reps, and then the program will keep track and notify you when you hit it.
 * The muscle sensor allows the user to get the most out of the push up by letting the user know
 *  via buzzer that they've gone down far enough and can come back up.
 */

 int counter = 0;
 int buzzerPin = 13;
 int set;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); 
  Serial.setTimeout(10);
}

void loop() {
  
  Serial.print("Enter the amount of pushups you want to do: ");
  
  while(set <= 0) {
    set = Serial.parseInt();
  }

  Serial.println(set);
  
  while (counter < set) {
    
    int muscleVal = analogRead(A0);

    if (muscleVal > 930) {
      tone(buzzerPin, 500);
      delay(500);
      noTone(buzzerPin);
      counter++;
      while(analogRead(A0) > 400);
      tone(buzzerPin, 1000);
      delay(500);
      noTone(buzzerPin);
      Serial.println(counter);
    }
    
  }
  tone(buzzerPin, 1000);
  delay(2000);
  noTone(buzzerPin);
  Serial.println("FINISHED");
  while(true);
}
