#include "pch.h"
#include "Recognizer_GraveStoneDoji.h"

Recognizer_GraveStoneDoji::Recognizer_GraveStoneDoji() : Recognizer("GraveStoneDoji", 1)
{
}

bool Recognizer_GraveStoneDoji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];

	bool ReturnedValue;
	if (scs->Patterns->TryGetValue(PatternName, ReturnedValue))
	{
		return ReturnedValue;
	}
	else
	{
		return (scs->BodyRange < (scs->dojiBuffer * scs->Open) && scs->LowerTail < (scs->dojiBuffer * scs->Range));
	}
}