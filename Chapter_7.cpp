Lesson 7 : Organizing Code with Functions


Functions give you a way to compartmentalize and organize your program's execution logic. They enable you to split the contents of your application into logical blocks that are invoked sequentially. A function is essentially a subprogram that takes optional parameters and returns a value and it must be invoked in order to perform its task. 

Below is an example of a function prototype. A function prototype essentially tells the name of a function, the list of parameters accepted by the function(and their return types), and the return type of a function. The function prototypes tell that Area is a function that takes a parameter radius with a data type of value, and that function is expected to return a double value. The compiler recognizes this as valud and links the function call to its actual implementation. A function can have multiple parameters separated by commas, but it can only have one return type. When programming a function that does not need to return any value, specify the return type as void. 
  returnType functionName(functionParameters[returnType parameterName]);
  double Area(double radius);


The actual implementation of a function is what is called a definition. A function definition is always comprised of a statement block. A return statement is necessary unless the function is declared with return type void. Function parameters are like local variables. They are valid within the scope of the function only. 


You can also provide default values to function parameters. You can have multiple parameters with default values, but they should all be at the tail end of the parameter list. 
  #include <iostream>
  using namespace std;

  //Function Declarations(prototypes)
  double Area(double radius, double pi = 3.14);

  int main()
  {
    cout << "Enter radius: ";
    double radius = 0;
    cin >> radius; 

    cout << "pi is 3.14, do you wish to change this? (y/n)";
    char changePi = 'n';
    cin >> changePi; 

    double circleArea = 0;

    if (changePi = 'y')
    {
      cout << "Enter new pi: ";
      double newPi = 3.14;
      cin >> newPi;
      circleArea = Area(radius, newPi);
    }
    else 
      circleArea = Area(radius, newPi);

    //Call Function Area
    cout << "Area is: " << circleArea << endl;

    return 0;


    //Function Definitions
    double Area(double radius, double pi)
    {
      return pi * radius * radius
    }
  }


In certain cases, you can have a function call itself ~ recursive function. A recursive function should have a very clearly defined exit condition where it returns without invoking itself again. In the absence of an exit condition or in the event of a bug in the same, your program execution gets stuck at the recursive function that will keep invoking itself which eventually stops when the "stack overflows" and causes the app to crash. 

Using Recursive Functions to Calculate a Number in the Fibonacci Sequence
  #include <iostream>
  using namespace std;

  int GetFibNumber(int fibIndex)
  {
    if (fibIndex < 2)
      return fibIndex;
    else    //recursion example 
      return GetFibNumber(fibIndex - 1) + GetFibNumber(fibIndex - 2);
  }

  int main()
  {
    cout << "Enter 0-based index of desired Fibonacci number: ";
    int index = 0;
    cin >> index; 

    cout << "Fibonacci number is: " << GetFibNumber(index) << endl;
    return 0;
  }


Functions with Multiple Return Statements: Use multiple returns in a function with caution. It is much easier to understand and follow a function that starts at the top and returns at the bottom than it is to follow one that returns at multiple points in between. 


Functions don't restrict you to passing values one at a time: you can pass an array of values to a function. You can create two functions with the same name and return value but with different parameters. Functions with the same name and return type, but with different parameters are said to be overloaded functions. Overloaded functions can be useful in applications where a function with a particular name that produces a certain type of output might need to be invoked with different sets of parameters. 
  #include <iostream>
  using namespace std; 

  const double Pi = 3.14159265;
  double Area(double radius); 
  double Area(double radius, double height);

  int main()
  {
    cout << "Enter z for Cylinder, C for Circle: ";
    char userSelection = 'z';
    cin >> userSelection; 

    cout << "Enter radius: " << endl;
    double radius = 0;
    cin >> radius; 

    if (userSelection == 'z')
    {
      cout << "Enter height: ";
      double height = 0;
      cin >> height; 

      //Invoke overloaded variant of Area for Cylinder 
      cout << "Area of cylinder is: " << Area (radius, height) << endl;
    }
    else 
      cout << "Area of circle is: " << Area (radius) << endl;

    return 0;
  }

  double Area(double radius)
  {
    return Pi * radius * radius;
  }

  //overloaded function
  double Area(double radius, double height)
  {
    //reuse the area of circle
    return 2 * Area(radius) + 2 * Pi * radius * height; 
  }


Passing an Array of Values to a Function: 
  void DisplayInteger(int Number);                  //function displaying an integer
  void DisplayIntegers(int[] numbers, int Length);  //function displaying an array of integers 
    ^^ The first parameter tells the function that the data being input is an array and the second parameter supplies the length of the array. 


Passing Arguments by Reference: 
In cases where you might need a function to work on a variable that modifies a value that is available outside a function too, like in the calling function, you declare a parameter that takes an argument by reference. A form of the function Area from the previous example that computes and returns the area as a parameter by reference looks like: 
  void Area(double radius, double& result)
  {
    result = Pi * radius * radius;
  }
The & sign indicates that the second argument should NOT be copied to the function, it is a reference to the variable being passed. The return type has been changed to void because the function no longer supplies the area computed as a return value, but it supplies it as an output parameter by reference.

A function can return only one value using the return statement. If your function needs to perform operations that affect many values required at the caller, passing arguments by reference is one way to get a function to supply those modifications back to the calling module. 


A function call essentially means that the microprocessor jumps to executing the next instruction belonging to the called function at a nonsequential memory location. After it is done with executing the instructions in the function, it returns to where it left off. To implement this logic, the compiler converts your function call into a CALL instruction for the microprocessor and this instruction is accompanied by the address in memory the next instruction needs to be taken from. When the microprocessor encounters CALL, it saves the position of the instruction to be executed after the function call on the stack and jumps to the memory location contained in the CALL instruction. This memory location contains instructions belonging to the function which are executed by the microprocessor until it reaches the return(RET) statement. The RET statement results in the microprocessor popping that address from the stack stored during the CALL instruction. This address contains the location in the calling function where the execution needs to continue from. 

