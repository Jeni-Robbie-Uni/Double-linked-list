#include "LinkList.h"
#include "OtherFunctions.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{

    string menu;
    int listValue, menuOption;
    bool isNotValid;
    Intlist int_list;

    //Program Instructions
    cout << "The following program will allow the users to create a list of integers and then edit the list and view it in ascending and descending order." << endl;
    cout << "Enter list of integers, 0 to finish: " << endl;
    // Make list from user inputs
    listValue = getListValue();     //Get and validate input

    while (listValue != 0)          //Loop until exit condition hit
    {
        int_list.Insert(listValue);         //Insert value into list
        listValue = getListValue();         //get and validat another item in list
    }



    do {

        //Menu options to edit list 
        cout << "Please enter menu option to edit/view the list created. Enter 0 at any time to exit" << endl;
        cout << "1. Add to list " << endl;
        cout << "2. Delete item from list" << endl;
        cout << "3. View in acending order" << endl;
        cout << "4. View in descending order " << endl;
        cout << "0. Exit " << endl << endl;
        cout << "Please enter option: ";

        menuOption = getMenuOption();   //get and validate user input menu option


        switch (menuOption) {
        case 0:         //exit condition
            break;
        case 1:         //Add integer to existing list
            int menu;
            cout << "Enter an integer." << endl;

            listValue = getListValue();     //Get and validate input

            int_list.Insert(listValue);         //Insert value into list

            int_list.Print(true);               //Print new list;

            break;

        case 2:         //Delete item from List

            int userInput;
            bool isFound;

            if (int_list.isEmpty() == true)                                  //As the delete list checks if the list is empty and returns false as well as if item is not found, additional check for specific user feedback given.
            {
                cout << "List is empty. Items can not be deleted." << endl;
            }
            else {
                cout << "Current List: ";     /*print current list so user can see options*/
                int_list.Print(true);
                cout << endl;

                cout << "Enter number to delete:  " << endl;
                cin >> userInput;

                isFound = int_list.Delete(userInput);
                if (isFound == true) {                 //if found gives new list of integers
                    cout << "Current List: ";
                    int_list.Print(true);
                    cout << endl;
                }
                else {
                    cout << "Item not in list." << endl;       //Displays error message
                }
            }

            break;

        case 3:
            int_list.Print(true);           //Print numbers in ascending order
            break;

        case 4:
            int_list.Print(false);          //Print numbers in descending order
            break;

        default:
            cout << "Invalid Input Please try again" << endl;
            break;
        }
                cout << endl;
    }while (menuOption != 0);           //loop until exit condition


    return 0;
}

