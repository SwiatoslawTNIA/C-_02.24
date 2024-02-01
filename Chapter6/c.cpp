#include <iostream>
#include <climits>
#include <fstream>
#include <cstring>
#include "c.h"
#define strsize 40
void f_1(void);
const int MAX  = 5;
void fish(void);
void f_3(void);
void files(void);
void file_input(void);
void ex_1(void);
void ex_2(void);
void ex_3(void);
void ex_4(void);
void ex_5(void);
void ex_6(void);
void ex_7(void);
void ex_8(void);
void ex_9(void);
using namespace std;
int main(void)
{
  ex_9();
  return 0;
}
void ex_9(void)
{
  ifstream file;
  char line[81];//80 + NULL
  file.open("text.txt");
  int contributors;
  file >> contributors;
  if(!file.good())
  {
    cout << "Sorry, something went wrong...";
    exit(EXIT_FAILURE);
  }
  //create structs
  typedef struct 
  {
    char name[40];
    double contribution;
  } Contributor;

  Contributor *array = new Contributor[contributors];
  if(array == NULL)
  {
    fprintf(stderr, "Unable to allocate the memory on the heap");
    exit(EXIT_FAILURE);
  }
  //move to the next line:
  char c;
  while((c = file.get()) != '\n')
    ;
  for(int i = 0; i < contributors;++i)
  {
    file.getline(line, 81);
    strcpy(array[i].name,line);
    cout << "\nContributor: " << array[i].name << " , contribution: ";
    file >> array[i].contribution;
    cout << array[i].contribution;//print the output;
    file.get();//get the remaining enter;
  }
  //display it:
  delete [] array;
  //read by char:
}
void ex_8(void)
{
  ifstream file;
  file.open("text.txt");
  char c;
  int quantity = 0;
  while(file.good())//every char is included
  {
    file >> c;
    quantity++;
  }
  //if the file canno't be opened, then .good() gives false, so the loop will never execute, this 
  //case is covered, determine the reason of the termination of reading of the input:
  if(file.eof())
    cout << "Terminated because EOF";
  else if(file.fail())
    cout << "Terminated because of mismatched chars";
  else 
    cout << "Terminated for some unknown reason";
  cout << "The amount of chars in a file, that was read is: " << quantity;
  file.close();//Don't forget to close the file
}
void ex_7(void)
{
  char word[21];//a word max 20 chars long;
  int words_with_vowels = 0;
  while(cin >> word)
  {
    if( word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' ||word[0] == 'u')
      words_with_vowels++;
    if(strlen(word) == 1 && word[0] == 'q')
      break;
    //get the whitespace:
    cin.get();
  }
  printf("The amount of words with vowels: %d", words_with_vowels);
}
void ex_6(void)
{
  typedef struct 
  {
    char name[40];
    double contribution;
  } Contributor;
  int contributors;
  cout << "Enter the amount of contributors: ";
  while(!(cin >> contributors))//returns true if the input was correct
  {
    //clear the rest
    cin.clear();
    char c;
    while((c = cin.get()) != '\n')
      ;//display the message:
    cout << "\nPlease enter a valid number";
  }
  cin.get();//get the enter;
  cout << "\n";
  Contributor *array = new Contributor[contributors];
  int counter = 0;
  while(counter < contributors)
  {
    
    cout << "Enter the name of the contributor " << counter + 1 << ": ";
    cin.getline(array[counter].name, 40);//get the \n
    cout << "Enter the amount: ";
    cin >> array[counter].contribution;
    cin.get();//get the \name
    counter++;
  }
  //display information:
  cout << "\nGrand Patrons of our era";
  int i = 0;
  for(; i < contributors;++i)
  {
    if(array[i].contribution >= 10000)
    {
      cout << "\nContributor: " << array[i].name << " , amount: " << array[i].contribution;
    }
  }
  if(i == 0)
    cout << "\nNone";
  cout << "\nPatrons";
  i = 0;
  for(; i < contributors;++i)
  {
    if(array[i].contribution < 10000)
    {
      cout << "\nContributor: " << array[i].name << " , amount: " << array[i].contribution;
    }
  }
  if(i == 0)
    cout << "\nNone";
  delete [] array;//free the allocated memory
}
void ex_5(void)
{
  //check if the income is bigger than 5000, if yes => move further:
  //the tax is discarded from the difference of the lower and upper bounds
  double income = 0.0, tax = 0.0, difference = 0.0;
  cout << "Enter your income: ";
  cin >> income; 
  if(income > 5000)
  {
    difference = income - 10000;
    if(difference > 0)
    {
      tax += 1000;
    }
    difference = income - 20000;
    if(difference > 0)
    {
      tax += 3000;
    }
    difference = income - 35000;
    if(income > 0)
    {
      tax += difference * 0.2;
    }
    cout << "The income tax is " << tax;
  }
  else
  {
    cout << "The income tax is 0";
  }
}

void ex_4(void)
{
  struct bop {
  char fullname[strsize]; // real name
  char title[strsize];
  // job title
  char bopname[strsize]; // secret BOP name
  int preference;
  // 0 = fullname, 1 = title, 2 = bopname
  };
  //print the first part:
  char letter;
  bop people[10];//initialize and it works!!!
  cout << "Benevolent Order of Programmers Report";
  cout << "a. display by name\tb. display by title\nc. display by bopname\td. display by preference\nq. quit";
  bool done = false;
  while(!done)
  {
    cout << "\nEnter your choice:";
    cin >> letter;
    switch (letter)
    {
      case('a'):
      {
        for(int i = 0; i < 10;++i)
        {
          cout << people[i].fullname << "\n";
        }
        break;
      };
      case('b'):
      {
        for(int i = 0; i < 10;++i)
        {
          cout << people[i].title << "\n";
        }
        break;
      };
      case('c'):
      {
        for(int i = 0; i < 10;++i)
        {
          cout << people[i].bopname << "\n";
        }
        break;
      };
      case('d'):
      {
        for(int i = 0; i < 10;++i)
        {
          if(people[i].preference == 0)
          {
            cout << people[i].fullname << "\n";
          }
          else if(people[i].preference == 1)
          {
            cout << people[i].title << "\n";
          }
          else if(people[i].preference == 2)
          {
            cout << people[i].bopname << "\n";
          }
        }
        break;
      };
      case('q'):
      {
        cout << "Bye";
        done = true;
        break;
      }
      default:
      {
        cout << "Please enter the correct choice!!!\n";
        break;
      }
    }
  }
} 
void ex_3(void)
{
  //what is the condition for the do-while loop?
  bool done = true;
  char c;
  do{
    if(done == false)
    {
      cout << "Please enter a c, p, t, or g: ";
    }
    else
    {
      cout << "Please enter one of the following choices:\n";
      cout << "c) carnivore\tp) pianist\n";
      cout << "t) tree\t g) game\n";
    }
    done = true;
    cin >> c;
    switch(c)
    {
      case('t'): cout << "A maple is a tree";
                 break;
      case('p'): cout << "A pianist loves music";
                 break;
      case('c'): cout << "Carnivors hate loud music";
                 break;
      case('g'): cout << "I'm not playing games";
                 break;
      default: done = false;
    }
  }while(!done);
}
void ex_2(void)
{
  double arr[10], var = 0.0, total = 0.0, average = 0.0;//array to store input
  int index = 0, bigger_than_av, counter = 0;
  while(cin >> var && counter < 10)//returns false if some kind of input mismatch
  {
    if(var == 0)
      break;//if the var is zero, break
    arr[index++] = var;
    counter++;
  }
  //reporting:
  //total:
  for(int i = 0; i < index;++i)
  {
    total += arr[i];
  }
  average = total / index;
  for(int i = 0; i < index;++i)
  {
    if(arr[i] > average)
      ++bigger_than_av;
  }
  cout << "\nThe average is: " <<  average <<  ", " << bigger_than_av << " numbers are larger than the average";
}
void ex_1(void)
{
//   Write a program that reads keyboard input to the @ symbol and that echoes the
// input except for digits, converting each uppercase character to lowercase, and vice
// versa. (Don’t forget the cctype family.)
  char c;
  while((c = cin.get()) != '@')//read by one char
  {
    if(!isdigit(c))
    {
      if(isupper(c))
        cout << (char)tolower(c);
      else if(islower(c))
        cout << (char)toupper(c);
    }
  }
}
void file_input(void)
{
  ifstream file_input;
  file_input.open("text.txt");
  char line[81];
  cout << "The output: ";
  while(file_input >> line)
  {
    fprintf(stdout, "%s\n", line);
  }
  //determine the reason of termination of a program:
  if(file_input.eof())
    cout << "EOF has been reached.";
  else if(file_input.fail())
    cout << "A mismatch was found(almost impossible)";
  else 
    cout << "The program terminated for an unknown reason";
  file_input.close();  
}
void files(void)
{
  char string[40];
  int model_year = 0;
  double original_price = 0.0, now_asking = 0.0;
  cout << "Enter the make and model of an automobile:" << endl;
  cin.getline(string, 40);
  cout << "Enter the model year" << endl;
  cin >> model_year;
  cout << "Enter the original asking price" << endl;
  cin >> original_price;
  now_asking = original_price * 0.913;
  //print the result:
  cout.precision(4);
  cout << "Make and model: " << string << "\nYear: " << model_year << "\nWas asking: " << original_price
  << "\nNow asking: " << now_asking;
  ofstream file;
  file.open("text.txt");
  //store the data in a file:
  file.precision(4);
  file << "Make and model: " << string << "\nYear: " << model_year << "\nWas asking: " << original_price
  << "\nNow asking: " << now_asking;
  file.close();
  // int a_grade = 0, b_grade = 0, c_grade = 0, d_grade = 0, f_grade;
  // char c = 'c';
  // switch(c)
  // {
  //   case('A'): a_grade++;
  //   case('B'): b_grade++;
  //   case('C'): c_grade++;
  //   case('D'): d_grade++;
  //   default: f_grade++;
  // }
}
void f_3(void)
{
  // char c; 
  // cin >> c;
  // cout << (int)c;//3(char code for '3', not a numerical value) => 51

  // int c;
  // cin >> c;
  // cout << c;//38

  int c;
  cin >> c;
  cout << c;//38
  
}
void f_1(void)
{
  cout << INT_MAX << " " << INT_MIN << endl;
  cout << __LDBL_MIN__;
  cout << "Hello World";
  if( not(12 > 9) or 9 < 6)
  {
    printf("Everything is possible.\v\v");
  }
  else 
  {
    printf("\n");
    printf("Anything is possible!!!!\r");
    // ungetc('\t', stdout);
    // ungetc('\n', stdout);
    // ungetc('\n', stdout);
    // ungetc('\n', stdout);

  }
}
void fish(void)
{
  //get the input:
  double fish[MAX];
  cout << "Enter the weights of your fish:\n";
  cout << "You may enter up to " << MAX << " fish <q to terminate>.\n";
  cout << "fish #1";
  int i = 0;
  for(; i < MAX;++i)
  {
    //we need to reset the input
    cout << "Round"<< i + 1 << ": ";
    //until the user enters the correct one:
    while(!(cin >> fish[i]))
    {
      cin.clear();
      while(cin.get() != '\n')
        ;
      //skip everything to the new line
      cout << "Please enter a number: ";
    }
  }
    //calculate the average:
  double total = 0.0;
  for(int j = 0; j < i;++j)
  {
    total += fish[j];
  }
  //display the data:
  if(i == 0)
    cout << "No fish\n";
  else
    cout << total / i << " = average weight of " << i << " fish.\n";
  cout << "Done.\n";
}