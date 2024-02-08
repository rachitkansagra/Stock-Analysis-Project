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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridViewCandlesticks = (gcnew System::Windows::Forms::DataGridView());
			this->StartDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->EndDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCandlesticks))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(493, 369);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 48);
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
			this->dataGridViewCandlesticks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCandlesticks->Location = System::Drawing::Point(6, 2);
			this->dataGridViewCandlesticks->Name = L"dataGridViewCandlesticks";
			this->dataGridViewCandlesticks->ReadOnly = true;
			this->dataGridViewCandlesticks->RowHeadersWidth = 51;
			this->dataGridViewCandlesticks->RowTemplate->Height = 24;
			this->dataGridViewCandlesticks->Size = System::Drawing::Size(1123, 327);
			this->dataGridViewCandlesticks->TabIndex = 1;
			// 
			// StartDateTimePicker
			// 
			this->StartDateTimePicker->Location = System::Drawing::Point(12, 395);
			this->StartDateTimePicker->Name = L"StartDateTimePicker";
			this->StartDateTimePicker->Size = System::Drawing::Size(381, 22);
			this->StartDateTimePicker->TabIndex = 2;
			this->StartDateTimePicker->Value = System::DateTime(2023, 7, 1, 0, 0, 0, 0);
			// 
			// EndDateTimePicker
			// 
			this->EndDateTimePicker->Location = System::Drawing::Point(767, 395);
			this->EndDateTimePicker->Name = L"EndDateTimePicker";
			this->EndDateTimePicker->Size = System::Drawing::Size(314, 22);
			this->EndDateTimePicker->TabIndex = 3;
			// 
			// Form_StockPicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1132, 447);
			this->Controls->Add(this->EndDateTimePicker);
			this->Controls->Add(this->StartDateTimePicker);
			this->Controls->Add(this->dataGridViewCandlesticks);
			this->Controls->Add(this->button1);
			this->Name = L"Form_StockPicker";
			this->Text = L"Form_StockPicker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCandlesticks))->EndInit();
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

		//BoundListOfCandlesticks = gcnew BindingList<candlestick^>(TempListOfCandlesticks);
		dataGridViewCandlesticks->DataSource = BoundListOfCandlesticks;
	}
};
};