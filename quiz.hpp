// Filename: quiz.hpp
#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <iostream>
#include <string>
using namespace std;

// Definition of the class Question.
class question {
private:
  string _text;
  string _answer;

public:
  void set_text(string text) { _text = text; }
  void set_answer(string answer) { _answer = answer; }
  string text() { return _text; }
  string answer() { return _answer; }
};
question create_question();
#endif
