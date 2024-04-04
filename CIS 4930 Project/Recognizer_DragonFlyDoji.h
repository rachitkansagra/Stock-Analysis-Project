#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

public ref class Recognizer_DragonFlyDoji : Recognizer
{
	public:
	Recognizer_DragonFlyDoji();

	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};