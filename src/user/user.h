/// \file user.h
/// \brief Class which represents user.
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \version 1.0.0.0
/// \date 08.01.2019

#ifndef SIX_DEGREES_SEPARATION_THEORY_USER_USER_H_
#define SIX_DEGREES_SEPARATION_THEORY_USER_USER_H_

#include <cstdint>
#include <set>
#include <string>

/// \namesapce six_degrees_separation_theory.
/// \brief Project six degrees separation theory namespace.
namespace six_degrees_separation_theory {

/// \class User user.h. 
class User {
 public:
  /// \brief User class constructor.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  explicit User(std::string name, std::string surname);

  /// \brief User class destructor.
  ~User() = default;

  /// \brief User class copy constructor.
  /// \param[in] user User class object.
  User(const User &user) = delete;

  /// \brief User class move constructor.
  /// \param[in] user User class object.
  User(User &&user) = default;
 
  /// \brief User class copy assignment operator.
  /// \param[in] user User class object.
  /// \return User class object.
  User &operator=(const User &user) = delete;

  /// \brief User class move assignment operator.
  /// \param[in] user User class object.
  /// \return User class object.
  User &operator=(User &&user) = default;

  /// \brief Set name.
  /// \param[in] name Name.
  void SetName(const std::string &name);
  void SetName(std::string &&name);

  /// brief Get name.
  /// \return Returns user's name.
  std::string GetName() const noexcept {
    return name_;
  }

  /// \brief Set surname.
  /// \param[in] surname.
  void SetSurname(const std::string &surname);
  void SetSurname(std::string &&surname);

  /// \brief Get surname.
  /// \return Returns user's surname.
  std::string GetSurname() const noexcept {
    return surname_;
  }

  /// \brief Set id.
  /// \param[in] id.
  void SetId(uint64_t id);
  
  /// \brief Get id.
  /// \return Returns user's id.
  uint64_t GetId() const noexcept {
    return id_;
  }

  /// \brief Set additional connection.
  /// \param id User's id to whom current user will be connected.
  void SetConnection(uint64_t id);

  /// \brief Return user's available direct connections.
  /// \return User's direct connections.
  inline std::set<uint64_t> GetConnections() const noexcept {
    return connections_;
  }

 private:
  std::string name_;
  std::string surname_;
  uint64_t id_;
  std::set<uint64_t> connections_{};
};
}  // namespace six_degrees_separation_theory

#endif // SIX_DEGREES_SEPARATION_THEORY_USER_USER_H_

