#define cm195   12401;
#define cm240   12600;
#define cm5   200006;
#define cm50 20100;
#define cm100 221636;
#define cm150 11328;
#define cm200 12422;
    int inputPin=4;  // define ultrasonic signal receiver pin  ECHO to D4
      int outputPin=5; // define ultrasonic signal transmitter pin  TRIG to D5
      String Sdata;
      unsigned long ldata;
      void setup()
      {
        Serial.begin(9600);
        pinMode(inputPin, INPUT);
        pinMode(outputPin, OUTPUT);
        ldata=200001;
       }
     void loop()
    {
      digitalWrite(outputPin, LOW);
        delayMicroseconds(2);
        digitalWrite(outputPin, HIGH); // Pulse for 10μs to trigger ultrasonic detection
        delayMicroseconds(10);
        digitalWrite(outputPin, LOW);  
        int distance = pulseIn(inputPin, HIGH);  // Read receiver pulse time
        distance= distance/58;   // Transform pulse time to distance
        Serial.println(distance);   //Ourput distance                
        delay(50); 
       /* int i =1;
        while(i){
       // digitalWrite(outputPin, LOW);
        //delayMicroseconds(2);
        digitalWrite(outputPin, HIGH); // 
        //delayMicroseconds(10);
        digitalWrite(outputPin, LOW); 
        ///.delayMicroseconds(12);
        }*/
        /*int distance = pulseIn(inputPin, HIGH); 
         if (distance){
             distance= distance/58;
             Serial.println(digitalRead(distance));
         }
    *//*while(Serial.available() >0){
        Sdata+=char(Serial.read());
        delay(4);
      }
      if (Sdata.length() >0){
        ldata=strtoul(Sdata.c_str(),NULL,10);
              Serial.println(ldata);
              Sdata="";
      }
         //digitalWrite(outputPin, LOW);
       digitalWrite(outputPin, HIGH);
      delayMicroseconds(ldata);
       digitalWrite(outputPin, LOW);
    // delayMicroseconds(2000);*/
     }
