#include "pch.h"
#include "Recognizer_BearishEngulfing.h"

// Constructor for the Bearish Engulfing recognizer
Recognizer_BearishEngulfing::Recognizer_BearishEngulfing() : Recognizer("Bearish Engulfing", 2)
{
}

// Recognize function for the Bearish Engulfing recognizer
bool Recognizer_BearishEngulfing::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ second_scs = lscs[CurrentIndex]; // Get the current candlestick
	smartcandlestick^ first_scs = lscs[CurrentIndex - 1]; // Get the previous candlestick

	bool ReturnedValue; // Variable to store the value of the pattern
	if (second_scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{
		// Calculate and return the value of the pattern
		return (first_scs->Patterns["Bullish"] && second_scs->Patterns["Bearish"] && first_scs->High < second_scs->High && first_scs->Low > second_scs->Low);
	}
}