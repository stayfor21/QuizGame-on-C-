#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
#include <ctime>     

class Question {
private:
    std::string question_text;
    std::string answer_1;
    std::string answer_2;
    std::string answer_3;
    std::string answer_4;

    int correct_answer = 0;
    int question_score = 0;

public:

    Question() = default;

    Question(const std::string& question_text, const std::string& answer_1,
             const std::string& answer_2, const std::string& answer_3,
             const std::string& answer_4, int correct_answer, int question_score);

    void SetValues(const std::string& question_text, const std::string& answer_1,
                   const std::string& answer_2, const std::string& answer_3,
                   const std::string& answer_4, int correct_answer, int question_score);

    int AskQuestion();
};


Question::Question(const std::string& qt, const std::string& a1, const std::string& a2, 
                   const std::string& a3, const std::string& a4, int ca, int qs)
    : question_text(qt), answer_1(a1), answer_2(a2), answer_3(a3), answer_4(a4),
      correct_answer(ca), question_score(qs) {}

void Question::SetValues(const std::string& qt, const std::string& a1, const std::string& a2,
                         const std::string& a3, const std::string& a4, int ca, int qs) {
    question_text = qt;
    answer_1 = a1;
    answer_2 = a2;
    answer_3 = a3;
    answer_4 = a4;
    correct_answer = ca;
    question_score = qs;
}

int Question::AskQuestion() {
    int answer = 0;
    std::cout << "\n" << question_text << "\n"
              << "\t1) " << answer_1 << "\n"
              << "\t2) " << answer_2 << "\n"
              << "\t3) " << answer_3 << "\n"
              << "\t4) " << answer_4 << "\n";

    std::cout << "Your answer (1-4): ";
    std::cin >> answer;


    while (answer < 1 || answer > 4) {
        std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
        std::cin >> answer;
    }

    if (answer == correct_answer) {
        std::cout << "Correct! Score: +" << question_score << "\n";
        return question_score;
    } else {
        std::cout << "Incorrect. Score: +0\nCorrect Answer: " << correct_answer << "\n";
        return 0;
    }
}

