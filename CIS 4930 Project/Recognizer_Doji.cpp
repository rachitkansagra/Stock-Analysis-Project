#include "pch.h"
#include "Recognizer_Doji.h"

Recognizer_Doji::Recognizer_Doji() : Recognizer("Doji", 1)
{
}

bool Recognizer_Doji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}