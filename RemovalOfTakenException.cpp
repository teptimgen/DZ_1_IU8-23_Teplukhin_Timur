// Copyright 2015 <Timur Teplukhin>

#include "RemovalOfTakenException.h"
#include <string>

using std::to_string;

RemovalOfTakenException::RemovalOfTakenException(const string& title) :
        exception() {
    errMsg = "Cannot remove a taken book (title '" + title + "')";
}

RemovalOfTakenException::RemovalOfTakenException(int id) : exception() {
    errMsg = "Cannot remove a taken book (id " + to_string(id) + ")";
}

const char* RemovalOfTakenException::what() const {
    return errMsg.c_str();
}

