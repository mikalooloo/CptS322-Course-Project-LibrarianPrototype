#include "functions.hpp"
// I'm not sure where this code is going exactly so I only touched this to fix conflict errors, -Mikaela
// okay now I'm gonna add some file functions

std::fstream openFile(std::string filename) {
	std::fstream file(filename);

	if (!file.is_open()) {
		std::cout << filename << " failed to open!" << std::endl;
		exit(1);
	}

	return file;
}

// reads all lines in users.csv into usersList
void readUsers (std::fstream& file, std::list<User>* usersList) {
	std::string readline = "";
	User tempUser; tempUser.setRegister();

	while (!file.eof()) {
		while (std::getline(file, readline, ',')) {
			tempUser.setName(readline);
			std::getline(file, readline, ',');
			tempUser.setUsername(readline);
			std::getline(file, readline, ',');
			tempUser.setPassword(readline);
			std::getline(file, readline, '\n');
			tempUser.setFeesDue(stof(readline));
			usersList->push_back(tempUser);
		}
	}

	file.close();
}

// writes all current users in the list to users.csv
void writeUsers(std::fstream& file, std::list<User>* usersList) {
	for (std::list<User>::iterator v = usersList->begin(); v != usersList->end(); ++v) {
		file << v->getName();
		file << ",";
		file << v->getUsername();
		file << ",";
		file << v->getPassword();
		file << ",";
		file << v->getFeesDue();
		file << "\n";
	}

	file.close();
}

// returns true if user is found, false if not, and the iterator v is pointing to said user if true
bool findUser(std::list<User>* usersList, std::list<User>::iterator& v, std::string username, std::string password) {
	for (v = usersList->begin(); v != usersList->end(); ++v) {
		if (v->getUsername() == username && v->getPassword() == password) return true;
	}
	// if no user is found
	return false;
}

void readBooks(std::fstream& file, std::list<Book>* bookList) {
	std::string readline = "";
	std::string fname, lname, name, author, isbn;
	bool co;
	int waitNum;


	while (!file.eof()) {
		while (std::getline(file, readline, ',')) {
			name = readline;
			std::getline(file, readline, ',');
			author = readline;
			std::getline(file, readline, ',');
			isbn = readline;
			std::getline(file, readline, ',');
			co = (bool)(std::stoi(readline));
			std::getline(file, readline, '\n');
			waitNum = std::stoi(readline);
			Book tempBook(isbn, name, author, co, waitNum);
			bookList->push_back(tempBook);
		}
		
	}

	file.close();
}

void displayBooks(std::list<Book>* bookList) {
	std::list<Book>::iterator it;
	std::cout << "Book titles: \n";
	for (it = bookList->begin(); it != bookList->end(); it++) {
		std::cout << it->getName() << std::endl;
	}
}
void bookActions(std::list<Book>* bookList, std::list<Book>* cart) {
	int opt = 0;
	while (opt != 3 || opt > 3 || opt < 1) {
		displayBooks(bookList);
		std::cout << "\n\nWould you like to (1) search for books/authors, (2) select book, (3) go back?\t";
		std::cin >> opt;
		if (opt == 1)
			searchBooks(bookList, cart);
		if (opt == 2)
			selectBook(bookList, cart);
		if (opt == 3) {
			return;
		}
		opt = 0;
	}
}
//Searched for books based on title, author, and ISBN
void searchBooks(std::list<Book>* bookList, std::list<Book>* cart) {
	std::list<Book> tempList;
	std::list<Book>::iterator it;
	int opt = 0;
	while (opt < 1 || opt > 3) {
		std::cout << "\nWould you like to search for an (1) author, (2) title, or (3) ISBN?";
		std::cin >> opt;
	}
	if (opt == 1) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string c;
		std::cout << "\nPlease input the author: ";
		std::getline(std::cin, c);
		for (it = bookList->begin(); it != bookList->end(); it++) {
			if (it->getAuthor() == c) {
				tempList.push_back((*it));
			}
		}
	}
	if (opt == 2) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string t;
		std::cout << "\nPlease input the title: ";
		std::getline(std::cin, t);
		for (it = bookList->begin(); it != bookList->end(); it++) {
			if (it->getName() == t) {
				tempList.push_back((*it));
			}
		}
	}
	if (opt == 3) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string i;
		std::cout << "\nPlease input the ISBN: ";
		std::getline(std::cin, i);
		for (it = bookList->begin(); it != bookList->end(); it++) {
			if (it->getISBN() == i) {
				tempList.push_back((*it));
			}
		}
	}

	if (tempList.empty())
		std::cout << "\nThere were no books with that information...\n";
	else
		displayBooks(&tempList);

	system("pause");
	bookActions(bookList, cart);
}
//Gets a specific book by title
void selectBook(std::list<Book>* bookList, std::list<Book>* cart) {
	std::cout << "\nWhat book would you like to select: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string b;
	Book tempBook;
	std::getline(std::cin, b);
	std::list<Book>::iterator it;
	for (it = bookList->begin(); it != bookList->end(); it++) {
		if (it->getName() == b) {
			int choice = 0;
			std::cout << "Book Title: " << it->getName() << "\nBook Author: " << it->getAuthor();
			std::cout << "\nBook ISBN: " << it->getISBN() << "\nWaitlist: " << it->getWaitlist();
			while (choice > 2 || choice < 1) {
				std::cout << "\n\nWould you like to (1) Add book to cart or (2) Return to book search?\n";
				std::cin >> choice;
			}
			if (choice == 1) {
				cart->push_back(*it);
			}
			else {
				bookActions(bookList, cart);
			}
		}
	}

}

