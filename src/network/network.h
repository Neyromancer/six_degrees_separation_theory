/// \file network.h
/// \brief Class which represents user's network.
/// \author Dmitry Kormulev.
/// \version 1.0.0.0
/// \date 09.01.2019

#ifndef SIX_DEGREES_SEPARATION_THEORY_NETWORK_NETWORK_H_
#define SIX_DEGREES_SEPARATION_THEORY_NETWORK_NETWORK_H_

#include <cstdint>
#include <string>
#include <list>

#include "../user/user.h"

/// \namespace six_degrees_separation_theory.
/// \brief Project six degrees separation theory namespace.
namespace six_degrees_separation_theory {

/// \class Network network.h.
class Network {
 public:
  /// \brief Network class constructor.
  explicit Network();

  /// \brief Network class destructor.
  ~Network() = default;

  /// \brief Network class copy constructor.
  /// \param[in] network Network class object.
  Netwok(const Network &network) = delete;

  /// \brief Network class move constructor.
  /// \param[in] network Network class object.
  Network(Network &&network) = default;

  /// \brief Network class copy assignment operator.
  /// \param[in] network Network class object.
  /// \return Network class object.
  Network &operator(const Network &network) = delete;

  /// \brief Network class move assignment operator.
  /// \param[in] network Network class object.
  /// \return Network class object.
  Network &operator(Network &&network) = default;

  /// \brief Add user to the network.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  void CreateAndAddUserToNetwork(const std::string &name, 
                                 const std::string &surname);
  void CreateAndAddUserToNetwork(std::string &&name,
                                 std::string &&surname);

  /// \brief Return user by his/her id.
  /// \param[in] id ID.
  /// \return Object of class User.
  User &GetUserById(uint64_t id);

  /// \brief Remove user by id.
  /// \param[in] id ID.
  void RemoveUserById(uint64_t id);

  /// \brief Remove all users with passed name.
  /// \param[in] name Name.
  void RemoveUserByName(const std::string &name);
  void RemoveUserByName(std::string &&name);

  /// \brief Remove all users with passed surname.
  /// \param[in] surname Surname.
  void RemoveUserBySurname(const std::string &surname);
  void RemoveUserBySurname(std::string &&surname);

  /// \brief Print users from network.
  void PrintWholeNetwork() const noexcept;

  /// \brief Print user with passed id.
  /// \param[in] id ID.
  void PrintUserById(uint64_t id) const noexcept;

  /// \brief Print all users with passed name.
  /// \param[in] name Name.
  void PrintUserByName(const std::string &name) const noexcept;
  void PrintUserByName(std::string &&name) const noexcept;

  /// \brief Print all users with passed surname.
  /// \brief[in] surname Surname.
  void PrintUserBySurname(const std::string &surname) const noexcept;
  void PrintUserBySurname(std::string &&surname) const noexcept;

 private:
  std::list<User> network_{}; 
};
}  // namespace six_degrees_separation_theory.

#endif // SIX_DEGREES_SEPARATION_THEORY_NETWORK_NETWORK_H_

