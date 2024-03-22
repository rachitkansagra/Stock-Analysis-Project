#include "pch.h"
#include "smartcandlestick.h"
#include "candlestick.h"

// Constructor for the smartcandlestick class
smartcandlestick::smartcandlestick(String^ csvLine) : candlestick(csvLine)
{
	Patterns = gcnew Dictionary<String^, bool>();
	ComputeHigherProperties();
	ComputePatterns();
}

void smartcandlestick::ComputeHigherProperties()
{
	Range = High - Low;
	BodyRange = Math::Abs(Open - Close);
	TopPrice = Math::Max(Open, Close);
	BottomPrice = Math::Min(Open, Close);
	UpperTail = Math::Max(High - TopPrice, 0.0);
	LowerTail = Math::Max(BottomPrice - Low, 0.0);
}

void smartcandlestick::ComputePatterns()
{
    Patterns->Add("Bullish", isBullishcs());
    Patterns->Add("Bearish", isBearishcs());
    Patterns->Add("Neutral", isNeutralcs());
    Patterns->Add("Marubozu", isMarubozucs());
    Patterns->Add("Doji", isDojics());
    Patterns->Add("DragonFlyDoji", isDragonFlyDojics());
    Patterns->Add("GraveStoneDoji", isGraveStoneDojics());
    Patterns->Add("Hammer", isHammercs());
    Patterns->Add("InvertedHammer", isInvertedHammercs());
}

// Method to check if the candlestick is bullish
bool smartcandlestick::isBullishcs()
{
    return Open < Close;
}

// Method to check if the candlestick is bearish
bool smartcandlestick::isBearishcs()
{
    return Open > Close;
}

// Method to check if the candlestick is neutral
bool smartcandlestick::isNeutralcs()
{
    return BodyRange >= (0.05 * Range) && BodyRange <= (0.25 * Range);
}

// Method to check if the candlestick is a marubozu
bool smartcandlestick::isMarubozucs()
{
    return Math::Abs(BodyRange - Range) < (0.01 * Open);
}

// Method to check if the candlestick is a doji
bool smartcandlestick::isDojics()
{
    return BodyRange < (dojiBuffer * Open);
}

// Method to check if the candlestick is a dragonfly doji
bool smartcandlestick::isDragonFlyDojics()
{
    return Patterns["Doji"] && UpperTail < (dojiBuffer * Range);
}

// Method to check if the candlestick is a gravestone doji
bool smartcandlestick::isGraveStoneDojics()
{
    return Patterns["Doji"] && LowerTail < (dojiBuffer * Range);
}

// Method to check if the candlestick is a hammer
bool smartcandlestick::isHammercs()
{
    return UpperTail < (0.1 * Range) && BodyRange >= (0.15 * Range) && BodyRange <= (0.35 * Range);
}

// Method to check if the candlestick is an inverted hammer
bool smartcandlestick::isInvertedHammercs()
{
    return LowerTail < (0.1 * Range) && BodyRange >= (0.15 * Range) && BodyRange <= (0.35 * Range);
}