void checkOutCart(std::list<Book>* cart, std::list<Book>* bookList) {
	int choice = 0;
	std::list<Book>::iterator itc;
	std::list<Book>::iterator itb;
	std::cout << "\n*** Current Cart ***\n";
	displayBooks(cart);
	while (choice < 1 || choice > 2) {
		std::cout << "Would you like to checkout these books (1) yes (2) no?";
		std::cin >> choice;
	}

	if (choice == 1) {
		for (itc = cart->begin(); itc != cart->end(); itc++) {
			for (itb = bookList->begin(); itb != bookList->end(); itb++) {
				if (itc->getISBN() == itb->getISBN()) {
					if (itb->getCheckedOut() == true) {
						itb->setWaitlist(itb->getWaitlist() + 1);
						std::cout << "\nYou are number " << itb->getWaitlist() << " for " << itb->getName();
					}
					else {
						itb->setWaitlist(itb->getWaitlist() + 1);
						itb->setCheckedOut(true);
					}
				}
			}
		}
		std::cout << "\nGo pick them up when they are ready!\n";
	}
	else {
		int opt = 0;
		std::cout << "\nWould you like to (1) delete books from cart, (2) add more books, (3) go back to main menu?\n";
		while (opt < 1 || opt > 3) {
			std::cin >> opt;
		}
		if (opt == 1) {
			deleteBooks(cart);
		}
		if (opt == 2) {
			bookActions(cart, bookList);
		}
		if (opt == 3) {
			return;
		}
	}
}

void deleteBooks(std::list<Book>* cart) {
	int choice = 0;
	std::list<Book>::iterator itc;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string c;
	std::cout << "\nPlease input the book you want to delete: ";
	std::getline(std::cin, c);
	for (itc = cart->begin(); itc != cart->end(); itc++) {
		if (itc->getName() == c) {
			cart->erase(itc);
			break;
		}
	}
	while (choice > 2 || choice < 1) {
		std::cout << "\nWould you like to delete another (1) yes (2) no? ";
		std::cin >> choice;
	}
	if (choice == 1) {
		deleteBooks(cart);
	}
	else {
		return;
	}

}

void storeBooks(std::list<Book>* bookList) {
	std::list<Book>::iterator it;
	std::fstream file = openFile("books.csv");
	for (it = bookList->begin(); it != bookList->end(); it++) {
		file << it->getName() << "," << it->getAuthor() << "," << it->getISBN() << "," << it->getCheckedOut() << "," << it->getWaitlist() << "\n";
	}
	file.close();
}


//Admin functions

