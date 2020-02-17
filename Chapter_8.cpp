Lesson 8 : Pointers & References Explained


A pointer is also a variable ~ one that stores an address in memory ~ a pointer is a special variable that points to a location in memory. Memory locations are typically addressed using hexadecimalnotation. A pointer needs to be declared. You normally declare a pointer to point to a specific value type(example: int ~ this means that the address contained in the pointer points to a location in the memory that holds an integer). You can also specific a pointer to a block of memory (a void pointer). As with most variables, unless you initialize a pointer, it will contain a random value. You can initialize a pointer to NULL since NULL Is a value that can be checked against and one that cannot be a memory address. 
  pointedType * PointerVariableName = NULL;
  int *pointsToINt = NULL;

A pointer contains a junk value unless it has been initialized. This junk value is particularly dangerous in the case of a pointer because the value of a pointer is expected to contain an address. Uninitialized pointers can result in your program accessing invalid memory locations, resulting in your application crashing. 


Variables are tools provided for you to work with data in memory. If varName is a variable, &varName gives the address in memory where its value is placed. The amount of memory cnsumed by a variable is dependent on its type. You can use the sizeof operator to see how much memory is being used by a variable. So once you know how much memory a variable is occupying,  you can say that myVar located at address 000x000 is using [sizeof(myVar) -> 4 bytes] 4 bytes. The referencing operator (&) is also called the address-of operator. 


You know that pointers are variables used to hold memory addresses, so now we can use pointers to store addresses: 
  #include <iostream>
  using namespace std;

  int main()
  {
    int age = 30;
    int* pointsToInt = &age;    //pointer initialized to age

    cout << "Integer age is at: 0x" << hex << pointsToInt << endl;
    //^^Display pointer value
    return 0;
  }
Be forewarned, the address of a variable might change at every run of the application on the exact computer. 

Access Pointed Data Using the Deference Operator(*): 
  #include <iostream>
  using namespace std; 

  int main()
  {
    int age = 30;
    int dogsAge = 9;

    cout << "Integer age = " << age << endl;
    cout << "Integer dogsAge = " << dogsAge << endl;

    int* pointsToInt = &age;
    cout << "pointsToInt points to age " << endl;

    //Displaying the value of pointer 
    cout << "pointsToInt = 0x" << hex << pointsToINt << endl;

    //Displaying the value at the pointed location
    cout << "*pointsToInt = " << dex << *pointsToInt << endl;

    pointsToInt = &dogsAge;
    cout << "pointsToInt points to dogsAge now" << endl;

    cout << "pointsToInt = 0x" << hex << pointsToInt << endl;
    cout << "*pointsToInt = " << dec << *pointsToInt << endl;

    return 0; 
  }
The deferencing operator(*) is also called the indirection operator. 


What is the sizeof() of a pointer?
The pointer is just another variable that contains a memory address. Regardless of the type it is pointing to, a pointer is an address in memory ~ a number. The length of an address(the number of bytes required to store it) is a constant for a given system. The sizeof() of a pointer is dependent on the compiler and the OS the program has been compiled for and is NOT dependent on the nature of the data being pointed to. 


Dynamic Memory Allocation
When you write a program containing an array declaration such as: int myNums[100]; (a static array of 100 integers), there are two problems: 
  1. You are limiting the capacity of your program since it cannot store more than 100 numbers. 
  2. You are reducing the performance of the system in cases where only one number needs to be stored because you've reserved space for 100]

These problems exist because the memory allocation in an array as declared above is static and fixed by the compiler. In order to write an application that is able to optimally consume memory resources on the basis of the needs of the user, you need to use dynamic memory allocation. This enables you to allocate more when you need more memory and release memory when uneeded. C++ supplies the operators new and delete to help you better manage the memory consumption of your application. Pointers being variables that are used to contain memory addresses play a critical role in efficient dynamic memory allocation.

You use new to allocate new memory blocks. The most frequently used form of new returns a pointer to the requested memory if successful or throws an exception. When using new, you need to specify the data type for which the memory is being allocated: 
  Type* Pointer = new Type;    //request memory for one element
You can also specify the number of elements you want to allocate that memory for ~ when you need to allocate memory for more than one element. 
  Type* Pointer = new Type[numElements;]    //request memory for numElements

If you need to allocate integers you use this syntax: 
  int* pointToAnInt = new int;    //get a pointer to an integer
  int* pointToNums = new int[10];   //pointer to a block of 10 integers

Note that new indicates a request for memory. There is no guarantee that a call for allocation always succeeds because this depends on the state of the system and the availability of memory resources. 

