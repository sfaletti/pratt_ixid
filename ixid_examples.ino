//polls analog pin with a pot or similar
//prints the analog value to the Serial port

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
	//read analog pin with potentiometer
	potVal = analogRead(potPin);
	Serial.println(potVal);

	delay(10); //delay keeps things more stable
}