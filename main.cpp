#include <iostream>
#include <list>
#include <algorithm>
#include <array>


/*
 * Functions to add:
 * printSchedule();
 * printDay();
 * others I haven't thought of yet...
 */

// Function prototypes
void addTask(std::string, double time);
void removeTask(std::string, double time);
void clearSchedule();
void clearDay(std::string day);
void exampleSchedule();


// Global Variables
const int arraySize = 8; // Size of the array holding the linked lists
    // Standard is size 8; 1 list for Monday - Sunday, and 1 list for completed tasks

int main()
{
    std::array<std::list<int>, arraySize> scheduleArray; // initialize scheduleArray
    return 0;
}

void addTask(std::string, double time)
{
    // need to code
}

void removeTask(std::string, double time)
{
    // need to code
}

void clearSchedule()
{
    // need to code
}

void clearDay(std::string day)
{
    // need to code
}

void exampleSchedule()
{
    // need to code
}