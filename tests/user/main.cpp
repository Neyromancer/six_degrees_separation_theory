/// \file main.cpp
/// \brief 
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \date 13.01.2019

#include <gtest/gtest.h>

#include "user/user.h"

//class UserTest : public ::testing::Test {
// protected:
//  void SetUp override {
//    user.
//  }
//
// User user_;
//};

TEST (UserClassTest, UserIdEvaluation) {
  User user1("User1", "User1");
  User user2("User2", "User2");
  User user3("User3", "User3");
  EXPECT_EQ(user1.GetId(), 1);
  EXPECT_EQ(user2.GetId(), 2);
  EXPECT_EQ(user3.GetId(), 3);
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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
