//main.cpp for Library
#include <iostream>
#include "classes.hpp"

int main(void)
{
	int choice;
	User currentUser();
	
	do 
	{
		std::cout << "Library Assistant Main Menu" << std::endl;
		std::cout << "Please pick an option below" << std::endl;
		std::cin >> choice;

		switch (choice) {
			case 1:
				// View Book Inventory
				break;
			case 2:
				// Check Out Cart
				break;
			case 3:
				// Check In Book(s)
				break;
			case 4:
				// Check Balance
				break;
			case 5:
				// Register/Edit User
				break;
			case 6:
				//Exit
				break;
			default:
				std::cout << std::endl << choice << " is not a valid input. Please try again!" << std::endl << std::endl;
				break;
		}
	} while(choice != 6);



	return 0;
}
