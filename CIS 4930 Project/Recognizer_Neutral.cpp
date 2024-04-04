#include "pch.h"
#include "Recognizer_Neutral.h"

Recognizer_Neutral::Recognizer_Neutral() : Recognizer("Neutral", 1)
{
}

bool Recognizer_Neutral::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}