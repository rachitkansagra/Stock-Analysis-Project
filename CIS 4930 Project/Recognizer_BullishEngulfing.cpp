#include "pch.h"
#include "Recognizer_BullishEngulfing.h"

Recognizer_BullishEngulfing::Recognizer_BullishEngulfing() : Recognizer("Bullish Engulfing", 2)
{
}

bool Recognizer_BullishEngulfing::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ second_scs = lscs[CurrentIndex];
	smartcandlestick^ first_scs = lscs[CurrentIndex - 1];

	bool ReturnedValue;
	if (second_scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return (first_scs->Patterns["Bearish"] && second_scs->Patterns["Bullish"] && first_scs->High < second_scs->High && first_scs->Low > second_scs->Low);
	}
}