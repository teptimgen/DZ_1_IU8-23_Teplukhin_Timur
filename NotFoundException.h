// Copyright 2015 <Timur Teplukhin>
#pragma once

#include "Headers.h"
#include <string>

class NotFoundException : public exception {
    string errMsg;
 public:
    explicit NotFoundException(const string&);
    explicit NotFoundException(int id);
    const char* what() const throw();
};
