#include "pch.h"
#include "Recognizer_GraveStoneDoji.h"

Recognizer_GraveStoneDoji::Recognizer_GraveStoneDoji() : Recognizer("GraveStoneDoji", 1)
{
}

bool Recognizer_GraveStoneDoji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}