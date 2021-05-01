#include "classes.hpp"

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
