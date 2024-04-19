#include "pch.h"
#include "Recognizer_Marubozu.h"

// Constructor for the Marubozu recognizer
Recognizer_Marubozu::Recognizer_Marubozu() : Recognizer("Marubozu", 1)
{
}

// Recognize function for the Marubozu recognizer
bool Recognizer_Marubozu::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return Math::Abs(scs->BodyRange - scs->Range) < (0.01 * scs->Open);
	}
}