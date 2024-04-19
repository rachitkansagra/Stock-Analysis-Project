#include "pch.h"
#include "Recognizer.h"

// Recognizer constructor
Recognizer::Recognizer(String^ pn, int pl) 
{
	PatternName = pn; // Name of the pattern
	PatternLength = pl; // Length of the pattern
}

// Recognize All method that recognizes all patterns in the list
void Recognizer::recognizeAll(List<smartcandlestick^>^ lscs)
{ 
	// Loop through the list of smart candlesticks
	for (int i = PatternLength - 1; i < lscs->Count; i++) 
	{
		lscs[i]->Patterns[PatternName] = Recognize(lscs, i); // Recognize the pattern and store it in the smart candlestick
	}
}