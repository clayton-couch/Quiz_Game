#pragma once
#include <Windows.h>
#include <string>
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
	/// Summary for Question_True_False_Screen
	/// </summary>
	public ref class Question_True_False_Screen : public System::Windows::Forms::Form
	{
	public:
		Question_True_False_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		bool get_answer() {
			return answer;
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
	
		System::Windows::Forms::Label^ lbl_Current_Score;
	public: System::Windows::Forms::Label^ lbl_difficulty;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;


	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	public: bool close_program = false;
	public: System::Windows::Forms::Panel^ pnl_Answer;
	public: System::Windows::Forms::Label^ lbl_Answer;

	private: int pnl_time = 3;
	private: System::Windows::Forms::PictureBox^ btn_close;
	public: System::Windows::Forms::Label^ lbl_progress;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btn_show_answer;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RadioButton^ radio_true;
	private: System::Windows::Forms::RadioButton^ radio_false;
	private: System::Windows::Forms::Button^ button3;
	public:
	private:
	public:

	public:

	
	public:

	public:
		System::Windows::Forms::Label^ lbl_Question;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Question_True_False_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:


	private: bool answer;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Question_True_False_Screen::typeid));
			this->lbl_Question = (gcnew System::Windows::Forms::Label());
			this->lbl_Current_Score = (gcnew System::Windows::Forms::Label());
			this->lbl_difficulty = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pnl_Answer = (gcnew System::Windows::Forms::Panel());
			this->lbl_Answer = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_progress = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_show_answer = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radio_true = (gcnew System::Windows::Forms::RadioButton());
			this->radio_false = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->pnl_Answer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Question
			// 
			this->lbl_Question->AutoSize = true;
			this->lbl_Question->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_Question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Question->Location = System::Drawing::Point(3, 0);
			this->lbl_Question->Name = L"lbl_Question";
			this->lbl_Question->Size = System::Drawing::Size(35, 13);
			this->lbl_Question->TabIndex = 0;
			this->lbl_Question->Text = L"label1";
			// 
			// lbl_Current_Score
			// 
			this->lbl_Current_Score->AutoSize = true;
			this->lbl_Current_Score->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_Current_Score->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Current_Score->ForeColor = System::Drawing::Color::Red;
			this->lbl_Current_Score->Location = System::Drawing::Point(432, 74);
			this->lbl_Current_Score->Name = L"lbl_Current_Score";
			this->lbl_Current_Score->Size = System::Drawing::Size(50, 19);
			this->lbl_Current_Score->TabIndex = 3;
			this->lbl_Current_Score->Text = L"label1";
			// 
			// lbl_difficulty
			// 
			this->lbl_difficulty->AutoSize = true;
			this->lbl_difficulty->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_difficulty->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_difficulty->ForeColor = System::Drawing::Color::Red;
			this->lbl_difficulty->Location = System::Drawing::Point(12, 74);
			this->lbl_difficulty->Name = L"lbl_difficulty";
			this->lbl_difficulty->Size = System::Drawing::Size(50, 19);
			this->lbl_difficulty->TabIndex = 6;
			this->lbl_difficulty->Text = L"label1";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::SystemColors::Control;
			this->flowLayoutPanel1->Controls->Add(this->lbl_Question);
			this->flowLayoutPanel1->Controls->Add(this->pnl_Answer);
			this->flowLayoutPanel1->Location = System::Drawing::Point(44, 239);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(450, 165);
			this->flowLayoutPanel1->TabIndex = 7;
			// 
			// pnl_Answer
			// 
			this->pnl_Answer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_Answer->Controls->Add(this->lbl_Answer);
			this->pnl_Answer->Location = System::Drawing::Point(44, 3);
			this->pnl_Answer->Name = L"pnl_Answer";
			this->pnl_Answer->Size = System::Drawing::Size(364, 140);
			this->pnl_Answer->TabIndex = 1;
			this->pnl_Answer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Question_True_False_Screen::pnl_Answer_Paint);
			// 
			// lbl_Answer
			// 
			this->lbl_Answer->AutoSize = true;
			this->lbl_Answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Answer->ForeColor = System::Drawing::Color::Red;
			this->lbl_Answer->Location = System::Drawing::Point(22, 21);
			this->lbl_Answer->Name = L"lbl_Answer";
			this->lbl_Answer->Size = System::Drawing::Size(51, 16);
			this->lbl_Answer->TabIndex = 0;
			this->lbl_Answer->Text = L"label1";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(12, 119);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(113, 100);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 16;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(214, 531);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(115, 68);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(354, 44);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(177, 27);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 21;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(2, 44);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(177, 27);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 20;
			this->pictureBox6->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::Control;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(489, -7);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(45, 45);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 22;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Question_True_False_Screen::btn_close_Click);
			// 
			// lbl_progress
			// 
			this->lbl_progress->AutoSize = true;
			this->lbl_progress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_progress->Location = System::Drawing::Point(309, 18);
			this->lbl_progress->Name = L"lbl_progress";
			this->lbl_progress->Size = System::Drawing::Size(57, 20);
			this->lbl_progress->TabIndex = 23;
			this->lbl_progress->Text = L"label1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(354, 490);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 57);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Skip Question";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Question_True_False_Screen::button1_Click);
			// 
			// btn_show_answer
			// 
			this->btn_show_answer->Enabled = false;
			this->btn_show_answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_show_answer->Location = System::Drawing::Point(29, 531);
			this->btn_show_answer->Name = L"btn_show_answer";
			this->btn_show_answer->Size = System::Drawing::Size(122, 35);
			this->btn_show_answer->TabIndex = 25;
			this->btn_show_answer->Text = L"Check Answer";
			this->btn_show_answer->UseVisualStyleBackColor = true;
			this->btn_show_answer->Click += gcnew System::EventHandler(this, &Question_True_False_Screen::btn_show_answer_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(29, 490);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(122, 35);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Continue";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Question_True_False_Screen::button2_Click);
			// 
			// radio_true
			// 
			this->radio_true->AutoSize = true;
			this->radio_true->Location = System::Drawing::Point(214, 452);
			this->radio_true->Name = L"radio_true";
			this->radio_true->Size = System::Drawing::Size(50, 17);
			this->radio_true->TabIndex = 27;
			this->radio_true->TabStop = true;
			this->radio_true->Text = L"False";
			this->radio_true->UseVisualStyleBackColor = true;
			this->radio_true->CheckedChanged += gcnew System::EventHandler(this, &Question_True_False_Screen::radio_true_CheckedChanged);
			// 
			// radio_false
			// 
			this->radio_false->AutoSize = true;
			this->radio_false->Location = System::Drawing::Point(214, 427);
			this->radio_false->Name = L"radio_false";
			this->radio_false->Size = System::Drawing::Size(47, 17);
			this->radio_false->TabIndex = 28;
			this->radio_false->TabStop = true;
			this->radio_false->Text = L"True";
			this->radio_false->UseVisualStyleBackColor = true;
			this->radio_false->CheckedChanged += gcnew System::EventHandler(this, &Question_True_False_Screen::radio_false_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(214, 490);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(122, 35);
			this->button3->TabIndex = 29;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Question_True_False_Screen::button3_Click);
			// 
			// Question_True_False_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(534, 611);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->radio_false);
			this->Controls->Add(this->radio_true);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btn_show_answer);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lbl_progress);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->lbl_difficulty);
			this->Controls->Add(this->lbl_Current_Score);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Question_True_False_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Question_True_False_Screen";
			this->Load += gcnew System::EventHandler(this, &Question_True_False_Screen::Question_True_False_Screen_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->pnl_Answer->ResumeLayout(false);
			this->pnl_Answer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// WE GOTTA REMOVE THIS PART OF THE CODE SINCE WE ARE NOT USING BUTTONS ANYMORE!!!
	private: System::Void btn_True_Click(System::Object^ sender, System::EventArgs^ e) {
		

		
	}
	private: System::Void btn_False_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
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
public:	  Control^ getControl(String^ controlName)
{
	if (controlName == "flowLayoutPanel1")
		return flowLayoutPanel1;
	else
		return nullptr;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


	String^ message = "Do you want to skip?";
	String^ caption = "Confirmation";

	bool userResponse = ShowYesNoMessageBox(message, caption);

	if (userResponse)
	{
		// User clicked Yes
		// Do something...
		
		if (lbl_Answer->Text == "true") {
			answer = false;
		}
		else {
			answer = true;
		}




		this->Close();
		
	}
	else
	{
		// User clicked No
		// Do something...
		
	}




	

}
private: bool showAnswerButtonClicked = false; // Flag to check if btn_show_answer was clicked

private: System::Void btn_show_answer_Click(System::Object^ sender, System::EventArgs^ e) {
	button1->Enabled = false;
	System::String^ string_answer;
	
	if (lbl_Answer->Text == "true") {
		string_answer = "true";
	}
	else {
		string_answer = "false";
	}
	if (radio_true->Checked == true || radio_false->Checked == true) {
		button3->Enabled = false;
		btn_show_answer->Enabled = false;
		pnl_Answer->Visible = true;

		
		if (string_answer == "true" && answer == true) {
			pnl_Answer->BackColor = System::Drawing::Color::MediumAquamarine;
			lbl_Answer->ForeColor = System::Drawing::Color::Green;

			//Making sure the feedback fits properly in the panel
			String^ feedbackMessage = "Your answer is correct!";

			array<String^>^ lines = feedbackMessage->Split('\n');
			lbl_Answer->Text = feedbackMessage;

			lbl_Answer->AutoSize = true;
			lbl_Answer->MaximumSize = System::Drawing::Size(pnl_Answer->Width, 0);
		}
		else if (string_answer == "false" && answer == false) {
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

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	radio_true->Checked = false;
	radio_false->Checked = false;
	button2->Enabled = false;
	btn_show_answer->Enabled = false;
}
private: System::Void radio_true_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	answer = false;

}
private: System::Void radio_false_CheckedChanged(System::Object^ sender, System::EventArgs^ e){
	
	answer = true;

}
	   // Phindile edited this to ensure that the "Show Button is disabled unless at least one option is selected
private: System::Void Question_True_False_Screen_Load(System::Object^ sender, System::EventArgs^ e) {
	btn_show_answer->Enabled = false;
	button2->Enabled = false;

	radio_true->CheckedChanged += gcnew System::EventHandler(this, &Question_True_False_Screen::RadioButton_CheckedChanged);
	radio_false->CheckedChanged += gcnew System::EventHandler(this, &Question_True_False_Screen::RadioButton_CheckedChanged);
}
	   // Phindile edited this to ensure that the "Show Button is disabled unless at least one option is selected
private: void RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radio_true->Checked == true || radio_false->Checked) {
		btn_show_answer->Enabled = true;
		button2->Enabled = true;
	}
	else {
		btn_show_answer->Enabled = false;
		button2->Enabled = true;
	}
}

private: System::Void pnl_Answer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