Every allocation using new needs to be eventually released using an equal and opposite de-allocation via delete: 
  Type* Pointer = new Type;     //allocate memory
  delete Pointer;     //release memory allocated above
This rule also applies when you request memory for multiple elements.
  Type* Pointer = new Type[numElements];    //allocate block
  delete[] Pointer;     //release block allocated above

If you don't release allocated memory after you stop using it, this memory remains reserved and allocated for your application which reduces the amount of system memory available for apps to consume and could cause the execution of your app to be slower. This is also called a leak and should be avoided at all costs. 

Accessing Memory Allocated Using new via Operator * and Releasing it using delete
  #include <iostream> 
  using namespace std; 

  int main()
  {
    //Request memory space for an int 
    int* pointsToAnAge = new int;

    //Use allocated memory to store a number
    cout << "Enter your cat's age: "; 
    cin >> *pointsToAnAge; 

    //User indirection operator* to access value 
    cout << "Age" << *pointsToAnAge << " is stored at 0x" << hex << pointsToAnAge << endl;
    
    delete pointsToAnAge;   //release memory
    return 0;
  }

Operator delete cannot be invoked on any address contained in a pointer, rather only those that have been returned by new and only those that have not already been released by a delete. 


Allocate Using new[...] and Release Using delete[]
  #include <iostream> 
  #include <string> 
  using namespace std; 

  int main()
  {
    cout << "How many integers shall I reserve memory for?" << endl;
    int numEntries = 0; 
    cin >> numEntries; 

    int* myNumbers = new int[numEntries];
    cout << "Memory allocated at: 0x" << myNumbers << hex << endl;

    delete[] myNumbers; 
    return 0;
  }

Operators new and delete allocate memory from the free store. The free store is a memory abstraction in the form of a pol of memory where your application can allocate(reserve) memory from and de-allocate(release) memory to. 


A pointer contains a memory address. An increment or decrement operation on a pointer is interpreted by the compiler as your need to point to the next value in the block of memory, assuming it to be of the same type, and NOT to the next byte. So incrementing a pointer that points to an integer. For example, incrementing a pointer that points to an integer results in it being incremented by 4 bytes, by using ++ you are telling the compiler that you want it to point to the next consecutive integer. Decrementing pointers using -- demonstrates the same effect ~ the address value contained in the pointer is reduced by the sizeof the data type it is being pointed to. 


Using the const Keyword on Pointers: Declaring a variable as const effectively ensures that the value of the variable is fixed for the life of the variable. The value of a const-variable cannot be changed. Pointers are variable too, so const is relevant to them as well. 
    1. The address contained in the pointer is constant and cannot be changed, but the data at that address can be changed
        int daysInMonth = 30;
        int* const pDaysInMonth = &daysInMonth;
        *pDaysInMonth = 31;     //data pointed to can be changed!!
        int daysInLunarMonth = 28; 
        pDaysInMonth = &daysInLunarMonth;       //cannot be changed! Not OKAY!

    2. Data pointed to is constant and cannot be changed, yet the address contained in the pointer can be changed ~ that is, the pointer can point elsewhere. 
        int hoursInDay = 24; 
        const int* pointsToInt = &hoursInDay;
        int monthsInYear = 12; 
        pointsToInt = &monthsInYear;    //Okay! 
        *pointsToInt = 13;  //NOT OKAY! You can't change data being pointed to 
        int* newPointer = pointsToInt;    //NOT OKAY! You can't assign a const to a non const 

      3. Both the address contained in the pointer and the value being pointed to are constant and cannot be changed(most restrictive variant)
        int hoursInDay = 24; 
        const int* const pHoursInDay = &hoursInDay; 
        *pHoursInDay = 25;    //Not OK! Cannot change data being pointed to
        int daysInMonth = 30; 
        pHoursInDay = &daysInMonth;     //Not OK! Cannot change address


Passing Pointers to Functions: Pointers are an effective way to pass memory space that contains relevant data for functions to work on. The memory space shared can also return the result of an operation. When using a pointer with functions, it becomes important to ensure that the called function is only allowed to modify parameters that you want to let it modify. 
  #include <iostream> 
  using namespace std; 

  void CalcArea(const double* const ptrPi,      //const pointer to const data
                const double* const ptrRadius,  //i.e. no changes allowed
                double* const ptrArea)         //can change dara pointed to 
  {
    //check pointer validity before using!
    if (ptrPi && ptrRadius && ptrArea)
      *ptrArea = (*ptrPi) * (*ptrRadius) * (*ptrRadius);
  }
  
  int main()
  {
    const double Pi = 3.1416; 
    cout << "Enter radius of a circle: "; 
    double radius = 0;
    cin >> radius;

    double area = 0;
    CalcArea(&Pi, &radius, &area); 
    cout << "Area is = " << area << endl;
    return 0;
  }


