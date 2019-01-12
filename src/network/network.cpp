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

void Network::SetUserById(uint64_t id, const uint64_t connection_id = 0, 
                          const std::string &name = {}, 
                          const std::string &surname = {}) {
  for (auto &u : network_) {
    if (u.GetId() == id) {
      if (!name.empty())
        u.SetName(name);
      if (!surname.empty())
        u.SetSurname(surname);
      if (connection_id)
        u.SetConnection(connection_id);
    } // else throw if user not found.
  } 
}

void Network::RemoveUserById(uint64_t id) {
  auto tmp = network_.front();
  for (const auto &u : network_)
    if (u.GetId() == id)
      tmp = u;
    network_.remove(tmp);

}

void Network::RemoveUserByName(const std::string &name) {
  auto tmp = network_.front();
  for (const auto &u : network_)
    if (u.GetName() == name)
      tmp = u;
    network_.remove(tmp);
}

void Network::RemoveUserByName(std::string &&name) {
  auto tmp = network_.front();
  for (const auto &u : network_)
    if (u.GetName() == name)
      tmp = u;
    network_.remove(tmp);
}

void Network::RemoveUserBySurname(const std::string &surname) {
  auto tmp = network_.front();
  for (const auto &u : network_)
    if (u.GetSurname() == surname)
      tmp = u;
    network_.remove(tmp);
}

void Network::RemoveUserBySurname(std::string &&surname) {
  auto tmp = network_.front();
  for (const auto &u : network_)
    if (u.GetSurname() == surname)
      tmp = u;
    network_.remove(tmp);
}

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

void Network::AddConnection(const uint64_t id1, const uint64_t id2) {
  auto is_u1_fnd = false;
  auto is_u2_fnd = false;
  for (const auto &u : network_) {
    if (!is_u1_fnd && u.GetId() == id1)
      is_u1_fnd = true;

    if (!is_u2_fnd && u.GetId() == id2)
      is_u2_fnd = true;
  }

  if (is_u1_fnd && is_u2_fnd) {
    SetUserById(id1, id2);
    SetUserById(id2, id1);
  }
}

void Network::RemoveConnection(const uint64_t id1, const uint64_t id2) {
  auto is_u1_fnd = false;
  auto is_u2_fnd = false;
  for (const auto &u : network_) {
    if (!is_u1_fnd && u.GetId() == id1)
      is_u1_fnd = true;

    if (!is_u2_fnd && u.GetId() == id2)
      is_u2_fnd = true;
  }

  if (is_u1_fnd && is_u2_fnd) {
    RemoveConnectionById(id1, id2);
    RemoveConnectionById(id2, id1);
  }
}

void Network::RemoveConnectionById(const uint64_t id, 
                                   const uint64_t connection_id) {
  for (auto &u : network_)
    if (u.GetId() == id)
      u.RemoveConnection(connection_id);
}

}
