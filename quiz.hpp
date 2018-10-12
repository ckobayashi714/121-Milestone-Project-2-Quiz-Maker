// Filename: quiz.hpp
#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <iostream>
#include <string>
using namespace std;

class Question {
private:
  string _text;
  string _answer;

public:
  void set_text(string text) { _text = text; }
  void set_answer(string answer) { _answer = answer; }
  string get_text() { return _text; }
  string get_answer() { return _answer; }

  void create_question() {
    cout << "Please enter your question: ";
    getline(cin, _text);
    cout << "Please enter the answer: ";
    getline(cin, _answer);
    cout << "Question added!" << endl;
  };
};
#endif
