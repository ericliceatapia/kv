#include "logic.h"
#include <format>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

static std::unordered_map<int, std::string> kv_store;
const std::string DB_FILE = "database.txt";

void load_data() {
  std::ifstream file(DB_FILE);
  if (!file.is_open())
    return;

  std::string line;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string key_str, value;

    if (std::getline(ss, key_str, ',') && std::getline(ss, value)) {
      try {
        kv_store[std::stoi(key_str)] = value;
      } catch (...) {
        continue;
      }
    }
  }
  file.close();
}

void save_data() {
  std::ofstream file(DB_FILE, std::ios::trunc);

  for (const auto &pair : kv_store) {
    file << pair.first << "," << pair.second << "\n";
  }
  file.close();
}

void put(int key, const std::string &value) { kv_store[key] = value; }

std::string get(int key) {
  auto it = kv_store.find(key);
  if (it != kv_store.end()) {
    return it->second;
  }
  return "";
}

void del(int key) {
  size_t removed = kv_store.erase(key);

  if (removed == 0) {
    throw std::out_of_range(std::to_string(key) + " not found.");
  }
}

void clr() { kv_store.clear(); }

std::string all() { return "all called"; }