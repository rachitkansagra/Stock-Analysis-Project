#include "pch.h"
#include "Form_StockPicker.h"
#include "candlestick.h"
#include "smartcandlestick.h"

namespace CppCLRWinFormsProject {

	// This function reads candlestick data from a file and returns a list of candlestick objects.
	List<smartcandlestick^>^ Form_StockPicker::ReadCandlestickData(String^ filePath)
	{
		// Create a new list to store the resulting candlestick objects.
		List<smartcandlestick^>^ resultingListOfCandlesticks = gcnew List<smartcandlestick^>(1024);

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
	BindingList<smartcandlestick^>^ Form_StockPicker::FilterCandlestickData(List<smartcandlestick^>^ loc)
	{
		// Create a new list to store the resulting filtered candlestick objects.
		List<smartcandlestick^>^ TempListOfCandlesticks = gcnew List<smartcandlestick^>();
		for each (smartcandlestick^ candlestick in loc) // Loop through each candlestick in the list.
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
		BindingList<smartcandlestick^>^ resultingBoundListOfCandlesticks = gcnew BindingList<smartcandlestick^>(TempListOfCandlesticks);
		return resultingBoundListOfCandlesticks; // Return the binding list of candlestick objects.
	}

	// This function normalizes the candlestick chart based on the max high and min low values of the candlestick data.
	void Form_StockPicker::NormalizeCandlestickChart(BindingList<smartcandlestick^>^ bloc) {

		if(bloc ->Count == 0) // If the binding list of candlesticks is empty, return.
		{
			return;
		}

		double maxHigh = bloc[0]->High; // Set the max high value to the first candlestick high value.
		double minLow = bloc[0]->Low; // Set the min low value to the first candlestick low value.

		for each (smartcandlestick ^ candlestick in bloc) // Loop through each candlestick in the list.
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

		Recognizers = gcnew List<Recognizer^>(); // Create a new list to store the recognizers.

		Recognizers->Add(gcnew Recognizer_Bullish()); // Add Bullish recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Bearish()); // Add Bearish recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Neutral()); // Add Neutral recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Marubozu()); // Add Marubozu recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Doji()); // Add Doji recognizer to the list.
		Recognizers->Add(gcnew Recognizer_DragonFlyDoji()); // Add DragonFlyDoji recognizer to the list.
		Recognizers->Add(gcnew Recognizer_GraveStoneDoji()); // Add GraveStoneDoji recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Hammer()); // Add Hammer recognizer to the list.
		Recognizers->Add(gcnew Recognizer_InvertedHammer()); // Add InvertedHammer recognizer to the list.
		Recognizers->Add(gcnew Recognizer_BullishEngulfing()); // Add BullishEngulfing recognizer to the list.
		Recognizers->Add(gcnew Recognizer_BearishEngulfing()); // Add BearishEngulfing recognizer to the list.
		Recognizers->Add(gcnew Recognizer_BullishHarami()); // Add BullishHarami recognizer to the list.
		Recognizers->Add(gcnew Recognizer_BearishHarami()); // Add BearishHarami recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Peak()); // Add Peak recognizer to the list.
		Recognizers->Add(gcnew Recognizer_Valley()); // Add Valley recognizer to the list.

		// Loop through each recognizer in the list.
		for each (Recognizer^ recognizer in Recognizers)
		{
			comboBox_PatternSelector->Items->Add(recognizer->PatternName); // Add the recognizer pattern name to the combo box.
			if (listOfCandlesticks != nullptr) // Check if the list of candlesticks is not null.
			{
				recognizer->recognizeAll(listOfCandlesticks); // Recognize all the patterns in the list of candlesticks.
			}
		}

		comboBox_PatternSelector->Text = ""; // Set empty text to the combo box.
	}

	System::Void Form_StockPicker::comboBox_PatternSelector_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.
		Recognizer^ selectedPatternRecognizer = Recognizers[comboBox_PatternSelector->SelectedIndex]; // Get the selected pattern recognizer.
		int selectedPatternPatternLength = selectedPatternRecognizer->PatternLength; // Get the selected recognizer pattern length.

		// Loop through each candlestick in the Bound List of Candlesticks.
		for (int i = selectedPatternPatternLength - 1; i < BoundListOfCandlesticks->Count; i++)
		{
			// Check in the candlestick pattern dictionary if the pattern is recognized.
			if (BoundListOfCandlesticks[i]->Patterns[selectedPatternRecognizer->PatternName])
			{
				RectangleAnnotationFunc(i, selectedPatternPatternLength); // Draw a rectangle annotation for each recognized candlestick.
			}
		}
	}

	System::Void Form_StockPicker::RectangleAnnotationFunc(int EndIndex, int PatternLength)
	{
		System::Windows::Forms::DataVisualization::Charting::RectangleAnnotation^ rectangle = gcnew System::Windows::Forms::DataVisualization::Charting::RectangleAnnotation(); // Create a new rectangle annotation object.

		double minY = double::MaxValue; // Set the minimum Y value to the maximum value of a double.
		double maxY = double::MinValue; // Set the maximum Y value to the minimum value of a double;

		// Loop through each candlestick in the pattern length.
		for (int i = EndIndex; i >= EndIndex - PatternLength + 1; i--)
		{
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ current = chart_OHLCV->Series[0]->Points[i]; // Get the current data point.
			minY = Math::Min(minY, current->YValues[1]); // Compare the minimum Y value with the low value of the current data point.
			maxY = Math::Max(maxY, current->YValues[0]); // Compare the maximum Y value with the high value of the current data point.
		}

		rectangle->ClipToChartArea = "ChartArea_OHLC"; // Set the chart area for the rectangle annotation.
		rectangle->AxisX = chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisX; // Set the X axis for the rectangle annotation.
		rectangle->AxisY = chart_OHLCV->ChartAreas["ChartArea_OHLC"]->AxisY; // Set the Y axis for the rectangle annotation.
		rectangle->IsSizeAlwaysRelative = false; // Set the size to be relative to the chart area false

		rectangle->BackColor = Color::FromArgb(100, Color::Blue); // Set the background color of the rectangle annotation.
		rectangle->ForeColor = Color::Transparent; // Set the foreground color of the rectangle annotation.
		rectangle->ShadowColor = Color::Transparent; // Set the shadow color of the rectangle annotation.

		rectangle->Width = PatternLength; // Set the width of the rectangle annotation.
		rectangle->X = EndIndex - PatternLength + 1.5; // Set the X value of the rectangle annotation.
		rectangle->Y = maxY; // Set the Y value of the rectangle annotation.
		rectangle->Height = minY - maxY; // Set the height of the rectangle annotation.

		chart_OHLCV->Annotations->Add(rectangle); // Add the rectangle annotation to the chart.
	}

	System::Void Form_StockPicker::button_clearPattern_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		chart_OHLCV->Annotations->Clear(); // Clear the annotations in the chart.
		comboBox_PatternSelector->Text = ""; // Set empty text to the combo box.
	}
}