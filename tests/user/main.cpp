/// \file main.cpp
/// \brief 
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \date 13.01.2019

#include <string>

#include <gtest/gtest.h>

#include "user.h"

//class UserTest : public ::testing::Test {
// protected:
//  void SetUp override {
//    user.
//  }
//
// User user_;
//};

namespace six_degrees_separation_theory {

TEST (UserClassTest, UserConstructorEvalation) {
  std::string name = "user1_name";
  std::string surname = "user1_surname";
  //six_degrees_separation_theory::User user1(name, surname);
  User user1(name, surname);
  
  EXPECT_EQ(user1.GetName(), name);
  EXPECT_EQ(user1.GetSurname(), surname);
  EXPECT_EQ(user1.GetId(), 1);
}

TEST (UserClassTest, SetNameAndSurnameEvaluation) {
  User user1;
  //six_degrees_separation_theory::User user1;
  std::string name = "user1_name";
  std::string surname = "user1_surname";
  user1.SetNameAndSurname(name, surname);
  
  EXPECT_EQ(user1.GetName(), name);
  EXPECT_EQ(user1.GetSurname(), surname);
}

TEST (UserClassTest, UserIdEvaluation) {
  //six_degrees_separation_theory::User user1("User1", "User1");
  //six_degrees_separation_theory::User user2("User2", "User2");
  //six_degrees_separation_theory::User user3("User3", "User3");
  
  User user1("User1", "User1");
  User user2("User2", "User2");
  User user3("User3", "User3");

  EXPECT_EQ(user1.GetId(), 1);
  EXPECT_EQ(user2.GetId(), 2);
  EXPECT_EQ(user3.GetId(), 3);
}

TEST (UserClassTest, IncreaseConnectionsEvaluation) {
  //six_degrees_separation_theory::User user1("User1", "User1");
  User user1("User1", "User1");
  EXPECT_EQ(user1.GetNumberOfConnections(), 0);
  for (auto i = 1; i < 5; ++i) {
    user1.SetConnection(i);
    EXPECT_EQ(user1.GetNumberOfConnections(), i);
  }
}

TEST (UserClassTest, DecreaseConnectionsEvaluation) {
  //six_degrees_separation_theory::User user1("User1", "User1");
  User user1("User1", "User1");
  for (int i = 1; i <= 5; ++i)
    user1.SetConnection(i);

  EXPECT_EQ(user1.GetNumberOfConnections(), 5);
  for (int i = 1; i <= 5; ++i) {
    user1.RemoveConnection(i);
    EXPECT_EQ(user1.GetNumberOfConnections(), i);
  }
}

TEST (UserClassTest, ConnectionSizeEvaluation) {
  //six_degrees_separation_theory::User user("Umer", "Mansoor");
  User user("Umer", "Mansoor");
  EXPECT_EQ(user.GetNumberOfConnections(), 0);

  user.SetConnection(2);
  EXPECT_EQ(user.GetNumberOfConnections(), 1);

  user.SetConnection(3);
  EXPECT_EQ(user.GetNumberOfConnections(), 2);

  user.SetConnection(10);
  EXPECT_EQ(user.GetNumberOfConnections(), 3);

  user.SetConnection(34);
  EXPECT_EQ(user.GetNumberOfConnections(), 4);

  user.SetConnection(30);
  EXPECT_EQ(user.GetNumberOfConnections(), 5);

  user.RemoveConnection(30);
  EXPECT_EQ(user.GetNumberOfConnections(), 4);

  user.RemoveConnection(3);
  EXPECT_EQ(user.GetNumberOfConnections(), 3);
}

} // namespace six_degrees_separation_theory

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
