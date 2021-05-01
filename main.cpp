//main.cpp for Library
#include "classes.hpp"

int main(void)
{
	int choice;
	User currentUser;
	
	do 
	{
		std::cout << "Library Assistant Main Menu" << std::endl;
		std::cout << "Please pick an option below!" << std::endl;
		std::cout << "\n1. View Books\n2. Check Out\n3. Check In\n4. Check Balance\n5. Account\n6. Exit\n\n";
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
				if (!currentUser.getRegistered()) // user is not registered
				{
					// register user
				}
				else
				{
					// edit user
				}
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
