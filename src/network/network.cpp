/// \file network.cpp
/// \brief Source file for class Networ.
/// \author Dmitry Kormulev.
/// \version 1.0.0.1.
/// \date 10.01.2019

#include "network.h"

#include <algorithm>
#include <iostream>

namespace six_degrees_separation_theory {
void Network::CreateAndAddUserToNetwork(const std::string &name,
                                        const std::string &surname) {
  /// \add name and surname validation before user creation.
  User user{name, surname};
  network_.push_back(user);
}

void Network::CreateAndAddUserToNetwork(std::string &&name,
                                        std::string &&surname) {
  /// \add name and surname validation before user creation.
  User user{name, surname};
  network_.push_back(user);
}

void Network::SetUserById(uint64_t id, const std::string &name, 
                          const std::string &surname) {
  for (auto &u : network_) {
    if (u.GetId() == id) {
      u.SetName(name);
      u.SetSurname(surname);
    } // else throw that user not found.
  } 
}

void Network::SetUserById(uint64_t id, std::string &&name, 
                          std::string &&surname) {
  for (auto &u : network_) {
    if (u.GetId() == id) {
      u.SetName(name);
      u.SetSurname(surname);
    } // else throw that user not found.
  } 
}

void Network::RemoveUserById(uint64_t id) {
  for (const auto &u : network_)
    if (u.GetId() == id)
      // network_.remove(u);
      std::cout << "Value found and ready to be removed." << std::endl;
}

void Network::RemoveUserByName(const std::string &name) {
  for (const auto &u : network_)
    if (u.GetName() == name)
      std::cout << "Value found and ready to be removed." << std::endl;
      //network_.remove(u);
}

void Network::RemoveUserByName(std::string &&name) {
  for (const auto &u : network_)
    if (u.GetName() == name)
      std::cout << "Value found and ready to be removed." << std::endl;
      //network_.remove(u);
}

void Network::RemoveUserBySurname(const std::string &surname) {
  for (const auto &u : network_)
    if (u.GetSurname() == surname)
      std::cout << "Value found and ready to be removed." << std::endl;
      //network_.remove(u);
}

void Network::RemoveUserBySurname(std::string &&surname) {
  auto tmp = network_.front();
  for (const auto &u : network_)
    if (u.GetSurname() == surname)
      tmp = u;
      //std::cout << "Value found and ready to be removed." << std::endl;
    std::cout << "user: " << tmp.GetSurname() << std::endl;
    network_.remove(tmp);
}

//void Network::PrintWholeNetwork() const noexcept {
//  for (const auto &u : network_) {
//    std::cout << "user id: " << u.GetId() << std::endl;
//    std::cout << "user name: " << u.GetName() << std::endl;
//    std::cout << "user surname: " << u.GetSurname() << std::endl;
//    std::cout << "user connections: " << u.GetNumberOfConnections() << std::endl;
//  }
//}

void Network::PrintUserById(uint64_t id) const noexcept {
  for (const auto &u : network_) {
    if (u.GetId() == id) {
      std::cout << "user id: " << u.GetId() << std::endl;
      std::cout << "user name: " << u.GetName() << std::endl;
      std::cout << "user surname: " << u.GetSurname() << std::endl;
      std::cout << "user connections: " << u.GetNumberOfConnections() 
                << std::endl;
    }
  }
}

void Network::PrintUserByName(const std::string &name) const noexcept {
  for (const auto &u : network_) {
    if (u.GetName() == name) {
      std::cout << "user id: " << u.GetId() << std::endl;
      std::cout << "user name: " << u.GetName() << std::endl;
      std::cout << "user surname: " << u.GetSurname() << std::endl;
      std::cout << "user connections: " << u.GetNumberOfConnections() 
                << std::endl;     
    }
  }
}

void Network::PrintUserByName(std::string &&name) const noexcept {
  for (const auto &u : network_) {
    if (u.GetName() == name) {
      std::cout << "user id: " << u.GetId() << std::endl;
      std::cout << "user name: " << u.GetName() << std::endl;
      std::cout << "user surname: " << u.GetSurname() << std::endl;
      std::cout << "user connections: " << u.GetNumberOfConnections() 
                << std::endl;     
    }
  }
}

void Network::PrintUserBySurname(const std::string &surname) const noexcept { 
  for (const auto &u : network_) {
    if (u.GetSurname() == surname) {
      std::cout << "user id: " << u.GetId() << std::endl;
      std::cout << "user name: " << u.GetName() << std::endl;
      std::cout << "user surname: " << u.GetSurname() << std::endl;
      std::cout << "user connections: " << u.GetNumberOfConnections() 
                << std::endl;     
    }
  }
}

void Network::PrintUserBySurname(std::string &&surname) const noexcept{
  for (const auto &u : network_) {
    if (u.GetSurname() == surname) {
      std::cout << "user id: " << u.GetId() << std::endl;
      std::cout << "user name: " << u.GetName() << std::endl;
      std::cout << "user surname: " << u.GetSurname() << std::endl;
      std::cout << "user connections: " << u.GetNumberOfConnections() 
                << std::endl;     
    }
  }
}

}
