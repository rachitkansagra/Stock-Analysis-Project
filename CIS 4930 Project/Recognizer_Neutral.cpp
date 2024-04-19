#include "pch.h"
#include "Recognizer_Neutral.h"

// Constructor for the Neutral recognizer
Recognizer_Neutral::Recognizer_Neutral() : Recognizer("Neutral", 1)
{
}

// Recognize function for the Neutral recognizer
bool Recognizer_Neutral::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex]; // Get the current candlestick

	bool ReturnedValue; // Variable to store the value of the pattern
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{
		// Calculate and return the value of the pattern
		return scs->BodyRange >= (0.05 * scs->Range) && scs->BodyRange <= (0.25 * scs->Range);
	}
}