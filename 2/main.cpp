#include <fstream>
#include <iostream>

int main() {
  std::string input_line;
  std::fstream input_file("input.txt");

  int largest_calories[3];
  int calories = 0;
  while (getline(input_file, input_line)) {
    calories += atoi(input_line.c_str());

    if (input_line == "") {
      if (calories > largest_calories[0]) {
        largest_calories[2] = largest_calories[1];
        largest_calories[1] = largest_calories[0];
        largest_calories[0] = calories;
      } else if (calories > largest_calories[1]) {
        largest_calories[2] = largest_calories[1];
        largest_calories[1] = calories;
      } else if (calories > largest_calories[2]) {
        largest_calories[2] = calories;
      }
      calories = 0;
    }
  }

  std::cout << largest_calories[0] + largest_calories[1] + largest_calories[2];

  input_file.close();
}