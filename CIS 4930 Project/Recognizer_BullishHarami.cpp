#include "pch.h"
#include "Recognizer_BullishHarami.h"

// Constructor for the Bullish Harami recognizer
Recognizer_BullishHarami::Recognizer_BullishHarami() : Recognizer("Bullish Harami", 2)
{
}

// Recognize function for the Bullish Harami recognizer
bool Recognizer_BullishHarami::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (first_scs->Patterns["Bearish"] && second_scs->Patterns["Bullish"] && first_scs->Open > second_scs->High && first_scs->Close < second_scs->Low);
	}
}