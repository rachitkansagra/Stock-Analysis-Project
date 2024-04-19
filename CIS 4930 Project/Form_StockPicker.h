#pragma once
#include "candlestick.h"
#include "smartcandlestick.h"
#include "Recognizer.h"
#include "Recognizer_Bearish.h"
#include "Recognizer_BearishEngulfing.h"
#include "Recognizer_BearishHarami.h"
#include "Recognizer_Bullish.h"
#include "Recognizer_BullishEngulfing.h"
#include "Recognizer_BullishHarami.h"
#include "Recognizer_Doji.h"
#include "Recognizer_DragonFlyDoji.h"
#include "Recognizer_GraveStoneDoji.h"
#include "Recognizer_Hammer.h"
#include "Recognizer_InvertedHammer.h"
#include "Recognizer_Marubozu.h"
#include "Recognizer_Neutral.h"
#include "Recognizer_Peak.h"
#include "Recognizer_Valley.h"

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
	private: List<smartcandlestick^>^ listOfCandlesticks; // List of candlestick objects representing the stock data
	private: BindingList<smartcandlestick^>^ BoundListOfCandlesticks; // BindingList of candlestick objects representing the filtered stock data
	private: String^ StockDataFilePath; // Filepath of the stock data file
	private: List<Recognizer^>^ Recognizers; // List of candlestick pattern recognizers

	private: System::Windows::Forms::DateTimePicker^ StartDateTimePicker; // DateTimePicker control to select the start date for the date range
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_OHLCV; // Chart control to display the candlestick chart
	private: System::Windows::Forms::DateTimePicker^ EndDateTimePicker; // DateTimePicker control to select the end date for the date range

	private: System::Windows::Forms::Button^ button_LoadStock; // Button control to load stock data from a file
	private: System::Windows::Forms::Button^ button_Update; // Button control to update the stock data based on the new date range specified by the user
	private: System::Windows::Forms::Label^ labelStartDate; // Label control to display the text "Start Date:"
	private: System::Windows::Forms::Label^ labelEndDate; // Label control to display the text "End Date:"
	private: System::Windows::Forms::ComboBox^ comboBox_PatternSelector; // ComboBox control to select the candlestick pattern to display
	private: System::Windows::Forms::Label^ Label_CandleStickPattern; // Label control to display the text "CandleStick Pattern"
	private: System::Windows::Forms::Label^ Label_DateRange; // Label control to display the text "Date Range"
	private: System::Windows::Forms::Button^ button_clearPattern; // Button control to clear the candlestick pattern annotation from the chart
	private: System::Windows::Forms::Label^ label_FormHeading; // Label control to display the form heading

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_LoadStock; // OpenFileDialog control to allow the user to select a stock file

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea11 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea12 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->StartDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->EndDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->labelStartDate = (gcnew System::Windows::Forms::Label());
			this->labelEndDate = (gcnew System::Windows::Forms::Label());
			this->comboBox_PatternSelector = (gcnew System::Windows::Forms::ComboBox());
			this->Label_CandleStickPattern = (gcnew System::Windows::Forms::Label());
			this->Label_DateRange = (gcnew System::Windows::Forms::Label());
			this->button_clearPattern = (gcnew System::Windows::Forms::Button());
			this->label_FormHeading = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->SuspendLayout();
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_LoadStock->Location = System::Drawing::Point(138, 158);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(163, 48);
			this->button_LoadStock->TabIndex = 0;
			this->button_LoadStock->Text = L"Load Stock";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_LoadStock_Click);
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->FileName = L"openFileDialog_LoadStock";
			this->openFileDialog_LoadStock->Filter = L"All Files|*.csv|Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*-Day.csv";
			this->openFileDialog_LoadStock->Multiselect = true;
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_StockPicker::openFileDialog_LoadStock_FileOk);
			// 
			// StartDateTimePicker
			// 
			this->StartDateTimePicker->Location = System::Drawing::Point(138, 60);
			this->StartDateTimePicker->Name = L"StartDateTimePicker";
			this->StartDateTimePicker->Size = System::Drawing::Size(354, 22);
			this->StartDateTimePicker->TabIndex = 2;
			this->StartDateTimePicker->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// EndDateTimePicker
			// 
			this->EndDateTimePicker->Location = System::Drawing::Point(138, 109);
			this->EndDateTimePicker->Name = L"EndDateTimePicker";
			this->EndDateTimePicker->Size = System::Drawing::Size(354, 22);
			this->EndDateTimePicker->TabIndex = 3;
			// 
			// chart_OHLCV
			// 
			this->chart_OHLCV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea11->AlignWithChartArea = L"ChartArea_Volume";
			chartArea11->AxisY->IsStartedFromZero = false;
			chartArea11->Name = L"ChartArea_OHLC";
			chartArea12->Name = L"ChartArea_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea11);
			this->chart_OHLCV->ChartAreas->Add(chartArea12);
			this->chart_OHLCV->Location = System::Drawing::Point(6, 212);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series11->ChartArea = L"ChartArea_OHLC";
			series11->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series11->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series11->IsVisibleInLegend = false;
			series11->IsXValueIndexed = true;
			series11->LegendText = L"Stock Volume";
			series11->Name = L"Series_OHLC";
			series11->XValueMember = L"Date";
			series11->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series11->YValueMembers = L"High, Low, Open, Close";
			series11->YValuesPerPoint = 4;
			series12->ChartArea = L"ChartArea_Volume";
			series12->LegendText = L"Stock Volume";
			series12->Name = L"Series_Volume";
			series12->XValueMember = L"Date";
			series12->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series12->YValueMembers = L"Volume";
			this->chart_OHLCV->Series->Add(series11);
			this->chart_OHLCV->Series->Add(series12);
			this->chart_OHLCV->Size = System::Drawing::Size(1330, 523);
			this->chart_OHLCV->TabIndex = 4;
			this->chart_OHLCV->Text = L"chart1";
			// 
			// button_Update
			// 
			this->button_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Update->Location = System::Drawing::Point(332, 158);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(160, 48);
			this->button_Update->TabIndex = 5;
			this->button_Update->Text = L"Update";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_Update_Click);
			// 
			// labelStartDate
			// 
			this->labelStartDate->AutoSize = true;
			this->labelStartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelStartDate->Location = System::Drawing::Point(24, 60);
			this->labelStartDate->Name = L"labelStartDate";
			this->labelStartDate->Size = System::Drawing::Size(102, 20);
			this->labelStartDate->TabIndex = 6;
			this->labelStartDate->Text = L"Start Date:";
			// 
			// labelEndDate
			// 
			this->labelEndDate->AutoSize = true;
			this->labelEndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelEndDate->Location = System::Drawing::Point(27, 111);
			this->labelEndDate->Name = L"labelEndDate";
			this->labelEndDate->Size = System::Drawing::Size(93, 20);
			this->labelEndDate->TabIndex = 7;
			this->labelEndDate->Text = L"End Date:";
			// 
			// comboBox_PatternSelector
			// 
			this->comboBox_PatternSelector->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox_PatternSelector->FormattingEnabled = true;
			this->comboBox_PatternSelector->Location = System::Drawing::Point(906, 62);
			this->comboBox_PatternSelector->Name = L"comboBox_PatternSelector";
			this->comboBox_PatternSelector->Size = System::Drawing::Size(214, 24);
			this->comboBox_PatternSelector->TabIndex = 8;
			this->comboBox_PatternSelector->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_StockPicker::comboBox_PatternSelector_SelectedIndexChanged);
			// 
			// Label_CandleStickPattern
			// 
			this->Label_CandleStickPattern->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Label_CandleStickPattern->AutoSize = true;
			this->Label_CandleStickPattern->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_CandleStickPattern->Location = System::Drawing::Point(903, 27);
			this->Label_CandleStickPattern->Name = L"Label_CandleStickPattern";
			this->Label_CandleStickPattern->Size = System::Drawing::Size(204, 25);
			this->Label_CandleStickPattern->TabIndex = 9;
			this->Label_CandleStickPattern->Text = L"CandleStick Pattern";
			// 
			// Label_DateRange
			// 
			this->Label_DateRange->AutoSize = true;
			this->Label_DateRange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_DateRange->Location = System::Drawing::Point(133, 27);
			this->Label_DateRange->Name = L"Label_DateRange";
			this->Label_DateRange->Size = System::Drawing::Size(125, 25);
			this->Label_DateRange->TabIndex = 10;
			this->Label_DateRange->Text = L"Date Range";
			// 
			// button_clearPattern
			// 
			this->button_clearPattern->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_clearPattern->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_clearPattern->Location = System::Drawing::Point(906, 158);
			this->button_clearPattern->Name = L"button_clearPattern";
			this->button_clearPattern->Size = System::Drawing::Size(180, 48);
			this->button_clearPattern->TabIndex = 11;
			this->button_clearPattern->Text = L"Clear Pattern";
			this->button_clearPattern->UseVisualStyleBackColor = true;
			this->button_clearPattern->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_StockPicker::button_clearPattern_MouseClick);
			// 
			// label_FormHeading
			// 
			this->label_FormHeading->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label_FormHeading->AutoSize = true;
			this->label_FormHeading->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 22.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_FormHeading->ForeColor = System::Drawing::Color::Purple;
			this->label_FormHeading->Location = System::Drawing::Point(543, 33);
			this->label_FormHeading->Name = L"label_FormHeading";
			this->label_FormHeading->Size = System::Drawing::Size(273, 49);
			this->label_FormHeading->TabIndex = 12;
			this->label_FormHeading->Text = L"Stock Analysis";
			// 
			// Form_StockPicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1341, 737);
			this->Controls->Add(this->label_FormHeading);
			this->Controls->Add(this->button_clearPattern);
			this->Controls->Add(this->Label_DateRange);
			this->Controls->Add(this->Label_CandleStickPattern);
			this->Controls->Add(this->comboBox_PatternSelector);
			this->Controls->Add(this->labelEndDate);
			this->Controls->Add(this->labelStartDate);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->chart_OHLCV);
			this->Controls->Add(this->EndDateTimePicker);
			this->Controls->Add(this->StartDateTimePicker);
			this->Controls->Add(this->button_LoadStock);
			this->Name = L"Form_StockPicker";
			this->Text = L"Form_StockPicker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
	private: List<smartcandlestick^>^ ReadCandlestickData(String^ filePath);

	/// <summary>
	/// Overloaded method to filter list of candlestick based on the date range specified by the user
	/// </summary>
	private: void FilterCandlestickData();

	/// <summary>
	/// Filters list of candlestick based on the date range specified by the user
	/// </summary>
	/// <param name="loc">:Complete list of candlestick</param>
	/// <returns>A BindingList of candlestick objects representing the filtered data.</returns>
	private: BindingList<smartcandlestick^>^ FilterCandlestickData(List<smartcandlestick^>^ loc);
	
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
	private: void NormalizeCandlestickChart(BindingList<smartcandlestick^>^ bloc);

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

	/// <summary>
	/// Intializes the ComboBox control with the candlestick patterns.
	/// </summary>
	private: void InializeComboBox();

	/// <summary>
	/// Adds a RectangleAnnotation to the chart to highlight the candlestick pattern at the specified index.
	/// </summary>
	/// <param name="Index">: the index at which the annotation is represented</param>
	private: void RectangleAnnotationFunc(int EndIndex, int PatternLength);

	/// <summary>
	/// Event handler for the SelectedIndexChanged event of the comboBox_PatternSelector control.
	/// Changes the annotation on the chart based on the selected pattern.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void comboBox_PatternSelector_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	
	/// <summary>
	/// Event handler for the Click event of the button_clearPattern control.
	/// Removes all the annotation from the chart.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_clearPattern_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	};
};