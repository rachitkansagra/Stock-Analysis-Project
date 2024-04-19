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