#include "Bounce2.h"

// declare pins
const int buttonPin_1 = 3;
const int buttonPin_2 = 4;
const int buttonPin_3 = 5;
const int ledPin_1 = 10;
const int ledPin_2 = 11;

// declare input value variables
boolean ledVal_1 = false;
boolean ledVal_2 = false;
boolean switchVal = true;

// declare button object for easier edge detection
Bounce button_1 = Bounce();
Bounce button_switch = Bounce();

void setup()
{
	pinMode(buttonPin_1, INPUT_PULLUP);
	pinMode(buttonPin_2, INPUT_PULLUP);
	pinMode(buttonPin_3, INPUT_PULLUP);
	pinMode(ledPin_1, OUTPUT);
	pinMode(ledPin_2, OUTPUT);

	// set up Bounce object
	// digitalWrite(buttonPin_1, HIGH);
	button_1.attach(buttonPin_1);
	button_switch.attach(buttonPin_3);
	button_1.interval(5);
	button_switch.interval(5);
}

void loop()
{
	ledVal_2 = !digitalRead(buttonPin_2);

	button_1.update();
	if (button_1.fell()) {
		ledVal_1 = !ledVal_1;
	}

	button_switch.update();
	if (button_switch.fell()) {
		switchVal = !switchVal;
	}

	if (switchVal) { 
		digitalWrite(ledPin_1, ledVal_1);
		digitalWrite(ledPin_2, ledVal_2);
	}
	else {
		digitalWrite(ledPin_2, ledVal_1);
		digitalWrite(ledPin_1, ledVal_2);
	}
}
