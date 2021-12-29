cmake_minimum_required(VERSION 3.11)
project(
  UDP-communication
  VERSION 0.1
  DESCRIPTION "UDP-communication"
  LANGUAGES CXX)


add_executable (udp-server udp-server.cpp)
add_executable (udp-client udp-client.cpp)
add_executable (test test.cpp)