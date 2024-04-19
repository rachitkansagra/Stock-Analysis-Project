#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "candlestick.h"

// this class is a subclass of the candlestick class
public ref class smartcandlestick : candlestick
{
public:
	property double Range; // The Range of the candlestick
	property double BodyRange; // The Body Range of the candlestick
	property double TopPrice; // The Top price of the candlestick
	property double BottomPrice; // The Bottom price of the candlestick
	property double UpperTail; // The Upper Tail of the candlestick
	property double LowerTail; // The Lower Tail of the candlestick
	property Dictionary<String^, bool>^ Patterns; // Dictionary to store the patterns of the candlestick

	static double dojiBuffer = 0.02; // Buffer for the doji pattern

	/// <summary>
	/// Constructor for the smartcandlestick class
	/// </summary>
	/// <param name="csvLine">: A single line from a CSV file</param>
	smartcandlestick(String^ csvLine);

	/// <summary>
	/// Method to compute the higher properties of the candlestick
	/// </summary>
	void ComputeHigherProperties();
};