/// \file main.cpp
/// \brief 
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \date 13.01.2019

#include <string>

#include <gtest/gtest.h>

#include "user.h"

namespace six_degrees_separation_theory {

TEST (UserClassTest, UserConstructorEvalation) {
  std::string name = "user1_name";
  std::string surname = "user1_surname";
  User user1(name, surname);
  
  EXPECT_EQ(user1.GetName(), name);
  EXPECT_EQ(user1.GetSurname(), surname);
  EXPECT_EQ(user1.GetId(), 1);
}

TEST (UserClassTest, SetNameAndSurnameEvaluation) {
  User user1;
  std::string name = "user1_name";
  std::string surname = "user1_surname";
  user1.SetNameAndSurname(name, surname);
  
  EXPECT_EQ(user1.GetName(), name);
  EXPECT_EQ(user1.GetSurname(), surname);
  EXPECT_EQ(user1.GetId(), 2);
}

TEST (UserClassTest, UserIdEvaluation) {
  User user1("User1", "User1");
  EXPECT_EQ(user1.GetId(), 3);

  User user2("User2", "User2");
  EXPECT_EQ(user2.GetId(), 4);

  User user3("User3", "User3");
  EXPECT_EQ(user3.GetId(), 5);
}

TEST (UserClassTest, IncreaseConnectionsEvaluation) {
  User user1("User1", "User1");
  EXPECT_EQ(user1.GetNumberOfConnections(), 0);
  for (auto i = 1; i < 5; ++i) {
    user1.SetConnection(i);
    EXPECT_EQ(user1.GetNumberOfConnections(), i);
  }
}

TEST (UserClassTest, DecreaseConnectionsEvaluation) {
  User user1("User1", "User1");
  for (int i = 1; i <= 5; ++i)
    user1.SetConnection(i);

  EXPECT_EQ(user1.GetNumberOfConnections(), 5);
  for (int i = 5; i >= 1; --i) {
    EXPECT_EQ(user1.GetNumberOfConnections(), i);
    user1.RemoveConnection(i);
  }
}

TEST (UserClassTest, ConnectionSizeEvaluation) {
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