The stack is a Last-In-First-Out memory structure. ^^^^^^^^ PAGE 169 ^^^^^^^^^^ Putting data onto the stack is called a PUSH operation. Getting data out of the stack is called a POP operation. As the stack grows upwards, the stack pointer always increments as it grows and points to the top of the stack. The nature of the stack makes it optimal for handling function calls. When a function is called, all local variables are instantiated on the stack - pushed onto the stack. When the function ends, they pop off and the stack pointer returns to its original position. 


Inline Functions
A regular function call is translated into a CALL instruction, which results in stack operations and microprocessor execution shift to the function and so on. The overhead of performing an actual function call on a small function might be quite high so C++ compilers enable the programmer to declare such functions as inline. Keyword inline is the coder's request that these functions be expanded inline when called: 
  inline double GetPi()
  {
    return 3.14159;
  }

Using the inline keyword should be kept to a minimum and reserved only for those functions that do very little and need to do it with minimal overhead. Most modern compilers offer various performance optimization options. 


Automatic Return Type Deduction: Functions that rely on automatic return type deduction need to be defined before they're invoked. This is because the compiler needs to know a function's return type at the point where it is used. If this type of function has multiple return statements, they all must return the same data type. Recursive calls need to follow at least one return statement.
  #include <iostream>
  using namespace std; 

  const double Pi = 3.14159;
  auto Area(double radius)
  {
    return Pi * radius * radius;
  }

  int main()
  {
    cout << "Enter radius: ";
    double radius = 0;
    cin >> radius;

    cout << "Area is: " << Area(radius) << endl;

    return 0;
  }


Lambda Functions: Lambda functions were introduced in C++11 and help in the usage of STL algorithms to sort or process data. Typically a sort function requires you to supply a binary predicate ~ a function that compares two arguments and returns true if one is less than the other. Lambda functions can compact predicate definitions. The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements. A range is any sequence of objects that can be accessed through iterators or pointers, such as an array or an instance of some of the STL containers.
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;

  void DisplayNums(vector<int>& dynArray)
  {
    for_each (dynArray.begin(), dynArray.end(), [](int Element) {cout << Element << " ";});
    cout << endl;
  }

  int main()
  {
      vector<int> myNums;
      myNums.push_back(501);
      myNums.push_back(-1);
      myNums.push_back(25);
      myNums.push_back(-35);

      DisplayNums(myNums);
      cout << "Sorting them in descending order" << endl;

      sort (myNums.begin(), myNums.end(), [](int Num1, int Num2){return (Num2 < Num1);});

      DisplayNums(myNums);
      return 0;
  }




Lesson 7 Summary: 
A. What happens if I program a recursive function that doesn't end?
  Program execution doesn't end. This is not so bad per se, but a recursive function call takes more stack space which is finite and runs out as compared to infinite loops, and eventually the app crashes.

B. Why not inline every function? Doesn't it increase execution speed?
  It depends, but inlining every function results in functions that are used in multiple places to be placed at the point where they're called and this results in code bloat. Most modern compilers are better judges of what should/shouldn't be inlined. 

C. Can I supply default parameter values to all parameters in a function?
  Yes, it is possible and recommmended when logical to do so. 

D. I have two functions, both named Area. One takes a radius and the other takes height. I want one to return float and the other to return double. Can I do this?
  Function overloading needs both functions with the same name to also have the same return types. In this case, your compiler will throw an error. 


Lesson 7 Quiz/Exercises:
1. What is the scope of variables declared in a function's prototype?
    The duration of the function is the scope of the variables. 

2. What is the nature of the value passed to this function? 
    int Func(int &someNumber);
    someNumber is a reference to the variable in the calling function. It does not hold a copy. 

3. I have a function that invokes itself. What is such a function called?
    Recursive function

4. I have declared two functions, both with the same name and return type, but different parameter lists. What are these called?
    Overloaded function

5. Does the stack pointer point to the top, middle, or bottom of the stack?
    Top of the stack : Last In -- First Out

6. Write overloaded functions that calculate the volume of a sphere and a cylinder. Formulas provided below: 
    Volume of sphere = (4 * Pi * radius * radius * radius)/3
    Volume of cylinder = Pi * radius * radius * height 

    double volume(double radius, double pi = 3.14159)
    {
      return (4 * pi * (radius * radius * radius))/3;
    }

    double volume(double radius, double height, double pi = 3.14159)
    {
      return (pi * radius * radius * height);
    }


7. Write a function that accepts an array of double as input. 
    void arrayFunction(double numbers[], int length);


8. What is wrong with the following code: 
    #include <iostream>
    using namespace std; 
    
    const double Pi = 3.14159; 
    void Area(double radius, double result)
    {
      result = Pi * radius * radius;
    }

    int main()
    {
      cout << "Enter radius: "; 
      double radius = 0;
      cin >> radius; 

      double areaFetch = 0;
      Area(radius, areaFetch)

      cout << "The area is: " << areaFetch << endl;
      return 0; 
    }

    The parameter result should be a reference for the function Area() to be effective: 
    void Area(double radius, double &result)


9. What is wrong with the following function declaration? 
    double Area(double pi = 3.14159, double radius);

    The default parameter should be listed at the end or you will have a compilation error.


5. Write a function with return type void that still helps the caller calculate the area and circumference of a circle when supplied the radius. 
    void Calculate(double, radius, double &Area, double &Circumference)
    {
      Area = 3.14 * radius * radius;
      Circumference = 2 * 3.14 * radius;
    }