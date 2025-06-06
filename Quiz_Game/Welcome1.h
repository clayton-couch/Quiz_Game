#pragma once
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
	/// Summary for Welcome1
	/// </summary>
	public ref class Welcome1 : public System::Windows::Forms::Form
	{
	public:
		Welcome1(void)
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
		~Welcome1()
		{
			if (components)
			{
				delete components;
			}
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
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::PictureBox^ btn_close;
	public: bool close_program = false;

	public:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Welcome1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Impact", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(357, 618);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 67);
			this->button1->TabIndex = 7;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Welcome1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(357, 87);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(153, 125);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(208, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(431, 59);
			this->label1->TabIndex = 4;
			this->label1->Text = L"HUMAN ANATOMY QUIZ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Arial Nova", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(46, 237);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(851, 328);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(853, 3);
			this->btn_close->Margin = System::Windows::Forms::Padding(4);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(55, 49);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 13;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Welcome1::btn_close_Click);
			// 
			// Welcome1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(909, 697);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Welcome1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

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
};
}
