#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "smartcandlestick.h"

// This is the base class for all pattern recognizers
public ref class Recognizer
{
public:
	property String^ PatternName; // Name of the pattern
	property int PatternLength; // Length of the pattern

	/// <summary>
	/// Constructor for the Recognizer class
	/// </summary>
	/// <param name="pn">: Name of the pattern</param>
	/// <param name="pl">: Length of the pattern</param>
	Recognizer(String^ pn, int pl);

	/// <summary>
	/// Pure virtual function to recognize a pattern at a given index
	/// </summary>
	/// <param name="lscs">: List of smartcandlesticks</param>
	/// <param name="CurrentIndex">: Current index to recognize the pattern</param>
	/// <returns> True if the pattern is recognized, false otherwise</returns>
	virtual bool Recognize(List<smartcandlestick^>^ lscs, int CurrentIndex) = 0;

	/// <summary>
	/// Recognize all patterns in the list of smartcandlesticks
	/// </summary>
	/// <param name="lscs">: List of smartcandlesticks</param>
	void recognizeAll(List<smartcandlestick^>^ lscs);
};

