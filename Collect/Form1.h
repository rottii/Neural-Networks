#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Set_Net;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// User Defined Variables
		int  class_count = 0, numSample = 0, inputDim = 2, * neuron_count, layer = 4;//inputDim 2 boyutlu uzaydan aldýðýmýz için hep 2.
		float* Samples, * targets, * Weights, * bias;
		float* x = new float[inputDim];
		float* mean = new float[inputDim];
		float* std = new float[inputDim];
		

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveDataToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ testingToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ LayerCountBox;
	private: System::Windows::Forms::TextBox^ textBox2;

		   /// </summary>
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->LayerCountBox = (gcnew System::Windows::Forms::ComboBox());
			this->Set_Net = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(13, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(802, 578);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->LayerCountBox);
			this->groupBox1->Controls->Add(this->Set_Net);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->ClassCountBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(869, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 135);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Network Architecture";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(108, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Katman Sayýsý";
			// 
			// LayerCountBox
			// 
			this->LayerCountBox->FormattingEnabled = true;
			this->LayerCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			this->LayerCountBox->Location = System::Drawing::Point(10, 47);
			this->LayerCountBox->Name = L"LayerCountBox";
			this->LayerCountBox->Size = System::Drawing::Size(82, 21);
			this->LayerCountBox->TabIndex = 3;
			this->LayerCountBox->Text = L"1";
			// 
			// Set_Net
			// 
			this->Set_Net->Location = System::Drawing::Point(6, 74);
			this->Set_Net->Name = L"Set_Net";
			this->Set_Net->Size = System::Drawing::Size(131, 33);
			this->Set_Net->TabIndex = 2;
			this->Set_Net->Text = L"Network Setting";
			this->Set_Net->UseVisualStyleBackColor = true;
			this->Set_Net->Click += gcnew System::EventHandler(this, &Form1::Set_Net_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sýnýf Sayýsý";
			// 
			// ClassCountBox
			// 
			this->ClassCountBox->FormattingEnabled = true;
			this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			this->ClassCountBox->Location = System::Drawing::Point(10, 20);
			this->ClassCountBox->Name = L"ClassCountBox";
			this->ClassCountBox->Size = System::Drawing::Size(82, 21);
			this->ClassCountBox->TabIndex = 0;
			this->ClassCountBox->Text = L"1";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->ClassNoBox);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox2->Location = System::Drawing::Point(879, 191);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(190, 61);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data Collection";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(98, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Örnek Etiketi";
			// 
			// ClassNoBox
			// 
			this->ClassNoBox->FormattingEnabled = true;
			this->ClassNoBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9"
			});
			this->ClassNoBox->Location = System::Drawing::Point(7, 20);
			this->ClassNoBox->Name = L"ClassNoBox";
			this->ClassNoBox->Size = System::Drawing::Size(75, 21);
			this->ClassNoBox->TabIndex = 0;
			this->ClassNoBox->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(876, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->processToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1463, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->readDataToolStripMenuItem,
					this->saveDataToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readDataToolStripMenuItem
			// 
			this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			this->readDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->readDataToolStripMenuItem->Text = L"Read_Data";
			this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->saveDataToolStripMenuItem->Text = L"Save_Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->trainingToolStripMenuItem,
					this->testingToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			this->trainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingToolStripMenuItem_Click);
			// 
			// testingToolStripMenuItem
			// 
			this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			this->testingToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->testingToolStripMenuItem->Text = L"Testing";
			this->testingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testingToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1353, 35);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 243);
			this->textBox1->TabIndex = 5;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(869, 299);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(582, 300);
			this->chart1->TabIndex = 6;
			this->chart1->Text = L"Error";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(1093, 57);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(239, 56);
			this->textBox2->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1463, 633);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Error";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void draw_sample(int temp_x, int temp_y, int label) {
			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			switch (label) {
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}//switch
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}//draw_sample
        #pragma endregion
	    private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if( class_count == 0)
				MessageBox::Show("The Network Architeture should be firtly set up");
			else {
				float* x= new float[inputDim];
				int temp_x = (System::Convert::ToInt32(e->X));
				int temp_y = (System::Convert::ToInt32(e->Y));
				x[0] = float(temp_x - (pictureBox1->Width / 2));
				x[1] = float(pictureBox1->Height / 2 - temp_y);
				int label;
				int numLabel = Convert::ToInt32(ClassNoBox->Text);
				if (numLabel > class_count)
					MessageBox::Show("The class label cannot be greater than the maximum number of classes.");
				else {
					label = numLabel - 1; //Dögüler 0 dan baþladýðýndan, label deðeri 0 dan baþlamasý için bir eksiði alýnmýþtýr
					if (numSample == 0) { //Dinamik alýnan ilk örnek için sadece
						numSample = 1;  
						Samples = new float[inputDim]; targets = new float[1];
						for (int i = 0; i < inputDim; i++)
							Samples[i] = x[i];
						targets[0] = float(label);
					}
					else {
						numSample++;
						Samples = Add_Data(Samples, numSample, x, inputDim);
						targets = Add_Labels(targets, numSample, label);
					}//else
					draw_sample(temp_x, temp_y, label);
					label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
					delete [] x;
				}//else of if (Etiket ...
			}//else
	    }//pictureMouseClick
        private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			//Ana eksen doðrularini cizdir
			Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			int center_width, center_height;
			center_width = (int)(pictureBox1->Width / 2);
			center_height = (int)(pictureBox1->Height / 2);
			e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
			e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
        }
        private: System::Void Set_Net_Click(System::Object^ sender, System::EventArgs^ e) {
			// Network is constructed
			class_count = Convert::ToInt32(ClassCountBox->Text);
			//layer = Convert::ToInt32(LayerCountBox->Text);
			if (neuron_count != nullptr) delete[] neuron_count; // Safety cleanup
			neuron_count = new int[layer];//Giriþ ve Çýkýþ nöron sayýlarýný giriyoruz.
			//MessageBox::Show("layer: "+System::Convert::ToString(layer));
			neuron_count[0] = 4;
			neuron_count[layer - 3] = 6;//normal sayýyla gösterince bazen sýkýntý çýkýyor nedense
			neuron_count[layer - 2] = 6;
			neuron_count[layer - 1] = class_count;
			int weightNum = 0, biasNum = 0;
			for (int i = 0; i < layer; i++)
			{
				if (i == 0)
					weightNum += inputDim * neuron_count[i];
				else
					weightNum += neuron_count[i - 1] * neuron_count[i];
				biasNum += neuron_count[i];
			}
			Weights = new float[weightNum];
			bias = new float[biasNum];
			//initialize weights
			Weights = init_array_random(weightNum);
			bias = init_array_random(biasNum);

			Set_Net->Text = " Network is Ready : ";
        }//Set_Net
        private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char** c = new char *[2];
			// Veri Kümesini okunacak 
			MessageBox::Show("Veri Kümesini Yükleyin");
			c[0] = "../Data/Samples.txt";
			c[1] = "../Data/weights.txt";
			std::ifstream file;
			int num, w, h, Dim, label, weightNum, biasNum;
			file.open(c[0]); 
			if (file.is_open()) {
				//MessageBox::Show("Dosya acildi");
				file >> Dim>> w >> h >>num;
				textBox1->Text += "Dimension: "+ Convert::ToString(Dim) + "- Width: "+ Convert::ToString(w)+" - Height: "+ Convert::ToString(h)+ " - Number of Class: "+ Convert::ToString(num) +"\r\n";
				// Set network values
				class_count = num;
				inputDim = Dim;
				numSample = 0;
				float* x = new float[inputDim];
				while (!file.eof())
				{
					if (numSample == 0) { //ilk örnek için sadece
						numSample = 1;
						Samples = new float[inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							   file>>Samples[i];
						file >> targets[0];
					}
					else {
						
						for (int i = 0; i < inputDim; i++)
							file >> x[i];
						file >> label;
						if (!file.eof()) {
							numSample++;
							Samples = Add_Data(Samples, numSample, x, inputDim);
							targets = Add_Labels(targets, numSample, label);
						}
					}//else
				} //while
				delete[]x;
				file.close();
				for (int i = 0; i < numSample; i++) {
					draw_sample(Samples[i*inputDim]+w, h-Samples[i*inputDim+1], targets[i]);
					for (int j = 0; j < inputDim; j++)
						textBox1->Text += Convert::ToString(Samples[i * inputDim + j]) + " ";
					textBox1->Text += Convert::ToString(targets[i]) + "\r\n";
				}
				//draw_sample(temp_x, temp_y, label);
				label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
				MessageBox::Show("Dosya basari ile okundu");
			}//file.is_open
			else MessageBox::Show("Dosya acilamadi");

			//Get weights
			if (neuron_count != nullptr) delete[] neuron_count; // Safety cleanup
			neuron_count = new int[layer];//Giriþ ve Çýkýþ nöron sayýlarýný giriyoruz.
			int Layer;
			int* weightCount = new int[layer + 1]; 
			int* biasCount = new int[layer + 1];
			for (int i = 0; i < layer + 1; i++)
			{
				weightCount[i] = 0;
				biasCount[i] = 0;
			}

			file.open(c[1]);
			if (file.is_open()) {
				file >> Layer >> Dim >> num >> weightNum >> biasNum;
				for (int i = 0; i < layer; i++)
					file >> neuron_count[i];
				file >> mean[0] >> mean[1] >> std[0] >> std[1];
				Weights = new float[weightNum];
				bias = new float[biasNum];
				class_count = num;
				inputDim = Dim;
				textBox1->Text += "Layer: " + Convert::ToString(Layer) + " Dimension: " + Convert::ToString(Dim) + " numClass:" + Convert::ToString(num) + "\r\n";

				for (int i = 0; i < layer; i++)
				{
					int current_layer_weights = 0;

					if (i == 0) current_layer_weights = inputDim * neuron_count[i];
					else current_layer_weights = neuron_count[i - 1] * neuron_count[i];

					weightCount[i + 1] += weightCount[i] + current_layer_weights; //weightCount
					biasCount[i + 1] += biasCount[i] + neuron_count[i];//neuronCount
				}

				while (!file.eof())
				{
					for (int l = 0; l < layer; l++)
						for (int k = 0; k < neuron_count[l]; k++)
						{
							if (l == 0)
								for (int i = 0; i < inputDim; i++)
									file >> Weights[weightCount[l] + k * inputDim + i];
							else
								for (int i = 0; i < neuron_count[l - 1]; i++)
									file >> Weights[weightCount[l] + k * neuron_count[l - 1] + i];
						}
					
					for (int l = 0; l < layer; l++)
						for (int i = 0; i < neuron_count[l]; i++)
							file >> bias[biasCount[l] + i];
				}
				file.close();
			}//file.is_open
			delete[]c;
        }//Read_Data
        private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (numSample != 0) {
				char** c = new char* [2];
				// Veri Kümesi yazýlacak
				c[0] = "../Data/Samples.txt";
				c[1] = "../Data/weights.txt";
				std::ofstream ofs(c[0]);
				if (!ofs.bad()) {
					// Width,  Height, number of Class, data+label
					ofs <<inputDim<<" "<< pictureBox1->Width / 2 << " " << pictureBox1->Height / 2 <<" "<<class_count<< std::endl;
					for (int i = 0; i < numSample; i++) {
						for (int d = 0; d < inputDim; d++)
							ofs << Samples[i*inputDim+d] << " ";
						ofs << targets[i] << std::endl;
					}
					ofs.close();
				}
				else MessageBox::Show("Samples icin dosya acilamadi");
				std::ofstream file(c[1]);
				if (!file.bad()) {
					//Bunu en dýþa 1 kez yazsak daha iyi olur aslýnda
					int weightNum = 0, biasNum = 0;
					for (int i = 0; i < layer; i++)
					{
						if (i == 0)
							weightNum += inputDim * neuron_count[i];
						else
							weightNum += neuron_count[i - 1] * neuron_count[i];
						biasNum += neuron_count[i];
					}

					// #Layer Dimension numClass weights biases
					file << layer <<" "<<inputDim << " " << class_count << " " << weightNum << " " << biasNum << std::endl;
					for (int i = 0; i < layer; i++)
						file << neuron_count[i] << " ";
					file << std::endl;
					file << mean[0] << " " << mean[1] << " " << std[0] << " " << std[1] << std::endl;
					for (int k = 0; k < weightNum; k++) 
							file << Weights[k] << " ";
					file << std::endl;
					for (int k = 0; k < biasNum; k++)
						file << bias[k] << " ";
					file.close();
				}
				else MessageBox::Show("Weight icin dosya acilamadi");
				delete[]c;	
			}
			else MessageBox::Show("At least one sample should be given");
        }//Save_Data
	    private: System::Void testingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (neuron_count == nullptr)
			{
				MessageBox::Show("Set up the network first");
				return;
			}

			int num, temp_x, temp_y;
			float pred_y, screen_y, output;
			Bitmap^ surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			Graphics^ g = Graphics::FromImage(surface); 
			g->Clear(Color::White);

			Color c;
			if (class_count > 1)//Sýnýflandýrma
			{
				for (int row = 0; row < pictureBox1->Height; row += 1) {
					for (int column = 0; column < pictureBox1->Width; column += 1) {
						x[0] = (float)(column - (pictureBox1->Width / 2));
						x[1] = (float)((pictureBox1->Height / 2) - row);
						x[0] = (x[0] - mean[0]) / std[0];
						x[1] = (x[1] - mean[1]) / std[1];
						num = Test_Forward(x, Weights, bias, layer, neuron_count, inputDim);
						//MessageBox::Show("merhaba: class :" + System::Convert::ToString(numClass));
						switch (num) {
						case 0: c = Color::FromArgb(50, 50, 50); break;
						case 1: c = Color::FromArgb(160, 0, 0); break;
						case 2: c = Color::FromArgb(0, 0, 160); break;
						case 3: c = Color::FromArgb(0, 160, 0); break;
						case 4: c = Color::FromArgb(180, 180, 0); break;
						case 5: c = Color::FromArgb(130, 130, 0); break;
						default: c = Color::FromArgb(100, 160, 0);
						}//switch
						surface->SetPixel(column, row, c);
					}//column
					//MessageBox::Show("merhaba2: class :" + System::Convert::ToString(numClass));
				}
			}
			else//Regression
			{
				Pen^ linePen = gcnew Pen(Color::Black, 3.0f);

				float prev_screen_y = 0, prev_screen_x = 0;
				bool firstPoint = true;

				for (int column = 0; column < pictureBox1->Width; column += 1) {
					x[0] = (float)column - (pictureBox1->Width / 2);
					x[0] = (x[0] - mean[0]) / std[0];

					float output = Regression(x, Weights, bias, layer, neuron_count, 1);

					float real_y = (output * std[1]) + mean[1];
					float screen_y = (pictureBox1->Height / 2.0f) - real_y;

					if (!firstPoint) {
						g->DrawLine(linePen, prev_screen_x, prev_screen_y, (float)column, screen_y);
					}
					prev_screen_y = screen_y;
					prev_screen_x = (float)column;
					firstPoint = false;
				}
			}
			//Samples Draw
			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			for (int i = 0; i < numSample; i++) {
				switch (int(targets[i])) {
				case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
				}
				temp_x = int(Samples[i * inputDim]) + pictureBox1->Width / 2;
				temp_y = pictureBox1->Height / 2 - int(Samples[i * inputDim + 1]);
				g->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				g->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
			pictureBox1->Image = surface;
	    }//Testing
		private: System::Void trainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (neuron_count == nullptr)
			{
				MessageBox::Show("Set up the network first");
				return;
			}

			float learning_rate = 0.005f, min_error = 0.05f, error = 0, total_error = 0;
			int	max_epoch = 10000, epoch = 0;
			float alpha = 0.80f;

			int** sums = new int* [layer + 1] {0};//Bu o layer'a kadarki toplam nöron ve weight sayýsýný tutuyor(0 = noron sayýsý, 1 = weight sayýsý)
			for (int i = 0; i <= layer; i++)
			{
				sums[i] = new int[2] {0, 0};
			}

			for (int i = 0; i < layer; i++)// ilk layer'ý 0 yapýyorum ki aþaðýdaki hesaplamalarýn hepsine if eklemek zorunda kalmayayým. 
			{
				int current_layer_weights = 0;

				if (i == 0) 
				{
					if (class_count > 1)//Sýnýflandýrma
						current_layer_weights = inputDim * neuron_count[i];
					else//Regresyon
						current_layer_weights = neuron_count[i];
				}
				else current_layer_weights = neuron_count[i - 1] * neuron_count[i];

				sums[i + 1][1] += sums[i][1] + current_layer_weights; //weightCount
				sums[i + 1][0] += sums[i][0] + neuron_count[i];//neuronCount
			}

			float* prev_diffs = new float[sums[layer][1]];
			float* net = new float[sums[layer][0]];
			float* f_net = new float[sums[layer][0]];
			float* f_der = new float[sums[layer][0]];
			float *delta = new float[sums[layer][0]];

			for (int i = 0; i < sums[layer][1]; i++)
				prev_diffs[i] = 0.0f;
			for (int i = 0; i < sums[layer][0]; i++) 
			{
				net[i] = 0.0f;
				f_net[i] = 0.0f;
				f_der[i] = 0.0f;
				delta[i] = 0.0f;
			}

			if (mean == nullptr) mean = new float[inputDim];
			if (std == nullptr) std = new float[inputDim];
			Z_Score_Parameters(Samples, numSample, inputDim, mean, std);

			float* temp = new float[max_epoch];
			float* desired = new float[class_count];
			float* norm_samples, * norm_targets = nullptr;

			if (class_count > 1)//Sýnýflandýrma
			{
				norm_samples = new float[numSample * 2];

				for (int i = 0; i < numSample; i++)
				{
					for (int j = 0; j < inputDim; j++)
						norm_samples[i * inputDim + j] = float((Samples[i * inputDim + j] - mean[j]) / std[j]);
				}
			}
			else//Regresyon
			{
				norm_samples = new float[numSample];
				norm_targets = new float[numSample];

				for (int i = 0; i < numSample; i++)
				{
					norm_samples[i] = (Samples[i * inputDim] - mean[0]) / std[0];//x'ler
					norm_targets[i] = (Samples[i * inputDim + 1] - mean[1]) / std[1];//y'ler
				}
			}

			chart1->Series["Series1"]->Points->Clear();
			
			//eðitim kýsmý
			do {
				total_error = 0;
				for (int step = 0; step < numSample; step++)
				{
					//Forward
					for (int l = 0; l < layer; l++)
					{
						for (int k = 0; k < neuron_count[l]; k++)
						{
							net[sums[l][0] + k] = 0.0f;
							if (l == 0)//Ýlk katman
							{
								if (class_count > 1)
								{
									for (int i = 0; i < inputDim; i++)
									{
										net[sums[l][0] + k] += Weights[sums[l][1] + k * inputDim + i] * norm_samples[step * inputDim + i];
									}
								}
								else//Regresyon
								{
									net[sums[l][0] + k] += Weights[sums[l][1] + k] * norm_samples[step];
								}
							}
							else//Ara katmanlar ve son katman
							{
								for (int i = 0; i < neuron_count[l - 1]; i++)// l-1 almamýzýn sebebi ilk yerde inputDim i kullanýyor olmamýz.
								{
									net[sums[l][0] + k] += Weights[sums[l][1] + k * neuron_count[l - 1] + i] * f_net[sums[l - 1][0] + i];
								}
							}
							net[sums[l][0] + k] += bias[sums[l][0] + k];

							if (class_count == 1 && l == layer - 1)//Regresyonun son katmaný için 
							{
								f_net[sums[l][0] + k] = net[sums[l][0] + k];
								f_der[sums[l][0] + k] = 1.0f; 
							}
							else
							{
								f_net[sums[l][0] + k] = 2.0f / (1 + Math::Exp(-net[sums[l][0] + k])) - 1;
								f_der[sums[l][0] + k] = 0.5f * (1.0f - (f_net[sums[l][0] + k] * f_net[sums[l][0] + k]));
							}
						}
					}

					//Geri Besleme
					for (int l = layer - 1; l >= 0; l--)
					{
						for (int k = 0; k < neuron_count[l]; k++)
						{	
							//Delta Hesabý
							if (l == layer - 1)//Son katman
							{
								if (class_count == 1)//Regresyon
								{
									error = norm_targets[step] - f_net[sums[l][0] + k];
									delta[sums[l][0] + k] = error;
								}
								else//Sýnýflandýrma
								{
									//Doðru hedef
									if (targets[step] == k) desired[k] = 1.0f;
									else desired[k] = -1.0f;

									// hata hesaplama
									error = desired[k] - f_net[sums[l][0] + k];
									delta[sums[l][0] + k] = error * f_der[sums[l][0] + k];
								}
								total_error += Math::Abs(error);
							}
							else //Ara katmanlar ve son katman
							{
								delta[sums[l][0] + k] = 0;
								for (int n = 0; n < neuron_count[l + 1]; n++)
								{
									delta[sums[l][0] + k] += delta[sums[l + 1][0] + n] * f_der[sums[l][0] + k] * Weights[sums[l + 1][1] + n * neuron_count[l] + k];
								}
							}
							
							//Weight Hesabý
							if (l == 0)//Ýlk katman
							{
								if (class_count > 1)//Sýnýflandýrma
								{
									for (int i = 0; i < inputDim; i++)
									{
										float gradient_step = learning_rate * delta[sums[l][0] + k] * norm_samples[step * inputDim + i];//Momentum
										float velocity = alpha * prev_diffs[sums[l][1] + k * inputDim + i] + gradient_step;

										Weights[sums[l][1] + k * inputDim + i] += velocity;
										prev_diffs[sums[l][1] + k * inputDim + i] = velocity;
									}
								}
								else//Regresyon
								{
									float gradient_step = learning_rate * delta[sums[l][0] + k] * norm_samples[step];//Momentum
									float velocity = alpha * prev_diffs[sums[l][1] + k ] + gradient_step;

									Weights[sums[l][1] + k] += velocity;
									prev_diffs[sums[l][1] + k] = velocity;
								}
							}
							else //Ara katmanlar ve son katman
							{
								for (int i = 0; i < neuron_count[l - 1]; i++)
								{
									float gradient_step = learning_rate * delta[sums[l][0] + k] * f_net[sums[l - 1][0] + i];
									float velocity = alpha * prev_diffs[sums[l][1] + k * neuron_count[l - 1] + i] + gradient_step;

									Weights[sums[l][1] + k * neuron_count[l - 1] + i] += velocity;
									prev_diffs[sums[l][1] + k * neuron_count[l - 1] + i] = velocity;
								}
							}
							bias[sums[l][0] + k] += learning_rate * delta[sums[l][0] + k];
						}
					}
				}
				temp[epoch] = total_error/(numSample * class_count);
				epoch++;
			} while ((epoch < max_epoch) && (total_error / (numSample * class_count)) > min_error);

			//hata grafiði çizimi
			chart1->Refresh();
			for (int i = 0; i < epoch; i++)
			{
				chart1->Series["Series1"]->Points->AddXY(i, temp[i]);
			}

			for (int i = 0; i <= layer; i++) delete[] sums[i];
			delete[] sums;

			delete[] desired;
			delete[] norm_samples;
			if (class_count == 1) delete[] norm_targets;

			delete[] net;
			delete[] f_net;
			delete[] f_der;
			delete[] delta;
			delete[] temp;

			//direkt teste göndersin diye
			//testingToolStripMenuItem_Click(sender, e);
		}
};
}

