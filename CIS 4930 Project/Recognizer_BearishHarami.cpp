#include "pch.h"
#include "Recognizer_BearishHarami.h"

// Constructor for the Bearish Harami recognizer
Recognizer_BearishHarami::Recognizer_BearishHarami() : Recognizer("Bearish Harami", 2)
{
}

// Recognize function for the Bearish Harami recognizer
bool Recognizer_BearishHarami::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ second_scs = lscs[CurrentIndex]; // Get the current candlestick
	smartcandlestick^ first_scs = lscs[CurrentIndex - 1]; // Get the previous candlestick

	bool ReturnedValue; // Variable to store the value of the pattern
	if (second_scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{	// Calculate and return the value of the pattern
		return (first_scs->Patterns["Bullish"] && second_scs->Patterns["Bearish"] && first_scs->Close > second_scs->High && first_scs->Open < second_scs->Low);
	}

}