/// \file main.cpp

#include <cstdlib>
#include <iostream>

#include "./user/user.h"
#include "six_degrees_separation_theory_config.h"

#define VERSION VERSION_MAJOR

int main(void) {
  const std::string kProjectVersion = std::to_string(VERSION);
  std::cout << "version: " << kProjectVersion << std::endl;
  six_degrees_separation_theory::User user{"Dmitry", "Kormulev"};
  std::cout << "user " << user.GetName() << " with ID " << user.GetId() << " has ";
  if (user.GetConnections().empty())
    std::cout << "no";
  else
    std::cout << user.GetConnections().size();
  std::cout << " connections" << std::endl;

  return EXIT_SUCCESS;
}
