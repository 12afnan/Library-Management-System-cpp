#pragma once                                

#include <vector>                           
#include <string>                           

using namespace std;                        

#ifndef LIBRARY_H                           
#define LIBRARY_H                           

struct Book                                 
{
    string id{};                            
    string title{};                         
    string author{};                        
    bool issued{};                          
};

class Library                               
{
public:

    vector<Book> books;                     

    Book book;                              
    Library();                              

    void displayBooks();                    

    void insertBook();                      

    void fileToVector();                    

    bool compareBook(const Book& a, const Book& b); 

    int partition(vector<Book>& books, int low, int high); 

    void quickSort(vector<Book>& books, int low, int high); 

    void sortBook();                        

    void showSortedBook();                  

    int binarySearch(string title, int high, int low); 

    int sentinelSearch(string author);      

    void searchBook();                      

    void issueBook();                       

    void returnBook();                      

    void displayIssuedBook();              
};

#endif                   
