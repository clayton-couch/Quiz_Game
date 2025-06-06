#pragma once
#include <string>
#include <cctype>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <vcclr.h>

namespace QuizGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Special_Questions
	/// </summary>
	public ref class Special_Questions : public System::Windows::Forms::Form
	{
	public:
		Special_Questions(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		System::String^ StdStringToSystemString(const std::string& str)
		{
			return gcnew System::String(str.c_str());
		}

		std::string SystemStringToStdString(System::String^ str)
		{
			return msclr::interop::marshal_as<std::string>(str);
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
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	public: System::Windows::Forms::Panel^ pnl_Answer;
	public: System::Windows::Forms::Label^ lbl_Answer;

	private: System::Windows::Forms::PictureBox^ btn_close;
	public: System::Windows::Forms::Label^ lbl_progress;
	private: System::Windows::Forms::Button^ btn_show_answer;
	public: System::Windows::Forms::Label^ lbl_Question;

	public:

	public:

	public:

	public:

	public:
	private:
	public:
		int secondsLeft;
		System::String^ get_answer() {
			return answer;
		}
		bool is_time_up() {
			return times_up;
		}
		int get_current_time() {
			return secondsLeft;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Special_Questions()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool times_up = false;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::String^ answer;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	public: bool close_program = false;
	public: System::Windows::Forms::PictureBox^ heart_1;
	public: System::Windows::Forms::PictureBox^ heart_3;
	public: System::Windows::Forms::PictureBox^ heart_2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ txt_Answer;
	private: int minutes_remaining;
	private: int seconds_remaining;
	private: System::String^ time_left_string;


	private: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Timer^ timer1;
	public: System::Windows::Forms::Label^ lbl_Current_Score;
	public: System::Windows::Forms::Label^ lbl_difficulty;
	private: System::Windows::Forms::Label^ lbl_time;
	private: int pnl_time = 3;
	private: std::string toLower(const std::string& str) {
		std::string result;
		result.reserve(str.size()); // Reserve space for efficiency

		for (char c : str) {
			result += std::tolower(c);
		}

		return result;



	}

	public: Control^ getControl(String^ controlName)
	{
		if (controlName == "panel1")
			return panel1;
		else
			return nullptr;
	}



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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Special_Questions::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->heart_1 = (gcnew System::Windows::Forms::PictureBox());
			this->heart_3 = (gcnew System::Windows::Forms::PictureBox());
			this->heart_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_Question = (gcnew System::Windows::Forms::Label());
			this->pnl_Answer = (gcnew System::Windows::Forms::Panel());
			this->lbl_Answer = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_Answer = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_Current_Score = (gcnew System::Windows::Forms::Label());
			this->lbl_difficulty = (gcnew System::Windows::Forms::Label());
			this->lbl_time = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_progress = (gcnew System::Windows::Forms::Label());
			this->btn_show_answer = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart_2))->BeginInit();
			this->panel1->SuspendLayout();
			this->pnl_Answer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(138, 21);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(12, 115);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(138, 29);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Special_Questions::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 71);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(138, 21);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(353, 44);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(138, 21);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// heart_1
			// 
			this->heart_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heart_1.Image")));
			this->heart_1->Location = System::Drawing::Point(366, 71);
			this->heart_1->Name = L"heart_1";
			this->heart_1->Size = System::Drawing::Size(35, 35);
			this->heart_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->heart_1->TabIndex = 4;
			this->heart_1->TabStop = false;
			// 
			// heart_3
			// 
			this->heart_3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heart_3.Image")));
			this->heart_3->Location = System::Drawing::Point(448, 71);
			this->heart_3->Name = L"heart_3";
			this->heart_3->Size = System::Drawing::Size(35, 35);
			this->heart_3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->heart_3->TabIndex = 5;
			this->heart_3->TabStop = false;
			// 
			// heart_2
			// 
			this->heart_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heart_2.Image")));
			this->heart_2->Location = System::Drawing::Point(407, 71);
			this->heart_2->Name = L"heart_2";
			this->heart_2->Size = System::Drawing::Size(35, 35);
			this->heart_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->heart_2->TabIndex = 6;
			this->heart_2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lbl_Question);
			this->panel1->Controls->Add(this->pnl_Answer);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->txt_Answer);
			this->panel1->Location = System::Drawing::Point(12, 236);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(510, 249);
			this->panel1->TabIndex = 7;
			// 
			// lbl_Question
			// 
			this->lbl_Question->AutoSize = true;
			this->lbl_Question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Question->Location = System::Drawing::Point(19, 39);
			this->lbl_Question->Name = L"lbl_Question";
			this->lbl_Question->Size = System::Drawing::Size(51, 16);
			this->lbl_Question->TabIndex = 4;
			this->lbl_Question->Text = L"label1";
			// 
			// pnl_Answer
			// 
			this->pnl_Answer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_Answer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnl_Answer->Controls->Add(this->lbl_Answer);
			this->pnl_Answer->Location = System::Drawing::Point(105, 113);
			this->pnl_Answer->Name = L"pnl_Answer";
			this->pnl_Answer->Size = System::Drawing::Size(309, 136);
			this->pnl_Answer->TabIndex = 3;
			// 
			// lbl_Answer
			// 
			this->lbl_Answer->AutoSize = true;
			this->lbl_Answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Answer->ForeColor = System::Drawing::Color::Red;
			this->lbl_Answer->Location = System::Drawing::Point(7, 27);
			this->lbl_Answer->Name = L"lbl_Answer";
			this->lbl_Answer->Size = System::Drawing::Size(41, 13);
			this->lbl_Answer->TabIndex = 2;
			this->lbl_Answer->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(16, 141);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Answer:";
			// 
			// txt_Answer
			// 
			this->txt_Answer->ForeColor = System::Drawing::SystemColors::Highlight;
			this->txt_Answer->Location = System::Drawing::Point(105, 143);
			this->txt_Answer->Name = L"txt_Answer";
			this->txt_Answer->Size = System::Drawing::Size(319, 20);
			this->txt_Answer->TabIndex = 0;
			this->txt_Answer->TextChanged += gcnew System::EventHandler(this, &Special_Questions::txt_Answer_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(178, 501);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 86);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Special_Questions::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Special_Questions::timer1_Tick);
			// 
			// lbl_Current_Score
			// 
			this->lbl_Current_Score->AutoSize = true;
			this->lbl_Current_Score->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_Current_Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Current_Score->ForeColor = System::Drawing::Color::Red;
			this->lbl_Current_Score->Location = System::Drawing::Point(165, 14);
			this->lbl_Current_Score->Name = L"lbl_Current_Score";
			this->lbl_Current_Score->Size = System::Drawing::Size(0, 20);
			this->lbl_Current_Score->TabIndex = 9;
			// 
			// lbl_difficulty
			// 
			this->lbl_difficulty->AutoSize = true;
			this->lbl_difficulty->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_difficulty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_difficulty->ForeColor = System::Drawing::Color::Red;
			this->lbl_difficulty->Location = System::Drawing::Point(165, 72);
			this->lbl_difficulty->Name = L"lbl_difficulty";
			this->lbl_difficulty->Size = System::Drawing::Size(0, 20);
			this->lbl_difficulty->TabIndex = 10;
			// 
			// lbl_time
			// 
			this->lbl_time->AutoSize = true;
			this->lbl_time->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_time->ForeColor = System::Drawing::Color::Red;
			this->lbl_time->Location = System::Drawing::Point(165, 124);
			this->lbl_time->Name = L"lbl_time";
			this->lbl_time->Size = System::Drawing::Size(0, 20);
			this->lbl_time->TabIndex = 11;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(353, 115);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(169, 115);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 12;
			this->pictureBox5->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::Control;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(491, -7);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(45, 45);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 13;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Special_Questions::btn_close_Click);
			// 
			// lbl_progress
			// 
			this->lbl_progress->AutoSize = true;
			this->lbl_progress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_progress->Location = System::Drawing::Point(320, 9);
			this->lbl_progress->Name = L"lbl_progress";
			this->lbl_progress->Size = System::Drawing::Size(57, 20);
			this->lbl_progress->TabIndex = 14;
			this->lbl_progress->Text = L"label1";
			// 
			// btn_show_answer
			// 
			this->btn_show_answer->Enabled = false;
			this->btn_show_answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_show_answer->Location = System::Drawing::Point(369, 501);
			this->btn_show_answer->Name = L"btn_show_answer";
			this->btn_show_answer->Size = System::Drawing::Size(122, 35);
			this->btn_show_answer->TabIndex = 26;
			this->btn_show_answer->Text = L"Check Answer";
			this->btn_show_answer->UseVisualStyleBackColor = true;
			this->btn_show_answer->Click += gcnew System::EventHandler(this, &Special_Questions::btn_show_answer_Click);
			// 
			// Special_Questions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 611);
			this->Controls->Add(this->btn_show_answer);
			this->Controls->Add(this->lbl_progress);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->lbl_time);
			this->Controls->Add(this->lbl_difficulty);
			this->Controls->Add(this->lbl_Current_Score);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->heart_2);
			this->Controls->Add(this->heart_3);
			this->Controls->Add(this->heart_1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Special_Questions";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Special_Questions";
			this->Load += gcnew System::EventHandler(this, &Special_Questions::Special_Questions_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart_2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->pnl_Answer->ResumeLayout(false);
			this->pnl_Answer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		answer = txt_Answer->Text;
		if (!String::IsNullOrEmpty(txt_Answer->Text)) {
			this->Close();
		}
		else {
			MessageBox::Show("Please enter an answer.", "No Input.", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

private: System::Void Special_Questions_Load(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void btn_show_answer_Click(System::Object^ sender, System::EventArgs^ e) {
	btn_show_answer->Enabled = false;
	if (!String::IsNullOrEmpty(txt_Answer->Text)) {
		
		answer = txt_Answer->Text;
		

		if (toLower(SystemStringToStdString(lbl_Answer->Text)) == toLower(SystemStringToStdString(txt_Answer->Text))) {

			
			pnl_Answer->BackColor = System::Drawing::Color::MediumAquamarine;
			lbl_Answer->ForeColor = System::Drawing::Color::Green;

			//Making sure the feedback fits properly in the panel
			String^ feedbackMessage = "Your answer is correct!";

			array<String^>^ lines = feedbackMessage->Split('\n');
			lbl_Answer->Text = feedbackMessage;

			lbl_Answer->AutoSize = true;
			lbl_Answer->MaximumSize = System::Drawing::Size(pnl_Answer->Width, 0);
		}
		else {
			

			//Making sure the feedback fits properly in the panel
			String^ feedbackMessage = "Incorrect answer! The correct answer is: " + lbl_Answer->Text;

			array<String^>^ lines = feedbackMessage->Split('\n');
			lbl_Answer->Text = feedbackMessage;

			lbl_Answer->AutoSize = true;
			lbl_Answer->MaximumSize = System::Drawing::Size(pnl_Answer->Width, 0);

		}

		

	}
	pnl_Answer->Visible = true;

}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	secondsLeft--;

	if (secondsLeft <= 0)
	{
		answer = " ";
		bool times_up = true;

		this->Close();
		timer1->Stop();




	}
	else
	{

		if (secondsLeft > 60) {
			seconds_remaining = secondsLeft % 60;
			minutes_remaining = (secondsLeft - seconds_remaining) / 60;
			time_left_string = "Time left: " + StdStringToSystemString(std::to_string(minutes_remaining)) + " minutes and " + StdStringToSystemString(std::to_string(seconds_remaining)) + " seconds.";
		}
		else {
			time_left_string = "Time left: " + StdStringToSystemString(std::to_string(secondsLeft)) + " seconds.";
		}


		lbl_time->Text = time_left_string;
	}
	
}

private: System::Void txt_Answer_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (txt_Answer->Text->Length > 0) {
		btn_show_answer->Enabled = true;
		
	}
	else {
		btn_show_answer->Enabled = false;
	}

}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}
