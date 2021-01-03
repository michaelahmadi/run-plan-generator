runPlanGenerator: Day.o Week.o runPlanGenerator.o
	g++ Day.o Week.o runPlanGenerator.o -o runPlanGenerator

Day.o: Day.cpp runPlanGenerator.h
	g++ -c Day.cpp

Week.o: Week.cpp runPlanGenerator.h
	g++ -c Week.cpp

runPlanGenerator.o: runPlanGenerator.cpp runPlanGenerator.h
	g++ -c runPlanGenerator.cpp

clean:
	rm Day.o Week.o runPlanGenerator.o runPlanGenerator
