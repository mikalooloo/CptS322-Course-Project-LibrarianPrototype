//main.cpp for Library
#include "classes.hpp"

int main(void)
{
	int choice;
	User currentUser;
	std::string name; std::string username; std::string password;
	
	do 
	{
		std::cout << "Library Assistant Main Menu" << std::endl;
		std::cout << "Please pick an option below!" << std::endl;
		std::cout << "\n1. View Books\n2. Check Out\n3. Check In\n4. Check Balance\n5. Account\n6. Leave Session\n\n";
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
				if (!currentUser.getRegistered()) // user is not registered
				{
					std::cout << std::endl << "Please log in to your account before attempting to check your balance." << std::endl << std::endl;
				}
				else
				{
					std::cout << std::endl << "Library Balance" << std::endl;
					std::cout << "Fees Due: $" << currentUser.getFeesDue() << std::endl << std::endl;
				}
				break;
			case 5:
				// Register/Edit User
				if (!currentUser.getRegistered()) // user is not registered
				{
					// register user
					std::cout << std::endl << "Registering User" << std::endl;
					std::cout << "Enter your name: ";
					std::cin >> name;
					std::cout << std::endl << "Enter a username: ";
					std::cin >> username;
					std::cout << std::endl << "Enter a password: ";
					std::cin >> password;
					currentUser.setRegister(name,username,password);
					std::cout << std::endl << name << ", you are successfully registered!" << std::endl;
				}
				else
				{
					// edit user
					currentUser.editUser();
				}
				break;
			case 6:
				// Leave Session
				break;
			default:
				std::cout << std::endl << choice << " is not a valid input. Please try again!" << std::endl << std::endl;
				break;
		}
	} while(choice != 6);



	return 0;
}
