#include <iostream>
#include <string>

class Week
{
  // data members
private:
  int mileage; // total mileage run in the week

public:
  // constructor
  Week();

  // methods
  void addDay(); // Add a Day to the week
  void print(); // Printing method for debug purposes atm.

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