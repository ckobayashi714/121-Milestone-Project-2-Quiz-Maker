# QuizMaker Project Milestone 2

This is milestone 2 of the [QuizMaker Project](https://docs.google.com/document/d/1kxz9GX_Fm1rGeQZCyvOVQ7Szpre8MZwEgXG5zyMIcI8/edit?usp=sharing).

# Requirements
Design the `question` class that contains two data members: `_text` and `_answer`. Provide the appropriate accessor and mutator methods that will be used to access the data members. Use appropriate access specifiers so that the data members are only accessible through the accessor and mutators.

Implement the `create_question` function that does not receive any parameters, but returns a `question` object. The function should ask the user to input the question and answer then store this information into a `question` object. This object should be returned by the function. You can reuse your code from the `addQuestion` function from milestone 1.

Develop a menu-based command-line interface (CLI) that repeatedly asks a user to input a question and answer until the option to exit is used. Call the `create_question` function to ask for user's input. Kindly refer to the sample runs below and follow the output as closely as possible.

```
Welcome to QuizMaker

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: Who is the mother of the COBOL programming language?
Please enter the answer: Grace Hopper
Question added!

What would you like to do?
a. Create a question
b. Quit
Choice: x

Invalid option

What would you like to do?
a. Create a question
b. Quit
Choice: b

Thank you for using QuizMaker!
```

In this version, you should create an array of 100 `question` objects in the driver (`main.cpp`). Every time `create_question` is called, the object returned should be added to the end of the array such that the first object is in index 0, the second will be in index 1, and so forth.

Place the function prototypes and classes in `quiz.hpp`, the function implementations in `quiz.cpp`, and the main function in `quizgen.cpp`.

# Documentation
See [google's style guide](https://google.github.io/styleguide/cppguide.html#Comments) for more details.

## File comments
Describe the contents of the file on the first line. For example:

```cpp
// This file implements a simple calculator
```

## Function comments
Describe the use of the function and how it is implemented if it is non-obvious. For example:

```cpp
// Displays a greeting on the command line using the name parameter.
void show_greeting(string name) {
  // ...
}
```

## Implementation comments
Provide comments in tricky, non-obvious, interesting, or important parts of your code.

```cpp
// Compute the distance between two points using the distance formula
// sqrt((x1-x2)^2 + (y1-y2)^2)
double dist = sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
```

# Code evaluation
Open the terminal and navigate to the folder that contains this milestone. Assuming you have pulled the code inside of `/home/student/project01-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd project01-tuffy
```

Use the `g++` command to compile your code and the `./` command to run it. The sample commands below shows how you would compile code save in `quizgen.cc` and into the executable file `quizgen`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 quizgen.cpp quiz.cpp -o quizgen
./quizgen
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```
    
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
    
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    
    When you're done, make sure you type `git commit` again.   
    
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.

1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
    
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the project milestone page. Provide a short message in the text area such as "finished milestone" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
