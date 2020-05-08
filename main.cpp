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
bool isInList(std::forward_list<std::string> tempList, const std::string& task);
void exampleSchedule();
void menu();
void exit();
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

        if (daySelection == 1) {
            addTask(mondayTasks);
        } else if (daySelection == 2) {
            addTask(tuesdayTasks);
        } else if (daySelection == 3) {
            addTask(wednesdayTasks);
        } else if (daySelection == 4) {
            addTask(thursdayTasks);
        } else if (daySelection == 5) {
            addTask(fridayTasks);
        } else if (daySelection == 6) {
            addTask(saturdayTasks);
        } else if (daySelection == 7) {
            addTask(sundayTasks);
        }
    }
    else if (menuSelection == 2) {
        std::cout << "Which day would you like to delete a task from? - \n";
        std::cout << "1. Monday \n";
        std::cout << "2. Tuesday \n";
        std::cout << "3. Wednesday \n";
        std::cout << "4. Thursday \n";
        std::cout << "5. Friday \n";
        std::cout << "6. Saturday \n";
        std::cout << "7. Sunday \n";
        std::cin >> daySelection;

        if (daySelection == 1) {
            removeTask(mondayTasks);
        } else if (daySelection == 2) {
            removeTask(tuesdayTasks);
        } else if (daySelection == 3) {
            removeTask(wednesdayTasks);
        } else if (daySelection == 4) {
            removeTask(thursdayTasks);
        } else if (daySelection == 5) {
            removeTask(fridayTasks);
        } else if (daySelection == 6) {
            removeTask(saturdayTasks);
        } else if (daySelection == 7) {
            removeTask(sundayTasks);
        }

    }
    else if (menuSelection == 3) {
        std::cout << "Which day would you like to view? - \n";
        std::cout << "1. Monday \n";
        std::cout << "2. Tuesday \n";
        std::cout << "3. Wednesday \n";
        std::cout << "4. Thursday \n";
        std::cout << "5. Friday \n";
        std::cout << "6. Saturday \n";
        std::cout << "7. Sunday \n";
        std::cin >> daySelection;

        if (daySelection == 1) {
            printDay(mondayTasks);
        } else if (daySelection == 2) {
            printDay(tuesdayTasks);
        } else if (daySelection == 3) {
            printDay(wednesdayTasks);
        } else if (daySelection == 4) {
            printDay(thursdayTasks);
        } else if (daySelection == 5) {
            printDay(fridayTasks);
        } else if (daySelection == 6) {
            printDay(saturdayTasks);
        } else if (daySelection == 7) {
            printDay(sundayTasks);
        }
    }
    else if (menuSelection == 4) {
        clearSchedule(scheduleArray);

    }
    else if (menuSelection == 5) {

        std::cout << "Which day would you like to clear? - \n";
        std::cout << "1. Monday \n";
        std::cout << "2. Tuesday \n";
        std::cout << "3. Wednesday \n";
        std::cout << "4. Thursday \n";
        std::cout << "5. Friday \n";
        std::cout << "6. Saturday \n";
        std::cout << "7. Sunday \n";
        std::cin >> daySelection;

            if (daySelection == 1) {
                clearDay(mondayTasks);
            } else if (daySelection == 2) {
                clearDay(tuesdayTasks);
            } else if (daySelection == 3) {
                clearDay(wednesdayTasks);
            } else if (daySelection == 4) {
                clearDay(thursdayTasks);
            } else if (daySelection == 5) {
                clearDay(fridayTasks);
            } else if (daySelection == 6) {
                clearDay(saturdayTasks);
            } else if (daySelection == 7) {
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
    std::cout << "Please enter a task to add.";
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

bool isInList(std::forward_list<std::string> tempList, const std::string& task) {

    auto findIter = std::find(tempList.begin(), tempList.end(), task);
    return true;
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
    daySelection = 1; // example variable

    mondayTasks.assign({"Do laundry", "Dance practice", "Write c++ code"});
    printDay(mondayTasks);
    clearDay(mondayTasks);

}

void printDay(std::forward_list<std::string> tempList)
{
    // print the day by iterating through each element of the linked list
    std::cout << "\n" << "That day has the following tasks: " << std::endl;
    for (std::string&s : tempList)
        std::cout << s << std::endl;
    std::cout << std::endl;
}

void exit()
{
    std::cout << std::endl;
    std::cout << "See ya! \n";
    k = 1;
}
