#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Day
{
  // data members
private:
  std::string runType; // Type of Run: Easy, Long, Tempo, Intervals
  int miles; // Length of the run

public:
  // constructor
  Day();
  Day(std::string runType, int miles);

  // methods
  void addMile();
  int getMiles();
  void setRunType(std::string runType);
  std::string getRunType();
};

class Week
{
  // data members
private:
  int mileage; // total mileage run in the week
  std::vector<Day> days; // vector of days included in the week

public:
  // constructors
  Week();
  Week(int mileage);

  // methods
  void addDay(); // Add a Day to the week
  std::string print(); // Printing method to transfer data to .txt file
  int getMileage();
};
