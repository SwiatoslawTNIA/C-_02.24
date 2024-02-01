#include <iostream>
#include <cmath>
#define MAX 5
#define RADIAN 57.29577951
double cube(double x);
typedef struct 
{
  int hours;
  int mins;
} travel_time;

struct rect
{
double x;
double y;
};
struct polar
{
double distance;
double angle;
};
int fillArray(double arr[], int arr_size);
long double probability(unsigned int numbers, unsigned int picks);
void showArray(const double arr[], int arr_size);
void revalue(double arr[], double num, int arr_size);
travel_time *compute_time( travel_time* time1, travel_time* time2);
//const above doesn't mean that the original array has to be const
void run(void);
unsigned int calcElem(const char *string);
char *buildString(char c, int length);
void running(void);
void polars(void);
void structures(void);
//problem2
polar rect_to_polar(rect coords);
rect polar_to_coords(polar depos);
polar rect_to_polar(rect coords);

int main(void)
{
  const char *p1 = "Bruce Lee";
  char p2[] = "Bruce Lee";
  unsigned int res_1 = calcElem(p1);
  unsigned int res_2 = calcElem(p2);
  unsigned int res_3 = calcElem("Bruce Lee");
  printf("Results: %u %u %u", res_1, res_2, res_3);//u represents obviously the unsigned type
  polars();
  return 0;
}
void show_polar(polar depos)
{
  using namespace std;
  cout << "distance = " << depos.distance << endl;
  cout << "angle = " << RADIAN * depos.angle;
}
void polars(void)
{
  using namespace std;
  polar p_coords;
  rect rect_coords;
  printf("Enter the x and y values: ");
  while(cin >> rect_coords.x >> rect_coords.y)
  {
    polar p_coords = rect_to_polar(rect_coords);
    cout << "The distance: " << p_coords.distance << ", angle: " << p_coords.angle;
    cout << "\nEnter the x and y values: ";
  }
}
rect polar_to_coords(polar depos)
{
  using namespace std;
  //a triangle with hypothenuse depos.distance, depos.angle will be the lower angle (in the first quadrant)
  //sin angle = distance / y
  // y = sin angle * distance:
  rect coords;
  coords.y = sin(depos.angle) * depos.distance;
  //x = cos angle * distance:
  coords.x = cos(depos.angle) * depos.distance;
  return coords;
}
polar rect_to_polar(rect coords)
{
  //the distance is hypothenuse:
  polar polar_coords;
  polar_coords.distance = sqrt(coords.x * coords.x + coords.y * coords.y);
  polar_coords.angle = atan2(coords.y, coords.x) * RADIAN;
  return polar_coords;
}


void running(void)
{
  using namespace std;
  char character;
  int length = 0;
  cout << "Enter a character: ";
  cin >> character;
  cout << "Enter the length: ";
  cin >> length;
  char *result = buildString(character, length);
  cout << "This is the result:\n\t" << result << endl;
  delete result;
}

void structures(void)
{ 
  using namespace std;
  travel_time struct_1 = {5, 45};
  travel_time struct_2 = {6, 0};
  travel_time *total = compute_time(&struct_1, &struct_2);
  //display the output:
  cout << "The sum: " << total->hours << ":" << total->mins;
  delete total;
} 
travel_time *compute_time( travel_time* time1, travel_time* time2)
{
  // struct travel_time *new_time = (travel_time *)malloc(sizeof(struct travel_time));
  travel_time *new_time = new travel_time;
  unsigned int minutes = 0;
  minutes = time1->mins + time2->mins;
  if(minutes > 60)
  {
    int remainder = minutes / 60;//this will be int, (general solution)
    int new_minutes = minutes % (remainder * 60);//this gives the difference between the hours and minutes in minutes
    *new_time = { remainder + time1->hours + time2->hours, new_minutes}; 
    return new_time;
  }
  *new_time = {time1->hours + time2->hours, time1->mins + time2->mins};
  return new_time;
}
char *buildString(char c, int length)
{
  char *s = new char[length + 1];
  while(length-- > 0)
  {
    s[length] = c;
  }
  return s;
}
//count the number of chars in a string:
unsigned int calcElem(const char *string)//used const
{
  unsigned int total_elements = 0;
  while(*string++ != '\0')
  {
    ++total_elements;
  }
  return total_elements;
}
//a sum prototype for a two-dim array:
int sum(int arr[][10], int size)//works only with arrays of 10 cols ( with an array with x elements, each of which is 12 el. long)
{
  int total = 0;
  for(int r = 0; r < size;++r)
  {
    for(int c = 0; c < 4; ++c)
    {
      total += arr[r][c];
    }
  }
  return total;
}
void arrays(void)
{
  using namespace std;
  double properties[MAX];
  int size = fillArray(properties, MAX);
  showArray(properties, size);
  if(size > 0)
  {
    cout << "Enter revaluation factor: ";
    double factor = 0.0;
    while(!(cin >> factor))
    {
      cin.clear();//clear the error bit
      while(cin.get() != '\n')
        ;
      cout << "Please enter the correct value!!!";
    }
    revalue(properties, factor, size);
    showArray(properties, size);
  }
  cout << "Done.\n";
  cin.get();
  cin.get();
  return;
}


double cube(double x)
{
  return x * x * x;
}
void run(void)
{
  using namespace std;
  double total = 0, choices = 0;
  cout << "Enter the total amount of choices on the game card and the number of picks allowed:\n";
  while((cin >> total >> choices) && choices <= total)
  {
    cout << "You have one chance in " 
    << probability(total, choices) << " of winning.";
    cout << "Next two numbers: ((q to quit)";
  } 
}
long double probability(unsigned int numbers, unsigned int picks)
{
  long double result = 1L, n = 0.0L;
  unsigned p;
  for(n = numbers, p = picks; p > 0; n--, p--)
  {
    result *= n / p;
  }
  return result;
}
int fillArray(double arr[], int arr_size)
{
  using namespace std;
  double value = 0;
  int i = 0;
  for(; i < arr_size;++i)
  {
    //if the input is invalid, terminate with error, otherwise 
    if(!(cin >> value))
    {
      cin.clear();
      while(cin.get() != '\n')
        ;
      cout << "Wrong input format.";
      break;
    }
    else if(value < 0)//if the value is negative, terminate
      break;
    arr[i] = value;
  }
  return i;
}
void showArray(const double arr[], int arr_size)
{
  for(int i = 0; i < arr_size;++i)
  {
    fprintf(stdout, "Property #%d: %lf", i + 1, arr[i]);
  }
}
void revalue(double arr[], double num, int arr_size)
{
  for(int i = 0; i < arr_size;++i)
  {
    arr[i] *= num;
  }
}