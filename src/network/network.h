/// \file network.h
/// \brief Class which represents user's network.
/// \author Dmitry Kormulev.
/// \version 1.0.0.0
/// \date 09.01.2019

#ifndef SIX_DEGREES_SEPARATION_THEORY_NETWORK_NETWORK_H_
#define SIX_DEGREES_SEPARATION_THEORY_NETWORK_NETWORK_H_

#include <cstdint>
#include <list>
#include <iostream>
#include <set>
#include <string>

#include "../user/user.h"

/// \namespace six_degrees_separation_theory.
/// \brief Project six degrees separation theory namespace.
namespace six_degrees_separation_theory {

/// \class Network network.h.
class Network {
 public:
  /// \brief Network class constructor.
  explicit Network() {}

  /// \brief Network class destructor.
  ~Network() = default;

  /// \brief Network class copy constructor.
  /// \param[in] network Network class object.
  Network(const Network &network) = delete;

  /// \brief Network class move constructor.
  /// \param[in] network Network class object.
  Network(Network &&network) = default;

  /// \brief Network class copy assignment operator.
  /// \param[in] network Network class object.
  /// \return Network class object.
  Network &operator=(const Network &network) = delete;

  /// \brief Network class move assignment operator.
  /// \param[in] network Network class object.
  /// \return Network class object.
  Network &operator=(Network &&network) = default;

  /// \brief Add user to the network.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  void CreateAndAddUserToNetwork(const std::string &name, 
                                 const std::string &surname);
  void CreateAndAddUserToNetwork(std::string &&name,
                                 std::string &&surname);

  /// \brief Find the user by his/her id and change his/her name and surname.
  /// \param[in] id ID.
  /// \param[in] connection_id ID.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  void SetUserById(const uint64_t id, const uint64_t connection_id,
                   const std::string &name, const std::string &surname);

  /// \brief Get user by his/her id.
  /// \param[in] id ID.
  /// \return Object of class User.
  User GetUserById(const uint64_t id) const noexcept;

  /// \brief Check if id exist.
  /// \param[in] id.
  /// \return Result of checking id existence.
  bool IsIdExist(const uint64_t id) const noexcept;

  /// \brief Check if user exist.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  /// \return Result of checking user existence.
  bool IsUserExist(const std::string &name, const std::string &surname) const noexcept;
  bool IsUserExist(std::string &&name, std::string &&surname) const noexcept;

  /// \brief Remove user by id.
  /// \param[in] id ID.
  void RemoveUserById(const uint64_t id);

  /// \brief Remove all users with passed name.
  /// \param[in] name Name.
  void RemoveUserByName(const std::string &name);
  void RemoveUserByName(std::string &&name);

  /// \brief Remove all users with passed surname.
  /// \param[in] surname Surname.
  void RemoveUserBySurname(const std::string &surname);
  void RemoveUserBySurname(std::string &&surname);

  /// \brief Print users from network.
  inline void PrintWholeNetwork() const noexcept {
    for (const auto &u : network_)
      std::cout << u << std::endl;
  }

  /// \brief Print user with passed id.
  /// \param[in] id ID.
  void PrintUserById(const uint64_t id) const noexcept;

  /// \brief Print all users with passed name.
  /// \param[in] name Name.
  void PrintUserByName(const std::string &name) const noexcept;
  void PrintUserByName(std::string &&name) const noexcept;

  /// \brief Print all users with passed surname.
  /// \param[in] surname Surname.
  void PrintUserBySurname(const std::string &surname) const noexcept;
  void PrintUserBySurname(std::string &&surname) const noexcept;

  /// \brief Print user's connection at a particular depth.
  /// \param[in] id ID.
  /// \param[in] depth Network connection depth.
  void PrintConnectionsAtDepth(const uint64_t id, const uint64_t depth);

  /// \brief Print all user's connections.
  /// \param[in] id ID.
  void PrintAllUserConnections(const uint64_t id);

  /// \brief Add direct connection between 2 users represented by their ids.
  /// \param[in] id1 1st user id.
  /// \param[in] id2 2nd user id.
  void AddConnection(const uint64_t id1, const uint64_t id2);

  /// \brief Remove direct connection between 2 users represented by their ids.
  /// \param[in] id1 1st user id.
  /// \param[in] id2 2nd user id.
  void RemoveConnection(const uint64_t id1, const uint64_t id2);

  /// \brief Check user mutual connection.
  /// \param[in] id1 ID.
  /// \param[in] id2 ID.
  /// \return Result of the check.
  bool CheckUserInterconnection(const uint64_t id1, const uint64_t id2) const noexcept;

 private:
  /// \brief Remove direct connnection from user set by his/her id.
  /// \param[in] id ID.
  /// \param[in] connection_id ID.
  void RemoveConnectionById(const uint64_t id, const uint64_t connection_id);

  /// \brief Recall used id.
  /// \param[in] id ID.
  void RecallId(const uint64_t id);

  /// \brief Check if id have been used.
  /// \param[in] id ID.
  /// \return Resutl of the check if ID used.
  bool IsIdUsed(const uint64_t id) const noexcept;

  std::list<User> network_{};
  std::set<uint64_t> used_id_{};
};
}  // namespace six_degrees_separation_theory.

#endif // SIX_DEGREES_SEPARATION_THEORY_NETWORK_NETWORK_H_

