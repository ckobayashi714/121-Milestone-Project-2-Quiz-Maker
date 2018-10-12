#include "quiz.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  /* This will create an array of 100 question objects*/
  question q;
  question qArray[100];

  /* This program will reapteadly ask the user to input a question or exit. If
  the user inputs something other than a or b (capital letters too), they will
  be notified with an invalid message, but will then be asked again what option
  they would like to choose.*/
  char choice;
  int i = 0;
  cout << "Welcome to QuizMaker\n";

  do {
    cout << "\n"
         << "What would you like to do?\n"
         << "a. Create a question\n"
         << "b. Quit\n"
         << "Choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 'a':
    case 'A':
      cout << "\n";
      qArray[i] = create_question();
      i++;
      break;
    case 'b':
    case 'B':
      break;
    default:
      cout << "\nInvalid option\n";
    }
  } while (choice != 'b' && choice != 'B');
  cout << "\n"
       << "Thank you for using QuizMaker!\n";
  return 0;
}
