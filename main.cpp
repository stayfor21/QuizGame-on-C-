#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  
#include "header.hpp"

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));

    cout << "\n\n\t\t\t<QUIZ GAME>" << endl;
    cout << "\nChoose a category:\n1) Science\n2) History\n3) General Knowledge\n";
    int category_choice;
    cin >> category_choice;

    vector<Question> science_questions;
    vector<Question> history_questions;
    vector<Question> general_questions;

    science_questions.push_back(Question("What is the formula of water?", "H2O", "H2", "CO2", "CH", 1, 10));
    science_questions.push_back(Question("What planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", "Venus", 2, 10));
    science_questions.push_back(Question("What gas do plants absorb?", "Oxygen", "Nitrogen", "Carbon Dioxide", "Helium", 3, 10));
    science_questions.push_back(Question("What is the boiling point of water?", "90°C", "50°C", "100°C", "150°C", 3, 10));
    science_questions.push_back(Question("How many planets are in the solar system?", "7", "8", "9", "10", 2, 10));

    history_questions.push_back(Question("In what year did World War II end?", "1941", "1945", "1939", "1949", 2, 10));
    history_questions.push_back(Question("Who was the first president of the USA?", "Abraham Lincoln", "George Washington", "Thomas Jefferson", "John Adams", 2, 10));
    history_questions.push_back(Question("What year did the Roman Empire fall?", "476 AD", "300 AD", "1453 AD", "500 AD", 1, 10));
    history_questions.push_back(Question("Where did the Renaissance begin?", "France", "England", "Italy", "Spain", 3, 10));
    history_questions.push_back(Question("Who was known as 'The Maid of Orleans'?", "Cleopatra", "Queen Elizabeth", "Joan of Arc", "Mary Stuart", 3, 10));

    general_questions.push_back(Question("How many days are there in a week?", "5", "4", "7", "6", 3, 10));
    general_questions.push_back(Question("What year did the Titanic sink?", "1905", "1912", "1915", "1920", 2, 10));
    general_questions.push_back(Question("What is the capital of France?", "Berlin", "Paris", "Madrid", "Lisbon", 2, 10));
    general_questions.push_back(Question("Which animal is known as the 'Ship of the Desert'?", "Horse", "Camel", "Elephant", "Lion", 2, 10));
    general_questions.push_back(Question("How many continents are there?", "5", "6", "7", "8", 3, 10));

    vector<Question> selected_questions;
    if (category_choice == 1) {
        selected_questions = science_questions;
    } else if (category_choice == 2) {
        selected_questions = history_questions;
    } else if (category_choice == 3) {
        selected_questions = general_questions;
    } else {
        cout << "Invalid category choice. Exiting game.\n";
        return 0;
    }

    int total_score = 0;

    random_shuffle(selected_questions.begin(), selected_questions.end());

    cout << "\nYou selected category " << category_choice << ". Answer all 5 questions:\n";
    for (auto& question : selected_questions) {
        total_score += question.AskQuestion();
    }

    cout << "\nTotal points scored in this category: " << total_score << " out of 50 possible.\n";

    if (total_score >= 40) {
        cout << "Congratulations! You won in this category!\n";
    } else {
        cout << "You didn't score enough points. Try again!\n";
    }

    return 0;
}

