#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "candlestick.h"

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

	smartcandlestick(String^ csvLine); // Constructor to create a smart candlestick from a CSV line

	/// <summary>
	/// Method to compute the higher properties of the candlestick
	/// </summary>
	void ComputeHigherProperties();

	/// <summary>
	/// Method to compute the patterns of the candlestick
	/// </summary>
	void ComputePatterns();

	/// <summary>
	/// Method to check if the candlestick is bullish
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is bullish </returns>
	bool isBullishcs();

	/// <summary>
	/// Method to check if the candlestick is bearish
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is bearish </returns>
	bool isBearishcs();

	/// <summary>
	/// Method to check if the candlestick is neutral
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is neutral </returns>
	bool isNeutralcs();

	/// <summary>
	/// Method to check if the candlestick is a marubozu
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is a marubozu </returns>
	bool isMarubozucs();

	/// <summary>
	/// Method to check if the candlestick is a doji
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is a doji </returns>
	bool isDojics();

	/// <summary>
	/// Method to check if the candlestick is a dragonfly doji
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is a dragonfly doji </returns>
	bool isDragonFlyDojics();

	/// <summary>
	/// Method to check if the candlestick is a gravestone doji
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is a gravestone doji </returns>
	bool isGraveStoneDojics();

	/// <summary>
	/// Method to check if the candlestick is a hammer
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is a hammer </returns>
	bool isHammercs();

	/// <summary>
	/// Method to check if the candlestick is an inverted hammer
	/// </summary>
	/// <returns> A boolean value indicating if the candlestick is an inverted hammer </returns>
	bool isInvertedHammercs();
};