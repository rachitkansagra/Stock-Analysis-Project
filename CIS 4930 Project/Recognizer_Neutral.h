#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "Recognizer.h"

// This class recognizes the Neutral pattern
public ref class Recognizer_Neutral : Recognizer
{
	public:

	/// <summary>
	/// Constructor for the Recognizer_Neutral class
	/// </summary>
	Recognizer_Neutral();

	/// <summary>
	/// Overrides the Recognize function in the base class to recognize the Neutral pattern
	/// </summary>
	/// <param name="lscs">: List of smartcandlesticks</param>
	/// <param name="CurrentIndex">: Current index to recognize the pattern</param>
	/// <returns> True if the pattern is recognized, false otherwise</returns>
	bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) override;
};