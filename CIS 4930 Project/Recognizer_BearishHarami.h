#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

public ref class Recognizer_BearishHarami : Recognizer
{
	public:
	Recognizer_BearishHarami();

	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};