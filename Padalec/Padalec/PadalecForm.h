#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>
#include "SnakePart.h"
#include "Input.h"
#include "Score.h"

namespace Padalec
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class PadalecForm : public System::Windows::Forms::Form
	{

	public:

		PadalecForm(void)
		{
			InitializeComponent();

			start = false;
			gameloop->Interval = 200; // like UI timer in milliseconds
			gameloop->Tick += gcnew EventHandler(this, &PadalecForm::Game);
			gameloop->Start();
		}

	protected:

		~PadalecForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		// snake size (board = 400x400)
		const int part_height = 16;		// it's better to use a divisor of board size 
		const int part_width = 16;		//  to avoid glitches when hitting border

		bool start = false;
		bool gameover = false;

		Input::Direction direction = Input::Direction::None;

		List<SnakePart^>^ snake = gcnew List<SnakePart^>();		// snake object

		SnakePart^ food = gcnew SnakePart();	// food object

		Score^ score = gcnew Score();	// score object
	private: System::Windows::Forms::PictureBox^  Head;
	private: System::Windows::Forms::PictureBox^  Apple;


	private: System::Windows::Forms::Timer^  Left_Move;
	private: System::Windows::Forms::Timer^  Right_Move;
	private: System::Windows::Forms::Timer^  Up_Move;
	private: System::Windows::Forms::Timer^  Down_Move;

			 Timer^ gameloop = gcnew Timer();  // timer for game

#pragma region HelperMetods

			 void StartGame()
			 {
				 snake->Clear();
				 snake->Add(gcnew SnakePart(10, 3));
				 gameover = false;

				 // score initialization
				 score->SetScoreStep(10);  //score->value = 0 because of constructor

				 direction = Input::Direction::Down; // default moving direction

				 Head->Visible = true;
				 Apple->Visible = true;
				 Down_Move->Enabled = true;

			 }

			 void Game(Object^ sender, EventArgs^ e)
			 {
				 if (start)
				 {
					 //Permanent move + walls
					 Moves();

					 //Changing direction by arrow keys
					 ChangeDirection();

					 //Eating and score incrementation
					 Eat();

					 pictureBox1->Invalidate();

				 }
			 }

			 void Generate()
			 {}	 // TODO: Generate() food = change actual food location after contact with snake's head

			 void ChangeDirection()  // changing direction variable value based on pressed key
			 {}  // TODO: ChangeDirection()

			 void Moves()  // moving head + other parts and collision check and walls based on direction
			 {}  // TODO: Moves()

			 void Eat()	// score changing with specific step and creating another apple
			 {
				 if (snake[0]->X == food->X && snake[0]->Y == food->Y)
				 {
					 snake->Add(gcnew SnakePart(snake[snake->Count - 1]->X, snake[snake->Count - 1]->Y));
					 score->ScoreIncrement();
					 Generate();
				 }
			 }
#pragma endregion

#pragma region Events

			 // do this when form is loading
			 System::Void PadalecForm_Load(Object^ sender, EventArgs^ e)
			 {
				 //Drawing a picture box with segments event
				 pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this,
					 &PadalecForm::pictureBox1_Paint);
			 }

			 System::Void pictureBox1_Paint(Object^ sender, PaintEventArgs^ e)
			 {
				 // TODO: picturebox1_Paint method

				 // creating images (head, part and apple) on graphic object with specific methods,
				 // sizes and locations 
			 }

			 System::Void PadalecForm_KeyDown(Object^ sender, KeyEventArgs^ e)
			 {
				 Input::ChangeState(e->KeyCode, true);

			 }

			 System::Void PadalecForm_KeyUp(Object^ sender, KeyEventArgs^ e)
			 {
				 Input::ChangeState(e->KeyCode, false);
			 }

			 System::Void button1_Click(Object^ sender, EventArgs^ e)
			 {
				 StartGame();
				 gameover = false;
				 start = true;
				 button1->Enabled = false;
			 }

