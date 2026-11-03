#include <iostream>
//#include <cctype>
#include <string>
#include <vector>
using namespace std;

struct QuizQuestion {
    string question;
    vector<string> options;
    char correctAnswer;
};

int main() {
    vector<QuizQuestion> questions = {
        {
            "Which of the following is used to store a single character?",
            {"int", "char", "float", "double"},
            'B'
        },
        {
            "Which keyword is used to define a function in C++?",
            {"func", "define", "int", "return"},
            'C'
        },
        {
            "Which of these is a loop in C++?",
            {"if", "switch", "for", "case"},
            'C'
        },
        {
            "What is the correct syntax for printing output in C++?",
            {"print()", "console.log()", "cout <<", "System.out.println()"},
            'C'
        },
        {
            "Which header file is commonly used for input and output?",
            {"<math.h>", "<iostream>", "<string.h>", "<vector>"},
            'B'
        }
    };

    int score = 0;
    char userAnswer;

    cout << "Welcome to the C++ Quiz!\n\n";

    for (size_t i = 0; i < questions.size(); i++) {
        cout << "Question " << (i + 1) << ": " << questions[i].question << "\n";
        for (size_t j = 0; j < questions[i].options.size(); j++) {
            cout << char('A' + j) << ". " << questions[i].options[j] << "\n";
        }

        cout << "Your answer: ";
        cin >> userAnswer;
        userAnswer = static_cast<char>(toupper(static_cast<unsigned char>(userAnswer)));

        if (userAnswer == questions[i].correctAnswer) {
            cout << "Correct!\n\n";
            score++;
        } else {
            cout << "Wrong! Correct answer: " << questions[i].correctAnswer << "\n\n";
        }
    }

    cout << "Your final score: " << score << " / " << questions.size() << "\n";

    if (score == static_cast<int>(questions.size())) {
        cout << "Excellent! You got all questions right!\n";
    } else if (score >= questions.size() * 0.7) {
        cout << "Good job! Keep practicing.\n";
    } else {
        cout << "Nice try! Review the concepts and try again.\n";
    }

    return 0;
}
