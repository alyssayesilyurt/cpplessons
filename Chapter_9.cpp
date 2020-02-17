Lesson 9 : Classes & Objects



A declaration of a class tells the compiler about the class and its properties. Methods are essentially functions that are members of a class. All attributes of a class and all functions declared within it are called members of the class. 
  class Cat 
  {
    //Member Attributes
    string name; 
    string breed; 
    string color; 
    string age; 

    //Member functions
    void Talk(string sayMeow);
    void ShowAffection;
    ...
  };

  Cat myCat;    //myCat is an object of class Cat

  Cat* duman = new Cat();   //dynamically allocated Cat 
  delete duman;       //de-allocate memory


A class is like a blueprint and simply declaring a class has no effect on the execution of a program. To use the features of a class, you create an instance of that class called an object which you use to access the member methods and attributes. 


Accessing Members Using the Dot Operator(.): 
To access attributes of a class instance, you use the dot operator: 
  myCat.name;     //duman

If you use pointers, you can use the pointer operator(->) to access members or you can use the indirection operator(*) to reference the object following the dot operator: 

Accessing Members Using the Pointer Operator(->)
  #include <iostream>
  #include <string> 
  using namespace std; 

  class Cat
  {
    public: 
      string name;
      int age; 
      string breed; 
      string color; 

      void SayMeow()
      {
        cout << "Meow meow meow meow" << endl;
      }

      void AboutMe()
      {
        cout << "I am " + name << " the " + color +  breed + " cat." << "I am " + age << " years old." << endl;
      }
  };

  int main()
  {
    //An object of class Cat with name Duman
    Cat myCat; 
    myCat.name = "Duman";
    myCat.age = 1;
    myCat.breed = "Tabby";
    myCat.color = "Grey";

    //An object of class Cat with name Luna
    Cat lunaCat; 
    lunaCat.name = "Luna";
    lunaCat.age = 4;
    lunaCat.breed = "Tabby";
    lunaCat.color = "mixed";


    myCat.sayMeow();
    myCat.AboutMe();
    lunaCat.sayMeow();
    lunaCat.AboutMe();
  }


Keywords public and private: 
Information can be classified into at least two categories: public and private. C++ allows you to mlodel class attributes and methods as public or private. Public class members can be used by anyone in possession of an object of the class. Private class members can be used only within the class. C++ keywords public and private help you as the designer of a class decide what parts of a class can be invoked from outside it. 


Abstraction of Data via Keyword private: 
  #include <iostream> 
  #include <string>
  using namespace std; 

  class Woman 
  {
    private: 
      //Private Member Data
      int age;

    public: 
      string name; 

      void SetAge(int inputAge)
      {
        age = inputAge
      }

      //Lies about age if over 30
      int GetAge()
      {
        if (age > 30)
          return (age - 3);
        else 
          return age;
      }
  };

  int main()
  {
    Woman.Aleida; 
    Aleida.name = "Aleida"; 
    Aleida.SetAge(32);

    Woman.Misleidys;
    Misleidys.name = "Misleidys"; 
    Misleidys.setAge(27);

    cout << "Mileidys is " << Misleidys.GetAge() << " years old." << endl; 
    cout << "Aleida is " << Aleida.GetAge() << " years old." << endl;

    return 0; 
  }

  
A constructor is a special function that takes the name of the class and returns no value. A constructor can be implemented either inline within the class or externally outside the class declaration. You an also implement it outside the class: 
  class Cat
  {
    public: 
      Cat();
      {
        //constructor code here 
      }
  };

    --> Outside a Class
  class Cat
  {
    public:
      Cat();
  };
  //constructor implementation
  Cat::Cat()
  {
    //constructor code here
  }


:: is called the scope resolution operator. 

A constructor is always invoked during object creation, when an instance of a class is constructed. A constructor is a perfect place for you to initialize class member variables such as integers, pointers, and so on to values you choose. 
  #include <iostream> 
  #include <string>
  using namespace std; 

  class Cat
  {
    private: 
      string name;
      int age; 
      string breed; 
      string color;

    public: 
      Cat()   //constructor
      {
        age = 1;  //initialization
        cout << "Constructed an instance of class Cat" << endl;
      }

      void SetName (string catsName)
      {
        names = catsName;
      }

      void SetAge (int catsAge)
      {
        age = catsAge;
      }

      void SetBreed (string catsBreed)
      {
        breed = catsBreed;
      }

      void SetColor (string catsColor)
      {
        color = catsColor;
      }

      void IntroduceSelf()
      {
        cout << "I am " + name + " and am ";
        cout << age << " years old" << endl;
      }
  };

  int main()
  {
    Cat.myCat;
    myCat.SetName("Duman");
    myCat.SetAge (1);
    myCat.SetBreed("Tabby");
    myCat.SetColor("Grey");

    myCat.IntroduceSelf();
  }