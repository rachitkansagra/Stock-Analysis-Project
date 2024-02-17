#include "pch.h"
#include "Form_StockPicker.h"
#include "candlestick.h"

namespace CppCLRWinFormsProject {

	// This function reads candlestick data from a file and returns a list of candlestick objects.
	List<candlestick^>^ Form_StockPicker::ReadCandlestickData(String^ filePath)
	{
		// Create a new list to store the resulting candlestick objects.
		List<candlestick^>^ resultingListOfCandlesticks = gcnew List<candlestick^>(1024);

		if (File::Exists(filePath))  // Check if the file exists.
		{
			StreamReader^ reader = gcnew StreamReader(filePath); // Open the file for reading.
			String^ line = reader->ReadLine(); // Read the first line (header line) of the file.
			while ((line = reader->ReadLine()) != nullptr) // Read the rest of the lines in the file until the end.
			{
				candlestick^ singlecandlestick = gcnew candlestick(line); // Create a new candlestick object from the line.
				resultingListOfCandlesticks->Add(singlecandlestick); // Add the new candlestick object to the list.
			}
			reader->Close(); // Close the file.
		}
		else
		{
			Console::WriteLine("File does not exist"); // Print an error message to the console if File Not Found.
		}

		return resultingListOfCandlesticks; // Return the list of candlestick objects.
	}

	// This function filters a list of candlestick objects based on the start and end date time pickers.
	BindingList<candlestick^>^ Form_StockPicker::FilterCandlestickData(List<candlestick^>^ loc)
	{
		// Create a new list to store the resulting filtered candlestick objects.
		List<candlestick^>^ TempListOfCandlesticks = gcnew List<candlestick^>();
		for each (candlestick ^ candlestick in listOfCandlesticks) // Loop through each candlestick in the list.
		{
			if (candlestick->Date > EndDateTimePicker->Value) // If the candlestick date is greater than the end date time picker value, break the loop.
			{
				break;
			}

			if (candlestick->Date >= StartDateTimePicker->Value && candlestick->Date <= EndDateTimePicker->Value)
			{  // If the candlestick date is greater than or equal to the start date time picker value and less than or equal to the end date time picker value, add the candlestick to the list.
				TempListOfCandlesticks->Add(candlestick);
			}
		}

		// Create a new binding list to store the resulting filtered candlestick objects.
		BindingList<candlestick^>^ resultingBoundListOfCandlesticks = gcnew BindingList<candlestick^>(TempListOfCandlesticks);
		return resultingBoundListOfCandlesticks; // Return the binding list of candlestick objects.
	}

	// This function normalizes the candlestick chart based on the max high and min low values of the candlestick data.
	void Form_StockPicker::NormalizeCandlestickChart(BindingList<candlestick^>^ bloc) {

		if(bloc ->Count == 0) // If the binding list of candlesticks is empty, return.
		{
			return;
		}

		double maxHigh = bloc[0]->High; // Set the max high value to the first candlestick high value.
		double minLow = bloc[0]->Low; // Set the min low value to the first candlestick low value.

		for each (candlestick ^ candlestick in bloc) // Loop through each candlestick in the list.
		{
			if(candlestick->High > maxHigh) 
			{	// If the candlestick high value is greater than the max high value, set the max high value to the candlestick high value.
				maxHigh = candlestick->High;
			}

			if (candlestick->Low < minLow)
			{	// If the candlestick low value is less than the min low value, set the min low value to the candlestick low value.
				minLow = candlestick->Low;
			}
		}

		maxHigh = maxHigh * 1.02; // Increase the max high value by 2%.
		minLow = minLow * 0.98; // Decrease the min low value by 2%.

		chart_OHLCV->ChartAreas[0]->AxisY->Maximum = maxHigh; // Set the maximum value of the y-axis to the max high value.
		chart_OHLCV->ChartAreas[0]->AxisY->Minimum = minLow; // Set the minimum value of the y-axis to the min low value.
	}

	// This function displays the candlestick data in the data grid view and the chart.
	void Form_StockPicker::DisplayCandlestickData() {
		dataGridViewCandlesticks->DataSource = BoundListOfCandlesticks; // Set the data source of the data grid view to the binding list of candlestick objects.
		chart_OHLCV->DataSource = BoundListOfCandlesticks; // Set the data source of the chart to the binding list of candlestick objects.
		chart_OHLCV->DataBind(); // Bind the data to the chart.
	}

	void Form_StockPicker::ReadCandlestickData() {
		// Call the overloaded function to read candlestick data from a file and return a list of candlestick objects.
		listOfCandlesticks = ReadCandlestickData(openFileDialog_LoadStock->FileName);
	}


	void Form_StockPicker::FilterCandlestickData() {
		// Call the overloaded function to filter a list of candlestick objects based on the start and end date time pickers and return a binding list of candlestick objects.
		BoundListOfCandlesticks = FilterCandlestickData(listOfCandlesticks);
	}

	void Form_StockPicker::NormalizeCandlestickChart() {
		// Call the overloaded function to normalize the candlestick chart based on the max high and min low values of the candlestick data.
		NormalizeCandlestickChart(BoundListOfCandlesticks);
	}

	System::Void Form_StockPicker::button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show the open file dialog when Load Stock button is clicked.
		openFileDialog_LoadStock->ShowDialog();
	}

	System::Void Form_StockPicker::openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {

		ReadCandlestickData(); // Read candlestick data from a stock file.
		FilterCandlestickData(); // Filter candlestick data based on the start and end date time pickers.
		NormalizeCandlestickChart(); // Normalize the candlestick chart based on the max high and min low values of the candlestick data.
		DisplayCandlestickData(); // Display the candlestick data in the data grid view and the chart.
	}

	System::Void Form_StockPicker::button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listOfCandlesticks != nullptr) // Check if the list of candlesticks is not null.
		{
			FilterCandlestickData(); // Filter candlestick data based on the new start and end date time pickers.
			NormalizeCandlestickChart(); // Normalize the candlestick chart based on the max high and min low values of the candlestick data.
			DisplayCandlestickData(); // Display the candlestick data in the data grid view and the chart.
		}
	}
}