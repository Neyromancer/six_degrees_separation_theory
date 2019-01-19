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
  User user2;
  User user3(name, surname);

  EXPECT_EQ(user1.GetName(), name);
  EXPECT_EQ(user1.GetSurname(), surname);
  EXPECT_EQ(user1.GetId(), 1);
  EXPECT_EQ(user2.GetId(), 0);
  EXPECT_EQ(user3.GetName(), name);
  EXPECT_EQ(user3.GetSurname(), surname);
  EXPECT_EQ(user3.GetId(), 2);
}

TEST (UserClassTest, SetNameAndSurnameEvaluation) {
  User user1;
  EXPECT_EQ(user1.GetId(), 0);

  std::string name = "user1_name";
  std::string surname = "user1_surname";
  user1.SetNameAndSurname(name, surname);
  
  EXPECT_EQ(user1.GetName(), name);
  EXPECT_EQ(user1.GetSurname(), surname);
  EXPECT_EQ(user1.GetId(), 1);

  std::string tmp_name = "user_tmp_name";
  std::string tmp_surname = "user_tmp_surname";
  user1.SetNameAndSurname(tmp_name, tmp_surname);
  EXPECT_EQ(user1.GetName(), tmp_name);
  EXPECT_EQ(user1.GetSurname(), tmp_surname);
  EXPECT_EQ(user1.GetId(), 1); 
}

TEST (UserClassTest, UserIdEvaluation) {
  User user0;
  EXPECT_EQ(user0.GetId(), 0);

  User user1("User1", "User1");
  EXPECT_EQ(user1.GetId(), 1);

  User user2("User2", "User2");
  EXPECT_EQ(user2.GetId(), 2);

  User user3("User3", "User3");
  EXPECT_EQ(user3.GetId(), 3);
}

TEST (UserClassTest, IncreaseConnectionsEvaluation) {
  User user1("User1", "User1");
  EXPECT_EQ(user1.GetNumberOfConnections(), 0);
  for (auto i = 2; i < 5; ++i) {
    user1.SetConnection(i);
    EXPECT_EQ(user1.GetNumberOfConnections(), i - 1);
  }
}

TEST (UserClassTest, DecreaseConnectionsEvaluation) {
  User user1("User1", "User1");
  for (int i = 2; i <= 5; ++i)
    user1.SetConnection(i);

  EXPECT_EQ(user1.GetNumberOfConnections(), 4);
  for (int i = 5; i >= 2; --i) {
    EXPECT_EQ(user1.GetNumberOfConnections(), i - 1);
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
