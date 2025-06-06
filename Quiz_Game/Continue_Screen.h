#pragma once

namespace QuizGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Continue_Screen
	/// </summary>
	public ref class Continue_Screen : public System::Windows::Forms::Form
	{
	public:
		Continue_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		System::Windows::Forms::Label^ lbl_Message;
		int get_decision() {
			return decision;
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Continue_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int decision = 1;
	protected:
	private: System::Windows::Forms::Button^ btn_Yes;
	private: System::Windows::Forms::Button^ btn_No;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Continue_Screen::typeid));
			this->lbl_Message = (gcnew System::Windows::Forms::Label());
			this->btn_Yes = (gcnew System::Windows::Forms::Button());
			this->btn_No = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Message
			// 
			this->lbl_Message->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_Message->Font = (gcnew System::Drawing::Font(L"Poor Richard", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Message->Location = System::Drawing::Point(12, 33);
			this->lbl_Message->Name = L"lbl_Message";
			this->lbl_Message->Size = System::Drawing::Size(360, 19);
			this->lbl_Message->TabIndex = 0;
			this->lbl_Message->Text = L"label1";
			// 
			// btn_Yes
			// 
			this->btn_Yes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_Yes->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Yes->Location = System::Drawing::Point(12, 272);
			this->btn_Yes->Name = L"btn_Yes";
			this->btn_Yes->Size = System::Drawing::Size(180, 57);
			this->btn_Yes->TabIndex = 1;
			this->btn_Yes->Text = L"Yes";
			this->btn_Yes->UseVisualStyleBackColor = false;
			this->btn_Yes->Click += gcnew System::EventHandler(this, &Continue_Screen::btn_Yes_Click);
			// 
			// btn_No
			// 
			this->btn_No->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_No->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_No->Location = System::Drawing::Point(198, 272);
			this->btn_No->Name = L"btn_No";
			this->btn_No->Size = System::Drawing::Size(180, 57);
			this->btn_No->TabIndex = 2;
			this->btn_No->Text = L"No";
			this->btn_No->UseVisualStyleBackColor = false;
			this->btn_No->Click += gcnew System::EventHandler(this, &Continue_Screen::btn_No_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 99);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(360, 157);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Continue_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_No);
			this->Controls->Add(this->btn_Yes);
			this->Controls->Add(this->lbl_Message);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Continue_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Continue_Screen";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_Yes_Click(System::Object^ sender, System::EventArgs^ e) {
		decision = 1;
		this->Close();
	}
	private: System::Void btn_No_Click(System::Object^ sender, System::EventArgs^ e) {
		decision = 0;
		this->Close();
	}
};
}
