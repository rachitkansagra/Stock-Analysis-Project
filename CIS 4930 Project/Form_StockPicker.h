#pragma once
#include "candlestick.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form_StockPicker
	/// </summary>
	public ref class Form_StockPicker : public System::Windows::Forms::Form
	{
	private: List<candlestick^>^ listOfCandlesticks; // List of candlestick objects representing the stock data
	private: BindingList<candlestick^>^ BoundListOfCandlesticks; // BindingList of candlestick objects representing the filtered stock data

	private: System::Windows::Forms::DateTimePicker^ StartDateTimePicker; // DateTimePicker control to select the start date for the date range
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_OHLCV; // Chart control to display the candlestick chart
	private: System::Windows::Forms::DateTimePicker^ EndDateTimePicker; // DateTimePicker control to select the end date for the date range

	private: System::Windows::Forms::Button^ button_LoadStock; // Button control to load stock data from a file
	private: System::Windows::Forms::Button^ button_Update; // Button control to update the stock data based on the new date range specified by the user
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_LoadStock; // OpenFileDialog control to allow the user to select a stock file
	private: System::Windows::Forms::DataGridView^ dataGridViewCandlesticks; // DataGridView control to display the filtered candlestick data

	public:
		Form_StockPicker(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_StockPicker()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridViewCandlesticks = (gcnew System::Windows::Forms::DataGridView());
			this->StartDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->EndDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCandlesticks))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->SuspendLayout();
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_LoadStock->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_LoadStock->Location = System::Drawing::Point(455, 677);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(183, 48);
			this->button_LoadStock->TabIndex = 0;
			this->button_LoadStock->Text = L"Load Stock";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_LoadStock_Click);
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->FileName = L"openFileDialog_LoadStock";
			this->openFileDialog_LoadStock->Filter = L"All Files|*.csv|Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*-Day.csv";
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_StockPicker::openFileDialog_LoadStock_FileOk);
			// 
			// dataGridViewCandlesticks
			// 
			this->dataGridViewCandlesticks->AllowUserToAddRows = false;
			this->dataGridViewCandlesticks->AllowUserToDeleteRows = false;
			this->dataGridViewCandlesticks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewCandlesticks->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewCandlesticks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCandlesticks->Location = System::Drawing::Point(6, 0);
			this->dataGridViewCandlesticks->Name = L"dataGridViewCandlesticks";
			this->dataGridViewCandlesticks->ReadOnly = true;
			this->dataGridViewCandlesticks->RowHeadersWidth = 51;
			this->dataGridViewCandlesticks->RowTemplate->Height = 24;
			this->dataGridViewCandlesticks->Size = System::Drawing::Size(1330, 236);
			this->dataGridViewCandlesticks->TabIndex = 1;
			// 
			// StartDateTimePicker
			// 
			this->StartDateTimePicker->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->StartDateTimePicker->Location = System::Drawing::Point(45, 691);
			this->StartDateTimePicker->Name = L"StartDateTimePicker";
			this->StartDateTimePicker->Size = System::Drawing::Size(323, 22);
			this->StartDateTimePicker->TabIndex = 2;
			this->StartDateTimePicker->Value = System::DateTime(2023, 7, 1, 0, 0, 0, 0);
			// 
			// EndDateTimePicker
			// 
			this->EndDateTimePicker->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->EndDateTimePicker->Location = System::Drawing::Point(973, 691);
			this->EndDateTimePicker->Name = L"EndDateTimePicker";
			this->EndDateTimePicker->Size = System::Drawing::Size(292, 22);
			this->EndDateTimePicker->TabIndex = 3;
			// 
			// chart_OHLCV
			// 
			this->chart_OHLCV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea5->AlignWithChartArea = L"ChartArea_Volume";
			chartArea5->AxisY->IsStartedFromZero = false;
			chartArea5->Name = L"ChartArea_OHLC";
			chartArea6->Name = L"ChartArea_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea5);
			this->chart_OHLCV->ChartAreas->Add(chartArea6);
			legend3->Alignment = System::Drawing::StringAlignment::Far;
			legend3->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			legend3->IsDockedInsideChartArea = false;
			legend3->IsTextAutoFit = false;
			legend3->Name = L"Legend_Volume";
			this->chart_OHLCV->Legends->Add(legend3);
			this->chart_OHLCV->Location = System::Drawing::Point(6, 242);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series5->ChartArea = L"ChartArea_OHLC";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series5->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series5->IsVisibleInLegend = false;
			series5->IsXValueIndexed = true;
			series5->Legend = L"Legend_Volume";
			series5->LegendText = L"Stock Volume";
			series5->Name = L"Series_OHLC";
			series5->XValueMember = L"Date";
			series5->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series5->YValueMembers = L"High, Low, Open, Close";
			series5->YValuesPerPoint = 4;
			series6->ChartArea = L"ChartArea_Volume";
			series6->Legend = L"Legend_Volume";
			series6->LegendText = L"Stock Volume";
			series6->Name = L"Series_Volume";
			series6->XValueMember = L"Date";
			series6->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series6->YValueMembers = L"Volume";
			this->chart_OHLCV->Series->Add(series5);
			this->chart_OHLCV->Series->Add(series6);
			this->chart_OHLCV->Size = System::Drawing::Size(1330, 429);
			this->chart_OHLCV->TabIndex = 4;
			this->chart_OHLCV->Text = L"chart1";
			// 
			// button_Update
			// 
			this->button_Update->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Update->Location = System::Drawing::Point(692, 677);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(160, 48);
			this->button_Update->TabIndex = 5;
			this->button_Update->Text = L"Update";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_Update_Click);
			// 
			// Form_StockPicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1341, 737);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->chart_OHLCV);
			this->Controls->Add(this->EndDateTimePicker);
			this->Controls->Add(this->StartDateTimePicker);
			this->Controls->Add(this->dataGridViewCandlesticks);
			this->Controls->Add(this->button_LoadStock);
			this->Name = L"Form_StockPicker";
			this->Text = L"Form_StockPicker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCandlesticks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	/// <summary>
	/// Overloaded method to read stock data from a file and return a list of candlestick objects
	/// </summary>
	private: void ReadCandlestickData();

	/// <summary>
	/// Reads stock data from a file and returns a list of candlestick objects
	/// </summary>
	/// <param name="filePath">:Stock data filepath</param>
	/// <returns>List of candlestick objects</returns>
	private: List<candlestick^>^ ReadCandlestickData(String^ filePath);

	/// <summary>
	/// Overloaded method to filter list of candlestick based on the date range specified by the user
	/// </summary>
	private: void FilterCandlestickData();

	/// <summary>
	/// Filters list of candlestick based on the date range specified by the user
	/// </summary>
	/// <param name="loc">:Complete list of candlestick</param>
	/// <returns>A BindingList of candlestick objects representing the filtered data.</returns>
	private: BindingList<candlestick^>^ FilterCandlestickData(List<candlestick^>^ loc);
	
	/// <summary>
	///  Displays the filtered candlestick data in a DataGridView and a Chart.
	/// </summary>
	private: void DisplayCandlestickData();

	/// <summary>
	/// Overloaded method to normalize the candlestick chart by adjusting the maximum and minimum values of the Y-axis
	/// </summary>
	private: void NormalizeCandlestickChart();

	/// <summary>
	///  Normalizes the candlestick chart by adjusting the maximum and minimum values of the Y-axis
	/// </summary>
	/// <param name="bloc">:The BindingList of candlestick objects for which the chart is normalized</param>
	private: void NormalizeCandlestickChart(BindingList<candlestick^>^ bloc);

	/// <summary>
	/// Event handler for the Click event of the button_LoadStock control.
	/// Opens a file dialog to allow the user to select a stock file.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e);

	/// <summary>
	/// Event handler for the FileOk event of the openFileDialog_LoadStock control.
	/// Reads candlestick data from the selected file, filters it, normalizes the candlestick chart, and displays the data.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	
	/// <summary>
	/// Event handler for the Click event of the button_Update control.
	/// Filters the candlestick data and displays it based on the new date range specified by the user.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
};
};