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
	private: List<candlestick^>^ listOfCandlesticks;
	private: BindingList<candlestick^>^ BoundListOfCandlesticks;
	private: System::Windows::Forms::DateTimePicker^ StartDateTimePicker;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_OHLCV;


	private: System::Windows::Forms::DateTimePicker^ EndDateTimePicker;

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::DataGridView^ dataGridViewCandlesticks;

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridViewCandlesticks = (gcnew System::Windows::Forms::DataGridView());
			this->StartDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->EndDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCandlesticks))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(611, 677);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Load Stock";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_StockPicker::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_StockPicker::openFileDialog1_FileOk);
			// 
			// dataGridViewCandlesticks
			// 
			this->dataGridViewCandlesticks->AllowUserToAddRows = false;
			this->dataGridViewCandlesticks->AllowUserToDeleteRows = false;
			this->dataGridViewCandlesticks->Anchor = System::Windows::Forms::AnchorStyles::Top;
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
			this->StartDateTimePicker->Location = System::Drawing::Point(45, 691);
			this->StartDateTimePicker->Name = L"StartDateTimePicker";
			this->StartDateTimePicker->Size = System::Drawing::Size(323, 22);
			this->StartDateTimePicker->TabIndex = 2;
			this->StartDateTimePicker->Value = System::DateTime(2023, 7, 1, 0, 0, 0, 0);
			// 
			// EndDateTimePicker
			// 
			this->EndDateTimePicker->Location = System::Drawing::Point(973, 691);
			this->EndDateTimePicker->Name = L"EndDateTimePicker";
			this->EndDateTimePicker->Size = System::Drawing::Size(292, 22);
			this->EndDateTimePicker->TabIndex = 3;
			// 
			// chart_OHLCV
			// 
			chartArea1->AlignWithChartArea = L"ChartArea_Volume";
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->Name = L"ChartArea_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea1);
			this->chart_OHLCV->ChartAreas->Add(chartArea2);
			legend1->Alignment = System::Drawing::StringAlignment::Far;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			legend1->IsDockedInsideChartArea = false;
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend_Volume";
			this->chart_OHLCV->Legends->Add(legend1);
			this->chart_OHLCV->Location = System::Drawing::Point(6, 242);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend_Volume";
			series1->LegendText = L"Stock Volume";
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"High, Low, Open, Close";
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"ChartArea_Volume";
			series2->Legend = L"Legend_Volume";
			series2->LegendText = L"Stock Volume";
			series2->Name = L"Series_Volume";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueMembers = L"Volume";
			this->chart_OHLCV->Series->Add(series1);
			this->chart_OHLCV->Series->Add(series2);
			this->chart_OHLCV->Size = System::Drawing::Size(1330, 429);
			this->chart_OHLCV->TabIndex = 4;
			this->chart_OHLCV->Text = L"chart1";
			// 
			// Form_StockPicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1341, 737);
			this->Controls->Add(this->chart_OHLCV);
			this->Controls->Add(this->EndDateTimePicker);
			this->Controls->Add(this->StartDateTimePicker);
			this->Controls->Add(this->dataGridViewCandlesticks);
			this->Controls->Add(this->button1);
			this->Name = L"Form_StockPicker";
			this->Text = L"Form_StockPicker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCandlesticks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: List<candlestick^>^ ReadCandlestickData(String^ filePath);
	private: BindingList<candlestick^>^ FilterCandlestickData(List<candlestick^>^ loc);

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->ShowDialog();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		String^ filePath = openFileDialog1->FileName;
		
		listOfCandlesticks = ReadCandlestickData(filePath);
		BoundListOfCandlesticks = FilterCandlestickData(listOfCandlesticks);

		dataGridViewCandlesticks->DataSource = BoundListOfCandlesticks;
		chart_OHLCV->DataSource = BoundListOfCandlesticks;
		chart_OHLCV->DataBind();
	}
	};
};