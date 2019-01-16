/// \file main.cpp
/// \brief Unit-tests for class Netowrk.
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \date 16.01.2019

#include <string>

#include <gtest/gtest.h>

#include "network.h"

namespace six_degrees_separation_theory {

TEST (NetworkClassTest, CreateAndAddUserToNetwork) {
  Network network;
  std::string name = "User1_name";
  std::string surname = "User1_surname";
  network.CreateAndAddUserToNetwork(name, surname);
  EXPECT_TRUE(network.IsUserExist(name, surname));
}

} // six_degree_separation_theory

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
