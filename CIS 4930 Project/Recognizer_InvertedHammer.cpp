#include "pch.h"
#include "Recognizer_InvertedHammer.h"

Recognizer_InvertedHammer::Recognizer_InvertedHammer() : Recognizer("InvertedHammer", 1)
{
}

bool Recognizer_InvertedHammer::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];

	bool ReturnedValue;
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return (scs->LowerTail < (0.1 * scs->Range) && scs->BodyRange >= (0.15 * scs->Range) && scs->BodyRange <= (0.35 * scs->Range));
	}
}