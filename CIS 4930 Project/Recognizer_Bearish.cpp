#include "pch.h"
#include "Recognizer_Bearish.h"

// Constructor for the Bearish recognizer
Recognizer_Bearish::Recognizer_Bearish() : Recognizer("Bearish", 1)
{
}

// Recognize function for the Bearish recognizer
bool Recognizer_Bearish::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex]; // Get the current candlestick

	bool ReturnedValue; // Variable to store the value of the pattern
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{
		return scs->Open > scs->Close; // Calculate and return the value of the pattern
	}
}