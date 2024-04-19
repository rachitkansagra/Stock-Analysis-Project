#include "pch.h"
#include "Recognizer_Bullish.h"

// Constructor for the Bullish recognizer
Recognizer_Bullish::Recognizer_Bullish() : Recognizer("Bullish", 1)
{
}

// Recognize function for the Bullish recognizer
bool Recognizer_Bullish::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex]; // Get the current candlestick

	bool ReturnedValue; // Variable to store the value of the pattern
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{
		return scs->Open < scs->Close; // Calculate and return the value of the pattern
	}
}