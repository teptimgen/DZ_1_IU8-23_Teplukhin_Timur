// Copyright 2015 <Timur Teplukhin>
#pragma once

#include "Book.h"
#include <string>
#include <list>

class Library : private std::list <Book> {
    string name;
    string type;
    int countCheckedOut;
    int maxId;

 public:
    Library();
    Library(const string&, const string&);
    ~Library();

    void SetName(const string&);
    const string& GetName() const;

    void SetType(const string&);
    const string& GetType() const;

    void SetCountCheckedOut(int countCheckedOut);
    int GetCountCheckedOut() const;

    int Has(const Book&) const;

    int Library::GetSize() const;

    void AddBook(Book);
    void RemoveBook(int id);
    void RemoveBook(const Book&);
    const Book& GetBook(int id) const;
    void TakeBook(int id);
    void PassBook(int id);
    void PrintBook(int id);

    void PrintLibrary();

    friend ostream& operator<<(ostream&, const Library&);
    Library& operator+=(const Book&);
};

