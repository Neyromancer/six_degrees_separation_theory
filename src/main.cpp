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
  //std::cout << "print by name: " << std::endl;
  //std::cout << "Simon:" << std::endl; 
  //network.PrintUserByName("Simon");
  //std::cout << "Peter:" << std::endl; 
  //network.PrintUserByName("Peter");
  //std::cout << "===================================" << std::endl;
  //std::cout << "print by surname: " << std::endl;
  //std::cout << "Simon:" << std::endl; 
  //network.PrintUserBySurname("Vorlamov");
  //std::cout << "Peter:" << std::endl; 
  //network.PrintUserBySurname("Peterson");
  //std::cout << "===================================" << std::endl;  
  //std::cout << "print by id: " << std::endl;
  //std::cout << "0:" << std::endl; 
  //network.PrintUserById(0);
  //std::cout << "1:" << std::endl; 
  //network.PrintUserById(1);
  //std::cout << "===================================" << std::endl;
  //std::cout << "remove user by surname: " << std::endl;
  //network.RemoveUserBySurname("Peterson");
  //std::cout << "===================================" << std::endl;
  //std::cout << "After adding connections: " << std::endl;
  //network.AddConnection(1, 3);
  //network.PrintWholeNetwork();
  //std::cout << "===================================" << std::endl;
  //network.PrintConnectionsAtDepth(1, 3);
  //std::cout << "After removing connections: " << std::endl;
  //network.RemoveConnection(1, 3);
  //network.PrintWholeNetwork();
  //std::cout << "===================================" << std::endl;

  return EXIT_SUCCESS;
}
