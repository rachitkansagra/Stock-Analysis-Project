#include "pch.h"
#include "Recognizer_Valley.h"

Recognizer_Valley::Recognizer_Valley() : Recognizer("Valley", 3)
{
}

bool Recognizer_Valley::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ third_scs = lscs[CurrentIndex];
	smartcandlestick^ second_scs = lscs[CurrentIndex - 1];
	smartcandlestick^ first_scs = lscs[CurrentIndex - 2];

	bool ReturnedValue;
	if (third_scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return (second_scs->Low < first_scs->Low && second_scs->Low < third_scs->Low);
	}
}