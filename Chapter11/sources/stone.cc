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
