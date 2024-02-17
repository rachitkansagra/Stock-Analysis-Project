#pragma once
using namespace System;
using namespace System::Globalization;

// A class to represent a single candlestick
public ref class candlestick 
{
public:
	property DateTime Date; // The date of the candlestick
	property double Open; // The opening price of the candlestick
	property double High; // The highest price of the candlestick
	property double Low; // The lowest price of the candlestick
	property double Close; // The closing price of the candlestick
	property unsigned long long Volume; // The volume of the candlestick
	
	candlestick(String^ csvLine); // Constructor to create a candlestick from a CSV line
};

