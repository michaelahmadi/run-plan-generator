# run-plan-generator
An application I wrote in C++ to generate a week-by-week training plan for runners to reach any goal mileage.

To Use:

    make
    ./runPlanGenerator [currentWeeklyMileage] [goalWeeklyMileage]

and then a file "Running Plan.txt" will be created which contains the generated plan.


Each week in the plan follows this format: Medium Run, Medium Run, Easy Run, Tempo Run, Easy Run, Long Run, Recovery Day

For example, here's the first week in the "Running Plan.txt" file when the currentWeeklyMileage is 10:
    
    Week: 0 | Mileage: 10
    Medium 2
    Medium 2
    Easy 1
    Tempo 1
    Easy 1
    Long 3
    Recovery 0

From there, additional weeks are included until the goal mileage is reached.