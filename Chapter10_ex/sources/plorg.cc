#include "plorg.h"

Plorg::Plorg(const char *n, int plorg_CI)
{
  strcpy(this->name, n);
  this->contentment_index = plorg_CI;
}
Plorg::~Plorg(void)
{
  std::cout << std::endl <<  "A descructor of type Plorg has been called.";

}
void Plorg::report_name(void)
{
  std::cout << "\n The name of the Plorg: " << this->name;
}

void Plorg::change_CI(int new_CI)
{
  contentment_index = new_CI;
}
