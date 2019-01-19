/// \file main.cpp
/// \brief Performance test for class Network.
/// \author Kormulev Dmitry <dmitry.kormulev@yandex.ru>
/// \version 1.0.0.0
/// \date 19.01.2019

#include <cstdint>
#include <chrono>
#include <thread>

#include "../network/network.h"

void CreateUser(six_degrees_separation_theory::Network &network) {
  uint64_t i{1};
  while (i < 20) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    network.CreateAndAddUserToNetwork("user" + std::to_string(i) + "_name",
                                      "user" + std::to_string(i) + "_surname");
    i = (i < UINT64_MAX) ? ++i : 0;
  }
}

void PrintNetwork(six_degrees_separation_theory::Network &network) {
  uint64_t i{1};
  while (i < 20) {  
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    network.PrintWholeNetwork();
    ++i;
  }
}

void RemoveUser(six_degrees_separation_theory::Network &network) {
  uint64_t i{1};
  while (i < 20) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    network.RemoveUserById(i);
    ++i;
  }
}

int main(int argc, char **argv) {
  six_degrees_separation_theory::Network network;
  //CreateUser(network);
  //PrintNetwork(network);
  std::thread t1(CreateUser, std::ref(network));
  //std::thread t2(PrintNetwork, std::ref(network));
  std::thread t3(RemoveUser, std::ref(network));
  t1.join();
  //t2.join();
  t3.join();
}
