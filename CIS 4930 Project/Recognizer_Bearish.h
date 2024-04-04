#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

public ref class Recognizer_Bearish : Recognizer
{
	public:
	Recognizer_Bearish();

	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};
