#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "smartcandlestick.h"

public ref class Recognizer
{
public:
	property String^ PatternName;
	property int PatternLength;

	Recognizer(String^ pn, int pl);

	virtual bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) = 0;
};

