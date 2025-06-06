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
	/// Summary for Difficulty_Select_Screen
	/// </summary>
	public ref class Difficulty_Select_Screen : public System::Windows::Forms::Form
	{
	public:
		Difficulty_Select_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		int getDifficulty() {

			return difficulty;
		}
		System::Windows::Forms::Button^ btnBeginner;
		System::Windows::Forms::Button^ btnIntermediate;
		System::Windows::Forms::PictureBox^ stan_pic;
		System::Windows::Forms::PictureBox^ lock_pic1;
		System::Windows::Forms::PictureBox^ lock_pic2;
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
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ btn_close;
	public:
		System::Windows::Forms::Button^ btnAdvanced;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Difficulty_Select_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: int difficulty;
	public: bool close_program = false;
	



	protected:

	protected:

	protected:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Difficulty_Select_Screen::typeid));
			this->btnBeginner = (gcnew System::Windows::Forms::Button());
			this->btnIntermediate = (gcnew System::Windows::Forms::Button());
			this->btnAdvanced = (gcnew System::Windows::Forms::Button());
			this->stan_pic = (gcnew System::Windows::Forms::PictureBox());
			this->lock_pic1 = (gcnew System::Windows::Forms::PictureBox());
			this->lock_pic2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_close = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stan_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lock_pic1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lock_pic2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->BeginInit();
			this->SuspendLayout();
			// 
			// btnBeginner
			// 
			this->btnBeginner->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnBeginner->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBeginner->Location = System::Drawing::Point(186, 279);
			this->btnBeginner->Name = L"btnBeginner";
			this->btnBeginner->Size = System::Drawing::Size(180, 57);
			this->btnBeginner->TabIndex = 0;
			this->btnBeginner->Text = L"Beginner";
			this->btnBeginner->UseVisualStyleBackColor = false;
			this->btnBeginner->Click += gcnew System::EventHandler(this, &Difficulty_Select_Screen::btnBeginner_Click);
			// 
			// btnIntermediate
			// 
			this->btnIntermediate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnIntermediate->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIntermediate->Location = System::Drawing::Point(186, 357);
			this->btnIntermediate->Name = L"btnIntermediate";
			this->btnIntermediate->Size = System::Drawing::Size(180, 57);
			this->btnIntermediate->TabIndex = 1;
			this->btnIntermediate->Text = L"Intermediate";
			this->btnIntermediate->UseVisualStyleBackColor = false;
			this->btnIntermediate->Click += gcnew System::EventHandler(this, &Difficulty_Select_Screen::btnIntermediate_Click);
			// 
			// btnAdvanced
			// 
			this->btnAdvanced->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnAdvanced->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdvanced->Location = System::Drawing::Point(186, 432);
			this->btnAdvanced->Name = L"btnAdvanced";
			this->btnAdvanced->Size = System::Drawing::Size(180, 57);
			this->btnAdvanced->TabIndex = 2;
			this->btnAdvanced->Text = L"Advanced";
			this->btnAdvanced->UseVisualStyleBackColor = false;
			this->btnAdvanced->Click += gcnew System::EventHandler(this, &Difficulty_Select_Screen::btnAdvanced_Click);
			// 
			// stan_pic
			// 
			this->stan_pic->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->stan_pic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stan_pic.Image")));
			this->stan_pic->Location = System::Drawing::Point(66, 357);
			this->stan_pic->Name = L"stan_pic";
			this->stan_pic->Size = System::Drawing::Size(123, 132);
			this->stan_pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->stan_pic->TabIndex = 3;
			this->stan_pic->TabStop = false;
			// 
			// lock_pic1
			// 
			this->lock_pic1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lock_pic1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lock_pic1.Image")));
			this->lock_pic1->Location = System::Drawing::Point(372, 370);
			this->lock_pic1->Name = L"lock_pic1";
			this->lock_pic1->Size = System::Drawing::Size(57, 44);
			this->lock_pic1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->lock_pic1->TabIndex = 4;
			this->lock_pic1->TabStop = false;
			// 
			// lock_pic2
			// 
			this->lock_pic2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lock_pic2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lock_pic2.Image")));
			this->lock_pic2->Location = System::Drawing::Point(372, 443);
			this->lock_pic2->Name = L"lock_pic2";
			this->lock_pic2->Size = System::Drawing::Size(57, 46);
			this->lock_pic2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->lock_pic2->TabIndex = 5;
			this->lock_pic2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(2, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(130, 103);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_close.Image")));
			this->btn_close->Location = System::Drawing::Point(495, 2);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(45, 45);
			this->btn_close->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btn_close->TabIndex = 13;
			this->btn_close->TabStop = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &Difficulty_Select_Screen::btn_close_Click);
			// 
			// Difficulty_Select_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(534, 611);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->lock_pic2);
			this->Controls->Add(this->lock_pic1);
			this->Controls->Add(this->stan_pic);
			this->Controls->Add(this->btnAdvanced);
			this->Controls->Add(this->btnIntermediate);
			this->Controls->Add(this->btnBeginner);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Difficulty_Select_Screen";
			this->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Difficulty_Select_Screen";
			this->Load += gcnew System::EventHandler(this, &Difficulty_Select_Screen::Difficulty_Select_Screen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stan_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lock_pic1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lock_pic2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn_close))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnBeginner_Click(System::Object^ sender, System::EventArgs^ e) {

		difficulty = 0;
		this->Close();
	}
	private: System::Void btnIntermediate_Click(System::Object^ sender, System::EventArgs^ e) {

		difficulty = 1;
		this->Close();
	}
private: System::Void btnAdvanced_Click(System::Object^ sender, System::EventArgs^ e) {

	    difficulty = 2;
		this->Close();
}
private: System::Void Difficulty_Select_Screen_Load(System::Object^ sender, System::EventArgs^ e) {
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
