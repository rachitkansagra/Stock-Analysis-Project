#include "pch.h"
#include "Form1.h"

namespace CppCLRWinFormsProject {

	List<candlestick^>^ Form1::ReadCandlestickData(String^ filePath)
	{
		listOfCandlesticks = gcnew List<candlestick^>(1024);

		if (File::Exists(filePath))
		{
			StreamReader^ reader = gcnew StreamReader(filePath);
			String^ line = reader->ReadLine();
			while ((line = reader->ReadLine()) != nullptr)
			{
				candlestick^ singlecandlestick = gcnew candlestick(line);
				listOfCandlesticks->Add(singlecandlestick);
			}
			reader->Close();
		}
		else
		{
			Console::WriteLine("File does not exist");
		}

		BoundListOfCandlesticks = gcnew BindingList<candlestick^>(listOfCandlesticks);
		dataGridViewCandlesticks->DataSource = BoundListOfCandlesticks;
		return listOfCandlesticks;
	}
}