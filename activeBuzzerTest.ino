int buzzPin = 8;
int readPin = A0;
int valueRead; //value, read from readPin (is controlled by potentiometer)
int maxValueRead = 1023;
int minBuzzingTime = 0; //the higher this is, the more annoying the sound
int buzzingTime;
int maxBuzzingTime = 500; //the higher this is, the more annoying the sound
int pauses[] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597}; //modify this array to set different rythm (all values in milliseconds)
int pauseIndex = 0; //this used to point to the needed element of array pauses[]



void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pauseIndex+=1;
  pauseIndex%=sizeof(pauses)/sizeof(int);

  valueRead = analogRead(readPin);
  buzzingTime = int(float(maxBuzzingTime - minBuzzingTime)/float(maxValueRead) * float(valueRead));


  if (buzzingTime>0) {
    digitalWrite(buzzPin, HIGH);
    delay(buzzingTime);
    digitalWrite(buzzPin, LOW);
    delay(pauses[pauseIndex]);
  }
  Serial.println("Reading from pin: "+ String(valueRead) + " *** Applied buzzing time " + String(buzzingTime));
  if (buzzingTime == 0) delay(100);
}
