#include "Welcome_Screen.h"
#include "Save_Score_Screen.h"
#include "Results_Screen.h"
#include "Question_True_False_Screen.h"
#include "Question_Multiple_Choice_Screen.h"
#include "Question_Fill_In_Blank_Screen.h"
#include "Difficulty_Select_Screen.h"
#include "Continue_Screen.h"
#include "Special_Questions.h"
#include "Welcome1.h"
#include "loading_screen.h"


#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#include <random>
#include <cctype>
#include <algorithm>





using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace QuizGame;
using namespace System::Threading;




//FUNCTION FOR CONVERTING A STRING TO LOWERCASE

std::string toLower(const std::string& str) {
    std::string result;
    result.reserve(str.size());  // Reserve space for efficiency

    for (char c : str) {
        result += std::tolower(c);
    }

    return result;
}



//CLASSES



class MultiChoice {
private:   //DECLARE PRIVATE VARIABLES
    int difficulty;
    std::string question_text;
    std::string choices[4];
    int correct_answer;

public:
    MultiChoice(int difficulty, std::string question_text, std::string choices[], int correct_answer) {  //CONSTRUCTOR
        this->difficulty = difficulty;
        this->question_text = question_text;
        for (int i = 0; i < 4; i++) {
            this->choices[i] = choices[i];     //ASSIGN CHOICES ARRAY FROM CONTRCUTOR TO LOCAL ARRAY
        }

        this->correct_answer = correct_answer;

    }

    //GETTER FUNCTIONS

    int get_difficulty() {
        return difficulty;
    }
    std::string get_question_text() {
        return question_text;
    }

    std::string* get_choices() {    //RETURN POINTER FOR CHOICES ARRAY
        return choices;
    }

    int get_correct_answer() {
        return correct_answer;
    }

    // Returns the correct answer as a letter
    System::String^ get_correct_answer_letter(int correctAnswer) {
        System::String^ letter;

        switch (correctAnswer) {
        case 1:
            letter = "A";
            break;
        case 2:
            letter = "B";
            break;
        case 3:
            letter = "C";
            break;
        default:
            letter = "D";
            break;
        }

        return letter;
    }

};

class FillInBlank {
private:     //DECLARE PRIVATE VARIABLES
    int difficulty;
    std::string question_prefix;
    std::string question_suffix;
    std::string correct_answer;

public:
    FillInBlank(int difficulty, std::string question_prefix, std::string question_suffix, std::string correct_answer) {  //CONSTRUCTOR
        this->question_prefix = question_prefix;
        this->question_suffix = question_suffix;
        this->correct_answer = correct_answer;
        this->difficulty = difficulty;
    }

    //GET METHODS

    int get_difficulty() {
        return difficulty;
    }

    std::string get_question_prefix() {
        return question_prefix;
    }

    std::string get_question_suffix() {
        return question_suffix;
    }

    std::string get_correct_answer() {
        return correct_answer;
    }


};




//CLASS TEMPLATE

// Template class for both SpecialQuestion and TrueOrFalse
template<typename T, typename U>
class Question {
private:
    int difficulty;
    T question_text;
    U correct_answer; 

public:
    
    Question(int difficulty, T question, U correct_answer) {
        this->difficulty = difficulty;
        this->question_text = question;
        this->correct_answer = correct_answer;
    }

    // Get methods
    T get_question_text() {
        return question_text;
    }

    U get_correct_answer() {
        return correct_answer;
    }

    int get_difficulty() {
        return difficulty;
    }
};


//FUNCTION TEMPLATES
// Function template for converting from std::string to System::String^
template<typename T>
System::String^ StdStringToSystemString(const T& str) {
    return gcnew System::String(str.c_str());
}

// Function template for converting from System::String^ to std::string
template<typename T>
std::string SystemStringToStdString(T^ str) {
    return msclr::interop::marshal_as<std::string>(str);
}



//PLAYER STRUCT

struct Player {
    std::string name;
    int score;

};



//COMPARE PLAYER STRUCTS

bool comparePlayers(const Player& a, const Player& b) {
    return a.score > b.score; // Sort in descending order of points
}

// For the speacial quiz
void check_and_update_answer(System::String^ userAnswer, std::string correctAnswer, int& score, int& count_correct, int& hearts) {
    std::string userAnswerStr = toLower(SystemStringToStdString(userAnswer));
    std::string correctAnswerStr = toLower(correctAnswer);

    if (userAnswerStr == correctAnswerStr) {
        score += 100;
        count_correct++;
    }
    else {
        System::String^ msg_string = StdStringToSystemString("Incorrect, the correct answer was: " + correctAnswer);
        hearts--;
    }

}


