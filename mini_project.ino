#include<LiquidCrystal.h>
LiquidCrystal LCD(2,3,4,5,6,7);
int IR_pin1 = A0;
int IR_pin2 = A1;
float ReadValue1;
float ReadValue2;            
unsigned long start_time;
unsigned long end_time;
float time_taken;
float distance = 16.0;
float speed_vehicle;
int i;
void setup() {
  Serial.begin(9600);
  pinMode(IR_pin1,INPUT);
  pinMode(IR_pin2,INPUT);
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Speed");
  delay(1000);

}

void loop() {
  
   while(1){
    
    ReadValue1 = analogRead(A0);
    ReadValue2 = analogRead(A1);
     if(ReadValue1>100){
        start_time = millis();
        break;
   }
  }
 
    while(1){
      
       ReadValue1 = analogRead(A0);
       ReadValue2 = analogRead(A1);
      if(ReadValue2>100){
        end_time = millis();
        i=0;
        break;
      }
        }

        
    time_taken = (end_time-start_time) ;
    speed_vehicle = ((distance/time_taken)*1000);
    Serial.println("Speed in cm/s is  ");
    Serial.println(speed_vehicle); 
    LCD.setCursor(0,1);
 
    if(speed_vehicle<=50.0){
      LCD.setCursor(0,0);
      LCD.print("Speed       ");
      LCD.setCursor(0,1);
      LCD.print(speed_vehicle);
      LCD.print(" cm/s");
    }
    else{
      LCD.setCursor(0,0);
      LCD.print("OVERSPEEDING");
      LCD.setCursor(0,1);
      LCD.print(speed_vehicle);
      LCD.print(" cm/s");
        
    }
    }


    

  
