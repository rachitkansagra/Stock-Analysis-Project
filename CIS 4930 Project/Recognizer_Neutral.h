#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

public ref class Recognizer_Neutral : Recognizer
{
	public:
	Recognizer_Neutral();

	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};