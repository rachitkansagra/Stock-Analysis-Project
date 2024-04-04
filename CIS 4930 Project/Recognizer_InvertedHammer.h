#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

ref class Recognizer_InvertedHammer : Recognizer
{
	public:
	Recognizer_InvertedHammer();

	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};