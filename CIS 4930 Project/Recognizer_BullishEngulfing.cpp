#include "pch.h"
#include "Recognizer_BullishEngulfing.h"

// Constructor for the Bullish Engulfing recognizer
Recognizer_BullishEngulfing::Recognizer_BullishEngulfing() : Recognizer("Bullish Engulfing", 2)
{
}

// Recognize function for the Bullish Engulfing recognizer
bool Recognizer_BullishEngulfing::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (first_scs->Patterns["Bearish"] && second_scs->Patterns["Bullish"] && first_scs->High < second_scs->High && first_scs->Low > second_scs->Low);
	}
}