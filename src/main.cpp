/// \file main.cpp

#include <cstdlib>
#include <iostream>

#include "./user/user.h"

int main(void) {

  six_degrees_separation_theory::User user{"Dmitry", "Kormulev", 1};
  if (user.GetConnections().empty())
    std::cout << "user " << user.GetName() << " has no connections." 
              << std::endl;

  return EXIT_SUCCESS;
}
