#pragma once
#include <string>
#include <cctype>
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
	/// Summary for Question_Fill_In_Blank_Screen
	/// </summary>
	public ref class Question_Fill_In_Blank_Screen : public System::Windows::Forms::Form
	{
	public:
		Question_Fill_In_Blank_Screen(void)
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
		System::String^ get_answer() {

			return txt_Answer->Text;
		}
		std::string SystemStringToStdString(System::String^ str)
		{
			return msclr::interop::marshal_as<std::string>(str);
		}
		System::String^ StdStringToSystemString(const std::string& str)
		{
			return gcnew System::String(str.c_str());
		}
		System::Windows::Forms::Label^ lbl_Q_Prefix;
		System::Windows::Forms::Label^ lbl_current_score;
	public: System::Windows::Forms::Label^ lbl_difficulty;
	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::PictureBox^ pictureBox4;
	public: bool close_program = false;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public: System::Windows::Forms::Panel^ pnl_Answer;
	public: System::Windows::Forms::Label^ lbl_Answer;
	private: int pnl_time = 3;
	private: System::Windows::Forms::PictureBox^ btn_close;
	public: System::Windows::Forms::Label^ lbl_progress;
	private: System::Windows::Forms::Button^ btn_show_answer;
	public:
	private: System::Windows::Forms::Button^ button1;
	public:
	private:

	private: std::string toLower(const std::string& str) {
		std::string result;
		result.reserve(str.size()); // Reserve space for efficiency

		for (char c : str) {
			result += std::tolower(c);
		}

		return result;
	    

		
	}

		   //Use this fuction in main()
	public:	  Control^ getControl(String^ controlName)
	{
		if (controlName == "panel2")
			return panel2;
		else
			return nullptr;
	}


	public:

	
	public:

	public:
		System::Windows::Forms::Label^ lbl_Q_Suffix;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Question_Fill_In_Blank_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	 
	private: System::Windows::Forms::TextBox^ txt_Answer;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::String^ answer;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Question_Fill_In_Blank_Screen::typeid));
			this->lbl_Q_Prefix = (gcnew System::Windows::Forms::Label());
			this->lbl_Q_Suffix = (gcnew System::Windows::Forms::Label());
			this->txt_Answer = (gcnew System::Windows::Forms::TextBox());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->lbl_current_score = (gcnew System::Windows::Forms::Label());
			this->lbl_difficulty = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pnl_Answer = (gcnew System::Windows::Forms::Panel());
			this->lbl_Answer = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_progress = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_show_answer = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->pnl_Answer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Q_Prefix
			// 
			this->lbl_Q_Prefix->AutoSize = true;
			this->lbl_Q_Prefix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Q_Prefix->Location = System::Drawing::Point(3, 14);
			this->lbl_Q_Prefix->Name = L"lbl_Q_Prefix";
			this->lbl_Q_Prefix->Size = System::Drawing::Size(35, 13);
			this->lbl_Q_Prefix->TabIndex = 0;
			this->lbl_Q_Prefix->Text = L"label1";
			// 
			// lbl_Q_Suffix
			// 
			this->lbl_Q_Suffix->AutoSize = true;
			this->lbl_Q_Suffix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Q_Suffix->Location = System::Drawing::Point(3, 107);
			this->lbl_Q_Suffix->Name = L"lbl_Q_Suffix";
			this->lbl_Q_Suffix->Size = System::Drawing::Size(35, 13);
			this->lbl_Q_Suffix->TabIndex = 1;
			this->lbl_Q_Suffix->Text = L"label1";
			// 
			// txt_Answer
			// 
			this->txt_Answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Answer->ForeColor = System::Drawing::SystemColors::Highlight;
			this->txt_Answer->Location = System::Drawing::Point(6, 67);
			this->txt_Answer->Name = L"txt_Answer";
			this->txt_Answer->Size = System::Drawing::Size(341, 22);
			this->txt_Answer->TabIndex = 2;
			this->txt_Answer->TextChanged += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::txt_Answer_TextChanged);
			// 
			// btnConfirm
			// 
			this->btnConfirm->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConfirm->Location = System::Drawing::Point(183, 513);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(180, 57);
			this->btnConfirm->TabIndex = 3;
			this->btnConfirm->Text = L"Continue";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::btnConfirm_Click);
			// 
			// lbl_current_score
			// 
			this->lbl_current_score->AutoSize = true;
			this->lbl_current_score->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_current_score->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_current_score->ForeColor = System::Drawing::Color::Red;
			this->lbl_current_score->Location = System::Drawing::Point(433, 79);
			this->lbl_current_score->Name = L"lbl_current_score";
			this->lbl_current_score->Size = System::Drawing::Size(50, 19);
			this->lbl_current_score->TabIndex = 4;
			this->lbl_current_score->Text = L"label1";
			// 
			// lbl_difficulty
			// 
			this->lbl_difficulty->AutoSize = true;
			this->lbl_difficulty->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_difficulty->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_difficulty->ForeColor = System::Drawing::Color::Red;
			this->lbl_difficulty->Location = System::Drawing::Point(28, 79);
			this->lbl_difficulty->Name = L"lbl_difficulty";
			this->lbl_difficulty->Size = System::Drawing::Size(50, 19);
			this->lbl_difficulty->TabIndex = 5;
			this->lbl_difficulty->Text = L"label1";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->Controls->Add(this->pnl_Answer);
			this->panel2->Controls->Add(this->txt_Answer);
			this->panel2->Controls->Add(this->lbl_Q_Suffix);
			this->panel2->Controls->Add(this->lbl_Q_Prefix);
			this->panel2->Location = System::Drawing::Point(11, 310);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(511, 197);
			this->panel2->TabIndex = 7;
			// 
			// pnl_Answer
			// 
			this->pnl_Answer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_Answer->Controls->Add(this->lbl_Answer);
			this->pnl_Answer->Location = System::Drawing::Point(44, 93);
			this->pnl_Answer->Name = L"pnl_Answer";
			this->pnl_Answer->Size = System::Drawing::Size(443, 101);
			this->pnl_Answer->TabIndex = 3;
			// 
			// lbl_Answer
			// 
			this->lbl_Answer->AutoSize = true;
			this->lbl_Answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Answer->ForeColor = System::Drawing::Color::Red;
			this->lbl_Answer->Location = System::Drawing::Point(17, 14);
			this->lbl_Answer->Name = L"lbl_Answer";
			this->lbl_Answer->Size = System::Drawing::Size(41, 13);
			this->lbl_Answer->TabIndex = 0;
			this->lbl_Answer->Text = L"label1";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(11, 108);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(113, 100);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(105, 513);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(72, 57);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(345, 49);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(177, 27);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 17;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(11, 49);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(177, 27);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(491, -2);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(45, 45);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 18;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::btn_close_Click);
			// 
			// lbl_progress
			// 
			this->lbl_progress->AutoSize = true;
			this->lbl_progress->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_progress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_progress->Location = System::Drawing::Point(306, 9);
			this->lbl_progress->Name = L"lbl_progress";
			this->lbl_progress->Size = System::Drawing::Size(57, 20);
			this->lbl_progress->TabIndex = 19;
			this->lbl_progress->Text = L"label1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(394, 513);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 36);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Skip Question";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::button1_Click);
			// 
			// btn_show_answer
			// 
			this->btn_show_answer->Enabled = false;
			this->btn_show_answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_show_answer->Location = System::Drawing::Point(394, 555);
			this->btn_show_answer->Name = L"btn_show_answer";
			this->btn_show_answer->Size = System::Drawing::Size(122, 35);
			this->btn_show_answer->TabIndex = 27;
			this->btn_show_answer->Text = L"Check Answer";
			this->btn_show_answer->UseVisualStyleBackColor = true;
			this->btn_show_answer->Click += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::btn_show_answer_Click);
			// 
			// Question_Fill_In_Blank_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(534, 611);
			this->Controls->Add(this->btn_show_answer);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lbl_progress);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->lbl_difficulty);
			this->Controls->Add(this->lbl_current_score);
			this->Controls->Add(this->btnConfirm);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Question_Fill_In_Blank_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Question_Fill_In_Blank_Screen";
			this->Load += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::Question_Fill_In_Blank_Screen_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->pnl_Answer->ResumeLayout(false);
			this->pnl_Answer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (!String::IsNullOrEmpty(txt_Answer->Text)) {
			
			answer = txt_Answer->Text;
			this->Close();

		}
		else {
			String^ message = "Continue to the next question without answering?";
			String^ caption = "Confirmation";

			bool userResponse = ShowYesNoMessageBox(message, caption);

			if (userResponse)
			{
				txt_Answer->Text = "ok";
				this->Close();

			}
			else
			{
				// User clicked No
				// Do something...

			}
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
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ message = "Are you sure you want to skip?";   // Phindile changed this prompt to "Are you sure ..."
	String^ caption = "Confirmation";

	bool userResponse = ShowYesNoMessageBox(message, caption);

	if (userResponse)
	{
		txt_Answer->Text = "ok";
		this->Close();

	}
	else
	{
		// User clicked No
		// Do something...

	}






}

	   // Making sure the button "Show button" is diable unless "txt_Answer" is not empty
private: System::Void Question_Fill_In_Blank_Screen_Load(System::Object^ sender, System::EventArgs^ e) {
	btn_show_answer->Enabled = false;

	txt_Answer->TextChanged += gcnew System::EventHandler(this, &Question_Fill_In_Blank_Screen::txt_Answer_TextChanged);
}

	   // Enable btn_show_answer only if the answer txt_answer is not empty
private: System::Void txt_Answer_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txt_Answer->Text->Length > 0) {
		btn_show_answer->Enabled = true;
	}
	else {
		btn_show_answer->Enabled = false;
	}
}

private: System::Void btn_show_answer_Click(System::Object^ sender, System::EventArgs^ e) {
	button1->Enabled = false;
	txt_Answer->Enabled = false;
	btn_show_answer->Enabled = false;
	pnl_Answer->Visible = true;

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

};
}
