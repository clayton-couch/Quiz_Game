#pragma once
#include <iostream>
#include <Windows.h>
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>

namespace QuizGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Welcome_Screen
	/// </summary>
	public ref class Welcome_Screen : public System::Windows::Forms::Form
	{
	public:
		Welcome_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		int get_quiz_type() {
			return timed_quiz;
		}
		bool close_program = false;
	public: static bool ShowYesNoMessageBox(String^ message, String^ caption)
	{
		// Convert System::String to std::wstring
		pin_ptr<const wchar_t> pinnedMessage = PtrToStringChars(message);
		pin_ptr<const wchar_t> pinnedCaption = PtrToStringChars(caption);

		// Display a message box with Yes and No buttons
		System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(gcnew String(pinnedMessage), gcnew String(pinnedCaption), MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		// Check the user's response
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			// User clicked Yes
			return true;
		}
		else
		{
			// User clicked No
			return false;
		}
	}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;

	private: System::Windows::Forms::PictureBox^ btn_close;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Panel^ pnl_timed_quiz;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Panel^ pnl_regular_quiz;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::Button^ button3;






	public:
		System::Windows::Forms::ListBox^ list_top_scores;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Welcome_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnContinue;
	private: int timed_quiz = 0;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Welcome_Screen::typeid));
			this->btnContinue = (gcnew System::Windows::Forms::Button());
			this->list_top_scores = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pnl_timed_quiz = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pnl_regular_quiz = (gcnew System::Windows::Forms::Panel());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->pnl_timed_quiz->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->pnl_regular_quiz->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->SuspendLayout();
			// 
			// btnContinue
			// 
			this->btnContinue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnContinue->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnContinue->Location = System::Drawing::Point(212, 82);
			this->btnContinue->Margin = System::Windows::Forms::Padding(4);
			this->btnContinue->Name = L"btnContinue";
			this->btnContinue->Size = System::Drawing::Size(240, 70);
			this->btnContinue->TabIndex = 0;
			this->btnContinue->Text = L"Continue";
			this->btnContinue->UseVisualStyleBackColor = false;
			this->btnContinue->Click += gcnew System::EventHandler(this, &Welcome_Screen::btnContinue_Click);
			// 
			// list_top_scores
			// 
			this->list_top_scores->BackColor = System::Drawing::Color::White;
			this->list_top_scores->Font = (gcnew System::Drawing::Font(L"Poor Richard", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->list_top_scores->ForeColor = System::Drawing::Color::Black;
			this->list_top_scores->FormattingEnabled = true;
			this->list_top_scores->ItemHeight = 31;
			this->list_top_scores->Location = System::Drawing::Point(212, 114);
			this->list_top_scores->Margin = System::Windows::Forms::Padding(4);
			this->list_top_scores->Name = L"list_top_scores";
			this->list_top_scores->Size = System::Drawing::Size(256, 345);
			this->list_top_scores->TabIndex = 1;
			this->list_top_scores->SelectedIndexChanged += gcnew System::EventHandler(this, &Welcome_Screen::list_top_scores_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(497, 114);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(148, 127);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Welcome_Screen::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-2, 82);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(195, 73);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(189, 13);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(352, 93);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(4, 4);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(192, 62);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 8;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(0, 13);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(192, 62);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 9;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(254, 4);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(117, 65);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 10;
			this->pictureBox8->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(661, 0);
			this->btn_close->Margin = System::Windows::Forms::Padding(4);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(55, 49);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 12;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Welcome_Screen::btn_close_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(249, 88);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(207, 70);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Welcome_Screen::button1_Click);
			// 
			// pnl_timed_quiz
			// 
			this->pnl_timed_quiz->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pnl_timed_quiz->Controls->Add(this->pictureBox4);
			this->pnl_timed_quiz->Controls->Add(this->pictureBox6);
			this->pnl_timed_quiz->Controls->Add(this->pictureBox8);
			this->pnl_timed_quiz->Controls->Add(this->button1);
			this->pnl_timed_quiz->Location = System::Drawing::Point(127, 470);
			this->pnl_timed_quiz->Name = L"pnl_timed_quiz";
			this->pnl_timed_quiz->Size = System::Drawing::Size(460, 162);
			this->pnl_timed_quiz->TabIndex = 15;
			this->pnl_timed_quiz->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(405, 0);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(55, 49);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 17;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &Welcome_Screen::pictureBox4_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Impact", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(427, 631);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(273, 109);
			this->button2->TabIndex = 16;
			this->button2->Text = L"TIMED QUESTIONS";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Welcome_Screen::button2_Click);
			// 
			// pnl_regular_quiz
			// 
			this->pnl_regular_quiz->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pnl_regular_quiz->Controls->Add(this->pictureBox9);
			this->pnl_regular_quiz->Controls->Add(this->pictureBox7);
			this->pnl_regular_quiz->Controls->Add(this->btnContinue);
			this->pnl_regular_quiz->Controls->Add(this->pictureBox2);
			this->pnl_regular_quiz->Location = System::Drawing::Point(127, 470);
			this->pnl_regular_quiz->Name = L"pnl_regular_quiz";
			this->pnl_regular_quiz->Size = System::Drawing::Size(458, 155);
			this->pnl_regular_quiz->TabIndex = 17;
			this->pnl_regular_quiz->Visible = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(403, 0);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(55, 49);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 18;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &Welcome_Screen::pictureBox9_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Impact", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(3, 630);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(273, 110);
			this->button3->TabIndex = 18;
			this->button3->Text = L"REGULAR QUESTIONS";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Welcome_Screen::button3_Click);
			// 
			// Welcome_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(712, 752);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pnl_regular_quiz);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pnl_timed_quiz);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->list_top_scores);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Welcome_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome_Screen";
			this->Load += gcnew System::EventHandler(this, &Welcome_Screen::Welcome_Screen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->pnl_timed_quiz->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->pnl_regular_quiz->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnContinue_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void list_top_scores_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Welcome_Screen_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timed_quiz = 1;
		this->Close();
	}
	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ message = "Are you sure you want to exit?";  //Phindile edited this from warning to a confirmation
		String^ caption = "Confirmation";

		bool userResponse = ShowYesNoMessageBox(message, caption);

		if (userResponse)
		{
			close_program = true;
			this->Close();


		}
		else
		{
			// User clicked No
			// Do something...

		}

	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	pnl_timed_quiz->Visible = true;
	pnl_regular_quiz->Visible = false;
}
private: System::Void pictureBox4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	pnl_timed_quiz->Visible = false;
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	pnl_regular_quiz->Visible = true;
	pnl_timed_quiz->Visible = false;
}
private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) {
	pnl_regular_quiz->Visible = false;
}
};
}
