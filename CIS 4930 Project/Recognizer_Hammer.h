#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

public ref class Recognizer_Hammer : Recognizer
{
	public:
	Recognizer_Hammer();

	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};