// Copyright 2015 <Timur Teplukhin>
#include "Book.h"
#include <string>
#include <list>

Book::Book() {
    id = 0;
    title = "\0";
    authors = "\0";
    pages = 0;
    checkOut = FALSE;
}

Book::Book(const Book& book) {
    id = book.id;
    title = book.title;
    authors = book.authors;
    pages = book.pages;
    checkOut = book.checkOut;
}

Book::Book(const string& title, const string& authors,
        int pages, byte checkOut) {
    id = 0;
    this->title = title;
    this->authors = authors;
    this->pages = pages;
    this->checkOut = checkOut;
}

Book::~Book() {
    id = 0;
    title = "\0";
    authors = "\0";
    pages = 0;
    checkOut = FALSE;
}

void Book::SetId(int id) {
    this->id = id;
}

int Book::GetId() const {
    return id;
}

void Book::SetTitle(const string& title) {
    this->title = title;
}

const string& Book::GetTitle() const {
    return title;
}

void Book::SetAuthors(const string& authors) {
    this->authors = authors;
}

const string& Book::GetAuthors() const {
    return authors;
}

void Book::SetPages(int pages) {
    this->pages = pages;
}

int Book::GetPages() const {
    return pages;
}

void Book::SetCheckOut(byte checkOut) {
    this->checkOut = checkOut;
}

byte Book::GetCheckOut() const {
    return checkOut;
}

ostream& operator<<(ostream& os, const Book& book) {
    os << "id:............." << book.id << endl;
    os << "Title:.........." << book.title.c_str() << endl;
    os << "Authors:........" << book.authors.c_str() << endl;
    os << "Pages:.........." << book.pages << endl;
    os << "Status:........." << ((book.checkOut) ?
        "Taken" : "Available") << endl;
    return os;
}

const Book& Book::operator=(const Book& book) {
    if (this != &book) {
        id = book.id;
        title = book.title;
        authors = book.authors;
        pages = book.pages;
        checkOut = book.checkOut;
    }
    return *this;
}

bool operator==(const Book& bookOne, const Book& bookTwo) {
    return bookOne.id == bookTwo.id;
}
