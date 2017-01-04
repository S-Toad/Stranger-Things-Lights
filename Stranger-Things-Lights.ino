#include <Adafruit_NeoPixel.h>

#define LED_LENGTH 50
#define ALPHABET_LENGTH 26
#define DATA_PIN 6

// milliseconds
#define LETTER_DELAY 750
#define MESSAGE_DELAY 30000

Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(LED_LENGTH, DATA_PIN, NEO_RGB + NEO_KHZ400);

uint32_t charColorArray[ALPHABET_LENGTH];

String messages[20];
int amountOfMessages;

void setup()
{
	Serial.begin(9600);
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
  addMessage("abcdefghijklmnopqrstuvwxyz");
  addMessage("noescape");
  addMessage("demogorgon");
}

void loop()
{
	showMessage();
  delay(1000);
	flash();
	delay(MESSAGE_DELAY);
  clearLEDs();
}

void addMessage(String msg)
{
	amountOfMessages++;
	messages[amountOfMessages - 1] = msg;
}

void showMessage()
{
	// Generates a random int between 0 and the amount
	// of the messages
	int randMsg = random(amountOfMessages);

	String randomString = messages[randMsg];

	for (int i = 0; i < randomString.length(); i++)
	{
		// 97 is the int value of a, we need a to be
		// considered 0, b = 1, and etc.
		int ledValue = getLedValue(randomString[i]);
    int charValue = (int)randomString[i] - 97;
   
		// Grabs the character's corresponding color
		uint32_t color = charColorArray[charValue];

		// Sets that LED to that color
		ledStrip.setPixelColor(ledValue, color);

		// Updates LEDs
		ledStrip.show();

		// Waits
		delay(LETTER_DELAY);

		// Turns LED off for next iteration
		ledStrip.setPixelColor(ledValue, 0);
	}
	ledStrip.show();
}

void flash()
{
	for (int i = 0; i < LED_LENGTH; i++)
	{
		ledStrip.setPixelColor(i, charColorArray[random(ALPHABET_LENGTH)]);
		ledStrip.show();
	}
}

void clearLEDs()
{
	for (int i = 0; i < LED_LENGTH; i++)
	{
		ledStrip.setPixelColor(i, 0);
	}

	ledStrip.show();
}

// This code is very specific to my setup of LEDs (How they're wrapped on the wall)
int getLedValue(char c)
{
	int n = (int)c;
  n = n - 97;

	if (n <= 7)
	{
		return n;
	}
	else if (8 <= n && n <= 16)
	{
		return (28 - n);
	}
	else
	{
		return (n + 7);
	}
}

void createLedArray()
{
	// Constant Colors defined here
	uint32_t red = ledStrip.Color(255, 0, 0);
	uint32_t white = ledStrip.Color(255, 255, 255);
	uint32_t blue = ledStrip.Color(18, 82, 186);
	uint32_t purple = ledStrip.Color(177, 18, 186);
	uint32_t green = ledStrip.Color(30, 153, 55);
	uint32_t yellow = ledStrip.Color(239, 239, 21);
	uint32_t teal = ledStrip.Color(80, 208, 237);

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
