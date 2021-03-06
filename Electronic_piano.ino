#define analogInPin1 A3
#define analogInPin2 A4
#define analogInPin3 A5
#define speaker 8
#define EASY 2
#define MED 3
#define HARD 4
#define red 5 
#define green 6

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int easyques[4]={};
int easyanswer[4]={};
int medques[4]={};
int medanswer1[4]={};
int medanswer2[4]={};
int hardques[4]={};
int hardanswer1[4]={};
int hardanswer2[4]={};
int hardanswer3[4]={};
int i,j,k;

int frequency[] = {262, 277, 293, 311, 329, 349, 371, 392, 
                   416, 440, 467, 493, 523, 554, 587, 622, 
                   660, 698, 739, 783, 830, 880, 932, 987, 1046};


int upperLimit[] = {50, 150, 300, 450, 650, 
                    800, 900, 960, 1000};

int lowerLimit[] = {0, 51, 151, 301, 451, 
                    651, 801, 901, 961};

void setup() {
  pinMode (EASY,INPUT);
  pinMode (MED,INPUT);
  pinMode (HARD,INPUT);
  pinMode (speaker, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(EASY)== LOW){
  easyquestion();
  easyquestioncheck();
  }
  else if(digitalRead(MED)== LOW){
  medquestion();
  medquestioncheck();
  }
  else if(digitalRead(HARD)== LOW){
  hardquestion();
  hardquestioncheck();
  }
  else {
    readMelody();
  }
  
  //Serial.print("Value1 = ");
  //Serial.println(sensorValue1);
  //Serial.print("Value2 = ");
  //Serial.println(sensorValue2);
  //Serial.print("Value3 = ");
  //Serial.println(sensorValue3);
  Serial.println(frequency[i]);
}


void readMelody() {    
  sensorValue1 = analogRead(analogInPin1);   
  for(int i = 0; i<8; i++)
  {
    if (sensorValue1 < upperLimit[i]  && sensorValue1 >= lowerLimit[i]){
      tone(speaker,frequency[i],60);
    }
  }
  sensorValue2 = analogRead(analogInPin2);   
  for(int i = 0; i<8; i++)
  {
    if (sensorValue2 < upperLimit[i]  && sensorValue2 >= lowerLimit[i]){
      tone(speaker,frequency[i+8],60);
    }
  }
  sensorValue3 = analogRead(analogInPin3);   
  for(int i = 0; i<9; i++)
  {
    if (sensorValue3 < upperLimit[i]  && sensorValue3 >= lowerLimit[i]){
      tone(speaker,frequency[i+16],60);
    }
  } 
  
}

void easyquestion(){
   for(int j =0;j<4;j++){
    digitalWrite(speaker,HIGH);
    int randomfrequency = frequency[random(7)];
    easyques[j]=randomfrequency;
    tone(speaker,randomfrequency,300);
    digitalWrite(speaker,LOW);
    delay(500);
    Serial.println(easyques[j]); 
   }
 }

void easyquestioncheck(){
  for(k =0;k<4;k++){
    sensorValue1=1023;
      while (sensorValue1==1023){
      sensorValue1 = analogRead(analogInPin1);   
        for(i = 0; i<8; i++)
        {
          if (sensorValue1 < upperLimit[i]  && sensorValue1 >= lowerLimit[i]){
            tone(speaker,frequency[i],60);
            easyanswer[k]=frequency[i];
          }
        }
      }
    if(easyanswer[k] == easyques[k]){
    digitalWrite(red,HIGH);
    delay(200);
    digitalWrite(red,LOW);
    }
    if(easyanswer[k] != easyques[k]){
    digitalWrite(green,HIGH);
    delay(200);
    digitalWrite(green,LOW);
    }
  }
}

void medquestion(){
  for(int j =0;j<4;j++){
      digitalWrite(speaker,HIGH);
      int randomfrequency = frequency[random(15)];
      medques[j]=randomfrequency;
      tone(speaker,randomfrequency,300);
      digitalWrite(speaker,LOW);
      delay(500);
      Serial.println(medques[j]); 
   }
}

void medquestioncheck(){
  for(k =0;k<4;k++){
    sensorValue1=1023;
    sensorValue2=1023;
      while (sensorValue1==1023&&sensorValue2==1023){
        sensorValue1 = analogRead(analogInPin1);   
        for(i = 0; i<8; i++)
        {
          if (sensorValue1 < upperLimit[i]  && sensorValue1 >= lowerLimit[i]){
            tone(speaker,frequency[i],60);
            medanswer1[k]=frequency[i];
          }
          sensorValue2 = analogRead(analogInPin2);   
          for(int i = 0; i<8; i++)
          {
            if (sensorValue2 < upperLimit[i]  && sensorValue2 >= lowerLimit[i]){
              tone(speaker,frequency[i+8],60);
              medanswer2[k]=frequency[i+8];
            }
          }
        }
      }
    if(medanswer1[k] == medques[k]|| medanswer2[k] == medques[k]){
      digitalWrite(red,HIGH);
      delay(200);
      digitalWrite(red,LOW);
    }
    if(medanswer1[k] != medques[k]&& medanswer2[k] != medques[k]){
      digitalWrite(green,HIGH);
      delay(200);
      digitalWrite(green,LOW);
    }
  }
}

void hardquestion(){
  for(int j =0;j<4;j++){
      digitalWrite(speaker,HIGH);
      int randomfrequency = frequency[random(24)];
      hardques[j]=randomfrequency;
      tone(speaker,randomfrequency,300);
      digitalWrite(speaker,LOW);
      delay(500);
      Serial.println(hardques[j]); 
  }
}

void hardquestioncheck(){
  for(k =0;k<4;k++){
    sensorValue1=1023;
    sensorValue2=1023;
    sensorValue3=1023;
      while (sensorValue1==1023&&sensorValue2==1023&&sensorValue3==1023){
        sensorValue1 = analogRead(analogInPin1);   
        for(i = 0; i<8; i++)
        {
          if (sensorValue1 < upperLimit[i]  && sensorValue1 >= lowerLimit[i]){
            tone(speaker,frequency[i],60);
            hardanswer1[k]=frequency[i];
          }
          sensorValue2 = analogRead(analogInPin2);   
          for(int i = 0; i<8; i++)
          {
            if (sensorValue2 < upperLimit[i]  && sensorValue2 >= lowerLimit[i]){
              tone(speaker,frequency[i+8],60);
              hardanswer2[k]=frequency[i+8];
            }
          }
          sensorValue3 = analogRead(analogInPin3);   
          for(int i = 0; i<9; i++)
          {
            if (sensorValue3 < upperLimit[i]  && sensorValue3 >= lowerLimit[i]){
              tone(speaker,frequency[i+16],60);
              hardanswer3[k]=frequency[i+16];
            }
          } 
        }
      }
    if(hardanswer1[k] == hardques[k]|| hardanswer2[k] == hardques[k]|| hardanswer3[k] == hardques[k]){
      digitalWrite(red,HIGH);
      delay(200);
      digitalWrite(red,LOW);
    }
    if(hardanswer1[k] != hardques[k]&& hardanswer2[k] != hardques[k]&& hardanswer3[k] != hardques[k]){
      digitalWrite(green,HIGH);
      delay(200);
      digitalWrite(green,LOW);
    }
  }
}
           
   
  