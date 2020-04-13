#pragma once
#include <iostream>
#include "LinkList.h"
#include <string>
#include <sstream>

using namespace std;


/***************************************************************************************************
File: OtherFunctions.h
Author : <Jeni Robbie>
Description: header file for other functions called in main cpp
Date Created: 16/03/20
Last Modified: 20/03/20

/***************************************************************************************************/

int getListValue();			///Returns Valid integer from string to insert into the list 
bool isTextPresentandNeg(string);//Test if characters in string a numerical
bool deleteListItem(Intlist);		//Get and Delete an item from inlist specified by user

bool isTextPresent(string userInput); //Test if characters in string is a positive integer

int getMenuOption();	//Get and valid menu option