/// \file main.cpp
/// \brief Unit-tests for class Netowrk.
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \version 1.0.0.1
/// \date 18.01.2019

#include <string>

#include <gtest/gtest.h>

#include "network.h"

namespace six_degrees_separation_theory {

TEST (NetworkClassTest, CreateAndAddUserToNetwork) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  EXPECT_TRUE(network.IsUserExist(name1, surname1));
}

TEST (NetworkClassTest, SetUserByIdEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  network.CreateAndAddUserToNetwork(name2, surname2);
  std::string test_name = "User_name_test";
  std::string test_surname = "User_surname_test";
  network.SetUserById(2, 1, test_name, test_surname);

  EXPECT_TRUE(newtowrk.IsUserExist(test_name, test_surname));
}

TEST (NetworkClassTest, GetUserByIdEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);
 
  EXPECT_EQ(network.GetUserById(1).GetName(), name1);
  EXPECT_EQ(networl.GetUserById(1).GetSurname(), surname1);
}

TEST (NetworkClassTest, IsIdExistEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  EXPECT_TRUE(network.IsIdExist(1));
}

TEST (NetworkClassTest, IsUserExist) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  EXPECT_TRUE(network.IsUserExist(name1, surname1));
}

} // six_degree_separation_theory

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
