#include <fstream>
#include <iostream>
#include <string>

char try_find(std::string &first_compartment, std::string &second_compartment) {
  for (char &c : first_compartment) {
    auto pos = second_compartment.find(c);
    if (pos != std::string::npos) {
      return c;
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

  int result;

  while (getline(input_file, input_line)) {
    std::string first_compartment =
        input_line.substr(0, input_line.length() / 2);
    std::string second_compartment =
        input_line.substr(input_line.length() / 2, input_line.length() / 2);
    result += calculate_char(try_find(first_compartment, second_compartment));
  }

  std::cout << result;

  input_file.close();
}