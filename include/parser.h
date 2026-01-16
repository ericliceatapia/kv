#pragma once

#include <string>
#include <vector>

struct Command {
  int key;
  std::string value;
  bool valid;
  char type;
};

Command parse_input(const std::string &input);