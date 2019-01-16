/// \file user.cpp 
/// \brief Source file for class User.
/// \author Kormulev Dmitry <dmitry.kormulev@yande.ru>
/// \version 1.0.0.0
/// \date 08.01.2019

#include "user.h"

namespace six_degrees_separation_theory {

User::User() : name_{}, surname_{} {}

User::User(std::string name, std::string surname) : name_(name),
           surname_(surname) {
  SetId();
}

std::ostream &operator<<(std::ostream &out, const User &user) {
  return out << "user id: " << user.id_ << std::endl
             << "user name: " << user.name_ << std::endl
             << "user surname: " << user.surname_ << std::endl
             << "user connections: " << user.GetNumberOfConnections();
}

void User::SetNameAndSurname(const std::string &name, 
                             const std::string &surname) {
  name_ = name;
  surname_ = surname;

  SetId();
}

void User::SetNameAndSurname(std::string &&name, std::string &&surname) {
  // validate name and surname
  name_ = name;
  surname_ = surname;

  SetId();
}

void User::SetId() {
  static uint64_t count_created_users{0};
  // check for type overflow
  id_ = ++count_created_users;
}

void User::SetConnection(const uint64_t id) {
  connections_.insert(id);
}

void User::RemoveConnection(const uint64_t id) {
  if (!connections_.empty())
    connections_.erase(id);
}

}  // six_degree_separation_theory
