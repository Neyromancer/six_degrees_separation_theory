/// \file user.h
/// \brief Class which represents user.
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \version 1.0.0.2
/// \date 18.01.2019

#ifndef SIX_DEGREES_SEPARATION_THEORY_USER_USER_H_
#define SIX_DEGREES_SEPARATION_THEORY_USER_USER_H_

#include <cstdint>
#include <ostream>
#include <set>
#include <string>

/// \namesapce six_degrees_separation_theory.
/// \brief Project six degrees separation theory namespace.
namespace six_degrees_separation_theory {

/// \class User user.h. 
class User {
 public:
  /// \brief User class constructor.
  User();

  /// \brief User class constructor.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  explicit User(std::string name, std::string surname);

  /// \brief User class destructor.
  ~User();

  /// \brief User class copy constructor.
  /// \param[in] user User class object.
  User(const User &user) = default;

  /// \brief User class move constructor.
  /// \param[in] user User class object.
  User(User &&user) = default;
 
  /// \brief User class copy assignment operator.
  /// \param[in] user User class object.
  /// \return User class object.
  User &operator=(const User &user) = default;

  /// \brief User class move assignment operator.
  /// \param[in] user User class object.
  /// \return User class object.
  User &operator=(User &&user) = default;

  /// \brief User class equality operator.
  /// \param[in] rhs User class object.
  /// \return State of equality of two objects.
  inline bool operator==(const User &rhs) const {
    return ((rhs.name_ == name_) &&
            (rhs.surname_ == surname_) &&
            (rhs.id_ == id_) &&
            (rhs.connections_ == connections_));
  }

  /// \brief User class inequality operator.
  /// \param[in] rhs User class object.
  /// \return State of equality of two objects.
  inline bool operator!=(const User &rhs) const {
    return !(*this == rhs);
  }

  /// \brief User class output operator.
  /// \param[in] out Output.
  /// \param[in] user User datum.
  /// \return Standrat output.
  friend std::ostream &operator<<(std::ostream &out, const User &user);

  /// \brief Set name and surname.
  /// \param[in] name Name.
  /// \param[in] surname Surname.
  void SetNameAndSurname(const std::string &name, const std::string &surname);
  void SetNameAndSurname(std::string &&name, std::string &&surname);

  /// \brief Set name.
  /// \param[in] name Name.
  // void SetName(const std::string &name);
  // void SetName(std::string &&name);

  /// brief Get name.
  /// \return Returns user's name.
  std::string GetName() const noexcept {
    return name_;
  }

  /// \brief Set surname.
  /// \param[in] surname.
  // void SetSurname(const std::string &surname);
  // void SetSurname(std::string &&surname);

  /// \brief Get surname.
  /// \return Returns user's surname.
  std::string GetSurname() const noexcept {
    return surname_;
  }

  /// \brief Set id.
  /// \param[in] id.
  void SetId(/*const uint64_t id*/);
  
  /// \brief Get id.
  /// \return Returns user's id.
  uint64_t GetId() const noexcept {
    return id_;
  }

  /// \brief Set additional connection.
  /// \param id User's id to whom current user will be connected.
  void SetConnection(const uint64_t id);

  /// \brief Return user's available direct connections.
  /// \return User's direct connections.
  inline std::set<uint64_t> GetConnections() const noexcept {
    return connections_;
  }

  /// \brief Remove passed connection.
  /// \param[in] id ID.
  void RemoveConnection(const uint64_t id);

  /// \brief Return number of connections.
  /// \return Number of connections.
  inline uint64_t GetNumberOfConnections() const noexcept {
    return static_cast<uint64_t>(connections_.size());
  }

 private:
  std::string name_;
  std::string surname_;
  static uint64_t counter_;
  uint64_t id_{};
  std::set<uint64_t> connections_{};
};
}  // namespace six_degrees_separation_theory

#endif // SIX_DEGREES_SEPARATION_THEORY_USER_USER_H_