#pragma endregion


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code

			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PadalecForm::typeid));
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->Head = (gcnew System::Windows::Forms::PictureBox());
				 this->Apple = (gcnew System::Windows::Forms::PictureBox());
				 this->Left_Move = (gcnew System::Windows::Forms::Timer(this->components));
				 this->Right_Move = (gcnew System::Windows::Forms::Timer(this->components));
				 this->Up_Move = (gcnew System::Windows::Forms::Timer(this->components));
				 this->Down_Move = (gcnew System::Windows::Forms::Timer(this->components));
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Head))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Apple))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->BackColor = System::Drawing::Color::AntiqueWhite;
				 this->pictureBox1->Location = System::Drawing::Point(2, 12);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(400, 400);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 // 
				 // button1
				 // 
				 this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->button1->Location = System::Drawing::Point(12, 417);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(122, 31);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Start";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &PadalecForm::button1_Click);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label1->ForeColor = System::Drawing::Color::Black;
				 this->label1->Location = System::Drawing::Point(199, 422);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(58, 18);
				 this->label1->TabIndex = 2;
				 this->label1->Text = L"Score:";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label2->ForeColor = System::Drawing::Color::Black;
				 this->label2->Location = System::Drawing::Point(257, 422);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(17, 18);
				 this->label2->TabIndex = 3;
				 this->label2->Text = L"0";
				 // 
				 // Head
				 // 
				 this->Head->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Head.Image")));
				 this->Head->Location = System::Drawing::Point(155, 156);
				 this->Head->Name = L"Head";
				 this->Head->Size = System::Drawing::Size(16, 16);
				 this->Head->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->Head->TabIndex = 4;
				 this->Head->TabStop = false;
				 this->Head->Visible = false;
				 this->Head->Click += gcnew System::EventHandler(this, &PadalecForm::PadalecForm_Load);
				 // 
				 // Apple
				 // 
				 this->Apple->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Apple.Image")));
				 this->Apple->Location = System::Drawing::Point(131, 275);
				 this->Apple->Name = L"Apple";
				 this->Apple->Size = System::Drawing::Size(16, 16);
				 this->Apple->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->Apple->TabIndex = 5;
				 this->Apple->TabStop = false;
				 this->Apple->Visible = false;
				 // 
				 // Left_Move
				 // 
				 this->Left_Move->Interval = 10;
				 this->Left_Move->Tick += gcnew System::EventHandler(this, &PadalecForm::Left_Move_Tick);
				 // 
				 // Right_Move
				 // 
				 this->Right_Move->Interval = 10;
				 this->Right_Move->Tick += gcnew System::EventHandler(this, &PadalecForm::Right_Move_Tick);
				 // 
				 // Up_Move
				 // 
				 this->Up_Move->Interval = 10;
				 this->Up_Move->Tick += gcnew System::EventHandler(this, &PadalecForm::Up_Move_Tick);
				 // 
				 // Down_Move
				 // 
				 this->Down_Move->Interval = 10;
				 this->Down_Move->Tick += gcnew System::EventHandler(this, &PadalecForm::Down_Move_Tick);
				 // 
				 // PadalecForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::LightPink;
				 this->ClientSize = System::Drawing::Size(400, 464);
				 this->Controls->Add(this->Apple);
				 this->Controls->Add(this->Head);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->pictureBox1);
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"PadalecForm";
				 this->Text = L"Padalec";
				 this->Load += gcnew System::EventHandler(this, &PadalecForm::PadalecForm_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PadalecForm::PadalecForm_KeyDown_1);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &PadalecForm::PadalecForm_KeyUp);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Head))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Apple))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void Left_Move_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		{
			int x = Head->Location.X;
			int y = Head->Location.Y;
			x -= 3;
			Head->Location = System::Drawing::Point(x, y);
		}
	}
	private: System::Void Right_Move_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		{
			int x = Head->Location.X;
			int y = Head->Location.Y;
			x += 3;
			Head->Location = System::Drawing::Point(x, y);
		}
	}
	private: System::Void Up_Move_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		{
			int x = Head->Location.X;
			int y = Head->Location.Y;
			y -= 3;
			Head->Location = System::Drawing::Point(x, y);
		}
	}
	private: System::Void Down_Move_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		{
			int x = Head->Location.X;
			int y = Head->Location.Y;
			y += 3;
			Head->Location = System::Drawing::Point(x, y);
		}
	}
	private: System::Void PadalecForm_KeyDown_1(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		{
			int x = Head->Location.X;
			int y = Head->Location.Y;

			if (e->KeyCode == Keys::Right)
			{
				Left_Move->Enabled = false;
				Up_Move->Enabled = false;
				Down_Move->Enabled = false;
				Right_Move->Enabled = true;
			}
			else if (e->KeyCode == Keys::Left)
			{
				Left_Move->Enabled = true;
				Up_Move->Enabled = false;
				Down_Move->Enabled = false;
				Right_Move->Enabled = false;
			}
			else if (e->KeyCode == Keys::Up)
			{
				Left_Move->Enabled = false;
				Up_Move->Enabled = true;
				Down_Move->Enabled = false;
				Right_Move->Enabled = false;
			}
			else if (e->KeyCode == Keys::Down)
			{
				Left_Move->Enabled = false;
				Up_Move->Enabled = false;
				Down_Move->Enabled = true;
				Right_Move->Enabled = false;
			}
		}

	}
	};
}