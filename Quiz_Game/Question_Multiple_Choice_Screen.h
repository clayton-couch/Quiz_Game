#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <vcclr.h>
#include <msclr/marshal.h>

namespace QuizGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Question_Multiple_Choice_Screen
	/// </summary>
	public ref class Question_Multiple_Choice_Screen : public System::Windows::Forms::Form
	{
	public:
		Question_Multiple_Choice_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
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

		  // Use this method to access panel in main method
	public:	  Control^ getControl(String^ controlName)
		{
			if (controlName == "panel2")
				return panel2;
			else
				return nullptr;
		}

	private: System::Windows::Forms::Button^ btn_show_answer;
	public: System::Windows::Forms::Label^ lbl_progress;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	public:
	private:
	public:
		bool close_program = false;
		int get_answer() {
			return answer;
		}
		System::Windows::Forms::Label^ lbl_Question;
		System::Windows::Forms::RadioButton^ Choice_1;
		System::Windows::Forms::RadioButton^ Choice_2;
		System::Windows::Forms::RadioButton^ Choice_3;
		System::Windows::Forms::Label^ lbl_Current_Score;
	public: System::Windows::Forms::Label^ lbl_difficulty;
	private: System::Windows::Forms::PictureBox^ pictureBox4;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	public: System::Windows::Forms::Panel^ pnl_Answer;
	public: System::Windows::Forms::Label^ lbl_Answer;

	
	private: System::Windows::Forms::PictureBox^ btn_close;
	public:

	public:


	public:
	public:
		System::Windows::Forms::RadioButton^ Choice_4;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Question_Multiple_Choice_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::String^ StdStringToSystemString(const std::string& str)
	{
		return gcnew System::String(str.c_str());
	}

		  std::string SystemStringToStdString(System::String^ str)
		  {
			  return msclr::interop::marshal_as<std::string>(str);
		  }

	protected:

	private: System::Windows::Forms::Button^ btn_Continue;
	private: int answer = 0;
	private: System::ComponentModel::IContainer^ components;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Question_Multiple_Choice_Screen::typeid));
			this->lbl_Question = (gcnew System::Windows::Forms::Label());
			this->Choice_1 = (gcnew System::Windows::Forms::RadioButton());
			this->Choice_2 = (gcnew System::Windows::Forms::RadioButton());
			this->Choice_3 = (gcnew System::Windows::Forms::RadioButton());
			this->Choice_4 = (gcnew System::Windows::Forms::RadioButton());
			this->btn_Continue = (gcnew System::Windows::Forms::Button());
			this->lbl_Current_Score = (gcnew System::Windows::Forms::Label());
			this->lbl_difficulty = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pnl_Answer = (gcnew System::Windows::Forms::Panel());
			this->lbl_Answer = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			this->btn_show_answer = (gcnew System::Windows::Forms::Button());
			this->lbl_progress = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel1->SuspendLayout();
			this->pnl_Answer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Question
			// 
			this->lbl_Question->AutoSize = true;
			this->lbl_Question->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_Question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Question->Location = System::Drawing::Point(5, 16);
			this->lbl_Question->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_Question->Name = L"lbl_Question";
			this->lbl_Question->Size = System::Drawing::Size(46, 17);
			this->lbl_Question->TabIndex = 0;
			this->lbl_Question->Text = L"label1";
			// 
			// Choice_1
			// 
			this->Choice_1->AutoSize = true;
			this->Choice_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Choice_1->Location = System::Drawing::Point(9, 18);
			this->Choice_1->Margin = System::Windows::Forms::Padding(4);
			this->Choice_1->Name = L"Choice_1";
			this->Choice_1->Size = System::Drawing::Size(125, 24);
			this->Choice_1->TabIndex = 1;
			this->Choice_1->TabStop = true;
			this->Choice_1->Text = L"radioButton1";
			this->Choice_1->UseVisualStyleBackColor = true;
			this->Choice_1->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::Choice_1_CheckedChanged);
			// 
			// Choice_2
			// 
			this->Choice_2->AutoSize = true;
			this->Choice_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Choice_2->Location = System::Drawing::Point(9, 63);
			this->Choice_2->Margin = System::Windows::Forms::Padding(4);
			this->Choice_2->Name = L"Choice_2";
			this->Choice_2->Size = System::Drawing::Size(125, 24);
			this->Choice_2->TabIndex = 2;
			this->Choice_2->TabStop = true;
			this->Choice_2->Text = L"radioButton2";
			this->Choice_2->UseVisualStyleBackColor = true;
			this->Choice_2->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::Choice_2_CheckedChanged);
			// 
			// Choice_3
			// 
			this->Choice_3->AutoSize = true;
			this->Choice_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Choice_3->Location = System::Drawing::Point(9, 110);
			this->Choice_3->Margin = System::Windows::Forms::Padding(4);
			this->Choice_3->Name = L"Choice_3";
			this->Choice_3->Size = System::Drawing::Size(125, 24);
			this->Choice_3->TabIndex = 3;
			this->Choice_3->TabStop = true;
			this->Choice_3->Text = L"radioButton3";
			this->Choice_3->UseVisualStyleBackColor = true;
			this->Choice_3->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::Choice_3_CheckedChanged);
			// 
			// Choice_4
			// 
			this->Choice_4->AutoSize = true;
			this->Choice_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Choice_4->Location = System::Drawing::Point(9, 154);
			this->Choice_4->Margin = System::Windows::Forms::Padding(4);
			this->Choice_4->Name = L"Choice_4";
			this->Choice_4->Size = System::Drawing::Size(125, 24);
			this->Choice_4->TabIndex = 4;
			this->Choice_4->TabStop = true;
			this->Choice_4->Text = L"radioButton4";
			this->Choice_4->UseVisualStyleBackColor = true;
			this->Choice_4->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::Choice_4_CheckedChanged);
			// 
			// btn_Continue
			// 
			this->btn_Continue->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Continue->Location = System::Drawing::Point(287, 663);
			this->btn_Continue->Margin = System::Windows::Forms::Padding(4);
			this->btn_Continue->Name = L"btn_Continue";
			this->btn_Continue->Size = System::Drawing::Size(240, 70);
			this->btn_Continue->TabIndex = 5;
			this->btn_Continue->Text = L"Continue";
			this->btn_Continue->UseVisualStyleBackColor = true;
			this->btn_Continue->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::btn_Continue_Click);
			// 
			// lbl_Current_Score
			// 
			this->lbl_Current_Score->AutoSize = true;
			this->lbl_Current_Score->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_Current_Score->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Current_Score->ForeColor = System::Drawing::Color::Red;
			this->lbl_Current_Score->Location = System::Drawing::Point(565, 130);
			this->lbl_Current_Score->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_Current_Score->Name = L"lbl_Current_Score";
			this->lbl_Current_Score->Size = System::Drawing::Size(60, 23);
			this->lbl_Current_Score->TabIndex = 6;
			this->lbl_Current_Score->Text = L"label1";
			// 
			// lbl_difficulty
			// 
			this->lbl_difficulty->AutoSize = true;
			this->lbl_difficulty->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_difficulty->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_difficulty->ForeColor = System::Drawing::Color::Red;
			this->lbl_difficulty->Location = System::Drawing::Point(16, 130);
			this->lbl_difficulty->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_difficulty->Name = L"lbl_difficulty";
			this->lbl_difficulty->Size = System::Drawing::Size(60, 23);
			this->lbl_difficulty->TabIndex = 7;
			this->lbl_difficulty->Text = L"label1";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(3, 172);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(151, 123);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 8;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::pictureBox4_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Controls->Add(this->pnl_Answer);
			this->panel1->Controls->Add(this->Choice_1);
			this->panel1->Controls->Add(this->Choice_2);
			this->panel1->Controls->Add(this->Choice_3);
			this->panel1->Controls->Add(this->Choice_4);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(69, 433);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(576, 226);
			this->panel1->TabIndex = 10;
			// 
			// pnl_Answer
			// 
			this->pnl_Answer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_Answer->Controls->Add(this->lbl_Answer);
			this->pnl_Answer->Location = System::Drawing::Point(181, 33);
			this->pnl_Answer->Margin = System::Windows::Forms::Padding(4);
			this->pnl_Answer->Name = L"pnl_Answer";
			this->pnl_Answer->Size = System::Drawing::Size(381, 190);
			this->pnl_Answer->TabIndex = 5;
			this->pnl_Answer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Question_Multiple_Choice_Screen::pnl_Answer_Paint);
			// 
			// lbl_Answer
			// 
			this->lbl_Answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Answer->ForeColor = System::Drawing::Color::Red;
			this->lbl_Answer->Location = System::Drawing::Point(32, 30);
			this->lbl_Answer->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_Answer->Name = L"lbl_Answer";
			this->lbl_Answer->Size = System::Drawing::Size(52, 17);
			this->lbl_Answer->TabIndex = 0;
			this->lbl_Answer->Text = L"label1";
			this->lbl_Answer->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::lbl_Answer_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(73, 156);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(96, 70);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->Controls->Add(this->lbl_Question);
			this->panel2->Location = System::Drawing::Point(69, 303);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(576, 123);
			this->panel2->TabIndex = 11;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(3, 94);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(236, 33);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(460, 94);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(236, 33);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(656, 1);
			this->btn_close->Margin = System::Windows::Forms::Padding(4);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(55, 49);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 16;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::btn_close_Click);
			// 
			// btn_show_answer
			// 
			this->btn_show_answer->Enabled = false;
			this->btn_show_answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_show_answer->Location = System::Drawing::Point(533, 663);
			this->btn_show_answer->Margin = System::Windows::Forms::Padding(4);
			this->btn_show_answer->Name = L"btn_show_answer";
			this->btn_show_answer->Size = System::Drawing::Size(163, 43);
			this->btn_show_answer->TabIndex = 17;
			this->btn_show_answer->Text = L"Check Answer";
			this->btn_show_answer->UseVisualStyleBackColor = true;
			this->btn_show_answer->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::btn_show_answer_Click);
			// 
			// lbl_progress
			// 
			this->lbl_progress->AutoSize = true;
			this->lbl_progress->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_progress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_progress->Location = System::Drawing::Point(412, 49);
			this->lbl_progress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_progress->Name = L"lbl_progress";
			this->lbl_progress->Size = System::Drawing::Size(70, 25);
			this->lbl_progress->TabIndex = 18;
			this->lbl_progress->Text = L"label1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(100, 679);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 44);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Skip Question";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(535, 709);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(161, 28);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::button2_Click);
			// 
			// Question_Multiple_Choice_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(712, 752);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lbl_progress);
			this->Controls->Add(this->btn_show_answer);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->lbl_difficulty);
			this->Controls->Add(this->lbl_Current_Score);
			this->Controls->Add(this->btn_Continue);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Question_Multiple_Choice_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Question_Multiple_Choice_Screen";
			this->Load += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::Question_Multiple_Choice_Screen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->pnl_Answer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Choice_1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		answer = 1;
		
		

	}
	private: System::Void Choice_2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		answer = 2;
		
	}
	private: System::Void Choice_3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		answer = 3;
		
	}
	private: System::Void Choice_4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		answer = 4;
		
	}
	private: System::Void btn_Continue_Click(System::Object^ sender, System::EventArgs^ e) {
		if (answer > 0) {
			this->Close();
		}
		else {
			if (showAnswerButtonClicked) {
				this->Close();
			}
			else {
				String^ message = "Continue to the next question without answering?";  //Phindile edited this from warning to a confirmation
				String^ caption = "Confirmation";

				bool userResponse = ShowYesNoMessageBox(message, caption);

				if (userResponse)
				{
					if (lbl_Answer->Text == "1") {
						answer = 2;
					}
					else if (lbl_Answer->Text == "2") {
						answer = 1;
					}
					else if (lbl_Answer->Text == "3") {
						answer = 4;
					}
					else {
						answer = 3;
					}

					this->Close();

				}
				else
				{
					// User clicked No
					// Do something...

				}
			}
		}

	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	// Phindile edited this to ensure that the "Show Button is disabled unless at least one option is selected
	private: System::Void Question_Multiple_Choice_Screen_Load(System::Object^ sender, System::EventArgs^ e) {
		btn_show_answer->Enabled = false;
		button1->Enabled = true;

		Choice_1->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::RadioButton_CheckedChanged);
		Choice_2->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::RadioButton_CheckedChanged);
		Choice_3->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::RadioButton_CheckedChanged);
		Choice_4->CheckedChanged += gcnew System::EventHandler(this, &Question_Multiple_Choice_Screen::RadioButton_CheckedChanged);
	}

    // Phindile edited this to ensure that the "Show Button is disabled unless at least one option is selected
	private: void RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Choice_1->Checked == true || Choice_2->Checked == true || Choice_3->Checked == true || Choice_4->Checked == true) {
			btn_show_answer->Enabled = true;
		}
		else {
			btn_show_answer->Enabled = false;
		}
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

	private: bool showAnswerButtonClicked = false;


	private: System::Void btn_show_answer_Click(System::Object^ sender, System::EventArgs^ e) {		
		button1->Enabled = false;  // Disable skip button
		button2->Enabled = false;  // Disable clear button

		if (lbl_Answer->Text == StdStringToSystemString(std::to_string(answer))) {

		    pnl_Answer->BackColor = System::Drawing::Color::MediumAquamarine;
			lbl_Answer->ForeColor = System::Drawing::Color::Green;

			// Making sure feedback fits properly into the panel
			String^ feedbackMessage = "Your answer is correct!";

			array<String^>^ lines = feedbackMessage->Split('\n');
			lbl_Answer->Text = feedbackMessage;

			lbl_Answer->AutoSize = true;
			lbl_Answer->MaximumSize = System::Drawing::Size(pnl_Answer->Width, 0);

		}
		else {

			if (lbl_Answer->Text == "1") {
				lbl_Answer->Text = "A";
			}
			else if (lbl_Answer->Text == "2") {
				lbl_Answer->Text = "B";
			}
			else if (lbl_Answer->Text == "3") {
				lbl_Answer->Text = "C";
			}
			else {
				lbl_Answer->Text = "D";
			}

			//Making sure the feedback fits properly in the panel
			String^ feedbackMessage = "Incorrect answer! The correct answer is: " + lbl_Answer->Text;

			array<String^>^ lines = feedbackMessage->Split('\n');
			lbl_Answer->Text = feedbackMessage;

			lbl_Answer->AutoSize = true;
			lbl_Answer->MaximumSize = System::Drawing::Size(pnl_Answer->Width, 0);
			}

			pnl_Answer->Visible = true;
			showAnswerButtonClicked = true;
		
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ message = "Are you sure you want to skip?";
	String^ caption = "Confirmation";

	bool userResponse = ShowYesNoMessageBox(message, caption);

	if (userResponse)
	{
		if (lbl_Answer->Text == "1") {
			answer = 2;
		}
		else if (lbl_Answer->Text == "2") {
			answer = 1;
		}
		else if (lbl_Answer->Text == "3") {
			answer = 4;
		}
		else {
			answer = 3;
		}

		this->Close();

	}
	else
	{
		// User clicked No
		// Do something...

	}






}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	
	Choice_1->Checked = false;
	Choice_2->Checked = false;
	Choice_3->Checked = false;
	Choice_4->Checked = false;
	answer = -1;


}
private: System::Void lbl_Answer_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void pnl_Answer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

};
}
