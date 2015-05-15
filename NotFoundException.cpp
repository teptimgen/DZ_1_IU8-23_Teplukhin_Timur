// Copyright 2015 <Timur Teplukhin>

#include "NotFoundException.h"
#include <string>

using std::to_string;

NotFoundException::NotFoundException(const string& title) : exception() {
    errMsg = "Cannot find the book (title '" + title + "')";
}

NotFoundException::NotFoundException(int id) : exception() {
    errMsg = "Cannot find the book (id " + to_string(id) + ")";
}

const char* NotFoundException::what() const {
    return errMsg.c_str();
}

