#include "h.h"
//extend defs:
namespace SALES
{
  using namespace std;
  // copies the lesser of 4 or n items from the array ar
  // to the sales member of s and computes and stores the
  // average, maximum, and minimum values of the entered items;
  // remaining elements of sales, if any, set to 0
  void setSales(Sales & s, const double ar[], int n)
  {
    double total = 0.0, average = 0.0, maximum = ar[0], minimum = ar[0];//have to set the min to the
    //first value, if we set mean to 0, all values will be bigger, then the mean would be erroneous
    int i = 0;
    for(; i < n && i < 4;++i)
    {
      s.sales[i] = ar[i];
      total += ar[i];
      if(maximum < ar[i])
        maximum = ar[i];
      if(minimum > ar[i])
        minimum = ar[i];
    }
    average = total / i;
    s.average = average;
    s.min = minimum;
    s.max = maximum;
    while(i < 4)
    {
      s.sales[i++] = 0;
    }
  }
  // gathers sales for 4 quarters interactively, stores them
  // in the sales member of s and computes and stores the
  // average, maximum, and minimum values
  void setSales(Sales & s)
  {
    double average = 0.0, min = 0.0, max = 0.0, total = 0.0, current_sale = 0.0;
    for(int i = 0; i < 4; ++i)
    {
      cout << "\nPlease enter the sales for quarter " << i << ": " << endl;
      while(!(cin >> current_sale))
      {
        cin.clear();
        while(cin.get() != '\n')
          continue;
        cout << "\nPlease enter the correct value type.";
      }
      if(i == 0)
      {
        min = current_sale;
        max = current_sale;
      }
      else
      {
        if(max < current_sale)
          max = current_sale;
        if (min > current_sale)
          min = current_sale;
      }
      s.sales[i] = current_sale;
      
      total += current_sale;
    }
    average = total / 4;  
    s.average = average;
    s.max = max;
    s.min = min;
  }
  // display all information in structure s
  void showSales(const Sales & s)
  {
    cout << "\nDisplaying sales: " << endl;
    for(int i = 0; i < 4;++i)
    {
      cout << "\t\t" << i << s.sales[i] << endl;
    }
    cout << "\nAverage: " << s.average << ", min: " << s.min << ", max: " << s.max;
  }
} 