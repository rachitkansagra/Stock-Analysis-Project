#include "pch.h"
#include "Recognizer_Bullish.h"

Recognizer_Bullish::Recognizer_Bullish() : Recognizer("Bullish", 1)
{
}

bool Recognizer_Bullish::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}