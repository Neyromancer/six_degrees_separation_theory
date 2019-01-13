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
  network.CreateAndAddUserToNetwork("Kim", "Ugh");
  network.CreateAndAddUserToNetwork("Tir", "Bauman");
  network.CreateAndAddUserToNetwork("Volfgan", "Argson");
  //network.PrintWholeNetwork();
  //network.AddConnection(1, 3);
  network.AddConnection(1, 4);
  //network.AddConnection(1, 2);
  //network.AddConnection(1, 6);
  network.AddConnection(1, 5);
  network.AddConnection(4, 3);
  network.AddConnection(4, 2);
  network.AddConnection(3, 6);
  network.PrintWholeNetwork();
  std::cout << "===================================" << std::endl;
  //network.PrintConnectionsAtDepth(1, 3);
  //network.PrintAllUserConnections(1);
  //std::cout << "After removing connections: " << std::endl;
  //network.RemoveConnection(1, 3);
  //network.PrintWholeNetwork();
  network.CheckUserInterconnection(1, 6);
  std::cout << "===================================" << std::endl;

  return EXIT_SUCCESS;
}
