#include "quiz.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  /* This will create an array of 100 question objects*/
  Question q;
  Question qArray[100];
  for (int i = 0; i < 100; i++) {
    Question q;
    qArray[i] = q;
  }
  /* This program will reapteadly ask the user to input a question or exit. If the
  user inputs something other than a or b (capital letters too), they will be
  notified with an error message, but will then be asked again what option they
  would like to choose.*/
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
    {
    qArray[0] = Question::create_question();
    return 0;
  }
}