// POPULATE SPECIAL QUESTIONS VECTOR
void load_special_questions(std::vector<Question<std::string, std::string>>& special_question) {

    String^ special_line;
    StreamReader^ special_reader = gcnew StreamReader("SpecialQuestions.txt");
    
    // Reading from SpecialQuestions.txt
    while ((special_line = special_reader->ReadLine()) != nullptr) {

        array<String^>^ special_values = special_line->Split('_');
        Question<std::string, std::string> special_obj(Convert::ToInt32(special_values[0]), SystemStringToStdString(special_values[1]), SystemStringToStdString(special_values[2]));
        special_question.push_back(special_obj);


    }
    special_reader->Close();

}
void load_normal_questions(std::vector<MultiChoice>& multi_choice_vector , std::vector<FillInBlank>& fill_in_blank_vector , std::vector<Question<std::string, bool>>& true_or_false_vector) {

    StreamReader^ reader = gcnew StreamReader("Questions.txt");

    String^ line;

    while ((line = reader->ReadLine()) != nullptr) {

        if (line->StartsWith("FB")) {   //IT IS A FILL IN THE BLANK QUESTION
            array<String^>^ values = line->Split('_');  //SEPARATE "_" IN THE TEXTFILE

            FillInBlank obj(Convert::ToInt32(values[1]), SystemStringToStdString(values[2]), SystemStringToStdString(values[3]), SystemStringToStdString(values[4]));   //POPULATE CONSTRUCTOR WITH VARIABLES
            fill_in_blank_vector.push_back(obj);       //ADD OBJECT TO VECTOR

        }

        if (line->StartsWith("MC")) {   //IT IS A MULTIPLE CHOICE QUESTION
            array<String^>^ values = line->Split('_');   //SEPARATE "_" IN THE TEXTFILE

            std::string choices[4];
            choices[0] = SystemStringToStdString(values[3]);      // CREATE ARRAY OF CHOICES
            choices[1] = SystemStringToStdString(values[4]);
            choices[2] = SystemStringToStdString(values[5]);
            choices[3] = SystemStringToStdString(values[6]);

            MultiChoice obj(Convert::ToInt32(values[1]), SystemStringToStdString(values[2]), choices, Convert::ToInt32(values[7]));  //POPULATE CONSTRUCTOR WITH VARIABLES
            multi_choice_vector.push_back(obj);     //ADD OBJECT TO VECTOR

        }

        if (line->StartsWith("TF")) {   //IT IS A TRUE OR FALSE QUESTION
            array<String^>^ values = line->Split('_');

            bool answer = true;
            int value = Convert::ToInt32(values[3]);     // RETRIEVE BOOLEAN FROM TEXTFILE
            if (value == 0) {
                answer = false;                          //DETERMINE WHETHER ANSWER IS TRUE OR FALSE
            }

            Question<std::string, bool> obj(Convert::ToInt32(values[1]), SystemStringToStdString(values[2]), answer);   //POPULATE CONTRUCTOR WITH VARIABLES

            true_or_false_vector.push_back(obj);   //ADD OBJECT TO VECTOR


        }



    }

    reader->Close();

}
void load_top_scorers(std::vector<Player>& players) {
    StreamReader^ top_scores = gcnew StreamReader("Scores.txt");
    String^ line_scores;

    while ((line_scores = top_scores->ReadLine()) != nullptr) {

        array<String^>^ data = line_scores->Split('_');  //SEPARATE "_" IN THE TEXTFILE
        Player player1;
        player1.name = SystemStringToStdString(data[0]);
        player1.score = Convert::ToInt32(data[1]);
        players.push_back(player1);                    // ADD PLAYER STRUCT TO VECTOR

    }
    top_scores->Close();                             //CLOSE READER
}
void ask_special_question(bool& can_i_ask_question , Special_Questions^& special_questions , Question<std::string, std::string>& new_question , int& score , System::String^& difficulty_string , int& secondsLeft , int& question_accumulator) {

    //ASK QUESTIONS
    can_i_ask_question = false;
    special_questions->pnl_Answer->Visible = false;
    special_questions->lbl_Answer->Text = StdStringToSystemString(new_question.get_correct_answer());
    special_questions->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 1500";
    special_questions->lbl_difficulty->Text = difficulty_string;
    special_questions->secondsLeft = secondsLeft;
    special_questions->timer1->Enabled = true;
    special_questions->timer1->Start();
    special_questions->lbl_Question->Text = StdStringToSystemString(new_question.get_question_text());
    special_questions->lbl_Question->MaximumSize = System::Drawing::Size(special_questions->getControl("panel1")->Width, 0); // Ensuring the question fits onto the panel perfectly
    special_questions->ShowDialog();
    question_accumulator++;
    

}
void show_results_screen(int& score) {

    Results_Screen^ screen_results = gcnew Results_Screen();
    screen_results->lbl_Result->Text = "CONGRATULATIONS,YOU HAVE PASSED!!   Your score is: " +
        StdStringToSystemString(std::to_string(score));
    screen_results->ShowDialog();

}
void show_results_failed(int& score) {

    Results_Screen^ results_screen = gcnew Results_Screen();  //SHOW RESULTS

    results_screen->lbl_Result->Text = "FAILED! You achieved less than 66% , score is:  " + StdStringToSystemString(std::to_string(score)) + ". ";
    results_screen->ShowDialog();

}
void save_score(std::string& name , int& score) {

    std::string line_to_write = name + "_" + std::to_string(score);

    //SAVE SCORE TO TEXTFILE

    std::ofstream file("Scores.txt", std::ios::app);

    if (!file.is_open()) {

    }

    file.seekp(0, std::ios::end);
    file << line_to_write + "\n";
    file.close();

}
void show_loading_screen() {

    loading_screen^ load_screen = gcnew  loading_screen();
    load_screen->Show();
    for (int i = 0; i <= 100; i++)
    {
        load_screen->progressBar1->Value = i;
        
        System::Threading::Thread::Sleep(10); // Simulate delay
    }

    load_screen->Close();

}


