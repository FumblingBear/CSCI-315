#include <array>
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <memory>

// Function prototypes
std::forward_list<std::string> addTask(std::forward_list<std::string> tempList);
std::forward_list<std::string> removeTask(std::forward_list<std::string> tempList);
void clearSchedule(std::array<std::forward_list<std::string>, 7> scheduleArray);
std::forward_list<std::string> clearDay(std::forward_list<std::string> tempList);
bool isInList(std::forward_list<std::string> tempList, std::string task);
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

    // place the lists in an array
    scheduleArray = {mondayTasks, tuesdayTasks, wednesdayTasks, thursdayTasks, fridayTasks, saturdayTasks, sundayTasks};

    std::cout << std::endl;
    std::cout << "Please choose from the following options - \n";
    std::cout << "1. Add a task \n";
    std::cout << "2. Delete a task \n";
    std::cout << "3. View schedule \n";
    std::cout << "4. Clear Schedule \n";
    std::cout << "5. Clear Day \n";
    std::cout << "6. View example day \n";
    std::cout << "7. Exit \n";
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
        std::cout << "Which day would you like to delete a task from? - \n";
        std::cin >> daySelection;
        if (daySelection == 'Monday') {
            removeTask(mondayTasks);
        } else if (daySelection == 'Tuesday') {
            removeTask(tuesdayTasks);
        } else if (daySelection == 'Wednesday') {
            removeTask(wednesdayTasks);
        } else if (daySelection == 'Thursday') {
            removeTask(thursdayTasks);
        } else if (daySelection == 'Friday') {
            removeTask(fridayTasks);
        } else if (daySelection == 'Saturday') {
            removeTask(saturdayTasks);
        } else if (daySelection == 'Sunday') {
            removeTask(sundayTasks);
        }

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
    }
        else if (menuSelection == 4) {
        clearSchedule(scheduleArray);

    }
        else if (menuSelection == 5) {

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
    }   else if (menuSelection == 6) {
        exampleSchedule();
    }   else if (menuSelection == 7) {
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


std::forward_list<std::string> removeTask(std::forward_list<std::string> tempList)
{
    std::cout << "Which task would you like to delete? - \n";
    printDay(tempList);
    std::string task;
    std::cin >> task;
    std::cout << std::endl;

    if (isInList(tempList, task) == 1) {
        tempList.remove(task);
        std::cout << task << " deleted.";
    }
    else {
        std::cout << "Task not found in list.";
    }

    return tempList;
}

bool isInList(std::forward_list<std::string> tempList, std::string task) {
    auto findIter = std::find(tempList.begin(), tempList.end(), task);
}

void clearSchedule(std::array<std::forward_list<std::string>, 7> scheduleArray)
{
    for (int i=0; i<7; i++) {
        scheduleArray[i].clear();
    }
    std::cout << "Schedule cleared.";
}

std::forward_list<std::string> clearDay(std::forward_list<std::string> tempList)
{
    tempList.clear();
    return tempList;
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
    std::cout << "That day has the following tasks: " << std::endl;
    for (std::string&s : tempList)
        std::cout << s << std::endl;
    std::cout << std::endl;
}

void printSchedule()
{
    // I don't think we need a print schedule since we already have a printDay.
}
    
void exit()
{
    std::cout << std::endl;
    std::cout << "See ya! \n";
    k = 1;
}
