#include <iostream>

#include "logic.h"
#include "parser.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./kv <cmd1> <cmd2>..." << std::endl;
    return 1;
  }

  load_data();

  for (int i = 1; i < argc; ++i) {
    Command cmd = parse_input(argv[i]);

    if (!cmd.valid) {
      continue;
    }

    if (cmd.type == 'p') {
      put(cmd.key, cmd.value);
    } else if (cmd.type == 'g') {
      try {
        std::cout << get(cmd.key) << std::endl;
      } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
      }
    } else if (cmd.type == 'd') {
      try {
        del(cmd.key);
      } catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
      }
    } else if (cmd.type == 'c') {
      clr();
    } else if (cmd.type == 'a') {
      std::cout << all();
    }
  }

  save_data();

  return 0;
}