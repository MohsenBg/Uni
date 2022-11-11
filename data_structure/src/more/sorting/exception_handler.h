#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#include <exception>
#include <iostream>
using namespace std;

class Excpetion : public exception {
private:
  string message = "";

public:
  Excpetion(const string &exception_message = "") {
    message = exception_message;
  }

  const char *what() const noexcept override { return message.c_str(); }
};
#endif
