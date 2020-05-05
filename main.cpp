#include <iostream>
#include <forward_list>
#include <array>
#include <memory>

// Function prototypes
std::forward_list<std::string> addTask(std::forward_list<std::string> tempList);
std::forward_list<std::string> removeTask(std::forward_list<std::string> tempList);
void clearSchedule();
std::forward_list<std::string> clearDay(std::forward_list<std::string> tempList);
void exampleSchedule();
void menu();
void exit();
void printSchedule();
void printDay(std::forward_list<std::string> tempList);


// Global Variables
const int arraySize = 7; // Size of the array holding the linked lists
                         // Standard is size 7; 1 list for Monday - Sunday
int k = 0;
int menuSelection = 0;
int daySelection;


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
    return 0;
}

void menu() {
    std::array<std::forward_list<std::string>, arraySize> scheduleArray; // initialize scheduleArray
    // initialize task linked lists
    std::forward_list<std::string> mondayTasks;
    std::forward_list<std::string> tuesdayTasks;
    std::forward_list<std::string> wednesdayTasks;
    std::forward_list<std::string> thursdayTasks;
    std::forward_list<std::string> fridayTasks;
    std::forward_list<std::string> saturdayTasks;
    std::forward_list<std::string> sundayTasks;
    std::forward_list<std::string> completedTasks;

    std::cout << std::endl;
    std::cout << "Please choose from the following options - \n";
    std::cout << "1. Add a task \n";
    std::cout << "2. Delete a task \n";
    std::cout << "3. View schedule \n";
    std::cout << "4. View completed tasks \n";
    std::cout << "5. Clear Schedule \n";
    std::cout << "6. Clear Day \n";
    std::cout << "7. View example day \n";
    std::cout << "8. Exit \n";
    std::cout << " ";
    std::cin >> menuSelection;

    if (menuSelection == 1) {
        std::cout << "Which day would you like to add a task to? - \n";
        std::cout << "1. Monday \n";
        std::cout << "2. Tuesday \n";
        std::cout << "3. Wednesday \n";
        std::cout << "4. Thursday \n";
        std::cout << "5. Friday \n";
        std::cout << "6. Saturday \n";
        std::cout << "7. Sunday \n";
        std::cin >> daySelection;

        if (daySelection == 'Monday') {
            addTask(mondayTasks);
        } else if (daySelection == 'Tuesday') {
            addTask(tuesdayTasks);
        } else if (daySelection == 'Wednesday') {
            addTask(wednesdayTasks);
        } else if (daySelection == 'Thursday') {
            addTask(thursdayTasks);
        } else if (daySelection == 'Friday') {
            addTask(fridayTasks);
        } else if (daySelection == 'Saturday') {
            addTask(saturdayTasks);
        } else if (daySelection == 'Sunday') {
            addTask(sundayTasks);
        }
    } else if (menuSelection == 2) {
        std::cout << "Which task would you like to delete? - \n";
        printSchedule();
        std::string task;
        std::cin >> task;
        //removeTask(task);
    } else if (menuSelection == 3) {
        std::cout << "Which day would you like to view? - \n";
        std::cout << " ";
        std::cin >> daySelection;

        if (daySelection == 'Monday') {
            printDay(mondayTasks);
        } else if (daySelection == 'Tuesday') {
            printDay(tuesdayTasks);
        } else if (daySelection == 'Wednesday') {
            printDay(wednesdayTasks);
        } else if (daySelection == 'Thursday') {
            printDay(thursdayTasks);
        } else if (daySelection == 'Friday') {
            printDay(fridayTasks);
        } else if (daySelection == 'Saturday') {
            printDay(saturdayTasks);
        } else if (daySelection == 'Sunday') {
            printDay(sundayTasks);
        }
    }   else if (menuSelection == 4) {
        printDay(completedTasks);
    }   else if (menuSelection == 5) {
        // write code
    }   else if (menuSelection == 6) {

        std::cout << "Which day would you like to clear? - \n";
        std::cout << " ";
        std::cin >> daySelection;

            if (daySelection == 'Monday') {
                clearDay(mondayTasks);
            } else if (daySelection == 'Tuesday') {
                clearDay(tuesdayTasks);
            } else if (daySelection == 'Wednesday') {
                clearDay(wednesdayTasks);
            } else if (daySelection == 'Thursday') {
                clearDay(thursdayTasks);
            } else if (daySelection == 'Friday') {
                clearDay(fridayTasks);
            } else if (daySelection == 'Saturday') {
                clearDay(saturdayTasks);
            } else if (daySelection == 'Sunday') {
                clearDay(sundayTasks);
            }
    }   else if (menuSelection == 7) {
        exampleSchedule();
    }   else if (menuSelection == 8) {
        exit();
    }
}


std::forward_list<std::string> addTask(std::forward_list<std::string> tempList)
{
    std::string task;
    std::cin >> task;
    std::cout << std::endl;
    tempList.push_front(task);
    return tempList;
}

/*
std::forward_list<std::string> removeTask(std::forward_list<std::string> tempList)
{
    std::string task;
    std::cin >> task;
    std::cout << std::endl;

}
*/

void clearSchedule()
{
    for (int i=0; i<7; i++) {

    }
}

std::forward_list<std::string> clearDay(std::forward_list<std::string> tempList)
{
    std::string dayToClear;
    std::cin >> dayToClear;
    std::cout << std::endl;
    tempList.clear();
}

void exampleSchedule()
{
    std::forward_list<std::string> mondayTasks; // example list for monday
    daySelection = 'Monday'; // example variable

    mondayTasks.assign({"Do laundry", "Dance practice", "Write c++ code"});
    printDay(mondayTasks);
    clearDay(mondayTasks);

}

void printDay(std::forward_list<std::string> tempList)
{
    // print the day by iterating through each element of the linked list

    // I wrote this as an example of a print function for a linked list that seems to work well,
    // feel free to delete it to write a different one if you'd like though. I just needed one to test haha.
    std::cout << daySelection << " has the following tasks: " << std::endl;
    for (std::string&s : tempList)
        std::cout << s << std::endl;
    std::cout << std::endl;
}

void printSchedule()
{
    // print the schedule by iterating through each element of scheduleArray to print the associated linked lists.
}
    
void exit()
{
    std::cout << std::endl;
    std::cout << "See ya! \n";
    k = 1;
}