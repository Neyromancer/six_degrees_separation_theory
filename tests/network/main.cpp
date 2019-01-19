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

  EXPECT_TRUE(!network.IsUserExist(name1, surname1)) << "user " 
  << name1 << " " << surname1 << "was not created yet." << std::endl;

  network.CreateAndAddUserToNetwork(name1, surname1);

  EXPECT_TRUE(network.IsUserExist(name1, surname1)) << "user " 
  << name1 << " " << surname1 << "was not created." << std::endl;
  EXPECT_TRUE(network.IsIdExist(1)) << "id for user " << name1 << " " << surname1
  << " was set incorrectly" << std::endl;
 
  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  EXPECT_TRUE(!network.IsIdExist(2)) << "this id should not exist yet " 
                                     << std::endl;
  network.CreateAndAddUserToNetwork(name2, surname2);

  EXPECT_TRUE(network.IsUserExist(name2, surname2)) << "user " 
  << name1 << " " << surname1 << "was not created yet." << std::endl;
  EXPECT_TRUE(network.IsIdExist(2)) << "id for user " << name2 << " " << surname2
  << " was set incorrectly" << std::endl;
}

TEST (NetworkClassTest, IsUserExistEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  EXPECT_TRUE(network.IsUserExist(name1, surname1)) << "check for user" << name1
     << " " << surname1 << " failed" << std::endl;
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
  network.SetUserById(1, 2, test_name, test_surname);

  EXPECT_TRUE(network.IsUserExist(test_name, test_surname)) << "user's name " 
  << name1 << " and surname " << surname1 << " were not changed" << std::endl;
  EXPECT_EQ(network.GetUserById(1).GetNumberOfConnections(), 1) 
  << "user's connections were not increased" << std::endl;
  EXPECT_TRUE(!network.IsUserExist(name1, surname1)) << "user's name " << name1 
  << " and surname " << surname1 << " were not changed" << std::endl;
  
  network.SetUserById(2, 2, name1, surname1);
  EXPECT_TRUE(network.IsUserExist(name1, surname1));
  EXPECT_EQ(network.GetUserById(2).GetNumberOfConnections(), 0) 
  << "user's connections were increased" << std::endl;
}

TEST (NetworkClassTest, GetUserByIdEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);
 
  EXPECT_EQ(network.GetUserById(1).GetName(), name1);
  EXPECT_EQ(network.GetUserById(1).GetSurname(), surname1);
}

TEST (NetworkClassTest, IsIdExistEvaluation) {
  Network network;

  EXPECT_TRUE(!network.IsIdExist(1));

  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  EXPECT_TRUE(network.IsIdExist(1));

  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  network.CreateAndAddUserToNetwork(name2, surname2);
  EXPECT_TRUE(network.IsIdExist(2));

}

TEST (NetworkClassTest, RemoveUserByIdEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  network.CreateAndAddUserToNetwork(name2, surname2);

  EXPECT_TRUE(network.IsIdExist(1));

  network.RemoveUserById(1);

  EXPECT_TRUE(!network.IsIdExist(1));
}

TEST (NetworkClassTest, RemoveUserByNameEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  network.CreateAndAddUserToNetwork(name2, surname2);

  EXPECT_TRUE(network.IsUserExist(name1, surname1));

  network.RemoveUserByName(name1);

  EXPECT_TRUE(!network.IsUserExist(name1, surname1));
}

TEST (NetworkClassTest, RemoveUserBySurnameEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  network.CreateAndAddUserToNetwork(name2, surname2);

  EXPECT_TRUE(network.IsUserExist(name1, surname1));

  network.RemoveUserBySurname(surname1);

  EXPECT_TRUE(!network.IsUserExist(name1, surname1));
}

TEST (NetworkClassTest, AddConnectionEvaluation) {
  Network network;
  for (auto i = 1; i <= 5; ++i)
    network.CreateAndAddUserToNetwork("user" + std::to_string(i) + "_name",
                                      "user" + std::to_string(i) + "_surname");

  for (auto i = 1; i <= 5; ++i)
    EXPECT_EQ(network.GetUserById(i).GetNumberOfConnections(), 0);

  for (auto i = 2; i <= 5; ++i)
    network.AddConnection(1, i);

  EXPECT_EQ(network.GetUserById(1).GetNumberOfConnections(), 4);
  for (auto i = 2; i <= 5; ++i)
    EXPECT_EQ(network.GetUserById(i).GetNumberOfConnections(), 1);
}

TEST (NetworkClassTest, RemoveConnectionEvaluation) {
  Network network;
  std::string name1 = "User1_name";
  std::string surname1 = "User1_surname";
  network.CreateAndAddUserToNetwork(name1, surname1);

  std::string name2 = "User2_name";
  std::string surname2 = "User2_surname";
  network.CreateAndAddUserToNetwork(name2, surname2);

  std::string name3 = "User3_name";
  std::string surname3 = "User3_surname";
  network.CreateAndAddUserToNetwork(name3, surname3);

  network.AddConnection(1, 2);
  network.AddConnection(1, 3);

  EXPECT_EQ(network.GetUserById(1).GetNumberOfConnections(), 2);

  network.RemoveConnection(1, 2);

  EXPECT_EQ(network.GetUserById(1).GetNumberOfConnections(), 1);
}

TEST (NetworkClassTest, AreUsersConnectedEvaluation) {
  Network network;
  for (auto i = 1; i <= 20; ++i)
    network.CreateAndAddUserToNetwork("user" + std::to_string(i) + "_name",
                                      "user" + std::to_string(i) + "_surname");

  for (auto i = 2; i <= 5; ++i)
    network.AddConnection(1, i);

  network.AddConnection(2, 6);
  network.AddConnection(6, 15);
  network.AddConnection(15, 16);
  network.AddConnection(15, 17);
  network.AddConnection(3, 7);
  network.AddConnection(7, 11);
  network.AddConnection(7, 13);
  network.AddConnection(13, 14);
  network.AddConnection(14, 15);
  network.AddConnection(5, 8);
  network.AddConnection(8, 9);
  network.AddConnection(8, 10);
  network.AddConnection(9, 11);
  network.AddConnection(10, 12);
  network.AddConnection(4, 7);
  network.AddConnection(4, 16);
  network.AddConnection(4, 9);
  network.AddConnection(4, 11);

  EXPECT_TRUE(network.AreUsersConnected(1, 15));
  EXPECT_TRUE(!network.AreUsersConnected(1, 18));
  EXPECT_TRUE(!network.AreUsersConnected(18, 20));
  EXPECT_TRUE(network.AreUsersConnected(3, 7));
  EXPECT_TRUE(network.AreUsersConnected(1, 3));
  EXPECT_TRUE(network.AreUsersConnected(9, 13));
  EXPECT_TRUE(network.AreUsersConnected(5, 6));
}

} // six_degree_separation_theory

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
