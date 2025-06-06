#pragma once

namespace QuizGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Results_Screen
	/// </summary>
	public ref class Results_Screen : public System::Windows::Forms::Form
	{
	public:
		Results_Screen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	public: bool close_program = false;
	public:
		System::Windows::Forms::Label^ lbl_Result;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Results_Screen()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	private: System::Windows::Forms::Button^ btn_Continue;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Results_Screen::typeid));
			this->lbl_Result = (gcnew System::Windows::Forms::Label());
			this->btn_Continue = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Result
			// 
			this->lbl_Result->AutoSize = true;
			this->lbl_Result->BackColor = System::Drawing::SystemColors::Control;
			this->lbl_Result->Font = (gcnew System::Drawing::Font(L"Poor Richard", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Result->Location = System::Drawing::Point(12, 58);
			this->lbl_Result->Name = L"lbl_Result";
			this->lbl_Result->Size = System::Drawing::Size(40, 14);
			this->lbl_Result->TabIndex = 0;
			this->lbl_Result->Text = L"label1";
			// 
			// btn_Continue
			// 
			this->btn_Continue->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Continue->Location = System::Drawing::Point(104, 275);
			this->btn_Continue->Name = L"btn_Continue";
			this->btn_Continue->Size = System::Drawing::Size(180, 57);
			this->btn_Continue->TabIndex = 1;
			this->btn_Continue->Text = L"Continue";
			this->btn_Continue->UseVisualStyleBackColor = true;
			this->btn_Continue->Click += gcnew System::EventHandler(this, &Results_Screen::btn_Continue_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 112);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(360, 157);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// Results_Screen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_Continue);
			this->Controls->Add(this->lbl_Result);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Results_Screen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Results_Screen";
			this->Load += gcnew System::EventHandler(this, &Results_Screen::Results_Screen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_Continue_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Results_Screen_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
	close_program = true;
	this->Close();
}
};
}