//from milestone 3 - view book inventory
void getBooks(std::list<Book>* bookList, std::list<Book>* cart){
    std::fstream books = openFile("books.csv");
    readBooks(books, bookList);
    int opt = 0;
    std::list<Book>::iterator it;
    std::string newtitle;

    while (opt < 1 || opt > 4){
        std::cout <<"\n Would you like to see the (1) entire book database, (2) search books, (3) delete book, or (4) edit book.";
        std::cin >> opt;
    }

    if (opt == 1){
        displayBooks(bookList);
    }

    if (opt == 2){
        searchBooks(bookList, cart);
    }// if opt = 2

    if (opt == 3){
        std::fstream newFile;
        std::string deletebook;
        newFile.open("booksnew.csv");
        std::cout << "\nEnter the title of the book you want to delete: ";
	    std::getline(std::cin, deletebook);
        if(it->getName() == deletebook){
            for (it = bookList->begin(); it != bookList->end(); it++){
                bookList->erase(it);
            }
        }
        books.close();
        newFile.close();
        remove("bookscsv.csv");
        rename("booksnew.csv", "users.csv");
    }

    if(opt == 4){
        std::fstream newFile;
        std::string editbook;
        newFile.open("booksnew.csv");
        std::cout << "\nEnter the title of the book you want to edit: ";
	    std::getline(std::cin, editbook);
        if(it->getName() == editbook){
            std::cout << "\nPlease enter a new title: ";
            std::cin >> newtitle;
            for (it = bookList->begin(); it != bookList->end(); it++){
                it->setName(newtitle);
            }
        }
        books.close();
        newFile.close();
        remove("bookscsv.csv");
        rename("booksnew.csv", "users.csv");
    }
}

//from milestone 3 - search user
void getUser(){

}
//User functions

// takes username as input
// returns the Name associated with the username
std::string getName(std::list<User>* usersList, std::string username, std::string password,std::list<User>::iterator& v){
    // opening the user csv file
    std::fstream userfile = openFile("users.csv");

    // usersList updated with lines from users.csv
    readUsers(userfile, usersList);

    // usersList is everyone in the csv
    // v is one person
    if (findUser(usersList, v, username, password)){
        // v is now pointing at the user's information
        return v->getName();
    }
    userfile.close();
}

// gets username as input, uses getName() to receive name associated
// udpates the Name
void setName(std::list<User>* usersList, std::string username, std::string password,std::list<User>::iterator& v){
    std::fstream userfile = openFile("users.csv");
    readUsers(userfile, usersList);
    std::fstream newFile;
    newFile.open("usersnew.csv");
    std::string newname, oldname;
    oldname = getName(usersList, username, password, v);

    std::cout << "Current name associated with the username is:" << oldname;
    std::cout << "Please enter a new name: ";
    std::cin >> newname;

    for (v = usersList->begin(); v != usersList->end(); ++v){
        if (v->getUsername() == username && v->getPassword() == password){
            // replacing name in list<user> v
            v->setName(newname);
        }
    }

    writeUsers(newFile, usersList);
    userfile.close();
    newFile.close();
    // removing old csv
    remove("users.csv");
    // renaming the updated file with the existing file name
    rename("usersnew.csv", "users.csv");
}

// returns a print statement with name and username confirming the user is in the users csv
void isRegistered(std::list<User>* usersList, std::list<User>::iterator& v, std::string username, std::string password){
    // opening the user csv file
    std::fstream userfile = openFile("users.csv");

    // usersList updated with lines from users.csv
    readUsers(userfile, usersList);

    // usersList is everyone in the csv
    // v is one person
    if (findUser(usersList, v, username, password)){
        // v is now pointing at the user's information
        std::cout << "User exists in the database. Name:" << v->getName() << "Username: "<< v->getUsername() << "and the state of their registration: " << v->getRegistered();
    }
    userfile.close();
}

bool editUser();
std::string searchInventory();
void addItemToCart();
bool checkout();

//Book functions
void showBooks();
//Book getBooks();
bool checkinBook();
bool checkoutBook();

int getWaitlistNum();


//Order functions
std::list<std::string> totalItems();
void printDetails();
bool cancel();

//Payment functions

bool processPayment();
int computeLateFee();