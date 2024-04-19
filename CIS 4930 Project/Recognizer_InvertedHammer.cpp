#include "pch.h"
#include "Recognizer_InvertedHammer.h"

// Constructor for the InvertedHammer recognizer
Recognizer_InvertedHammer::Recognizer_InvertedHammer() : Recognizer("InvertedHammer", 1)
{
}

// Recognize function for the InvertedHammer recognizer
bool Recognizer_InvertedHammer::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (scs->LowerTail < (0.1 * scs->Range) && scs->BodyRange >= (0.15 * scs->Range) && scs->BodyRange <= (0.35 * scs->Range));
	}
}