//declare pin values 
const int potPin = 0;
const int pwmLEDPin = 10;
const int onLEDPin = 11;

//declare variables
unsigned long lastMillis = 0;
int elapsedTime = 0;

float dutyCycle = .5;
float freq = 1000.0 / 80;

boolean pwmVal = true;
boolean onVal = true;

void setup()
{
	pinMode(pwmLEDPin, OUTPUT);
	pinMode(onLEDPin, OUTPUT);
	digitalWrite(onLEDPin, onVal);
}

void loop()
{
	dutyCycle = float(analogRead(potPin)) / 1023.0;

	elapsedTime = millis() - lastMillis;
	
	if (elapsedTime > freq) { //reset time counter
		lastMillis = millis();
	}

	pwmVal = elapsedTime < freq * dutyCycle;

	digitalWrite(pwmLEDPin, pwmVal);
}