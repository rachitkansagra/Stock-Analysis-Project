#pragma once
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
#include "candlestick.h"

public ref class smartcandlestick : candlestick
{
public:
	property double Range; // The opening price of the candlestick
	property double BodyRange; // The highest price of the candlestick
	property double TopPrice; // The lowest price of the candlestick
	property double BottomPrice; // The closing price of the candlestick
	property double UpperTail; // The volume of the candlestick
	property double LowerTail; // The volume of the candlestick
	property Dictionary<String^, bool>^ Patterns;

	static double dojiBuffer = 0.02;

	smartcandlestick(String^ csvLine);
	void ComputeHigherProperties();
	void ComputePatterns();
	bool isBullishcs();
	bool isBearishcs();
	bool isNeutralcs();
	bool isMarubozucs();
	bool isDojics();
	bool isDragonFlyDojics();
	bool isGraveStoneDojics();
	bool isHammercs();
	bool isInvertedHammercs();
};