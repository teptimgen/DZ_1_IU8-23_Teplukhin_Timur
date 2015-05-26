// Copyright 2015 <Timur Teplukhin>
#pragma once

#include "Exceptions.h"
#include <string>
#include <list>

class Book {
    int id;
    string title;
    string authors;
    int pages;
    bool checkOut;

 public:
    Book();
    Book(const Book&);
    Book(const string&, const string&, int, bool);
    ~Book();

    void SetId(int id);
    int GetId() const;

    void SetTitle(const string&);
    const string& GetTitle() const;

    void SetAuthors(const string&);
    const string& GetAuthors() const;

    void SetPages(int pages);
    int GetPages() const;

    void SetCheckOut(bool checkOut);
    bool GetCheckOut() const;

    friend ostream& operator<<(ostream&, const Book&);
    const Book& operator=(const Book&);
    friend bool operator==(const Book&, const Book&);
};

