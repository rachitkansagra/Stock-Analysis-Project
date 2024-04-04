#include "pch.h"
#include "Recognizer_InvertedHammer.h"

Recognizer_InvertedHammer::Recognizer_InvertedHammer() : Recognizer("InvertedHammer", 1)
{
}

bool Recognizer_InvertedHammer::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}