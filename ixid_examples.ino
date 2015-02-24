//declare pin values 
const int potPin = 0;
const int ledPin = 10;
const int tonePin = 6;

//declare variables
int potVal = 0;
int ledVal = 0;
int toneFreq = 31;

//declare smoothing array variables
const int smoothLength = 20; //convenience variable
int smoothVals[smoothLength];

void setup()
{
	// Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
	pinMode(tonePin, OUTPUT);
}

void loop()
{
	potVal = analogRead(potPin); //read the pot

	// push reading onto average array
	for(int i=1; i<smoothLength; i++){
	    smoothVals[i-1] = smoothVals[i];
	}
	smoothVals[smoothLength-1] = potVal;

	ledVal = avgVals(smoothVals, smoothLength); //call the smoothing function
	
	analogWrite(ledPin, ledVal / 4); //turn on the LED

	toneFreq = map(ledVal, 0, 1023, 50, 600);
	tone(tonePin, toneFreq);

}

//function to handle averaging the array values
int avgVals(int _array[], int _arrayLength) {
	int avgVal = 0;
	for (int i=0; i<_arrayLength; i++) {
		avgVal += _array[i];
	}
	return avgVal / _arrayLength;
}