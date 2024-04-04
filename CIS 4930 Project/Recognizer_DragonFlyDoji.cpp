#include "pch.h"
#include "Recognizer_DragonFlyDoji.h"

Recognizer_DragonFlyDoji::Recognizer_DragonFlyDoji() : Recognizer("DragonFlyDoji", 1)
{
}

bool Recognizer_DragonFlyDoji::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ scs = lscs[CurrentIndex];
	return scs->Patterns[PatternName];
}