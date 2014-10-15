#include <Servo.h> 
#include <LiquidCrystal.h>
 
Servo myservo;
int flag;

LiquidCrystal lcd(6, 7, 8, 9, 10, 11);


void setup() {
  Serial.begin(9600);
  flag = 0;
  lcd.begin(16, 2);
}


int getVal(String p){
  	return p.substring(3,6).toInt();
}

// Главный цикл
void loop() {
 
  String command;
  
  if (Serial.available()) {
      lcd.clear();
	while (Serial.available()) {
		command.concat(Serial.read()-48);
	}

       
       
       
       
		int param = command.substring(0,1).toInt();
		int pin = command.substring(1,3).toInt();
		int p;
                Serial.println(command);
                Serial.println(param);
                Serial.println(pin);
                //lcd.clear();
                lcd.print(command);
                
                
		switch (param) {
			case 0:
				pinMode(pin,OUTPUT);
				digitalWrite(pin, LOW);
		      	break;
		    case 1:
				pinMode(pin,OUTPUT);
				digitalWrite(pin, HIGH);
		      	break;
		    case '2':
				myservo.attach(pin);
				p = getVal(command);
				myservo.write(p);
		      	break;
		    case '3':
				pinMode(pin,INPUT);
				Serial.print(digitalRead(pin));
		      	break;
		    case '4': {
		    	int aPin = A0;
		    	switch (pin) {
		    		case 1: aPin = A1;	break;
		    		case 2: aPin = A2;	break;
		    		case 3: aPin = A3;	break;
		    		case 4: aPin = A4;	break;
		    		case 5: aPin = A5;	break;
		    		}
				Serial.print(analogRead(aPin));
				}
		      	break;
		    case '5':
				pinMode(pin,OUTPUT);
				p = getVal(command);
				analogWrite(pin, p);
		      	break;
		}
	}

}

