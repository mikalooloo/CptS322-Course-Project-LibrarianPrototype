//main.cpp for Library
#include "classes.hpp"
#include "functions.hpp"

int main(void)
{
	// *******DECLARING VARIABLES*******
	int choice;
	User currentUser;
	
	std::string name; std::string username; std::string password;

	std::list<User> usersList; // list of all users
	readUsers(openFile("users.csv"),&usersList); // reads in all users from users.csv
	std::list<User>::iterator v; // iterator used for usersList
	
	// *******MAIN MENU*******
	do 
	{
		std::cout << "Library Assistant Main Menu" << std::endl;
		std::cout << "Please pick an option below!" << std::endl;
		std::cout << "\n1. View Books\n2. Check Out\n3. Check In\n4. Check Balance\n5. Account\n6. Leave Session\n\n";
		std::cin >> choice;

		switch (choice) {
			case 1:
				// ***View Book Inventory***
				break;
			case 2:
				// ***Check Out Cart***
				break;
			case 3:
				// ***Check In Book(s)***
				break;
			case 4:
				// ***Check Balance***
				if (!currentUser.getRegistered()) // user is not registered
				{
					std::cout << std::endl << "Please log in to your account before attempting to check your balance." << std::endl << std::endl;
				}
				else // user is registered
				{
					std::cout << std::endl << "Library Balance" << std::endl;
					std::cout << "Fees Due: $" << currentUser.getFeesDue() << std::endl << std::endl;
				}
				break;
			case 5:
				// ***Account***
				if (!currentUser.getRegistered()) // user is not logged in
				{
					do 
					{
						std::cout << std::endl << "Account" << std::endl << "Would you like to \n1. Make An Account\n2. Log In\n3. Return to Main Menu" << std::endl << std::endl;
						std::cin >> choice;

						if (choice == 1) { // register user
							std::cout << std::endl << "Make An Account" << std::endl;
							std::cout << "Enter your name: ";
							std::cin >> name;
							std::cout << std::endl << "Enter a username: ";
							std::cin >> username;
							std::cout << std::endl << "Enter a password: ";
							std::cin >> password;
							currentUser.setRegister(name,username,password);
							usersList.push_back(currentUser);
							std::cout << std::endl << name << ", you are successfully registered!" << std::endl;
							choice = 3; // to force back to Main Menu
						}
						else if (choice == 2) { // log in
							std::cout << std::endl << "Log In" << std::endl;
							std::cout << "Username: ";
							std::cin >> username;
							std::cout << "Password: ";
							std::cin >> password;
							if (!(findUser(&usersList,v,username,password))) {
								std::cout << std::endl << "User not found. Log in failed." << std::endl;
							}
							else {
								std::cout << v->getName() << std::endl;
								currentUser = *v;
								std::cout << std::endl << "User found. Log in successful. Welcome " << currentUser.getName() << "!" << std::endl;
								choice = 3; // to force back to Main Menu
							}
						}
					} while (choice != 3);
					choice = 5;
				}
				else // user is logged in
				{
					// edit user
					currentUser.editUser();
				}
				break;
			case 6:
				// ***Leave Session***
				writeUsers(openFile("users.csv"),&usersList); // writes all current users to users.csv
				break;
			default:
				std::cout << std::endl << choice << " is not a valid input. Please try again!" << std::endl << std::endl;
				break;
		}
	} while(choice != 6);



	return 0;
}
