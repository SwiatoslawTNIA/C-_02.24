#ifndef NAMESPACES_
#define NAMESPACES_
namespace Experiment
{
  // static double a;
  // static double c;
  extern int var;//local

  struct Luci 
  {
    mutable unsigned int age;
    mutable unsigned int state;
    mutable unsigned long long int change;
  };
}
#endif