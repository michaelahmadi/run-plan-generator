#include <iostream>
#include <string>
#include <vector>

class Week
{
  // data members
private:
  int mileage; // total mileage run in the week

public:
  // constructors
  Week();
  Week(int mileage);

  // methods
  void addDay(); // Add a Day to the week
  void print(); // Printing method for debug purposes atm.
  int getMileage();
};

class Day
{
  // data members
private:
  std::string runType; // Type of Run: Easy, Long, Tempo, Intervals

public:
  // constructor
  Day();

  // methods
  void setRunType(std::string runType);
  std::string getRunType();
};