#include <iostream>

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
        cout<<"\n Book ISBN: " << isbn;
        cout<<"\nBook Name: " << name;
        cout<<"\nAuthor:" << author;
    }
    bool checkoutBook() {
        checkedOut = true;
    }
    bool checkinBook() {
        checkedOut = false;
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
    void setPassword(std::stringn p) {
        password = p;
    }
    void setFees(float f) {
        feesDue = f;
    }
    // Getters
    bool isRegistered(void) {
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

    // Functions
   void editUser() { 
       new_name = "";
       new_user = "";
       cout << "\n Name: " << name;
       cout << "\n Enter a new name: ";
       cin >> new_name;
       setName(new_name);
       cout << "\n Updated new name: " << name;
       cout << "\n Username: "<< username;
       cin >> new_user;
       setUsername(new_user);
       cout << "\n Updated new username: " << username;
   }
   
   void addItemToCart(std::string i) {
       cart.push_back(i); // adds item i to cart
   }

   void checkout() {
       booksCheckedOut.splice(cart.end(), cart) // I think this will transfer all items from cart into booksCheckedOut
   }

   std::string searchInventory() {

   }


}