int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

 //DECLARE VECTORS OF QUESTIONS
    std::vector<Question<std::string, bool>> true_or_false_vector;   //STORES TRUE FALSE QUESTIONS
    std::vector<MultiChoice> multi_choice_vector; // STORES MULTI CHOICE QUESTIONS
    std::vector<FillInBlank> fill_in_blank_vector; //STORES FILL IN BLANK QUESTIONS
    std::vector<Question<std::string, std::string>> special_question;   //STORES SPECIAL QUIZ QUESTIONS

    int question_accumulator = 1; //KEEPS TRACK OF CURRENT QUIZ QUESTION PROGRESS
    int global_score = 0; //KEEPS TRACK OF FINAL USER SCORE ACROSS ALL DIFFICULTIES
    int score = 0;  //DECLARE AND INITIALIZE PLAYERE SCORE
    std::vector<Player> players;  //DECLARE PLAYER STRUCT VECTOR
    System::String^ player_string; // DECLARE PLAYER DEATILS STRING
    std::random_device rd; //GENERATES RANDOM 
    std::mt19937 gen(rd()); // Mersenne Twister random number engine
    int flag = 1;          //FLAGGER FOR QUESTIONS
    System::String^ difficulty_string; //CONVERTS INT DIFFICULTY LEVEL TO STRING FOR DISPLAY
    int quiz_type; //SPECIAL QUIZ OR NORMAL QUIZ DEPENDING ON USER INPUT
    int special_score;  //SPECIAL QUIZ SCORE
    int special_flag = 1; //SPECIAL QUIZ FLAGGER
    int hearts = 3;  //INITIAL HEARTS IN SPECIAL QUIZ
    int decision;  // USER DECISION BASED ON BUTTON PRESSED
    int secondsLeft; //TIME FOR EACH QUESTION IN SPECIAL QUIZ
    bool check_if_time_is_up = false; //RETURNS TRUE IF TIMER HAS ELAPSED
    bool can_i_ask_question = true ; //CHECKS IF A QUESTION HAS ALREADY BEEN ASKED IN CURRENT LOOP INDEX


 //POPULATE VECTORS WITH QUESTIONS FROM TEXTFILE

    
    


    // Reading from SpecialQuestions.txt
    load_special_questions(special_question);


    //Reading from Questions.txt
    load_normal_questions(multi_choice_vector, fill_in_blank_vector, true_or_false_vector);



    
