#include "h.h"

int main(void)
{
  SALES::Sales new_sales_structure;
  SALES::setSales(new_sales_structure);
  SALES::showSales(new_sales_structure);
  SALES::Sales sales_2;
  const double arr[] = {42, 324.3, 342.2, -23, 4324, -324};
  SALES::setSales(sales_2, arr, 6);
  SALES::showSales(sales_2);
  return 0;
}