#include "pch.h"
#include "Recognizer_BearishEngulfing.h"

Recognizer_BearishEngulfing::Recognizer_BearishEngulfing() : Recognizer("Bearish Engulfing", 2)
{
}

bool Recognizer_BearishEngulfing::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (first_scs->Patterns["Bullish"] && second_scs->Patterns["Bearish"] && first_scs->High < second_scs->High && first_scs->Low > second_scs->Low);
	}
}