runPlanGenerator: Week.o Day.o
	g++ Week.o Day.o -o runPlanGenerator

Week.o: Week.cpp runPlanGenerator.h
	g++ -c Week.cpp

Day.o: Day.cpp runPlanGenerator.h
	g++ -c Day.cpp

clean:
	rm Tile.o Chest.o Door.o Wall.o MyNode.o MyList.o Room.o Player.o proj7
