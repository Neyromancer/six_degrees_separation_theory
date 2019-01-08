/// \file user.cpp 
/// \brief Source file for class User.
/// \author Kormulev Dmitry <dmitry.kormulev@yande.ru>
/// \date 08.01.2019

#include "user.h"

namespace six_degrees_separation_theory {

User::User(std::string name, std::string surname) : name_(name),
           surname_(surname), id_(++count_created_users_) {}

void  User::SetName(const std::string &name) {
  name_ = name;
}

void User::SetName(std::string &&name) {
  name_ = name;
}

void User::SetSurname(const std::string &surname) {
  surname_ = surname;
}

void User::SetSurname(std::string &&surname) {
  surname_ = surname;
}

void SetId(uint64_t id) {
  id_ = id;
}

void User::SetConnection(uint64_t id) {
  connections_.insert(id);
}
}  // six_degree_separation_theory
