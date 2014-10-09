int solenoid = 12; 
#define     IR_LED                 3         // Digital pin that is hooked up to the IR LED.
#define     IR_SENSOR              4    
#define     BUCKET_CHECK_SECONDS   0.1  //How often it checks to see if there is a hand.

///////////////////////////////////////////////////////
// Setup function
//
// Called once at start up.
///////////////////////////////////////////////////////
void setup(void){
   
  // Set up the input and output pins.
  pinMode(IR_LED, OUTPUT);
  pinMode(IR_SENSOR, INPUT);
  pinMode(solenoid, OUTPUT);
}

///////////////////////////////////////////////////////
// Loop Function
//
// Called continuously after setup function.
///////////////////////////////////////////////////////
void loop(void) {
  if (isHandinBucket()) {  
digitalWrite(solenoid, HIGH);
  }
  else
  {
    digitalWrite(solenoid, LOW);
  }

 // Delay for 100 milliseconds so the hand in bucket check happens 10 times a second.
  delay(100);
  }


///////////////////////////////////////////////////////
// isHandinBucket function
//
// Returns true if a hand is in the candy bucket
///////////////////////////////////////////////////////
boolean isHandinBucket() {
  // Pulse the IR LED at 38khz for 1 millisecond
  pulseIR(1000);

  // Check if the IR sensor picked up the pulse (i.e. output wire went to ground).
  if (digitalRead(IR_SENSOR) == LOW) {
    return false; // Sensor can see LED, return false.
  }

  return true; // Sensor can't see LED, return true.
}

///////////////////////////////////////////////////////
// pulseIR function
//
// Pulses the IR LED at 38khz for the specified number
// of microseconds.
///////////////////////////////////////////////////////
void pulseIR(long microsecs) {
  // 38khz IR pulse function from Adafruit tutorial: http://learn.adafruit.com/ir-sensor/overview
  
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IR_LED, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IR_LED, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
 
 
  sei();  // this turns them back on
  

  
  }


