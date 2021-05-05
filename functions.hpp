#pragma once

#include "classes.hpp"
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <limits>


std::fstream openFile(std::string filename);
void readUsers(std::fstream file, std::list<User>* usersList);
bool findUser(std::list<User>* usersList, std::list<User>::iterator& v, std::string username, std::string password);
void writeUsers(std::fstream file, std::list<User>* usersList);
void readBooks(std::fstream file, std::list<Book>* booksList);
void displayBooks(std::list<Book>* bookList);
void bookActions(std::list<Book>* bookList, std::list<Book>* cart);
void searchBooks(std::list<Book>* bookList, std::list<Book>* cart);
void selectBook(std::list<Book>* bookList, std::list<Book>* cart);
void checkOutCart(std::list<Book>* cart, std::list<Book>* bookList);
void deleteBooks(std::list<Book>* cart);
void storeBooks(std::list<Book>* bookList);