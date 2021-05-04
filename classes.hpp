#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <list>

//Book Class
class Book
{
private:
    std::string isbn;
    std::string name;
    std::string author;
    bool checkedOut;
    int waitlist;

public:
    // Default Constructor
    Book() {
        isbn = "";
        name = "";
        author = "";
        checkedOut = false;
        waitlist = 0;
    }
    // Explicit Constructor
    Book(std::string i, std::string n, std::string a) {
        isbn = i;
        name = n;
        author = a;
        checkedOut = false;
        waitlist = 0;
    }

    // Functions
    void displayBook(){
        std::cout<<"\n Book ISBN: " << isbn;
        std::cout<<"\nBook Name: " << name;
        std::cout<<"\nAuthor:" << author;
    }
    bool checkoutBook() {
        checkedOut = true;
        if (checkedOut) return true;
        else return false;
    }
    bool checkinBook() {
        checkedOut = false;
        if (!checkedOut) return true;
        else return false;
    }
};


//User Class
class User 
{
private:
    bool isRegistered;
    std::string name;
    std::string username;
    std::string password;
    std::list<std::string> booksCheckedOut;
    std::list<std::string> cart;
    float feesDue;

public:
    // Default Constructor
    User() {
        isRegistered = false;
        name = "";
        username = "";
        password = "";
        feesDue = 0.0;
    }
    // Explicit Constructor
    User(std::string n, std::string u, std::string p) {
        isRegistered = true;
        name = n;
        username = u;
        password = p;
        feesDue = 0.0;
    }

    // Setters
    // for this I added the other fields because to me it wouldn't make sense if someone was registered unless they had those fields, feel free to change tho however
    void setRegister(std::string n, std::string u, std::string p) {
        isRegistered = true;
        name = n;
        username = u;
        password = p;
    }
    void setName(std::string n) {
        name = n;
    }
    void setUsername(std::string u) {
        username = u;
    }
    void setPassword(std::string p) {
        password = p;
    }
    void setFees(float f) {
        feesDue = f;
    }
    // Getters
    bool getRegistered(void) {
        return isRegistered;
    }
    std::string getName(void) {
        return name;
    }
    std::string getUsername(void) { 
        return username;
    }
    std::string getPassword(void) {
        return password;
    }
    std::list<std::string> * getBooksCheckedOut(void) {
        return &booksCheckedOut;
    }
    std::list<std::string> * getCart(void) {
        return &cart;
    }
    float getFeesDue(void) {
        return feesDue;
    }

    // Functions
   void editUser() { 
       int choice;
       std::string new_name = "";
       std::string confirm_identity = "";

       do {
            std::cout << std::endl << "Edit User\n";
            std::cout << "What do you wish to edit?\n\n";
            std::cout << "1. Name\n2. Username\n3. Password\n4. Return to Main Menu" << std::endl << std::endl;
            std::cin >> choice;

            switch (choice) {
                case 1: // Change Name
                    std::cout << std::endl << "Changing Name" << std::endl;
                    if (confirmIdentity()) {
                        std::cout << "\nIdentity confirmed. Current Name: " << name;
                        std::cout << "\nEnter a new name: ";
                        std::cin >> new_name;
                        setName(new_name);
                        std::cout << "\nUpdated new name: " << name << std::endl;
                    }
                    else {
                        std::cout << "\nIdentity not confirmed. Please try again later." << std::endl << std::endl;
                    }
                    break;
                case 2: // Change Username
                    std::cout << std::endl << "Changing Username" << std::endl;
                    if (confirmIdentity()) {
                        std::cout << "\nIdentity confirmed. Current Username: " << username;
                        std::cout << "\nEnter a new username: ";
                        std::cin >> new_name;
                        setUsername(new_name);
                        std::cout << "\nUpdated new username: " << username << std::endl;
                    }
                    else {
                        std::cout << "\nIdentity not confirmed. Please try again later." << std::endl << std::endl;
                    }
                    break;
                case 3: // Change Password
                    std::cout << std::endl << "Changing Password" << std::endl;
                    if (confirmIdentity()) {
                        std::cout << "\nIdentity confirmed. Enter a new password: ";
                        std::cin >> new_name;
                        setPassword(new_name);
                        std::cout << "\nYou have successfully updated your password." << std::endl;
                    }
                    else {
                        std::cout << "\nIdentity not confirmed. Please try again later." << std::endl << std::endl;
                    }
                    break;
                case 4: // Return to Main Menu
                    std::cout << std::endl << "Returning to Main Menu..." << std::endl;
                    break;
            }
       } while (choice != 4); // while the choice is not to return to Main Menu
   }
   
   bool confirmIdentity() {
       std::string entered_password = "";

       std::cout << "Enter password to confirm identity: ";
       std::cin >> entered_password;

       if (entered_password == password) return true;
       else return false;
   }
   void addItemToCart(std::string i) {
       cart.push_back(i); // adds item i to cart
   }

   void checkout() {
       booksCheckedOut.splice(cart.end(), cart); // I think this will transfer all items from cart into booksCheckedOut
   }

   std::string searchInventory() {
       
   }


};

#endif