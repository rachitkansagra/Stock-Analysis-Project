#include "pch.h"
#include "Recognizer_Doji.h"

// Constructor for the Doji recognizer
Recognizer_Doji::Recognizer_Doji() : Recognizer("Doji", 1)
{
}

// Recognize function for the Doji recognizer
bool Recognizer_Doji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex]; // Get the current candlestick
	
	bool ReturnedValue; // Variable to store the value of the pattern
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue)) // If the pattern has already been recognized
	{
		return ReturnedValue; // Return the value of the pattern
	}
	else
	{
		return scs->BodyRange < (scs->dojiBuffer * scs->Open); // Calculate and return the value of the pattern
	}
}