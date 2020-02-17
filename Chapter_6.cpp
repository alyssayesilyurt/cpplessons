Lesson 6 - Controlling Program Flow


if...else
An expression that evaluates to any non-zero number is considered to evaluate to true when it is used in a conditional statement. 
  if (condition)
    //Do Something
  else if (otherCondition)
    //Do Something Else
  else
    //Do Something Different!


If you want to execute multiple statements in the event of a successful or failed condition, you need to enclose them within statement blocks {...}. Such blocks are also called compound statements. 
  if (condition)
  {
    //Condition Success Block
    Statement1;
    Statement2;
  }
  else
  {
    //Condition Failure Block
    Statement3; 
    Statement4;
  }
  

Nested if Statements:
  if (expression1)
  {
    //Do Something;
    if (expression2)
      //Do Something Inside Here;
    else
      //Do Something Else Inside Here;
  }
  else
    //Do Something Else Out Here


Switch Case Statements: Switch case constructs are well-wsuited to being used with enumerators. 
  switch(expression)
  {
    case A:
      Do Something;
      break;
    case B: 
      Do Something Else;
      break;
    ....
    default: 
      Default When Case Doesn't Match Anything Above;
      break;
  }


Ternary Operator C++ Equivalent: 
(condition)? expressionTrue : expressionFalse;

(num1 > num2)? num1 : num2;


Do's and Don'ts :
  - Do use enumerators in switch expressions to make code readable.
  - Do remember to handle default unless deemed totally unnecessary. 
  - Do check if you forgot to insert break in each case statement.
  
  - Don't add two cases with the same label: it won't make sense and it won't compile. 
  - Don't complicate your case statements by including cases without break and relying on sequence. This will break functionality in the future when you move the case statements without paying attention to sequence.
  - Don't use complicated conditions or expressions when using conditional operators (?:).


A goto Loop instructs execution to continue from a particular, labeled, point in code. You can use it to go back and re-execute certain statements. You declare a label called Start and use goto to repeat execution from this point. Unless you invoke goto given a condition that can evaluate to false under certain circumstances or unless the code that repeats contains a return statement, this piece of code between the lael and command will repeat endlessly and keep the program in a loop.
  SomeFunction() 
  {
    Start:        //called a label
      CodeThatRepeatsHere;

      goto Start;
  }

  int main()
  {
    Start:
      int num1 = 0, num2 = 0;

      cout << "Enter 2 integers: " << endl;
      cin >> num1;
      cin >> num2;

      cout << num1 " + " num2 << " = " << num1 + num2 << endl;
      cout << "Do you wish to perform another operation? (y/n)" << endl;

      if (repeat == 'y')
        gotoStart;
      else 
        cout << "GoodBye!";
  }
goto is NOT the recommended form of loops because the frequent use of goto can result in unpredictable flow of code where execution can jump from one line to another in no particular order or sequence and in some cases it can also leave variables in unpredictable states. 


The while Loop
The statement block of a while loop is executed repeatedly as long as the expression evaluates to true. If your code never evaluates to false,you will be stuck in an endless loop. A loop is also called an iteration. Statements involving while, do...while, and for are also called iterative statements. 
  while(expression)
  {
    //Expression evaluates to true
    StatementBlock;
  }


The do...while Loop
There are cases that you need to ensure a certain segment of code repeats itself in a loop and executes at least once. This is where the while loop comes in. 
  do 
  {
    StatementBlock;       //executed at least once
  } while(condition);     //ends loop if condition evaluates to false


The for Loop
The for loop enables coders to define a counter variable with an initial value, check the value against an exit condition at the beginning of every loop, and change the value of the variable at the end of the loop. A variable such as counter that helps to access elements in a collection such as an array is also called an iterator. The scope of an iterator declared within the for construct is limited to the for loop. 
  for (initial expression executed only once;
       exit condition executed at the beginning of every loop;
       loop expression executed at the end of every loop )
  {
    DoSomething;
  }

  for (int counter = 0; counter < num2; ++counter)
  {
    cout << counter << endl;
  }