Similarities B/W Arrays and Pointers: 
  #include <iostream> 
  using namespace std; 

  int main()
  {
    //Static array of 5 integers
    int myNumbers[5];

    //Array assigned to pointer to int 
    int* pointToNums = myNumbers; 

    //Display address contained in pointer 
    cout << "pointToNums = 0x" << hex << pointToNums << endl;

    //Address of first element of array 
    cout << "&myNumbers[0] = 0x" << hex << &myNumbers[0] << endl;

    return 0;
  }
The code above demonstrates that an array variable can be assigned to a pointer of the same type, confirmming that an array is akin to a pointer. Because array variables are essentially pointers, it should be possible to use the de-preference operator(*) that you have used with pointers to work with arrays. Similarly, it should be possible to use the array operator( [] ) to work with pointers as shown below: 
  #include <iostream> 
  using namespace std;

  int main()
  {
    const int ARRAY_LEN = 5;

    //Static array of 5 integers, initialized
    int myNumbers[ARRAY_LEN] = {24, -1, 365, -999, 2011};

    //Pointer initialized to the first element of an array
    int* pointToNums = myNumbers; 

    cout << "Display array using pointer syntax, operator* " << endl;
    for (int index = 0; index < ARRAY_LEN; ++index)
      cout << "Element" << index << " = " << *(myNumbers + index) << endl;

    cout << "Display array using ptr with array syntax, operator[] " << endl; 
    for (int index = 0; index < ARRAY_LEN; ++index)
      cout << "Element " << index << " = " << pointToNums[index] << endl;

    return 0; 
  }
It is important to remember that pointers that are allocated dynamically using operator new still need to be released using operator delete, even if you accessed data using syntax commonly used with static arrays. If you forget to release them, your app leaks memory. 


Common Programming Mistakes Using Pointers: 
  A. Memory Leaks
      The longer an app runs, the larger the memory consumption and the slower the system works. This happens when the coder forgets tgo release dynamically allocated memory and it is a HUGE problem. 
    
  B. Pointers Don't Point to Valid Memory Locations
      When you deference a pointer using (*) to access the pointed value, you need to be sure that the pointer contains a valid memory location, or your app will likely crash. Invalid pointers are a common reason for app crashes. 

  C. Dangling Pointers 
      Any valid pointer is invalid after it has been released using delete. Once you use delete on a pointer, you CANNOT use it again after that point. To avoid this, some coders assign NULL to a pointer after initialization or after deleting it. They always check a pointer for validity by comparing it against NULL before dereferencing it using operator (*). 

  D. Check If Allocation Request Succeeded
      Up to this point, we assume that new will return a valid pointer to a block of memory. new usually succeeds unless the application asks for an unusually large amount of memory or if the system is in such a critical state that it has no memory to spare. It is not a good practice to simply assume that memory allocation requests will always succeed. The default method which we have been using so far uses exceptions where unsuccessful allocations result in an exception of type std::bad_alloc to be thrown. An exception results in the execution of your application being disrupted and unless you have an exception handler configured, your app ends with an error message of "unhandled exception". 




Do's and Don'ts 
  - Do always initialize pointer variables, or they will contain junk values. These junk values are interpreted as address locations ~ ones your application is not authorized to access. If you cannot initialize a pointer to a valid address returned by new during variable declaration, initialize it to NULL. 
  - Do ensure that your application is programmed in a way that pointers are used when their validity is assured, or your program might crash. 
  - Do remember to release memory allocated using new by using delete or your application will leak memory and reduce system performance. 

  - Don't access a block of memory or use a pointer after it has been released using delete. 
  - Don't invoke delete on a memory address more than once. 
  - Don't leak memory by forgetting to invoke delete when done using an allocated block of memory. 


What is a Reference?
A reference is an alias for a variable. When you declare a reference, you need to initialize it to a variable. The reference variable is just a different way to access the data stored in the variable being referenced. You would declare a reference using the reference operator(&) like below: 
  varType original = value; 
  varType& ReferenceVariable = original;

References are useful because they enable you to work with the memory location they are initialized to. 
  #include <iostream> 
  using namespace std; 
  
  void GetSquare(int& number)
  {
    number *= number;
  }

  int main()
  {
    cout << "Enter a number you wish to square: ";
    int number = 0; 
    cin >> number; 

    GetSquare(number);
    cout << "Square is: " << number << endl;
    return 0; 
  }


