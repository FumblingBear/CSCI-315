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
void menu();
void exit();


// Global Variables
const int arraySize = 8; // Size of the array holding the linked lists
    // Standard is size 8; 1 list for Monday - Sunday, and 1 list for completed tasks
int k = 0;
int menuSelection = 0;
int daySelection = 0;

int main()
{
    while (true)
    {
        std::cout << std::endl;
        if (k == 1)
        {
            break;
        }
        menu();
    }
    std::array<std::list<int>, arraySize> scheduleArray; // initialize scheduleArray
    return 0;
}

void menu() {
    std::cout << std::endl;
    std::cout << "Please choose from the following options - \n";
    std::cout << "1. Add a task \n";
    std::cout << "2. Delete a task \n";
    std::cout << "3. View schedule \n";
    std::cout << "4. View completed tasks \n";
    std::cout << "5. Exit \n";
    std::cout << " ";
    std::cin >> menuSelection;

    if (menuSelection == 1) {
        std::cout << "Which day would you like to add a task to? - \n";
        std::cout << " ";
        std::cin >> daySelection;

        if (daySelection == Monday) {
            // Code to access the linked list for Monday
            addTask();
        } else if (daySelection == Tuesday) {
            // Code to access the linked list for Tuesday
            addTask();
        } else if (daySelection == Wednesday) {
            // Code to access the linked list for Wednesday
            addTask();
        } else if (daySelection == Thursday) {
            // Code to access the linked list for Thursday
            addTask();
        } else if (daySelection == Friday) {
            // Code to access the linked list for Friday
            addTask();
        } else if (daySelection == Saturday) {
            // Code to access the linked list for Saturday
            addTask();
        } else if (daySelection == Sunday) {
            // Code to access the linked list for Sunday
            addTask();
        }
    } else if (menuSelection == 2) {
        cout << "Which task would you like to delete? - \n";
        // Code to show all of the tasks
        removeTask();
    } else if (menuSelection == 3) {
        std::cout << "Which day would you like to view? - \n";
        std::cout << " ";
        std::cin >> daySelection;

        if (daySelection == Monday) {
            // Code to access the linked list for Monday
        } else if (daySelection == Tuesday) {
            // Code to access the linked list for Tuesday
        } else if (daySelection == Wednesday) {
            // Code to access the linked list for Wednesday
        } else if (daySelection == Thursday) {
            // Code to access the linked list for Thursday
        } else if (daySelection == Friday) {
            // Code to access the linked list for Friday
        } else if (daySelection == Saturday) {
            // Code to access the linked list for Saturday
        } else if (daySelection == Sunday) {
            // Code to access the linked list for Sunday
        }
    } else if (menuSelection == 4) {
        // Code to view completed tasks
    } else if (menuSelection == 5) {
        exit();
    }
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
    
void exit()
{
    std::cout << std::endl;
    std::cout << "See ya! \n";
    k = 1;
}