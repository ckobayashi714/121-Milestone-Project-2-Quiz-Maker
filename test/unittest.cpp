#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../quiz.hpp"
using ::testing::HasSubstr;
using ::testing::StartsWith;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(Quiz, PublicMethodsPresent) {
  question q;
  ASSERT_NO_THROW({
    q.text();
    q.answer();
    q.set_text("a");
    q.set_answer("b");
  });
}

TEST(Quiz, MutatorsAndAccessors) {
  question q;
  std::string text, answer;
  text = generate_string(10);
  answer = generate_string(10);
  ASSERT_NO_THROW({
    q.set_text(text);
    q.set_answer(answer);
  });
  ASSERT_EQ(q.text(), text);
  ASSERT_EQ(q.answer(), answer);
}

TEST(Quiz, CreateQuestion) {
  std::string text, answer;
  text = generate_string(10);
  answer = generate_string(10);
  question temp, actual;
  temp.set_text(text);
  temp.set_answer(answer);
  std::string input = text+"\n"+answer;
  SIMULATE_CIN(input, {
    actual = create_question();
  });
  ASSERT_EQ(temp.text(), actual.text());
  ASSERT_EQ(temp.answer(), actual.answer());
}

TEST(Quiz, FiniteChoiceLoop) {
  srand (time(NULL));
  ASSERT_TIMED_BLOCK_START("Choice", 10000);
  main_output("quizgen", "a\nX\nX\nb");
  ASSERT_TIMED_BLOCK_END();
}

TEST(Quiz, CreateQuestionChoice) {
  std::string expected = "Welcome to QuizMaker\n\nWhat would you like to do?\n"
                         "a. Create a question\nb. Quit\nChoice: "
                         "\nPlease enter your question: Please enter the "
                         "answer: Question added!\n";
  ASSERT_MAIN_OUTPUT_THAT("quizgen", "a\nX\nX\nb", StartsWith(expected));
}

TEST(Quiz, QuitChoice) {
  std::string expected = "Welcome to QuizMaker\n\nWhat would you like to do?\n"
                         "a. Create a question\nb. Quit\nChoice: "
                         "\nThank you for using QuizMaker!\n";
  ASSERT_MAIN_OUTPUT_EQ("quizgen", "b", expected);
}

TEST(Quiz, InvalidOptionChoice) {
  std::string expected = "Welcome to QuizMaker\n\nWhat would you like to do?\n"
                         "a. Create a question\nb. Quit\nChoice: "
                         "\nInvalid option";
  ASSERT_MAIN_OUTPUT_THAT("quizgen", "x\nb", StartsWith(expected));
}

TEST(Quiz, ChoiceLoopLowercase) {
  int repetitions = rand() % 10 + 1;
  for (int i = 0; i < repetitions; i++) {
    std::string input = "";
    std::string expected = "Welcome to QuizMaker\n\n";
    char choice;
    do {
      choice = rand() % 3 + 97;
      expected += "What would you like to do?\na. Create a question\nb. Quit\n"
                  "Choice: \n";
      std::string s_choice(1, choice);
      input += s_choice + "\\n";
      switch (choice) {
        case 'a':
          expected += "Please enter your question: Please enter the answer: "
                      "Question added!\n\n";
          input += "q\\na\\n";
          break;
        case 'b':
          expected += "Thank you for using QuizMaker!\n";
          break;
        default:
          expected += "Invalid option\n\n";
      }
    } while(choice!= 'b');
    ASSERT_MAIN_OUTPUT_EQ("quizgen", input, expected);
  }
}

TEST(Quiz, ChoiceLoopUppercase) {
  int repetitions = rand() % 10 + 1;
  for (int i = 0; i < repetitions; i++) {
    std::string input = "";
    std::string expected = "Welcome to QuizMaker\n\n";
    char choice;
    do {
      choice = rand() % 3 + 65;
      expected += "What would you like to do?\na. Create a question\nb. Quit\n"
                  "Choice: \n";
      std::string s_choice(1, choice);
      input += s_choice + "\\n";
      switch (choice) {
        case 'A':
          expected += "Please enter your question: Please enter the answer: "
                      "Question added!\n\n";
          input += "q\\na\\n";
          break;
        case 'B':
          expected += "Thank you for using QuizMaker!\n";
          break;
        default:
          expected += "Invalid option\n\n";
      }
    } while(choice!= 'B');
    ASSERT_MAIN_OUTPUT_EQ("quizgen", input, expected);
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
