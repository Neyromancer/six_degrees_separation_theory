/// \file network.cpp
/// \brief Source file for class Networ.
/// \author Dmitry Kormulev.
/// \version 1.0.0.1
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

void Network::SetUserById(const uint64_t id, const uint64_t connection_id = 0, 
                          const std::string &name = {}, 
                          const std::string &surname = {}) {
  for (auto &u : network_) {
    if (u.GetId() == id) {
      if (!name.empty() && !surname.empty())
        u.SetNameAndSurname(name, surname);
      if (connection_id)
        u.SetConnection(connection_id);
    } // else throw if user not found.
  } 
}

User Network::GetUserById(const uint64_t id) const noexcept {
  User user;
  for (const auto &u : network_)
    if (u.GetId() == id)
      user = u;
  return user; 
}

bool Network::IsIdExist(const uint64_t id) const noexcept {
  auto is_exist = false;
  for (const auto &u : network_)
    if (u.GetId() == id)
      is_exist = true;
  return is_exist;
}

bool Network::IsUserExist(const std::string &name, 
                          const std::string &surname) const noexcept {
  auto is_exist = false;
  auto is_name = false;
  auto is_surname = false;
  for (const auto &u : network_) {
    if (u.GetName() == name)
      is_name = true;
    else
      is_surname = false;

    if (u.GetSurname() == surname)
      is_surname = true;
    else
      is_name = false;

    if (is_surname && is_name)
      is_exist = true;
  }
  return is_exist;
}

bool Network::IsUserExist(std::string &&name, 
                          std::string &&surname) const noexcept {
  auto is_exist = false;
  auto is_name = false;
  auto is_surname = false;
  for (const auto &u : network_) {
    if (u.GetName() == name)
      is_name = true;
    else
      is_surname = false;

    if (u.GetSurname() == surname)
      is_surname = true;
    else
      is_name = false;

    if (is_surname && is_name)
      is_exist = true;
  }
  return is_exist;
}

void Network::RemoveUserById(const uint64_t id) {
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

void Network::PrintUserById(const uint64_t id) const noexcept {
  for (const auto &u : network_)
    if (u.GetId() == id)
      std::cout << u;
}

void Network::PrintUserByName(const std::string &name) const noexcept {
  for (const auto &u : network_)
    if (u.GetName() == name)
      std::cout << u;
}

void Network::PrintUserByName(std::string &&name) const noexcept {
  for (const auto &u : network_)
    if (u.GetName() == name)
      std::cout << u;
}

void Network::PrintUserBySurname(const std::string &surname) const noexcept { 
  for (const auto &u : network_)
    if (u.GetSurname() == surname)
      std::cout << u;
}

void Network::PrintUserBySurname(std::string &&surname) const noexcept{
  for (const auto &u : network_)
    if (u.GetSurname() == surname)
      std::cout << u;
}

void Network::PrintConnectionsAtDepth(const uint64_t id, const uint64_t depth) {
  RecallId(id);
  if (IsIdExist(id)) { 
    auto d = depth;
    User user = GetUserById(id);
    if (!user.GetNumberOfConnections())
      return;

    if (d > 0) {
      for (const auto &tmp_id : user.GetConnections())
        if (!IsIdUsed(tmp_id))
          PrintConnectionsAtDepth(tmp_id, d - 1);
    } else {
      for (const auto &tmp_id : user.GetConnections()) {
          PrintUserById(tmp_id);
          std::cout << "\n======================" << std::endl;
      }
      return;
    }
  }

  if (!used_id_.empty())
    used_id_.clear();
}

void Network::PrintAllUserConnections(const uint64_t id) {
  static uint64_t connection_depth_level = 1;
  RecallId(id);
  User user = GetUserById(id);
  if (user.GetNumberOfConnections() > 1) {
    for (const auto &tmp_id : user.GetConnections()) {
      if (!IsIdUsed(tmp_id)) {
        PrintUserById(tmp_id);
        std::cout << "\nconnection level is " << connection_depth_level 
                  << std::endl;
      }
    }

    ++connection_depth_level;
    for (const auto &tmp_id : user.GetConnections())
      if (!IsIdUsed(tmp_id))
        PrintAllUserConnections(tmp_id);

    if (!used_id_.empty())
      used_id_.clear();
  } else {
    return;
  }
}

void Network::AddConnection(const uint64_t id1, const uint64_t id2) {
  //if (id1 == id2)
  //  throw error here
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

bool Network::AreUsersConnected(const uint64_t id1, const uint64_t id2) {
  // if (id1 == id2)
  //   throw error here
  RecallId(id1);
  static bool is_connected {false};
  User user = GetUserById(id1);
  if (user.GetNumberOfConnections() > 1) {
    for (const auto &tmp_id : user.GetConnections())
      if (id2 == tmp_id)
        is_connected = true;

    for (const auto &tmp_id : user.GetConnections()) {
      if (!IsIdUsed(tmp_id))
        AreUsersConnected(tmp_id, id2);
    }
  }

  return is_connected;
}

void Network::RecallId(const uint64_t id) {
  used_id_.insert(id);
}

bool Network::IsIdUsed(const uint64_t id) const noexcept {
  return (!used_id_.empty() && used_id_.find(id) != used_id_.end());
}

}
