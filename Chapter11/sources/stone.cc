#include "stone.h"
namespace STONEWT 
{
  Stonewt::Stonewt(void)
  {
    stone = pnds_left = pounds = 0;
  }
  Stonewt::Stonewt(double lbs)
  {
    pounds = lbs;
    stone = lbs / Lbs_per_stn;
    pnds_left = (int)lbs % Lbs_per_stn;//convert pounds to int
  }
  Stonewt::Stonewt(int stones, double pnds)
  {
    stone = stones;
    pounds = pnds;
    pnds_left = pounds - stones * Lbs_per_stn;
  }
  Stonewt::~Stonewt(void)
  {
    using namespace std;
    cout << endl << "destructor comes" << endl;
  }
  void Stonewt::show_lbs(void) const
  {
    std::cout << "The weight in pounds: " << pounds << std::endl;
  }
  void Stonewt::show_stn(void) const
  {
    std::cout << "The weight in pounds: " << pounds << " , and in stones: " << stone << " , pounds remaining: " 
    << pnds_left << std::endl;
  }
}
STONEWT::Stonewt::operator double(void) const//returns nothing
{
  return this->pounds;
}
STONEWT::Stonewt::operator int(void) const
{
  return int(this->pounds + 0.5);
}
// STONEWT::Stonewt STONEWT::Stonewt::operator+(const STONEWT::Stonewt & s2) const
// {
//   Stonewt new_stone;
//   new_stone.pounds = pounds + s2.pounds;
//   new_stone.stone = this->stone + s2.stone;
//   return new_stone;
// }

STONEWT::Stonewt STONEWT::operator+(const STONEWT::Stonewt & s1,  const STONEWT::Stonewt & s2)
{
  Stonewt new_stone;
  new_stone.pounds = s1.pounds + s2.pounds;
  new_stone.stone = s2.pounds + s2.stone;
  return new_stone;
}
// STONEWT::Stonewt::operator double(void) const
// {
//   return pounds;
// }
// //the conversion function must have no return type, since the compiler already knows the return type by looking
// //at the conversion type
// //the function must have no args, since we apply the conversion on the object we call it with, 
// //to implement the above, we need that the function must be a member function of the class .
// STONEWT::Stonewt::operator int(void) const
// {
//   return int(pounds);
// }
//the return value has to be 
STONEWT::Stonewt STONEWT::Stonewt::operator*(double v) const
{
  Stonewt new_obj;
  double total = this->pounds * v;
  new_obj.pounds = total;
  new_obj.pnds_left = (int)total % Lbs_per_stn;
  new_obj.stone = total / Lbs_per_stn;
  return new_obj;
}

STONEWT::Stonewt STONEWT::operator*(double val, const Stonewt & obj)
{
  // using namespace STONEWT;
  Stonewt new_obj;
  new_obj.pounds = obj.pounds * val;
  new_obj.pnds_left = (int)obj.pounds % Stonewt::Lbs_per_stn;//we have to use Stonewt::..., because the 
  //enum belongs to the class
  new_obj.stone = (int)obj.pounds / 60;
  return new_obj;
}