You can initialize multiple variables in a for loop within the first initialization expression that is executed once. 


The range-based for Loop
C++11 introduced a new variant of the for loop that makes operating over a range of values, such as those contained in an array, simpler to code and read. 
  for (varType varName : sequence)
  {
    //Use varName that contains an element from sequence
  }

You can simplify the for statements below by using automatic variable type deduction which will make this a generic for loop that will work for an array of elements of any type.  
  int someNums[] = {1, 101, -1, 40, 2040};
  for (int aNum : someNums)
  {
    cout << "The array elements are: " << aNum << endl;
  }


There are a few cases especially in loops handling many parameters with many conditions, where you are not able to program the loop condition effectively and need to modify program behavior even within the loop. This is where continue and break come in. continue lets you resume execution from the top of the loop. The code following it within the block is skipped. The effect of continue in a while, do...while, or for loop is that it results in the loop condition being re-evaluated and the loop block being re-entered in the condition evaluates to true. In case of a continue within a for loop, the loop expression is evaluated before the condition is re-evaluated. break exits the loop's block, ending the loop when invoked. 


Infinite loops are loops that always evaluate to true so they never end. While it is not recommended to include them in your code, they are useful for situations where you continuously need to check if something is true. For example, in an operating system you need to continually check whether you have connected a device such as a USB stick; this activity should not stop as long as the OS is running. 
Example: Using continue to Restart and break to Exit an Infinite for Loop
  #include <iostream>
  using namespace std;

  int main()
  {
    for (;;)   //infinite loop
    {
      cout << "Enter two integers: " << endl;
      int num1 = 0, num2 = 0;
      cin >> num1;
      cin >> num2;

      cout << "Do you wish to correct the numbers? (y/n): ";
      char changeNumbers = '\0';
      cin >> changeNumbers;

      if (changeNumbers == 'y')
        continue;     //restart the loop

      cout << num1 >> " x " << num1 << " = " << num1 * num2 << endl;

      cout << "Press x to exit or any other key to recalculate" << endl;
      char userSelection = '\0';
      cin >> userSelection;

      if (userSelection == 'x')
        break;    //end for loop
    }

    cout << "Goodbye!";
    return 0;

  }
Above, an empty for(;;) statement is used to create an infinite loop. This can be replaced with while(true) or a do...while(true) to generate the same output using a different loop type. 


Do's and Don'ts 
  - Do use do...while when the logic in the loop needs to be executed at least once. 
  - Do use while, do...while, or for loops with well-defined condition expressions.
  - Do indent code in a statement block contained in a loop to improve readability.

  - Don't use goto. 
  - Don't use continue and break indiscriminantly. 
  - Don't program infinite loops terminated using break unless absolutely necessary. 


Nested Loops
  #include <iostream>
  using namespace std;

  int main()
  {
    const int ARRAY1_LEN = 3;
    const int ARRAY2_LEN = 2;

    int myNums1[ARRAY1_LEN] = {35, -3, 0};
    int myNums2[ARRAY2_LEN] = {20, -1};

    cout << "Multiplying each int in myNums1 by each in myNums2: " << endl;

    for (int index1 = 0; index1 < ARRAY1_LEN; ++index1)
      for (int index2 = 0; index2 < ARRAY2_LEN; ++index2)
        cout << myNums1[index1] << " x " << myNums2[index2] \
        << " = " << myNums1[index1] * myNums2[index2] << endl;
  }


Using Nested Loops to Walk a Multidimensional Array 
  #include <iostream>
  using namespaced std;

  int main()
  {
    const int NUM_ROWS = 3;
    const int NUM_COLUMNS = 4;

    //2D ARRAY OF INTEGERS
    int MyInts[NUM_ROWS][NUM_COLUMNS] = { {34, -1, 879, 22},
                                          {24, 365, -101, -1},
                                          {-20, 40, 90, 97} };

    //iterate rows : each array of integers 
    for (int row = 0; row < NUM_ROWS; ++rows)
    {
      //iterate integers in each row(column)
      for (int column = 0; column < NUM_COLUMNS; ++columns)
      {
        cout << "Integer[" << row << "][" << column << " ] = " << MyInts[row][column] << endl;
      }
    } 
    return 0;
  }

  
