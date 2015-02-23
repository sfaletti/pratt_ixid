//polls analog pin with a pot or similar
//prints the analog value to the Serial port
//controls LEDs based on pot value

//declare pin values 
const int potPin = 0;
const int ledPin_1 = 10;
const int ledPin_2 = 11;

//declare variables
int potVal = 0;

void setup()
{
	Serial.begin(9600); //start Serial

	pinMode(ledPin_1, OUTPUT);
	pinMode(ledPin_2, OUTPUT);
}

void loop()
{
	
	potVal = analogRead(potPin); //read analog pin with potentiometer
	potVal /= 4; //convert from 10-bit to 8-bit value
	
	Serial.println(potVal); //write converted value to Serial port

	//convert pot value to 8 bit number and write to an LED
	analogWrite(ledPin_2, potVal);
	analogWrite(ledPin_1, 255 - potVal);

	delay(10); //delay keeps things more stable
}