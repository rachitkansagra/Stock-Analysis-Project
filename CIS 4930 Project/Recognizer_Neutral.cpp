#include "pch.h"
#include "Recognizer_Neutral.h"

Recognizer_Neutral::Recognizer_Neutral() : Recognizer("Neutral", 1)
{
}

bool Recognizer_Neutral::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];

	bool ReturnedValue;
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return scs->BodyRange >= (0.05 * scs->Range) && scs->BodyRange <= (0.25 * scs->Range);
	}
}