Using Nested Loops to Calculate Fibonacci Numbers
The Fibonacci series is a set of numbers starting with zero and one where every following number in the series is the sum of the previous two. Example: 0, 1, 1, 2, 3, 5, 8, 13, 21, etc...

  #include <iostream>
  using namespace std;

  int main()
  {
    const int numsToCalculate = 5;
    cout << "This program will calculate " << numsToCalculate << "Fibonacci Numbers at a time." << endl

    int num1 = 0, num2 = 1; 
    char wantMore = '\0';
    cout << num1 << " " << num2 << " ";

    do 
    {
      for (int counter = 0; counter < numsToCalculate; ++counter)
      {
        cout << num1 + num2 << " "; 
        int num2Temp = num2;
        num2 = num1 + num2; 
        num1 = numTemp;
      }

      cout << endl << "Do you want more numbers? (y/n)"; 
      cin >> wantMore; 
    } while (wantMore == 'y');

    cout << "Goodbye!" << endl;

    return 0;
  }





Lesson 6 Summary
A. What happens if I omit a break in a switch-case statement? 
  The break statement enables program execution to exit the switch construct. Without it, execution continues evaluating the following case statements. 
 

B. How do I exit an infinite loop?
  Use break to exit any loop containing it. Using return exits the function module, too.


C. My while loop lookins like while(Integer). Does the while loop execute when Integer evaluates to -1?
  Ideally a while expression should evaluate to a Boolean value true or false: false is zero. A condition that does not evaluate to zero is considered to evaluate to true. Because -1 is not zero, the while condition evaluates to true and the loop is executed. If you want the loop to be executed only for positive numbers, write an expression while(Integer > 0). This rule is true for all conditional statements and loops. 


D. Is there an empty while loop equivalent of for(;;)?
  No, while always needs an accompanying conditional expression. 


E. I changed a do...while(exp) ; to a while(exp) ; by copying and pasting. Should I anticipate any problems? 
  Yes, big ones! while(exp) ; is already a valid yet empty while loop due to the null statement (the semicolon) following the while, even if it is followed by a statement block. The statement block in question is executed once, but outside of the loop.



Lesson 6 Quiz
1. Why bother to indent code within statement blocks, nested ifs, and nested loops when it compiles even without indentation?
    If you fail to indent your code and use whitespace where appropriate, your code will look messy and be hard to read. When you or another coder goes to read it a few months or days later, it will give you a major headache.


2. You can implement a quick fix using goto. Why would you still avoid it?
    goto can make your code unstable or incredibly difficult to maintain. It will cause random jumps to random places and if you do not keep everything in exactly the same sequence as it was originally, you will have a mess to handle. 


3. Is it possible to write a for loop where the counter decrements? How would it look?
    Yes of course! 
    for (int i = 10; i >= 0 ; --i )
    {
      cout << i << endl;

      if (i == 0)
        cout << "Blastoff!" << endl;
    }


4. What is the problem with the following loop?
    for (int counter = 0; counter == 10; ++counter)
      cout << counter << " ";

    The condition in the for statement (counter == 10) is not satisfied so the loop will not even execute once and the cout statement in the body will not be used. 


5. Write a for loop to access elements in an array in the reverse order.
    #include <iostream> 
    using namespace std; 

    int main()
    {
      const int ARRAY_LEN = 5;
      int myNums[ARRAY_LEN] = { -55, 45, 9889, 0, 45};

      for (int index = ARRAY_LEN - 1; index >= 0; --index)
        cout << "myNums[" << index << "] = " << myNums[index] << endl;

      return 0;
    }

