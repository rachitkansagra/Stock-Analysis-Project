#include "pch.h"
#include "Recognizer_Valley.h"

// Constructor for the Valley recognizer
Recognizer_Valley::Recognizer_Valley() : Recognizer("Valley", 3)
{
}

// Recognize function for the Valley recognizer
bool Recognizer_Valley::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ third_scs = lscs[CurrentIndex]; // Get the current candlestick
	smartcandlestick^ second_scs = lscs[CurrentIndex - 1]; // Get the previous candlestick
	smartcandlestick^ first_scs = lscs[CurrentIndex - 2]; // Get the candlestick before the previous candlestick

	bool ReturnedValue; // Variable to store the value of the pattern
	if (third_scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{
		// Calculate and return the value of the pattern
		return (second_scs->Low < first_scs->Low && second_scs->Low < third_scs->Low);
	}
}