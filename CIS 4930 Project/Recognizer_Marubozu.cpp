#include "pch.h"
#include "Recognizer_Marubozu.h"

Recognizer_Marubozu::Recognizer_Marubozu() : Recognizer("Marubozu", 1)
{
}

bool Recognizer_Marubozu::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}