//Q_U_I_Z__G_A_M_E__S_T_A_R_T_S


    //POPULATE TOP SCORER VECTOR

    load_top_scorers(players);


    
 //SHOW WELCOME SCREEN
    Welcome1^ welcome_1 = gcnew Welcome1();
    welcome_1->ShowDialog();
    if (welcome_1->close_program == false) {

    
        show_loading_screen();

    Welcome_Screen^ welcome = gcnew Welcome_Screen();
    
    std::sort(players.begin(), players.end(), comparePlayers); //SORT PLAYERS VECTOR

    for (int i = 0; i < static_cast<int>(players.size()); i++) {
        Player new_player = players[i];
        player_string = StdStringToSystemString(new_player.name)+" ---> "+ StdStringToSystemString(std::to_string(new_player.score));
        welcome-> list_top_scores->Items->Add(player_string);    //ADD PLAYERS WITH TOP SCORES TO WELCOME PAGE

    }




   
    welcome->ShowDialog();
    if (welcome->close_program == true) {
        // PROGRAM CLOSES
    }else{

    quiz_type = welcome->get_quiz_type();   //RETRIEVE QUIZ TYPE DEPENDING ON BUTTON PRESSED

    show_loading_screen();

 //SHOW DIFFICULTY SELECT SCREEN
    Difficulty_Select_Screen^ difficulty_select = gcnew Difficulty_Select_Screen();
    if (quiz_type == 1) {
        difficulty_select->btnIntermediate->Enabled = true;
        difficulty_select->btnAdvanced->Enabled = true;
        difficulty_select->stan_pic->Visible = false;
        difficulty_select->lock_pic1->Visible = false;
        difficulty_select->lock_pic2->Visible = false;
    }
    else {
        difficulty_select->btnIntermediate->Enabled = false;
        difficulty_select->btnAdvanced->Enabled = false;
    }
   
    difficulty_select->ShowDialog();
    if (difficulty_select->close_program == true) {
        // CLOSE PROGRAM
    }else{

 //Return difficulty level selected
    int level = difficulty_select->getDifficulty();



 
    //SPECIAL QUIZ

    show_loading_screen();
    if (quiz_type ==  1) {   

        MessageBox::Show("Welcome to special quiz section. You get extra points for correct answers, but there's a catch! These questions will have a timer and hearts, if either of them run out you lose!!!! Beginners get 16 minutes, Intermediates get 10 minutes and Advanced players get only 5 minutes!!!  ;)", "Tips!", MessageBoxButtons::OK, MessageBoxIcon::Information);
        special_score = 0;

        special_flag = 1;

        MessageBox::Show("These questions will be hard", "ALERT!!!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        
        while (flag != 0) {
            //ASK 15 QUESTIONS
            int count_correct = 0;
           
            for (int i = 0; i < 15; i++) {

                if (level == 0) {
                    difficulty_string = "Beginner";
                    secondsLeft = 60;
                }
                else if (level == 1) {
                    difficulty_string = "Intermediate";
                    secondsLeft = 45;
                }
                else {
                    difficulty_string = "Advanced";
                    secondsLeft = 30;
                }

                Special_Questions^ special_questions = gcnew Special_Questions();
                special_questions->secondsLeft = secondsLeft;
                special_questions->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(i + 1)) + " / 15";
                std::shuffle(special_question.begin(), special_question.end(), gen); // Shuffle questions in vector
                while (special_question.back().get_difficulty() != level) {
                    std::shuffle(special_question.begin(), special_question.end(), gen); // Shuffle questions in vector 
                }
                Question<std::string, std::string> new_question = special_question.back();
                special_question.pop_back();
                special_questions->lbl_Question->Text = StdStringToSystemString(new_question.get_question_text());

                
                
                
                if (special_questions->is_time_up() == false) {
                if ((hearts == 3) && (can_i_ask_question == true)) {


                    //ASK QUESTIONS
                    
                    ask_special_question(can_i_ask_question, special_questions, new_question, score, difficulty_string, secondsLeft, question_accumulator);
                    
                    if (special_questions->close_program == true) {
                        flag = 0;
                        break;

                    }
                    else {
                        check_and_update_answer(special_questions->get_answer(), new_question.get_correct_answer(), score, count_correct, hearts);

                    }




                }
                else if ((hearts == 2) && (can_i_ask_question == true)) {

                    special_questions->heart_3->Visible = false;
                    ask_special_question(can_i_ask_question, special_questions, new_question, score, difficulty_string, secondsLeft, question_accumulator);                
                    if (special_questions->close_program == true) {
                        flag = 0;
                        break;

                    }
                    else {


                        check_and_update_answer(special_questions->get_answer(), new_question.get_correct_answer(), score, count_correct, hearts);

                    }
                }
                else if ((hearts == 1) && (can_i_ask_question == true)) {
                   
                    special_questions->heart_2->Visible = false;
                    special_questions->heart_3->Visible = false;



                    ask_special_question(can_i_ask_question, special_questions, new_question, score, difficulty_string, secondsLeft, question_accumulator);
                    if (special_questions->close_program == true) {
                        flag = 0;
                        break;

                    }
                    else {
                        check_and_update_answer(special_questions->get_answer(), new_question.get_correct_answer(), score, count_correct, hearts);

                    }
                }
                else if (hearts < 1 && can_i_ask_question == true) {  //NO MORE HEARTS
                    show_loading_screen();
                    Continue_Screen^ screen_continue = gcnew Continue_Screen();
                    screen_continue->lbl_Message->Text = "YOU HAVE RUN OUT OF HEARTS, RETRY IN LOWER DIFFICULTY?";
                    screen_continue->ShowDialog();
                    decision = screen_continue->get_decision();
                    if (decision == 0) {
                        MessageBox::Show("THANK YOU FOR PLAYING!!", "EXIT", MessageBoxButtons::OK, MessageBoxIcon::Information);
                        flag = 0;
                        break;

                    }
                    else {
                        show_loading_screen();
                        count_correct = 0;
                        hearts = 3;
                        secondsLeft = 600;
                        score = 0;
                        special_question.clear();
                        load_special_questions(special_question);
                        MessageBox::Show("RESTARTING QUIZ IN LOWER DIFFICULTY!!", "RELOAD", MessageBoxButtons::OK, MessageBoxIcon::Information);
                        if (level > 0) {
                            level--;
                        }
                        i = -1;

                    }

                }


                secondsLeft = special_questions->get_current_time();

            }
            if(secondsLeft < 1 ){  //TIME IS UP
                
            Continue_Screen^ screen_continue = gcnew Continue_Screen();
            screen_continue->lbl_Message->Text = "YOU HAVE RUN OUT OF TIME, RESTART IN LOWER DIFFICULTY?";
            screen_continue->ShowDialog();
            decision = screen_continue->get_decision();
            if (decision == 0) {
                MessageBox::Show("THANK YOU FOR PLAYING!!", "EXIT", MessageBoxButtons::OK, MessageBoxIcon::Information);
                flag = 0;
                break;

            }
            else {

                show_loading_screen();
                count_correct = 0;
                hearts = 3;
                secondsLeft = 600;
                score = 0;
                special_question.clear();
                load_special_questions(special_question);
                MessageBox::Show("RESTARTING QUIZ IN LOWER DIFFICULTY!!", "RELOAD", MessageBoxButtons::OK, MessageBoxIcon::Information);
                if (level > 0) {
                    level--;
                }
                i = -1;
            }

}




                if (count_correct > 8 ) {
                    show_loading_screen();
                    show_results_screen(score);
                    show_loading_screen();
                    Save_Score_Screen^ score_save = gcnew Save_Score_Screen();
                    score_save->lbl_Title->Text = "SPECIAL QUIZ COMPLETE!!";
                    score_save->ShowDialog();

                    
                    std::string name = SystemStringToStdString(score_save->get_name());

                    save_score(name , score);
                    
                    




                    MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);



                    flag = 0;
                    break;
                    
                }

                


                

                if (secondsLeft > 0) {
                    can_i_ask_question = true; // END OF LOOP, PROGRAM CAN ASK ANOTHER QUESTION
                    
                }
                
                if (special_questions->close_program == true) {
                    flag = 0;
                    break;

                }
            }// end of for loop

        }





    }
    //NORMAL QUIZ
    else {


        //START LOOP FOR 3 DIFFICULTY LEVELS(DEPENDING ON LEVEL CHOSEN)
        for (int difficulty = level; difficulty < 3; difficulty++) {

            //<MCQ QUESTIONS 

            score = 0;

            flag = 1;

            //DETERMINE DIFFICULTY STRING VALUE, THIS WILL BE DISPLAYED ON EVERY QUESTION FORM TO INDIACTE CURRENT DIFFICULTY LEVEL

            if (difficulty == 0) {
                difficulty_string = "Beginner";
            }
            else if (difficulty == 1) {
                difficulty_string = "Intermediate";
            }
            else {
                difficulty_string = "Advanced";
            }


            Question_Multiple_Choice_Screen^ multi_choice = gcnew Question_Multiple_Choice_Screen();
            multi_choice->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            multi_choice->lbl_difficulty->Text = difficulty_string;
            multi_choice->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";


            while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)


                std::shuffle(multi_choice_vector.begin(), multi_choice_vector.end(), gen); // Shuffle questions in vector

                MultiChoice question = multi_choice_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM

                    multi_choice->lbl_Question->Text = StdStringToSystemString(question.get_question_text());
                    multi_choice->lbl_Question->MaximumSize = System::Drawing::Size(multi_choice->getControl("panel2")->Width, 0); // Ensuring the question fits onto the panel perfectly
                    multi_choice->lbl_Answer->Text = StdStringToSystemString(std::to_string(question.get_correct_answer()));
                    multi_choice->pnl_Answer->Visible = false;

                    std::string* choices = question.get_choices();    //GET POINTER FOR CHOICES ARRAY

                    multi_choice->Choice_1->Text = StdStringToSystemString(choices[0]);    //ASSIGN CHOICES TO RADIOBUTTON TEXT
                    multi_choice->Choice_2->Text = StdStringToSystemString(choices[1]);
                    multi_choice->Choice_3->Text = StdStringToSystemString(choices[2]);
                    multi_choice->Choice_4->Text = StdStringToSystemString(choices[3]);


                    multi_choice_vector.pop_back();      //REMOVE QUESTION FROM VECTOR SINCE IT HASS BEEN ASKED ALREDY


                    multi_choice->ShowDialog();     //FIRST MCQ
                    question_accumulator++;
                    if (multi_choice->close_program == true) {
                        difficulty += 99;
                        break;
                    }
                    if (multi_choice->get_answer() == question.get_correct_answer()) {  //IF ANSWER IS CORRECT
                        score += 50;
                       
                    }
                    else {

                        
                        String^ letter = question.get_correct_answer_letter(question.get_correct_answer());

                    }

                    break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                }

                std::shuffle(multi_choice_vector.begin(), multi_choice_vector.end(), gen); // Shuffle questions in vector
            }

            Question_Multiple_Choice_Screen^ multi_choice2 = gcnew Question_Multiple_Choice_Screen();
            multi_choice2->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            multi_choice2->lbl_difficulty->Text = difficulty_string;
            multi_choice2->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(multi_choice_vector.begin(), multi_choice_vector.end(), gen); // Shuffle questions in vector

                    MultiChoice question = multi_choice_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM

                        multi_choice2->lbl_Question->Text = StdStringToSystemString(question.get_question_text());
                        multi_choice2->lbl_Question->MaximumSize = System::Drawing::Size(multi_choice2->getControl("panel2")->Width, 0);
                        multi_choice2->lbl_Answer->Text = StdStringToSystemString(std::to_string(question.get_correct_answer()));
                        multi_choice2->pnl_Answer->Visible = false;
                        std::string* choices = question.get_choices();    //GET POINTER FOR CHOICES ARRAY

                        multi_choice2->Choice_1->Text = StdStringToSystemString(choices[0]);    //ASSIGN CHOICES TO RADIOBUTTON TEXT
                        multi_choice2->Choice_2->Text = StdStringToSystemString(choices[1]);
                        multi_choice2->Choice_3->Text = StdStringToSystemString(choices[2]);
                        multi_choice2->Choice_4->Text = StdStringToSystemString(choices[3]);

                        multi_choice_vector.pop_back();


                        multi_choice2->ShowDialog();     //SECOND MCQ
                        question_accumulator++;
                        if (multi_choice2->close_program == true) {
                            difficulty += 99;
                            break;
                        }
                        if (multi_choice2->get_answer() == question.get_correct_answer()) {  //IF ANSWER IS CORRECT
                            score += 50;

                        }
                        else {

                            String^ letter = question.get_correct_answer_letter(question.get_correct_answer());



                        }






                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(multi_choice_vector.begin(), multi_choice_vector.end(), gen); // Shuffle questions in vector
                }
            }

            Question_Multiple_Choice_Screen^ multi_choice3 = gcnew Question_Multiple_Choice_Screen();
            multi_choice3->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            multi_choice3->lbl_difficulty->Text = difficulty_string;
            multi_choice3->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(multi_choice_vector.begin(), multi_choice_vector.end(), gen); // Shuffle questions in vector

                    MultiChoice question = multi_choice_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM

                        multi_choice3->lbl_Question->Text = StdStringToSystemString(question.get_question_text());
                        multi_choice3->lbl_Question->MaximumSize = System::Drawing::Size(multi_choice3->getControl("panel2")->Width, 0);
                        multi_choice3->lbl_Answer->Text = StdStringToSystemString(std::to_string(question.get_correct_answer()));
                        multi_choice3->pnl_Answer->Visible = false;
                        std::string* choices = question.get_choices();    //GET POINTER FOR CHOICES ARRAY

                        multi_choice3->Choice_1->Text = StdStringToSystemString(choices[0]);    //ASSIGN CHOICES TO RADIOBUTTON TEXT
                        multi_choice3->Choice_2->Text = StdStringToSystemString(choices[1]);
                        multi_choice3->Choice_3->Text = StdStringToSystemString(choices[2]);
                        multi_choice3->Choice_4->Text = StdStringToSystemString(choices[3]);

                        multi_choice_vector.pop_back();

                        multi_choice3->ShowDialog();     //FIRST MCQ
                        question_accumulator++;
                        if (multi_choice3->close_program == true) {
                            difficulty += 99;
                            break;
                        }
                        if (multi_choice3->get_answer() == question.get_correct_answer()) {  //IF ANSWER IS CORRECT
                            score += 50;

                        }
                        else {


                            String^ letter = question.get_correct_answer_letter(question.get_correct_answer());




                        }


                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(multi_choice_vector.begin(), multi_choice_vector.end(), gen); // Shuffle questions in vector
                }
            }


            




            //FILL IN BLANK QUESTIONS




            Question_Fill_In_Blank_Screen^ fill_in_blank = gcnew Question_Fill_In_Blank_Screen();
            fill_in_blank->lbl_current_score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            fill_in_blank->lbl_difficulty->Text = difficulty_string;
            fill_in_blank->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(fill_in_blank_vector.begin(), fill_in_blank_vector.end(), gen); // Shuffle questions in vector

                    FillInBlank question = fill_in_blank_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM


                        fill_in_blank->pnl_Answer->Visible = false;
                        fill_in_blank->lbl_Answer->Text = StdStringToSystemString(question.get_correct_answer());
                        fill_in_blank->lbl_Q_Prefix->Text = StdStringToSystemString(question.get_question_prefix());    //GET QUESTION TEXT
                        fill_in_blank->lbl_Q_Prefix->MaximumSize = System::Drawing::Size(fill_in_blank->getControl("panel2")->Width, 0);
                        fill_in_blank->lbl_Q_Suffix->Text = StdStringToSystemString(question.get_question_suffix());
                        fill_in_blank->lbl_Q_Suffix->MaximumSize = System::Drawing::Size(fill_in_blank->getControl("panel2")->Width, 0);



                        fill_in_blank_vector.pop_back();


                        fill_in_blank->ShowDialog();     //FIRST FILL IN BLANK QUESTION
                        question_accumulator++;
                        if (fill_in_blank->close_program == true) {
                            difficulty += 99;
                            break;
                        }


                        if (toLower(SystemStringToStdString(fill_in_blank->get_answer())) == toLower(question.get_correct_answer())) {  //IF ANSWER IS CORRECT
                            score += 50;

                        }
                        else { //DISPLAY CORRECT ANSWER


                        }


                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(fill_in_blank_vector.begin(), fill_in_blank_vector.end(), gen); // Shuffle questions in vector
                }
            }




            Question_Fill_In_Blank_Screen^ fill_in_blank2 = gcnew Question_Fill_In_Blank_Screen();
            fill_in_blank2->lbl_current_score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            fill_in_blank2->lbl_difficulty->Text = difficulty_string;
            fill_in_blank2->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(fill_in_blank_vector.begin(), fill_in_blank_vector.end(), gen); // Shuffle questions in vector

                    FillInBlank question = fill_in_blank_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM
                        fill_in_blank2->pnl_Answer->Visible = false;
                        fill_in_blank2->lbl_Answer->Text = StdStringToSystemString(question.get_correct_answer());
                        fill_in_blank2->lbl_Q_Prefix->Text = StdStringToSystemString(question.get_question_prefix());    //GET QUESTION TEXT
                        fill_in_blank2->lbl_Q_Prefix->MaximumSize = System::Drawing::Size(fill_in_blank2->getControl("panel2")->Width, 0);
                        fill_in_blank2->lbl_Q_Suffix->Text = StdStringToSystemString(question.get_question_suffix());
                        fill_in_blank2->lbl_Q_Suffix->MaximumSize = System::Drawing::Size(fill_in_blank2->getControl("panel2")->Width, 0);


                        fill_in_blank_vector.pop_back();


                        fill_in_blank2->ShowDialog();     //SECOND FILL IN BLANK QUESTION
                        question_accumulator++;
                        if (fill_in_blank2->close_program == true) {
                            difficulty += 99;
                            break;
                        }


                        if (toLower(SystemStringToStdString(fill_in_blank2->get_answer())) == toLower(question.get_correct_answer())) {  //IF ANSWER IS CORRECT
                            score += 50;

                        }
                        else { //DISPLAY CORRECT ANSWER



                        }






                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(fill_in_blank_vector.begin(), fill_in_blank_vector.end(), gen); // Shuffle questions in vector
                }
            }

            Question_Fill_In_Blank_Screen^ fill_in_blank3 = gcnew Question_Fill_In_Blank_Screen();
            fill_in_blank3->lbl_current_score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            fill_in_blank3->lbl_difficulty->Text = difficulty_string;
            fill_in_blank3->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(fill_in_blank_vector.begin(), fill_in_blank_vector.end(), gen); // Shuffle questions in vector

                    FillInBlank question = fill_in_blank_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM
                        fill_in_blank3->pnl_Answer->Visible = false;
                        fill_in_blank3->lbl_Answer->Text = StdStringToSystemString(question.get_correct_answer());
                        fill_in_blank3->lbl_Q_Prefix->Text = StdStringToSystemString(question.get_question_prefix());    //GET QUESTION TEXT
                        fill_in_blank3->lbl_Q_Prefix->MaximumSize = System::Drawing::Size(fill_in_blank3->getControl("panel2")->Width, 0);
                        fill_in_blank3->lbl_Q_Suffix->Text = StdStringToSystemString(question.get_question_suffix());
                        fill_in_blank3->lbl_Q_Suffix->MaximumSize = System::Drawing::Size(fill_in_blank3->getControl("panel2")->Width, 0);


                        fill_in_blank_vector.pop_back();


                        fill_in_blank3->ShowDialog();     //THIRD FILL IN BLANK QUESTION
                        question_accumulator++;
                        if (fill_in_blank3->close_program == true) {
                            difficulty += 99;
                            break;
                        }


                        if (toLower(SystemStringToStdString(fill_in_blank3->get_answer())) == toLower(question.get_correct_answer())) {  //IF ANSWER IS CORRECT
                            score += 50;

                        }
                        else { //DISPLAY CORRECT ANSWER



                        }






                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(fill_in_blank_vector.begin(), fill_in_blank_vector.end(), gen); // Shuffle questions in vector
                }
            }



            


            //TRUE OR FALSE QUESTIONS




            Question_True_False_Screen^ true_false = gcnew Question_True_False_Screen();
            true_false->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            true_false->lbl_difficulty->Text = difficulty_string;
            true_false->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
               
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)
                   
                    std::shuffle(true_or_false_vector.begin(), true_or_false_vector.end(), gen); // Shuffle questions in vector

                    Question<std::string, bool> question = true_or_false_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM

                        true_false->lbl_Question->Text = StdStringToSystemString(question.get_question_text());    //GET QUESTION TEXT
                        true_false->lbl_Question->MaximumSize = System::Drawing::Size(true_false->getControl("flowLayoutPanel1")->Width, 0);

                        true_false->pnl_Answer->Visible = false;

                        if (question.get_correct_answer() == true) {
                            true_false->lbl_Answer->Text = "true";
                        }
                        else {
                            true_false->lbl_Answer->Text = "false";
                        }



                        true_or_false_vector.pop_back();

                        true_false->ShowDialog();       //FIRST TRUE OR FALSE QUESTION
                        question_accumulator++;
                        if (true_false->close_program == true) {
                            difficulty += 99;
                            break;
                        }


                        if (true_false->get_answer() == question.get_correct_answer()) {  //IF ANSWER IS CORRECT
                            score += 50;

                        }







                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(true_or_false_vector.begin(), true_or_false_vector.end(), gen); // Shuffle questions in vector
                }
            }



            Question_True_False_Screen^ true_false2 = gcnew Question_True_False_Screen();
            true_false2->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            true_false2->lbl_difficulty->Text = difficulty_string;
            true_false2->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";

            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(true_or_false_vector.begin(), true_or_false_vector.end(), gen); // Shuffle questions in vector

                    Question<std::string, bool> question = true_or_false_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM

                        true_false2->lbl_Question->Text = StdStringToSystemString(question.get_question_text());    //GET QUESTION TEXT
                        true_false2->lbl_Question->Text = StdStringToSystemString(question.get_question_text());    //GET QUESTION TEXT
                        true_false2->lbl_Question->MaximumSize = System::Drawing::Size(true_false2->getControl("flowLayoutPanel1")->Width, 0);
                        true_false2->pnl_Answer->Visible = false;

                        if (question.get_correct_answer() == true) {
                            true_false2->lbl_Answer->Text = "true";
                        }
                        else {
                            true_false2->lbl_Answer->Text = "false";
                        }


                        true_or_false_vector.pop_back();


                        true_false2->ShowDialog();       //SECOND TRUE OR FALSE QUESTION
                        question_accumulator++;
                        if (true_false2->close_program == true) {
                            difficulty += 99;
                            break;
                        }


                        if (true_false2->get_answer() == question.get_correct_answer()) {  //IF ANSWER IS CORRECT
                            score += 50;
                            
                        }







                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(true_or_false_vector.begin(), true_or_false_vector.end(), gen); // Shuffle questions in vector
                }
            }
            Question_True_False_Screen^ true_false3 = gcnew Question_True_False_Screen();
            true_false3->lbl_Current_Score->Text = StdStringToSystemString(std::to_string(score)) + " / 450";
            true_false3->lbl_difficulty->Text = difficulty_string;
            true_false3->lbl_progress->Text = "Question: " + StdStringToSystemString(std::to_string(question_accumulator)) + " / 9";


            if (difficulty < 99) {
                while (flag != 0) {   //LOOK FOR RANDOM QUESTION THAT FITS THE PARAMETERS(DIFFICULTY)

                    std::shuffle(true_or_false_vector.begin(), true_or_false_vector.end(), gen); // Shuffle questions in vector

                    Question<std::string, bool> question = true_or_false_vector.back();  //RETRIEVE NEW QUESTION OBJECT

                    int Question_Difficulty = question.get_difficulty();  //RETREIVE DIFFICULTY OF QUESTION

                    if (Question_Difficulty == difficulty) { //IF QUESTION IS SAME AS REQUIRED DIFFICULTY, THEN LOAD IT INTO A FORM

                        true_false3->lbl_Question->Text = StdStringToSystemString(question.get_question_text());    //GET QUESTION TEXT
                        true_false3->lbl_Question->MaximumSize = System::Drawing::Size(true_false3->getControl("flowLayoutPanel1")->Width, 0);

                        true_false3->pnl_Answer->Visible = false;

                        if (question.get_correct_answer() == true) {
                            true_false3->lbl_Answer->Text = "true";
                        }
                        else {
                            true_false3->lbl_Answer->Text = "false";
                        }


                        true_or_false_vector.pop_back();


                        true_false3->ShowDialog();       //THIRD TRUE OR FALSE QUESTION
                        question_accumulator++;
                        if (true_false3->close_program == true) {
                            difficulty += 99;
                            break;
                        }


                        if (true_false3->get_answer() == question.get_correct_answer()) {  //IF ANSWER IS CORRECT
                            score += 50;
                            
                        }







                        break;                      //BREAK THE LOOP, WE FOUND AN APPROPRIATE QUESTION

                    }



                    std::shuffle(true_or_false_vector.begin(), true_or_false_vector.end(), gen); // Shuffle questions in vector
                }
            }

            show_loading_screen();

            //Q_U_E_S_T_I_O_N__L_E_V_E_L__C_O_M_P_L_E_T_E_D
            if (difficulty < 99) {
                global_score += score;
                if (score >= 300) {
                    show_results_screen(score);


                }
               



                    if (score < 300) {
                       
                        show_results_failed(score);
                        show_loading_screen();
                        Continue_Screen^ continue_screen = gcnew Continue_Screen();
                        continue_screen->lbl_Message->Text = "Would you like to restart the quiz?";
                        continue_screen->ShowDialog();

                        if (continue_screen->get_decision() == 1) {
                            difficulty--;
                            question_accumulator = 1;
                            //EMPTY OUT ALL VECTORS

                            true_or_false_vector.clear();
                            fill_in_blank_vector.clear();
                            multi_choice_vector.clear();


                            //POPULATE VECTORS ALL OVER AGAIN

                            load_normal_questions(multi_choice_vector, fill_in_blank_vector, true_or_false_vector);








                        }
                        else {
                            show_loading_screen();
                            Continue_Screen^ continue_screen_no = gcnew Continue_Screen();
                            continue_screen_no->lbl_Message->Text = "Would you like to save score?";
                            continue_screen_no->ShowDialog();
                            if (continue_screen_no->get_decision() == 1) {
                                show_loading_screen();
                                Save_Score_Screen^ save_score1 = gcnew Save_Score_Screen();
                                save_score1->lbl_Title->Text = "Congrats on making it this far";
                                save_score1->ShowDialog();
                                std::string name = SystemStringToStdString(save_score1->get_name());
                              
                                save_score(name, global_score);
                              



                                MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);

                            }
                            else {
                                MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);
                            }

                            break;

                        }





                    }
                    else {
                       
                        Continue_Screen^ continue_screen_passed = gcnew Continue_Screen();
                        System::String^ difficulty_text;

                        if (difficulty == 0) {
                            difficulty_text = "Intermediate";
                        }

                        if (difficulty == 1) {
                            difficulty_text = "Advanced";
                        }





                        if (difficulty < 2) {
                            continue_screen_passed->lbl_Message->Text = "Would you like to continue to " + difficulty_text + " difficulty?";
                            continue_screen_passed->ShowDialog();

                            if (continue_screen_passed->get_decision() == 1) {
                                
                                MessageBox::Show("YAYY!!!Next level will be abit harder, welcome to " + difficulty_text + "difficulty. ", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                question_accumulator = 1;
                            }
                            else {
                                Continue_Screen^ continue_screen_no_passed = gcnew Continue_Screen();
                                show_loading_screen();
                                continue_screen_no_passed->lbl_Message->Text = "Would you like to save score?";
                                continue_screen_no_passed->ShowDialog();
                                if (continue_screen_no_passed->get_decision() == 1) {
                                    show_loading_screen();
                                    Save_Score_Screen^ save_score2 = gcnew Save_Score_Screen();
                                    save_score2->lbl_Title->Text = "Congrats on making it this far";
                                    save_score2->ShowDialog();
                                    std::string name = SystemStringToStdString(save_score2->get_name());
                                    save_score(name, global_score);

                                   




                                    MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);

                                }
                                else {
                                    MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                }

                                break;


                            }

                        }
                        else {

                            continue_screen_passed->lbl_Message->Text = "QUIZ Complete! Would you like to continue to save score?";
                            continue_screen_passed->ShowDialog();
                            if (continue_screen_passed->get_decision() == 1) {
                                show_loading_screen();
                                Save_Score_Screen^ save_score3 = gcnew Save_Score_Screen();
                                save_score3->lbl_Title->Text = "Congrats on making it this far";
                                save_score3->ShowDialog();
                                std::string name = SystemStringToStdString(save_score3->get_name());
                                save_score(name, global_score);

                               




                                MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);


                            }
                            else {

                                MessageBox::Show("Thank you for playing!", " ", MessageBoxButtons::OK, MessageBoxIcon::Information);

                            }

                            break;


                        }



                    }
                
            }
        }

    }



    }

    }
    }

    return 0;
}