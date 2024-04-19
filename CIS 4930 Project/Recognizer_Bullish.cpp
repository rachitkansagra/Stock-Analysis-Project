#include "pch.h"
#include "Recognizer_Bullish.h"

Recognizer_Bullish::Recognizer_Bullish() : Recognizer("Bullish", 1)
{
}

bool Recognizer_Bullish::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];

	bool ReturnedValue;
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return scs->Open < scs->Close;
	}
}