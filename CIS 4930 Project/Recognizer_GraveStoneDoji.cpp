#include "pch.h"
#include "Recognizer_GraveStoneDoji.h"

// Constructor for the GraveStoneDoji recognizer
Recognizer_GraveStoneDoji::Recognizer_GraveStoneDoji() : Recognizer("GraveStoneDoji", 1)
{
}

// Recognize function for the GraveStoneDoji recognizer
bool Recognizer_GraveStoneDoji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (scs->BodyRange < (scs->dojiBuffer * scs->Open) && scs->LowerTail < (scs->dojiBuffer * scs->Range));
	}
}