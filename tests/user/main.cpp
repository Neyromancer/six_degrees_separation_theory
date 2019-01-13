/// \file main.cpp
/// \brief 
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \date 13.01.2019

#include <gtest/gtest.h>

#include "user/user.h"

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
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
