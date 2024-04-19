#include "pch.h"
#include "Recognizer_Marubozu.h"

Recognizer_Marubozu::Recognizer_Marubozu() : Recognizer("Marubozu", 1)
{
}

bool Recognizer_Marubozu::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];

	bool ReturnedValue;
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return Math::Abs(scs->BodyRange - scs->Range) < (0.01 * scs->Open);
	}
}