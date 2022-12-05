#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

struct Range {
  Range(const int start, const int stop) : m_start(start), m_stop(stop) {}

  const int m_start;
  const int m_stop;
};

bool is_range_contains(Range rhs, Range lhs) {
  if (rhs.m_start >= lhs.m_start && rhs.m_start <= lhs.m_stop) {
    return true;
  }

  if (rhs.m_stop >= lhs.m_start && rhs.m_stop <= lhs.m_stop) {
    return true;
  }

  if (lhs.m_start >= rhs.m_start && lhs.m_start <= rhs.m_stop) {
    return true;
  }

  if (lhs.m_stop >= rhs.m_start && lhs.m_stop <= rhs.m_stop) {
    return true;
  }

  return false;
}

int main() {
  std::string input_line;
  std::fstream input_file("input.txt");

  int result = 0;

  std::string range_delimiter = "-";
  std::string elf_delimiter = ",";

  while (getline(input_file, input_line)) {
    size_t range_pos = input_line.find(range_delimiter);
    size_t elf_pos = input_line.find(elf_delimiter);
    std::string elf_start = input_line.substr(0, range_pos);
    std::string elf_stop =
        input_line.substr(range_pos + 1, elf_pos - range_pos - 1);

    Range first_elf(std::stoi(elf_start), std::stoi(elf_stop));

    range_pos = input_line.substr(elf_pos).find(range_delimiter);
    elf_start = input_line.substr(elf_pos + 1, range_pos - 1);
    elf_stop = input_line.substr(elf_pos + range_pos + 1);

    Range second_elf(std::stoi(elf_start), std::stoi(elf_stop));

    if (is_range_contains(first_elf, second_elf)) {
      result++;
    }
  }

  std::cout << result;

  input_file.close();
}