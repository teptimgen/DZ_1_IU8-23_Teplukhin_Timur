// Copyright 2015 <Timur Teplukhin>
#pragma once

#include "Headers.h"
#include <string>

class RemovalOfTakenException : public exception {
    string errMsg;
 public:
    explicit RemovalOfTakenException(const string&);
    explicit RemovalOfTakenException(int id);
    const char* what() const throw();
};
