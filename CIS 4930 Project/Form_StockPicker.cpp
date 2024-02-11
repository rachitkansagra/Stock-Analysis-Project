#include "pch.h"
#include "Form_StockPicker.h"
#include "candlestick.h"

namespace CppCLRWinFormsProject {

	List<candlestick^>^ Form_StockPicker::ReadCandlestickData(String^ filePath)
	{

		List<candlestick^>^ resultingListOfCandlesticks = gcnew List<candlestick^>(1024);

		if (File::Exists(filePath))
		{
			StreamReader^ reader = gcnew StreamReader(filePath);
			String^ line = reader->ReadLine();
			while ((line = reader->ReadLine()) != nullptr)
			{
				candlestick^ singlecandlestick = gcnew candlestick(line);
				resultingListOfCandlesticks->Add(singlecandlestick);
			}
			reader->Close();
		}
		else
		{
			Console::WriteLine("File does not exist");
		}

		return resultingListOfCandlesticks;
	}

	BindingList<candlestick^>^ Form_StockPicker::FilterCandlestickData(List<candlestick^>^ loc)
	{
		List<candlestick^>^ TempListOfCandlesticks = gcnew List<candlestick^>(1024);
		for each (candlestick ^ candlestick in listOfCandlesticks)
		{
			if (candlestick->Date > EndDateTimePicker->Value)
			{
				break;
			}

			if (candlestick->Date >= StartDateTimePicker->Value && candlestick->Date <= EndDateTimePicker->Value)
			{
				TempListOfCandlesticks->Add(candlestick);
			}
		}

		BindingList<candlestick^>^ resultingBoundListOfCandlesticks = gcnew BindingList<candlestick^>(TempListOfCandlesticks);
		return resultingBoundListOfCandlesticks;
	}
}