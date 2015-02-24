//declare pin values 
const int accelX = 0;
const int accelY = 1;
const int accelZ = 2;

const int gyroX = 3;
const int gyroY = 4;
const int gyroZ = 5;


//declare variables
const int sensorCount = 6; //convenience variable
int sensorVals[sensorCount]; //array to store 6DOF sensor values
const int sensorPins[sensorCount] = {accelX, accelY, accelZ, gyroX, gyroY, gyroZ}; //array to store pin values. This will be easier to process
String pinNames[6] = {"aX", "aY", "aZ", "gX", "gY", "gZ"};

void setup()
{
	Serial.begin(9600);
	digitalWrite(13, HIGH);
}

void loop()
{
	//read sensor data
	for (int i=0; i<sensorCount; i++){
		sensorVals[i] = analogRead(sensorPins[i]);
	}

	//write sensor data
	for (int i=0; i<sensorCount; i++){
		// Serial.print(pinNames[i]);
		// Serial.print(":");
		Serial.print(sensorVals[i]);
		if (i < sensorCount - 1) {
			Serial.print(", ");
		}
		else Serial.print("\n");
	}
}