6. Write a nested loop equivalent of Figure 6.14 that adds elements in two arrays, but in reverse order. 
    #include <iostream> 
    using namespace std; 

    int main()
    {
      const int ARRAY1_LEN = 3; 
      const int ARRAY2_LEN = 2; 

      int myNums1[ARRAY1_LEN] = {35, -3, 0}; 
      int myInts2[ARRAY2_LEN] = {20, -1};

      cout << "Adding each int in myNums1 with each in myInts2: " << endl;

      for (int index1 = ARRAY1_LEN - 1; index1 >= 0; --index1)
        for (int index2 = ARRAY2_LEN - 1; index2 >= 0; --index2)
          cout << myNums1[index1] << " + " << myInts[index2] << " = " << myNums1[index1] + myInts2[index2] << endl;

      return 0;
    }


7. Write a program that displays Fibonacci numbers similar to Figure 6.16, but asks the user how many numbers they want to compute. 
    #include <iostream>
    using namespace std; 

    int main()
    {
      cout << "How many Fibonacci numbers do you wish to calculate? "
      int numsToCalculate = 0;
      cin >> numsToCalculate;
      cout << "This program will calculate " << numsToCalculate << "Fibonacci Numbers at a time." << endl

      int num1 = 0, num2 = 1; 
      char wantMore = '\0';
      cout << num1 << " " << num2 << " ";

      do 
      {
        for (int counter = 0; counter < numsToCalculate; ++counter)
        {
          cout << num1 + num2 << " "; 
          int num2Temp = num2;
          num2 = num1 + num2; 
          num1 = numTemp;
        }

        cout << endl << "Do you want more numbers? (y/n)"; 
        cin >> wantMore; 
      } while (wantMore == 'y');

      cout << "Goodbye!" << endl;

      return 0;
    }


8. Write a switch-case construct that tells if a color is in the rainbow or otherwise. Use enumerated constants.
    #include <iostream>
    using namespace std; 

    int main()
    {
      enum RainbowColors 
      {
        Red = 0, 
        Orange, 
        Yellow, 
        Green, 
        Blue, 
        Indigo, 
        Violet,
        Pink, 
        Brown, 
        Black,
        White, 
        Ivory, 
        Rose, 
        Lavender
      }

      cout << "Here are the colors available: " << endl; 
      cout << "Lavender" << Violet << endl;
      cout << "Red" << Red << endl;
      cout << "Rose" << Rose << endl;
      cout << "Orange" << Orange << endl; 
      cout << "Ivory" << Ivory << endl; 
      cout << "Yellow" << Yellow << endl;
      cout << "White" << White << endl; 
      cout << "Green" << Green << endl;
      cout << "Black" << Black << endl;
      cout << "Blue" << Blue << endl; 
      cout << "Brown" << Brown << endl;
      cout << "Indigo" << Indigo << endl;
      cout << "Pink" << Pink << endl; 
      cout << "Violet" << Violet << endl;

      cout << "Choose one by entering code: "
      int yourChoice = 0; 
      cin >> yourChoice; 


      switch (yourChoice)
      {
        case Red: 
        case Orange: 
        case Yellow: 
        case Green: 
        case Blue: 
        case Indigo: 
        case Violet: 
          cout << "Your choice is in the rainbow!" << endl;
          break; 

        default: 
          cout << "The color you choice is not in the rainbow!" << endl;
          break;
      }
      return 0;
    }


9. What is wrong with this code?
    for (int counter=10; counter=10; ++counter)
      cout << counter << " ";

    The coder assigned the initial counter variable to 10 so the loop will run once. 
    
10. What is wrong with this code?
    int loopCounter = 0; 
    while (loopCounter < 5);
    {
      cout << loopCounter << " "; 
      loopCounter++;
    }

    The while statement should not be followed by a ; (null statement) on the same line. The intended loop following the while is never reached and loopCounter is never incremented, so the while loop is an infinite loop that never executes the statements because of ';'.

11. What is wrong with this code?
    cout << "Enter a number between 0 and 4" << endl;
    int input = 0;
    cin >> input; 
    switch (input)
    {
      case 0: 
      case 1: 
      case 2: 
      case 3: 
      case 4: 
      cout << "Valid input" << endl;
      default: 
        cout << "Invalid input" << endl;
    }

    There is no break statement so the default case always executes!
  