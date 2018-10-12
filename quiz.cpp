// Filename quiz.cpp
#include "quiz.hpp"
#include <iostream>
#include <string>
using namespace std;

question create_question() {
  question q;
  string text, answer;
  cout << "Please enter your question: ";
  getline(cin, text);
  cout << "Please enter the answer: ";
  getline(cin, answer);
  cout << "Question added!" << endl;
  q.set_text(text);
  q.set_answer(answer);
  return q;
}
