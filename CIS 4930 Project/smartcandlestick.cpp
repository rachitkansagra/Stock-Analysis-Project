#include "pch.h"
#include "smartcandlestick.h"

// Constructor for the smartcandlestick class
smartcandlestick::smartcandlestick(String^ csvLine) : candlestick(csvLine)
{
	Patterns = gcnew Dictionary<String^, bool>(); // Initialize the patterns dictionary
	ComputeHigherProperties(); // Compute the higher properties
	//ComputePatterns(); // Compute the patterns
}

// Method to compute the higher properties of the candlestick
void smartcandlestick::ComputeHigherProperties()
{
	Range = High - Low; // Compute the range
	BodyRange = Math::Abs(Open - Close); // Compute the body range
	TopPrice = Math::Max(Open, Close); // Compute the top price
	BottomPrice = Math::Min(Open, Close); // Compute the bottom price
	UpperTail = Math::Max(High - TopPrice, 0.0); // Compute the upper tail
	LowerTail = Math::Max(BottomPrice - Low, 0.0); // Compute the lower tail
}

// Method to get the patterns of the candlestick
//void smartcandlestick::ComputePatterns()
//{
//    Patterns->Add("Bullish", isBullishcs()); // Add the bullish pattern to the dictionary
//    Patterns->Add("Bearish", isBearishcs()); // Add the bearish pattern to the dictionary
//    Patterns->Add("Neutral", isNeutralcs()); // Add the neutral pattern to the dictionary
//    Patterns->Add("Marubozu", isMarubozucs()); // Add the marubozu pattern to the dictionary
//    Patterns->Add("Doji", isDojics()); // Add the doji pattern to the dictionary
//    Patterns->Add("DragonFlyDoji", isDragonFlyDojics()); // Add the dragonfly doji pattern to the dictionary
//    Patterns->Add("GraveStoneDoji", isGraveStoneDojics()); // Add the gravestone doji pattern to the dictionary
//    Patterns->Add("Hammer", isHammercs()); // Add the hammer pattern to the dictionary
//    Patterns->Add("InvertedHammer", isInvertedHammercs()); // Add the inverted hammer pattern to the dictionary
//}
//
//// Method to check if the candlestick is bullish
//bool smartcandlestick::isBullishcs()
//{
//    return Open < Close;
//}
//
//// Method to check if the candlestick is bearish
//bool smartcandlestick::isBearishcs()
//{
//    return Open > Close;
//}
//
//// Method to check if the candlestick is neutral
//bool smartcandlestick::isNeutralcs()
//{
//    return BodyRange >= (0.05 * Range) && BodyRange <= (0.25 * Range);
//}
//
//// Method to check if the candlestick is a marubozu
//bool smartcandlestick::isMarubozucs()
//{
//    return Math::Abs(BodyRange - Range) < (0.01 * Open);
//}
//
//// Method to check if the candlestick is a doji
//bool smartcandlestick::isDojics()
//{
//    return BodyRange < (dojiBuffer * Open);
//}
//
//// Method to check if the candlestick is a dragonfly doji
//bool smartcandlestick::isDragonFlyDojics()
//{
//    return Patterns["Doji"] && UpperTail < (dojiBuffer * Range);
//}
//
//// Method to check if the candlestick is a gravestone doji
//bool smartcandlestick::isGraveStoneDojics()
//{
//    return Patterns["Doji"] && LowerTail < (dojiBuffer * Range);
//}
//
//// Method to check if the candlestick is a hammer
//bool smartcandlestick::isHammercs()
//{
//    return UpperTail < (0.1 * Range) && BodyRange >= (0.15 * Range) && BodyRange <= (0.35 * Range);
//}
//
//// Method to check if the candlestick is an inverted hammer
//bool smartcandlestick::isInvertedHammercs()
//{
//    return LowerTail < (0.1 * Range) && BodyRange >= (0.15 * Range) && BodyRange <= (0.35 * Range);
//}