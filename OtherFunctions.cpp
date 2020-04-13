#include"OtherFunctions.h"

/***************************************************************************************************
File: OtherFunctions.cpp
Author : <Jeni Robbie>
Description: cpp file for other function definititions called in main cpp
Date Created: 16/03/20
Last Modified: 20/03/20

/***************************************************************************************************/

//Test if characters in string is a numerical but allows for initial dasy at start to indicate neg number
bool isTextPresentandNeg(string userInput)
{

    int start = 0;         //start position of for loop
    if ((userInput[0] == '-') && (userInput.length() > 1))     //Check if negative number
        start = 1;                     //if negative number, loop starts from second char in string

    for (int i = start; i < userInput.length(); i++)               //Loop for whole number
    {
        int intval = (int)userInput[i];                         //Convert character to ASCII
        if (intval < 48 || intval > 57)                            //Check its between 0 and 9
        {
            cout << "Invalid input. Please enter a integer number" << endl;
            return true;            //If text is present
        }
    }

    return false;              // if text is not present in string
}

//Test if characters in string is a positive integer
bool isTextPresent(string userInput)
{

  

    for (int i = 0; i < userInput.length(); i++)               //Loop for whole number
    {
        int intval = (int)userInput[i];                         //Convert character to ASCII
        if (intval < 48 || intval > 57)                            //Check its between 0 and 9
        {
            cout << "Invalid input. Please enter a integer number" << endl;
            return true;            //If text is present
        }
    }

    return false;              // if text is not present in string
}





///Returns Valid integer from string input to insert into the list 
int getListValue()
{
    string listValueString;
    bool isText;
    int value;

    do {
        cin >> listValueString;
        isText = isTextPresentandNeg(listValueString);               //Check if input is valid


    } while (isText == true);

    stringstream x(listValueString);           //create stringstream object with string parameter
    x >> value;                    //Assign value integer with X object value
    return value;      //return integer

}
//Delete an item from inlist specified by user
bool deleteListItem(Intlist list) {
    int userInput;
    bool isFound;

    if (list.isEmpty() == true)                                  //As the delete list checks if the list is empty and returns false as well as if item is not found, additional check for specific user feedback given.
    {
        cout << "List is empty. Items can not be deleted." << endl;
        return false;
    }
    else {
        cout << "Current List: ";     /*print current list so user can see options*/
        list.Print(true);
        cout << endl;

        cout << "Enter number to delete:  " << endl;
        cin >> userInput;

        isFound = list.Delete(userInput);
        if (isFound == true) {                 //if found gives new list of integers
            cout << "Current List: ";
            list.Print(true);
            cout << endl;
        }
        else {
            cout << "Item not in list." << endl;       //Displays error message
        }





        return true;
    }
}
//Get and validate menu option
int getMenuOption() {
    string userInput;
    int input;
    bool isNotValid;
    do {
        cin >> userInput;
        isNotValid = isTextPresent(userInput); //Test if characters in string is a positive integer

    } while (isNotValid == true);
    stringstream x(userInput);           //create stringstream object with string parameter
    x >> input;                    //Assign value integer with X object value
    return input;

}