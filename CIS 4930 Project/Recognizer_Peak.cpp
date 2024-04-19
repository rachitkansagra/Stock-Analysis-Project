#include "pch.h"
#include "Recognizer_Peak.h"

// Constructor for the Peak recognizer
Recognizer_Peak::Recognizer_Peak() : Recognizer("Peak", 3)
{
}

// Recognize function for the Peak recognizer
bool Recognizer_Peak::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (second_scs->High > first_scs->High && second_scs->High > third_scs->High);
	}
}