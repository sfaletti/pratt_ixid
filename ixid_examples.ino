//polls analog pin with a pot or similar
//prints the analog value to the Serial port
//controls LEDs based on pot value

#include "Bounce2.h" //use Bounce library for button control

//declare pin values 
const int potPin = 0;
const int ledPin_1 = 10;
const int ledPin_2 = 11;
const int buttonPin_1 = 5;

//declare variables
int potVal = 0;
boolean toggleVal = false;
Bounce toggle_button = Bounce();

void setup()
{
	Serial.begin(9600); //start Serial

	pinMode(ledPin_1, OUTPUT);
	pinMode(ledPin_2, OUTPUT);

	//set up button. Pin first, then object
	pinMode(buttonPin_1, INPUT_PULLUP);
	toggle_button.attach(buttonPin_1);
	toggle_button.interval(5);

}

void loop()
{
	
	potVal = analogRead(potPin); //read analog pin with potentiometer
	potVal /= 4; //convert from 10-bit to 8-bit value
	
	Serial.println(potVal); //write converted value to Serial port

	//check toggle button
	toggle_button.update();
	if (toggle_button.fell()) {
		toggleVal = !toggleVal;
	}

	if (toggleVal) { 
	//write converted pot value to LED
		analogWrite(ledPin_2, potVal);
		analogWrite(ledPin_1, 255 - potVal);
	}
	else {
		analogWrite(ledPin_2, 255-potVal);
		analogWrite(ledPin_1, potVal);
	}

	delay(10); //delay keeps things more stable
}