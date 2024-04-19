#include "pch.h"
#include "Recognizer_Hammer.h"

Recognizer_Hammer::Recognizer_Hammer() : Recognizer("Hammer", 1)
{
}

bool Recognizer_Hammer::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];

	bool ReturnedValue;
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return (scs->UpperTail < (0.1 * scs->Range) && scs->BodyRange >= (0.15 * scs->Range) && scs->BodyRange <= (0.35 * scs->Range));
	}
}