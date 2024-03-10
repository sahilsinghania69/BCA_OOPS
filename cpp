1. Complete the given below code, it is strictly recommended to define the member functions outside of the class and not to include any namespace in your code.
#include <iostream>

class Box {
private:
    int length;
    int width;

public:
    void getDimensions();
    void showDimensions();
};

void Box::getDimensions() {
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter width: ";
    std::cin >> width;
}

void Box::showDimensions() {
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
}

int main() {
    Box box1, box2, box3;

    std::cout << "For box1:" << std::endl;
    box1.getDimensions();
    box1.showDimensions();

    std::cout << "\nFor box2:" << std::endl;
    box2.getDimensions();
    box2.showDimensions();

    std::cout << "\nFor box3:" << std::endl;
    box3.getDimensions();
    box3.showDimensions();

    return 0;
}
•	We have defined the Box class with private members length and width.
•	The getDimensions() member function prompts the user to enter the length and width of the box and stores the values in the respective data members.
•	The showDimensions() member function displays the length and width of the box.
•	Member function definitions are provided outside of the class.
•	In the main() function, we create three objects of the Box class (box1, box2, box3), and then call the getDimensions() and showDimensions() functions for each object to get and display their dimensions.
2.Complete the given code snippet which contains two data members e.g. principal and time which are mapped with objects and one data member, interest which is not mapped with any of the object. 

#include<iostream>
using namespace std;

class Banking {
private:
    static float interest;
    int principal;
    int time; // in months only

public:
    void getdata() {
        cout << "Enter principal amount: ";
        cin >> principal;
        cout << "Enter time (in months): ";
        cin >> time;
    }

    void Calculate_SI() {
        float simpleInterest = (principal * interest * time) / 100.0;
        cout << "Simple Interest: " << simpleInterest << endl;
    }
};

float Banking::interest = 2; // Initializing static member interest

int main() {
    Banking b1, b2;

    cout << "For b1:" << endl;
    b1.getdata(); // Getting data for b1
    b1.Calculate_SI(); // Calculating and displaying simple interest for b1

    cout << "\nFor b2:" << endl;
    b2.getdata(); // Getting data for b2
    b2.Calculate_SI(); // Calculating and displaying simple interest for b2

    return 0;
}
3.Write a program in C++ which contains a class Students, two members member function with same name (signature of the function may be different) to get and display the details of the student as given below:
Name (character array)
Marks (for five subjects)
Grade (>80%: E, 70-80%: A, 60-70%: B, 50-60%: C and less than 50%: F)
#include <iostream>
#include <cstring>

class Students {
private:
    char name[50];
    int marks[5];
    
    // Function to calculate grade based on marks
    char calculateGrade(int mark) {
        if (mark > 80)
            return 'E';
        else if (mark >= 70 && mark <= 80)
            return 'A';
        else if (mark >= 60 && mark < 70)
            return 'B';
        else if (mark >= 50 && mark < 60)
            return 'C';
        else
            return 'F';
    }

public:
    // Member function to set student details
    void setDetails(const char* studentName, const int studentMarks[5]) {
        strcpy(name, studentName);
        for (int i = 0; i < 5; ++i) {
            marks[i] = studentMarks[i];
        }
    }

    // Member function to display student details
    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks:\n";
        for (int i = 0; i < 5; ++i) {
            std::cout << "Subject " << (i+1) << ": " << marks[i] << std::endl;
        }
        std::cout << "Grade:\n";
        for (int i = 0; i < 5; ++i) {
            std::cout << "Subject " << (i+1) << ": " << calculateGrade(marks[i]) << std::endl;
        }
    }
};

int main() {
    Students student1;
    const char name[] = "John";
    int marks[] = {85, 72, 60, 55, 40}; // Sample marks for five subjects
    student1.setDetails(name, marks);
    student1.displayDetails();
    return 0;
}

4..Write a program in C++ with one member function to accept five integers from 0 to 9 and another function to display the equivalent values in word as shown below. The converted values should be stored in one of the member variables. 
Input
2	4	0	1	7

Output
Two	Four	Zero	One	Seven

#include <iostream>
#include <string>

class NumberConverter {
private:
    int numbers[5];
    std::string words[5];

    // Function to convert integer to word
    std::string convertToWord(int num) {
        switch (num) {
            case 0:
                return "Zero";
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
            default:
                return "Invalid";
        }
    }

public:
    // Member function to accept five integers and convert them to words
    void acceptNumbers(int num1, int num2, int num3, int num4, int num5) {
        numbers[0] = num1;
        numbers[1] = num2;
        numbers[2] = num3;
        numbers[3] = num4;
        numbers[4] = num5;

        for (int i = 0; i < 5; ++i) {
            words[i] = convertToWord(numbers[i]);
        }
    }

    // Member function to display the equivalent values in words
    void displayWords() {
        for (int i = 0; i < 5; ++i) {
            std::cout << words[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    NumberConverter converter;
    converter.acceptNumbers(2, 4, 0, 1, 7);
    std::cout << "Output: ";
    converter.displayWords();
    return 0;
}
5.Create your own header file named as Find_Calculation which consists of three important functions that accepts and return double value(s) to compute the square root, cube and power of integer values respectively. Add this library in your C++ code and call these functions to perform the mathematical calculations.
Note: Students are not allowed to use the readymade functions 

To create your own header file named "Find_Calculation" which consists of three functions to compute the square root, cube, and power of integer values, and then call these functions in your C++ code, you can follow these steps.

Step 1: Create a header file named "Find_Calculation.h" and define the function prototypes inside it.

Cpp1
// Find_Calculation.h

#ifndef FIND_CALCULATION_H
#define FIND_CALCULATION_H

double find_Sqrt(double value);
double find_Cube(double value);
double find_Pow(double base, double exponent);

#endif
Step 2: Implement the functions in a corresponding source file, for example, "Find_Calculation.cpp".

Cpp2
// Find_Calculation.cpp

#include "Find_Calculation.h"

double find_Sqrt(double value) {
    double epsilon = 1e-10;
    double guess = value / 2.0;
    while (abs(guess * guess - value) > epsilon) {
        guess = (guess + value / guess) / 2.0;
    }
    return guess;
}

double find_Cube(double value) {
    return value * value * value;
}

double find_Pow(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}
Step 3: Include the header file in your C++ code where you want to use these functions and call them accordingly.

Cpp3
// YourMain.cpp

#include <iostream>
#include "Find_Calculation.h"

int main() {
    double n1, n2, result;

    std::cout << "Enter a number: ";
    std::cin >> n1;

    // Calculate and display square root
    result = find_Sqrt(n1);
    std::cout << "Square root of " << n1 << " is: " << result << std::endl;

    // Calculate and display cube
    result = find_Cube(n1);
    std::cout << "Cube of " << n1 << " is: " << result << std::endl;

    std::cout << "Enter another number: ";
    std::cin >> n2;

    // Calculate and display power
    result = find_Pow(n1, n2);
    std::cout << n1 << " raised to the power " << n2 << " is: " << result << std::endl;

    return 0;
}
Ensure that "Find_Calculation.h", "Find_Calculation.cpp", and "YourMain.cpp" are in the same directory when you compile and run the code. This way, you have created your own header file named "Find_Calculation" containing three functions to compute square root, cube, and power of integer values, and used them in your C++ code.

