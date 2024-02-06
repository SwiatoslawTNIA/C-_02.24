#include "golf.h"
using namespace std;
void secondary(void)
{
  cout << "\nWhich option do you choose? (1 or 2)";
  int answer = 0;
  while(1)
  {
      cin >> answer;
      if(answer == 1 || answer == 2)
        break;
      else
      {
        cin.clear();
        while(cin.get() != '\n')
          continue;
        cout << "\nPlease enter the correct value: ";
      }
    }
  cin.get();
  ans(answer);
}

 

void ans(int answer)
{
  using namespace std;
  if(answer == 1)
  {
    //using static array:
    char buffer[500];
    int slag = 0;
    chaff *pointer = new (buffer) chaff;

    cout << "Enter the dross: ";
    cin.getline(pointer->dross, 20);
    cout << "\nEnter the slag: ";
    while(!(cin >> slag))
    {
      cin.clear();
      while(cin.get() != '\n')
        continue;
      cout << "\nEnter the correct value: ";
    }
    pointer->slag = slag;
    //display output:
    cout << "\nDisplaying the output: " << endl;
    cout << "\nDross: " << pointer->dross << endl;
    cout << "\nSlag: " << pointer->slag << endl;
  }
  else 
  {//allocate on the heap
    int slag = 0;
    chaff *pointer = new chaff;

    cout << "Enter the dross: ";
    cin.getline(pointer->dross, 20);
    cout << "\nEnter the slag: ";
    while(!(cin >> slag))
    {
      cin.clear();
      while(cin.get() != '\n')
        continue;
      cout << "\nEnter the correct value: ";
    }
    pointer->slag = slag;
    //display output:
    cout << "\nDisplaying the output: " << endl;
    cout << "\nDross: " << pointer->dross << endl;
    cout << "\nSlag: " << pointer->slag << endl;
    delete pointer;
  }
}