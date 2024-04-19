#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

// This class recognizes the BearishHarami pattern
public ref class Recognizer_BearishHarami : Recognizer
{
	public:

	/// <summary>
	/// Constructor for the Recognizer_BearishHarami class
	/// </summary>
	Recognizer_BearishHarami();

	/// <summary>
	/// Overrides the Recognize function in the base class to recognize the BearishHarami pattern
	/// </summary>
	/// <param name="lscs">: List of smartcandlesticks</param>
	/// <param name="CurrentIndex">: Current index to recognize the pattern</param>
	/// <returns> True if the pattern is recognized, false otherwise</returns>
	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};