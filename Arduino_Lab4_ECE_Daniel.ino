//Lab 3, Daniel Tikhonov November 8th 2026 ECE 1004

int pot0 = 0;
int pot1 = 1;
int leds[] = {9, 8, 7, 6, 5, 4, 3, 2}; 
//intial variables copied from the lab pdf

void setup() { //runs once
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
 pinMode(leds[i], OUTPUT); //sets all LEDs to output
  }
}

void loop() {
  // Read potentiometer values
  pot0 = analogRead(A0);
  pot1 = analogRead(A1);
  Serial.println(pot0); // Debug
 if (pot0 < 341) { //First estimate of the first third analog input range (0-341, relative to 0-1023)
 //Sequence 1 will Turn on ONE single light based on Pot 1's range
   sequence1(pot1);
 }

 else if (pot0 < 683) { //Rough estimate of the second third analog input range (from 342-683, relative to 0-1023)
 //Sequence 2 will turn on ALL lights based on Pot's 1 range
  for(int i=0; i < 8;i++){
    if((i*128) <= pot1){
      digitalWrite(leds[i], 1);
    }
    else{
      digitalWrite(leds[i], 0);
    }
  }
 } 
else { 
  for (int k = 0; k < 8; k++) { //3rd Sequence Implementation
    pot0 = analogRead(A0);          // re-read so changes take effect mid-wave
    pot1 = analogRead(A1);
    if (pot0 < 683) break;          // Pot 0 left the last third, so exit the wave
    allOff();
    digitalWrite(leds[k], HIGH);
    delay(speedOfDelay(pot1));
  }
}
}
void sequence1(int pot1){
  allOff();
  if (pot1 < 128)      { digitalWrite(leds[0], HIGH); }
  else if (pot1 < 256) { digitalWrite(leds[1], HIGH); }
  else if (pot1 < 384) { digitalWrite(leds[2], HIGH); }
  else if (pot1 < 512) { digitalWrite(leds[3], HIGH); }
  else if (pot1 < 640) { digitalWrite(leds[4], HIGH); }
  else if (pot1 < 768) { digitalWrite(leds[5], HIGH); }
  else if (pot1 < 896) { digitalWrite(leds[6], HIGH); }
  else                 { digitalWrite(leds[7], HIGH); }
}
 long speedOfDelay(int num){//This function Dynamically determines the speed of the light wave sequence
   return map(num, 0 , 1023, 60, 300);
}
 void allOff(){
      for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], LOW); //turns off all previous LEDS that were on before
 }
}