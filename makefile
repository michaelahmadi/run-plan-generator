RunPlanGenerator: Day.o Week.o RunPlanGenerator.o
	g++ Day.o Week.o RunPlanGenerator.o -o RunPlanGenerator

Day.o: Day.cpp RunPlanGenerator.h
	g++ -c Day.cpp

Week.o: Week.cpp RunPlanGenerator.h
	g++ -c Week.cpp

RunPlanGenerator.o: RunPlanGenerator.cpp RunPlanGenerator.h
	g++ -c RunPlanGenerator.cpp

clean:
	rm Day.o Week.o RunPlanGenerator.o RunPlanGenerator
