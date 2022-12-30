#pragma once
# define M_PI 3.14
#include <math.h>

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(607, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 125);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(560, 560);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(607, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 77);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(708, 159);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(87, 77);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Pause";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 584);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"WinFormGraph";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
	}
	private: int x = 280, y = 280; int angle = 2.0f; int a = 10, b = 2, i = 0;
		   
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = pictureBox1->CreateGraphics();
		if (x >= 500 || y >= 500) {
			pictureBox1->Invalidate();
			x = 280; y = 280; angle = 2.0f; i = 0;
		}
		g->DrawEllipse(Pens::Red, x, y, 10, 10);
		angle = 2 * i;
		x = ((a + b * angle) * cos(angle)) + x;
		y = ((a + b * angle) * sin(angle)) + y;
		i++;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Stop();
		pictureBox1->Invalidate();
		x = 280; y = 280; angle = 2.0f; i = 0;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Stop();
	}
	
};
}