Using Keyword const on References: 
  int original = 30; 
  const int& constRef = original; 
  constRef = 40;      //Not allowed: constRef can't change the value of the original
  int& ref2 = constRef;   //Not allowed: ref2 is not const 
  const int& constRef2 = constRef;  //Okay 


One of the major advantages of references is that they allow a called function to work on parameters that have not been copied from the calling function, resulting in significant performance improvements. However, since the called function works using parameters directly on the stack of the calling function, it is important to ensure that the called function cannot change the value of the variable at the caller's end. References defined as const solve this. A const reference parameter cannot be reassigned. 





Lesson 8 Summary
  A. Why dynamically allocate when you can do with static arrays where you don't need to worry about deallocation? 
    Static arrays have a fixed size and will neither scale upward if your application needs more memory nor will they optimize if your application needs less. 

  B. I have two pointers below, am I not better off calling delete using both to ensure that the memory is gone? 
    int* pointToAnInt = new int; 
    int* pCopy = pointToAnInt; 

    That would be wrong b/c you are allowed to invoke delete only once on the address returned by new. Ideally, you would avoid having two pointers pointing to the same address because performing delete on any one would invalidate the other. Your program should not be written in a way that you have any uncertainty about the validity of pointers used. 

  C. When should I use new(nothrow)?
    If you don't want to handle the exception std::bad_alloc, you use the nothrow version of operator new that returns NULL if the requested allocation fails. 

  D. I can call a function to calculate area using one of the two methods below, which is preferable?
    void CalculateArea (const double* ptrRadius, double* const ptrArea);
    void CalculateArea (const double& radius, double& area);

    Use the second one using references because the references cannot be invalid, but pointers can be.       

  E. I have a pointer and I understand that I cannot change the value of number using the pointer pointToAnInt due to the const declaration. Can I assign pointToAnInt to a non-const pointer and then use it to manipulat ethe value contained in the integer number? 
      int number = 30; 
      const int* pointToAnInt = &number;

      No, you cannot change the const-correctness of the pointer. 

  F. Why should I bother passing values to a function by reference? 
      YOu don't need to as long as it will not significantly affect you app's performance. If your function parameters accept objects that are quite heavy then passing by value would not be logical. Your function call would be a lot more efficient in using references. Use const generously except where the function needs to store a result in a variable. 



Lesson 8 Quiz/Exercises:
  1. Why can't you assign a const reference to a non-const reference?
      The whole point of using const is to protect the data being referred to from being changed. 

  2. Are new and delete functions?
      Both are operators. 

  3. What is the nature of value contained in a pointer variable?
      A memory address

  4. What operator would you use to acess the data pointed by a pointer?
      operator * 

  5. What is the display when these statements are executed: 
      0: int number = 3; 
      1: int* pNum1 = &number; 
      2: _*pNum1 = 20;
      3: int* pNum2 = pNum1; 
      4: number *= 2;
      5: cout << *pNum2; 

      Display: 40

  6. What are the similarities/differences between these three overloaded function? 
      int DoSomething(int num1, int num2); 
      int DoSomething(int& num1, int& num2);
      int DoSOmething(int* pNum1, int* pNum2); 

      1: the arguments are copied to the called function
      2: the arguments are not copied to the called function, they are references to the variables in the caller and the function can change them
      3: the arguments are pointers which can be NULL or invalid unlike references and validity must be checked


  7. How would you change the declaration of pNum1 in Question #5 Line 1 so as to make the assignment at Line 3 invalid? (It has something to do with ensuring that pNum1 cannot change the data pointed to.)
      const int* pNum1 = &number;


  8. What is wrong with this code? 
      #include <iostream> 
      using namespace std;

      int main()
      {
        int *pointToAnInt = new int; 
        pointToAnInt = 9; 
        cout << "The value at pointToAnInt: " << *pointToAnInt; 
        delete pointToAnInt; 
        return 0; 
      }

      You are assigning an integer to a pointer directly which overwrites the contained memory address by an integer value: 
        *pointToAnInt = 9;    //previously: pointToAnInt = 9;


    9. What is wrong with this code? When corrected, what is the output?
        #include <iostream> 
        using namespace std; 

        int main()
        {
          int pointToAnINt = new int; 
          int* pNumberCopy = pointToAnInt; 
          *pNumberCopy = 30; 
          cout << *pointToAnInt; 
          delete pNumberCopy; 
          delete pointToAnInt; 
          return 0; 
        }

        There is a double delete on the same memory address returned by new to pNumber and duplicated in pNumberCopy. Remove one. 

        Output: 30 