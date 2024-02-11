#include "pch.h"
#include "candlestick.h"

candlestick::candlestick(String^ csvLine)
{
	array<wchar_t>^ delimiters = { L','};
	array<String^>^ values = csvLine->Split(delimiters, StringSplitOptions::RemoveEmptyEntries);
	//array<String^>^ values = csvLine->Split(',');

	if (values->Length == 7)
	{
		Date = DateTime::ParseExact(values[0], "yyyy-MM-dd", CultureInfo::InvariantCulture);
		Open = Double::Parse(values[1], CultureInfo::InvariantCulture);
		High = Double::Parse(values[2], CultureInfo::InvariantCulture);
		Low = Double::Parse(values[3], CultureInfo::InvariantCulture);
		Close = Double::Parse(values[4], CultureInfo::InvariantCulture);
		Volume = Int64::Parse(values[6]);
	}
}