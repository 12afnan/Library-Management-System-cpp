# Library Management System
## About
A library management system built in C++ with the implementation of a data structure and algorithm for a university project.

## Data Structure and Algorithm implemented
1) Binary Search
2) Sentinel Search
3) Quick Sort

## Description
1) This project applies 3 different C++ files which are
   - Library.h (functions declaration)
   - Library.cpp (functions definition)
   - Main.cpp (Main function)
   
2) This program utilizes the fstream class to handle file input/output for storing book data. Update the file path in the Library.cpp source file for the insertBook, displayBooks, and fileToVector functions.
3) Since it was hard to implement DSA on the book's data in the file, I copied the data and placed it into the vector created.
4) Binary Search algorithm searches books by title, Sentinel Search by author. Quick Sort facilitates Binary Search.
5) Enter the desired ID, title ( _ for spaces), and author ( _ for spaces) for book insertion. The Book ID is a unique identifier that is utilized for both issuing and returning books.

## databook.txt
- Book ID
- Book's title
- Book's author
