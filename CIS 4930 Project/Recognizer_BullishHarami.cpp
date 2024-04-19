#include "pch.h"
#include "Recognizer_BullishHarami.h"

Recognizer_BullishHarami::Recognizer_BullishHarami() : Recognizer("Bullish Harami", 2)
{
}

bool Recognizer_BullishHarami::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (first_scs->Patterns["Bearish"] && second_scs->Patterns["Bullish"] && first_scs->Open > second_scs->High && first_scs->Close < second_scs->Low);
	}
}