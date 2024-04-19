#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

// This class recognizes the Marubozu pattern
public ref class Recognizer_Marubozu : Recognizer
{
	public:

	/// <summary>
	/// Constructor for the Recognizer_Marubozu class
	/// </summary>
	Recognizer_Marubozu();

	/// <summary>
	/// Overrides the Recognize function in the base class to recognize the Marubozu pattern
	/// </summary>
	/// <param name="lscs">: List of smartcandlesticks</param>
	/// <param name="CurrentIndex">: Current index to recognize the pattern</param>
	/// <returns> True if the pattern is recognized, false otherwise</returns>
	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};

