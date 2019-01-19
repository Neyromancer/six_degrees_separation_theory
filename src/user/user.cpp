/// \file user.cpp 
/// \brief Source file for class User.
/// \author Kormulev Dmitry <dmitry.kormulev@yande.ru>
/// \version 1.0.0.3
/// \date 19.01.2019

#include "user.h"

#include <cstdint>

namespace six_degrees_separation_theory {

uint64_t User::counter_{0};

User::User() : name_{}, surname_{} {}

User::User(std::string name, std::string surname) : name_(name),
           surname_(surname) {
  // static uint64_t count_created_users{0};
  // check for type overflow
  SetId();
}

std::ostream &operator<<(std::ostream &out, const User &user) {
  return out << "user id: " << user.GetId() << std::endl
             << "user name: " << user.name_ << std::endl
             << "user surname: " << user.surname_ << std::endl
             << "user connections: " << user.GetNumberOfConnections();
}

void User::SetNameAndSurname(const std::string &name, 
                             const std::string &surname) {
  name_ = name;
  surname_ = surname;
  if (!id_)
    SetId();
}

void User::SetNameAndSurname(std::string &&name, std::string &&surname) {
  name_ = name;
  surname_ = surname;

  if (!id_)
    SetId();
}

User::~User() {
  counter_ = (counter_ >= 1) ? --counter_ : 0;
}

inline void User::SetId(/*const uint64_t id*/) {
  counter_ = (counter_ < UINT64_MAX) ? ++counter_ : 0;
  id_ = counter_;
}

void User::SetConnection(const uint64_t id) {
  if (id_ != id)
    connections_.insert(id);
}

void User::RemoveConnection(const uint64_t id) {
  if (!connections_.empty())
    connections_.erase(id);
}

}  // six_degree_separation_theory
