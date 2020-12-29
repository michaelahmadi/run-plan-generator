#include <stdio.h>

class Week
{
  // data members
private:
  bool isOn; // data member for if the player is currently on the tile
  char type; // types are T = Tile, C = Chest, D = Door, W = Wall, E = Exit
  bool beenVisitedDFS; // for DFS 
public:
  // constructor
  Week();

  // methods
  void setType(char c); // setter
  char getType();  // getter
  bool isOnTile(); // getter
  void setOnTile(bool val); // setter
  virtual int getGold(); // for Chest class
  virtual char* getFileName(); // for Door class
  virtual bool beenVisitedChest(); // for Chest class
  virtual void setVisitedChest(); // for Chest class
  bool beenVisited(); // for DFS
  void setVisited(bool val); // for DFS
};

class Day
{
  // data members
private:
  ;
public:
  // constructor
  Day();

  // methods
};