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
void readUsers(std::fstream file, std::list<User> * usersList) {
    std::string readline = "";
    User tempUser; tempUser.setRegister();

    while (!file.eof()) {
        while (std::getline(file,readline,',')) {
            tempUser.setName(readline);
            std::getline(file,readline,',');
            tempUser.setUsername(readline);
            std::getline(file,readline,',');
            tempUser.setPassword(readline);
            std::getline(file,readline,',');
            tempUser.setFeesDue(stof(readline));
            usersList->push_back(tempUser);
        }
    }

    file.close();
}

// writes all current users in the list to users.csv
void writeUsers(std::fstream file, std::list<User> * usersList) {
    for(std::list<User>::iterator v = usersList->begin(); v != usersList->end(); ++v) {
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
bool findUser(std::list<User> * usersList, std::list<User>::iterator & v, std::string username, std::string password) {
    for (v = usersList->begin(); v != usersList->end(); ++v) {
        if (v->getUsername() == username && v->getPassword() == password) return true;
    }
    // if no user is found
    return false;
}

//Admin functions
void getUser();
void getBooks();

//User functions
std::string getName();
void setName();
void isRegistered();
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
