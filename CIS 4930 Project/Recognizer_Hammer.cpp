#include "pch.h"
#include "Recognizer_Hammer.h"

Recognizer_Hammer::Recognizer_Hammer() : Recognizer("Hammer", 1)
{
}

bool Recognizer_Hammer::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}