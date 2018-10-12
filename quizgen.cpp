#include "quiz.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Question q;

  Question qArray[100];
  for (int i = 0; i < 100; i++) {
    Question q;
    qArray[i] = q;
  }

  char choice;
  cout << "Welcome to QuizMaker\n";
  cout << endl;
  cout << "What would you like to do?\n";
  cout << "a. Create a question\n";
  cout << "b. Quit\n";
  cout << "Choice: ";
  cin >> choice;
  cin.ignore();
  int i = 0;

  do {
    switch (choice) {
    case 'a':
    case 'A':
      cout << endl;
      q.create_question();
      cout << endl;
      cout << "What would you like to do?" << endl;
      cout << "a. Create a question" << endl;
      cout << "b. Quit" << endl;
      cout << "Choice: ";
      cin >> choice;
      cin.ignore();
      break;
    case 'b':
    case 'B':
      break;
    default:
      cout << endl;
      cout << "Invalid option\n";
      cout << endl;
      cout << "What would you like to do?" << endl;
      cout << "a. Create a question" << endl;
      cout << "b. Quit" << endl;
      cout << "Choice: ";
      cin >> choice;
      cin.ignore();
    }
  } while (choice != 'b' && choice != 'B');
  cout << endl;
  cout << "Thank you for using QuizMaker!" << endl;
  return 0;

  //   {
  //   qArray[0] = Question::create_question();
  //   return 0;
  // }
}
