#include "pch.h"
#include "candlestick.h"

// Constructor for the candlestick class
candlestick::candlestick(String^ csvLine)
{
	array<wchar_t>^ delimiters = { L','}; // Delimiters for the CSV file
	array<String^>^ values = csvLine->Split(delimiters, StringSplitOptions::RemoveEmptyEntries); // Split the CSV line into an array of strings

	if (values->Length == 7) // If the array has 7 elements
	{
		Date = DateTime::ParseExact(values[0], "yyyy-MM-dd", CultureInfo::InvariantCulture); // Parse the date and store it in the Date property
		Open = Double::Parse(values[1], CultureInfo::InvariantCulture); // Parse the open price and store it in the Open property
		High = Double::Parse(values[2], CultureInfo::InvariantCulture); // Parse the high price and store it in the High property
		Low = Double::Parse(values[3], CultureInfo::InvariantCulture); // Parse the low price and store it in the Low property
		Close = Double::Parse(values[4], CultureInfo::InvariantCulture); // Parse the close price and store it in the Close property
		Volume = Int64::Parse(values[6]); // Parse the volume and store it in the Volume property
	}
}