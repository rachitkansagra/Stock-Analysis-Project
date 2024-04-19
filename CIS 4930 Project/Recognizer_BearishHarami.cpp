#include "pch.h"
#include "Recognizer_BearishHarami.h"

Recognizer_BearishHarami::Recognizer_BearishHarami() : Recognizer("Bearish Harami", 2)
{
}

bool Recognizer_BearishHarami::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
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
		return (first_scs->Patterns["Bullish"] && second_scs->Patterns["Bearish"] && first_scs->Close > second_scs->High && first_scs->Open < second_scs->Low);
	}

}