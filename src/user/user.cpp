/// \file user.cpp 
/// \brief Source file for class User.
/// \author Kormulev Dmitry <dmitry.kormulev@yande.ru>
/// \date 08.01.2019

namespace six_degree_separation_theory {

#include "user.h"

User::User(std::string name, std::string surname, uint64_t id) : name_(name),
           surname_(surname), id_(id) {}

void User::SetConnection(uint64_t id) {
  connections_.insert(id);
}
}  // six_degree_separation_theory
