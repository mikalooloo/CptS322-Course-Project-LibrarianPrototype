//main.cpp for Library
#include <iostream>

int main(void)
{
	int choice;
	std::cout << "Library Assistant Main Menu" << std::endl;
	std::cout << "Please pick an option below" << std::endl;
	std::cin >> choice;
	do 
	{
		switch (choice) {
			case 1:
				// View Book Inventory
				break;
			case 2:
				// Check In Book
				break;
			case 3:
				// Check Out Book
				break;
			case 4:
				// Check Balance
				break;
			case 5:
				// Edit User
				break;
			case 6:
				//Exit
				break;
		}
	} while(choice >= 0 || choice <= 6);



	return 0;
}
