/// \file main.cpp

#include <cstdlib>
#include <iostream>

#include "./user/user.h"
#include "./network/network.h"
#include "six_degrees_separation_theory_config.h"

#define VERSION VERSION_MAJOR

int main(void) {
  const std::string kProjectVersion = std::to_string(VERSION);
  std::cout << "version: " << kProjectVersion << std::endl;
  six_degrees_separation_theory::Network network;
  network.CreateAndAddUserToNetwork("Simon", "Vorlamov");
  network.CreateAndAddUserToNetwork("Simon", "Vorlamov");
  network.CreateAndAddUserToNetwork("Peter", "Peterson");
  network.PrintWholeNetwork();

  return EXIT_SUCCESS;
}
