#include <fstream>
#include <iostream>
#include <string>
#include <vector>

char try_find(std::vector<std::string> group) {
  for (char &c : group[0]) {
    auto pos = group[1].find(c);
    if (pos != std::string::npos) {
      auto pos = group[2].find(c);
      if (pos != std::string::npos) {
        return c;
      }
    }
  }
  return 'a';
}

int calculate_char(char character) {
  auto ascii_char = int(character);
  if (ascii_char >= 97) {
    return ascii_char - 96;
  } else {
    return ascii_char - 38;
  }
}

int main() {
  std::string input_line;
  std::fstream input_file("input.txt");

  int result = 0;

  std::vector<std::string> group;
  int counter = 0;

  while (getline(input_file, input_line)) {
    counter++;
    group.push_back(move(input_line));
    if (counter % 3 == 0) {
      result += calculate_char(try_find(move(group)));
    }
  }

  std::cout << result;

  input_file.close();
}