#include <fstream>
#include <iostream>

enum class obj_type {
  rock,   // lose
  paper,  // draw
  scissor // win
};

class obj {
public:
  obj(char type) {
    if ((type == 'A') || (type == 'X')) {
      m_type = obj_type::rock;
      result = 1;
    } else if ((type == 'B') || (type == 'Y')) {
      m_type = obj_type::paper;
      result = 2;
    } else if ((type == 'C') || (type == 'Z')) {
      m_type = obj_type::scissor;
      result = 3;
    }
  }

  int get_result(obj rhs) {
    if (rhs.m_type == obj_type::paper) {
      return result + 3;
    }

    if (rhs.m_type == obj_type::rock) {
      switch (m_type) {
      case obj_type::rock:
        return 3;
        break;
      case obj_type::paper:
        return 1;
        break;
      case obj_type::scissor:
        return 2;
        break;
      }
    }

    if (rhs.m_type == obj_type::scissor) {
      result = 6;
      switch (m_type) {
      case obj_type::rock:
        return result + 2;
        break;
      case obj_type::paper:
        return result + 3;
        break;
      case obj_type::scissor:
        return result + 1;
        break;
      }
    }

    return 0;
  }

  obj_type m_type;

private:
  int result;
};

int main() {
  std::string input_line;
  std::fstream input_file("input.txt");

  int result;

  while (getline(input_file, input_line)) {
    obj o(input_line[0]);
    result += o.get_result(obj(input_line[2]));
  }

  std::cout << result;

  input_file.close();
}