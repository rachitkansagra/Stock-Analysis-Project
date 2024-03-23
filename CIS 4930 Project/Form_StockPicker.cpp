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
				smartcandlestick^ singlecandlestick = gcnew smartcandlestick(line); // Create a new candlestick object from the line.
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
		chart_OHLCV->DataSource = BoundListOfCandlesticks; // Set the data source of the chart to the binding list of candlestick objects.
		chart_OHLCV->DataBind(); // Bind the data to the chart.
	}

	void Form_StockPicker::ReadCandlestickData() {
		// Call the overloaded function to read candlestick data from a file and return a list of candlestick objects.
		listOfCandlesticks = ReadCandlestickData(StockDataFilePath);
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

		array<String^>^ FileNames = openFileDialog_LoadStock->FileNames; // Gets all the file names selected in the open file dialog.
		StockDataFilePath = FileNames[0]; // Set the stock data file path to the first file path.
		chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.
		Text = Path::GetFileNameWithoutExtension(StockDataFilePath); // Set the title of the form to the name of the stock file.

		ReadCandlestickData();  // Read candlestick data from a stock file.
		FilterCandlestickData(); // Filter candlestick data based on the start and end date time pickers.
		NormalizeCandlestickChart(); // Normalize the candlestick chart based on the max high and min low values of the candlestick data.
		DisplayCandlestickData(); // Display the candlestick data in the chart.
		InializeComboBox(); // Initialize the combo box with the patterns.

		for (int i = 1; i < FileNames->Length; i++) {

			Form_StockPicker^ NewStockPickerForm = gcnew Form_StockPicker(); // Create a new stock picker form.
			NewStockPickerForm->chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.

			NewStockPickerForm->StockDataFilePath = FileNames[i]; // Get the file path for this particular stock form.
			NewStockPickerForm->Text = Path::GetFileNameWithoutExtension(NewStockPickerForm->StockDataFilePath); // Set the title of the form to the name of the stock file.

			NewStockPickerForm->ReadCandlestickData(); // Read candlestick data from a stock file.			
			NewStockPickerForm->FilterCandlestickData(); // Filter candlestick data based on the start and end date time pickers.
			NewStockPickerForm->NormalizeCandlestickChart(); // Normalize the candlestick chart based on the max high and min low values of the candlestick data.
			NewStockPickerForm->DisplayCandlestickData(); // Display the candlestick data in the chart.
			NewStockPickerForm->InializeComboBox(); // Initialize the combo box with the patterns.
			NewStockPickerForm->Show(); // Show the stock picker form.
		}
	}

	System::Void Form_StockPicker::button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listOfCandlesticks != nullptr) // Check if the list of candlesticks is not null.
		{
			chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.
			comboBox_PatternSelector->Text = "";
			FilterCandlestickData(); // Filter candlestick data based on the new start and end date time pickers.
			NormalizeCandlestickChart(); // Normalize the candlestick chart based on the max high and min low values of the candlestick data.
			DisplayCandlestickData(); // Display the candlestick data in the data grid view and the chart.
		}
	}

	Void Form_StockPicker::InializeComboBox() {
		comboBox_PatternSelector->Items->Clear(); // Clear the items in the combo box.

		if (listOfCandlesticks != nullptr) // Check if the list of candlesticks is not null.
		{
			smartcandlestick^ scs = dynamic_cast<smartcandlestick^>(listOfCandlesticks[0]); // Get the first candlestick in the list as a smart candlestick.
			for each (String^ pattern in scs->Patterns->Keys)
			{
				comboBox_PatternSelector->Items->Add(pattern); // Add the pattern to the combo box.
			}
		}
		comboBox_PatternSelector->Text = ""; // Set empty text to the combo box.
	}

	System::Void Form_StockPicker::comboBox_PatternSelector_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.
		List<int> recognizedIndexes; // Create a list to store the recognized indexes.
		String^ selectedPattern = comboBox_PatternSelector->SelectedItem->ToString(); // Get the selected pattern from the combo box.

		for each (candlestick^ cs in BoundListOfCandlesticks)
		{
			smartcandlestick^ scs = dynamic_cast<smartcandlestick^>(cs); // Get the candlestick as a smart candlestick.

			if (scs->Patterns[selectedPattern]) // Check if smart candlestick satisfies the selected pattern.
			{
				recognizedIndexes.Add(BoundListOfCandlesticks->IndexOf(cs)); // Add the index of the recognized candlestick to the list.
			}
		}

		for each(int i in recognizedIndexes)
		{
			RectangleAnnotationFunc(i); // Draw a rectangle annotation for each recognized candlestick.
		}
	}

	System::Void Form_StockPicker::RectangleAnnotationFunc(int Index)
	{
		System::Windows::Forms::DataVisualization::Charting::RectangleAnnotation^ rectangle = gcnew System::Windows::Forms::DataVisualization::Charting::RectangleAnnotation(); // Create a new rectangle annotation object.
		System::Windows::Forms::DataVisualization::Charting::DataPoint^ current = chart_OHLCV->Series[0]->Points[Index]; // Get the current data point.
		double minY = current->YValues[1]; // Get the minimum Y value.
		double maxY = current->YValues[0]; // Get the maximum Y value.

		rectangle->ClipToChartArea = "ChartArea_OHLC"; // Set the chart area for the rectangle annotation.
		rectangle->AxisX = chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisX; // Set the X axis for the rectangle annotation.
		rectangle->AxisY = chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY; // Set the Y axis for the rectangle annotation.
		rectangle->IsSizeAlwaysRelative = false; // Set the size to be relative to the chart area false

		rectangle->BackColor = Color::FromArgb(100, Color::Blue); // Set the background color of the rectangle annotation.
		rectangle->ForeColor = Color::Transparent; // Set the foreground color of the rectangle annotation.
		rectangle->ShadowColor = Color::Transparent; // Set the shadow color of the rectangle annotation.

		rectangle->Width = 1; // Set the width of the rectangle annotation.
		rectangle->X = Index + 0.5; // Set the X value of the rectangle annotation.
		rectangle->Y = maxY; // Set the Y value of the rectangle annotation.
		rectangle->Height = minY - maxY; // Set the height of the rectangle annotation.

		chart_OHLCV->Annotations->Add(rectangle); // Add the rectangle annotation to the chart.
	}

	System::Void Form_StockPicker::button_clearPattern_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.
		comboBox_PatternSelector->Text = ""; // Set empty text to the combo box.
	}
}