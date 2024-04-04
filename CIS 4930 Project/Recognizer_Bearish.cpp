#include "pch.h"
#include "Recognizer_Bearish.h"

Recognizer_Bearish::Recognizer_Bearish() : Recognizer("Bearish", 1)
{
}

bool Recognizer_Bearish::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}