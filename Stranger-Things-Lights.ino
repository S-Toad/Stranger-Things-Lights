#include "Color.h"
#include <Adafruit_NeoPixel\Adafruit_NeoPixel.h>

#define ALPHABET_LENGTH 26
#define DATA_PIN 6

// milliseconds
#define LETTER_DELAY 250
#define MESSAGE_DELAY 20000

Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(ALPHABET_LENGTH, DATA_PIN, NEO_GRB + NEO_KHZ400);

Color charColorArray[ALPHABET_LENGTH];

String messages[20];
int amountOfMessages;

void setup()
{
	// Intializes our strip
	ledStrip.begin();
	// Updates our LED strip
	ledStrip.show();

	// Creates an array of colors
	createLedArray();

	amountOfMessages = 0;

	// Messages are added here, they all must be lowercase
	addMessage("run");
	addMessage("hide");
}

void loop()
{
	// Generates a random int between 0 and the amount
	// of the messages
	int randMsg = rand() % amountOfMessages;

	String randomString = messages[randMsg];

	for (int i = 0; i < randomString.length; i++)
	{
		char character = randomString[i];

		// 97 is the int value of a, we need a to be 
		// considered 0, b = 1, and etc.
		int charValue = (int)character - 97;

		// Grabs the character's corresponding color
		Color color = charColorArray[charValue];

		// Sets that LED to that color
		ledStrip.setPixelColor(charValue, color.R, color.G, color.B);

		// Updates LEDs
		ledStrip.show();

		// Waits
		delayMicroseconds(LETTER_DELAY);

		// Turns LED off for next iteration
		ledStrip.setPixelColor(charValue, 0);
	}

	// Delays the messages
	delayMicroseconds(MESSAGE_DELAY);
}

void addMessage(String msg)
{
	amountOfMessages++;
	messages[amountOfMessages - 1] = msg;
}

void createLedArray()
{
	// Constant Colors defined here
	Color red = Color(255, 0, 0);
	Color white = Color(255, 255, 255);
	Color blue = Color(18, 82, 186);
	Color purple = Color(177, 18, 186);
	Color green = Color(30, 153, 55);
	Color yellow = Color(239, 239, 21);
	Color teal = Color(80, 208, 237);

	// Colors are mapped to the show
	// Where 0 = a, 1 = b, etc.
	charColorArray[0] = white;
	charColorArray[1] = blue;
	charColorArray[2] = purple;
	charColorArray[3] = green;
	charColorArray[4] = teal;
	charColorArray[5] = yellow;
	charColorArray[6] = purple;
	charColorArray[7] = green;
	charColorArray[8] = green;
	charColorArray[9] = purple;
	charColorArray[10] = teal;
	charColorArray[11] = green;
	charColorArray[12] = yellow;
	charColorArray[13] = purple;
	charColorArray[14] = purple;
	charColorArray[15] = green;
	charColorArray[16] = purple;
	charColorArray[17] = green;
	charColorArray[18] = white;
	charColorArray[19] = yellow;
	charColorArray[20] = blue;
	charColorArray[21] = purple;
	charColorArray[22] = blue;
	charColorArray[23] = yellow;
	charColorArray[24] = purple;
	charColorArray[25] = purple;
}