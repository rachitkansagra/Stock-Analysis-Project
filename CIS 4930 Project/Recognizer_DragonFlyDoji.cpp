#include "pch.h"
#include "Recognizer_DragonFlyDoji.h"

// Constructor for the DragonFlyDoji recognizer
Recognizer_DragonFlyDoji::Recognizer_DragonFlyDoji() : Recognizer("DragonFlyDoji", 1)
{
}

// Recognize function for the DragonFlyDoji recognizer
bool Recognizer_DragonFlyDoji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (scs->BodyRange < (scs->dojiBuffer * scs->Open) && scs->UpperTail < (scs->dojiBuffer * scs->Range));
	}
}