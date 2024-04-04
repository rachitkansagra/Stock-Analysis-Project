#include "pch.h"
#include "Recognizer_Peak.h"

Recognizer_Peak::Recognizer_Peak() : Recognizer("Peak", 3)
{
}

bool Recognizer_Peak::Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex)
{
	smartcandlestick^ third_scs = lscs[CurrentIndex];
	smartcandlestick^ second_scs = lscs[CurrentIndex - 1];
	smartcandlestick^ first_scs = lscs[CurrentIndex - 2];
	return (second_scs->High > first_scs->High && second_scs->High > third_scs->High);
}