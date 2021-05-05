#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "classes.hpp"
#include <fstream>
#include <iterator>

std::fstream openFile(std::string filename);
void readUsers(std::fstream file, std::list<User> * usersList);
bool findUser(std::list<User> * usersList, std::list<User>::iterator & v, std::string username, std::string password);
void writeUsers(std::fstream file, std::list<User> * usersList);

#endif