    
int inputPin=4;  // define ultrasonic signal receiver pin  ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin  TRIG to D5
String Sdata;
unsigned long ldata;
long Z;
int pin=0;
      void setup()
      {
        Serial.begin(9600);
        pinMode(inputPin, INPUT);
        pinMode(outputPin, OUTPUT);
        ldata=934;Z=2;
       }
     void loop(){
      while(Serial.available() >0){
        Sdata+=char(Serial.read());
        delay(4);
      }
      if (Sdata.length() >0){
        ldata=strtoul(Sdata.c_str(),NULL,10);
        ldata=ldata*9.4+944;
        Serial.println(ldata);
         Z=1;
      }
          if (Sdata=="stop"){
            Z=0;
          }else if (Sdata=="start"){
            Z=2;
          }
          Sdata="";
      if (Z==1){
       digitalWrite(outputPin, HIGH);
     delay(24);//300-420 //delay(29);400-500
     delayMicroseconds(ldata);
       digitalWrite(outputPin, LOW);
    Serial.println(ldata);
      }else if(Z==2){
      digitalWrite(outputPin, HIGH);
     delay(24);//300-420 //delay(29);400-500
     delayMicroseconds(ldata);
     digitalWrite(outputPin, LOW);
    Serial.println(ldata);
    ldata=ldata+1;
   }
}
