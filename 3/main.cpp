#include <fstream>
#include <iostream>

enum class obj_type { rock, paper, scissor };

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
    if (m_type == rhs.m_type) {
      return result + 3;
    }

    if (m_type == obj_type::rock) {
      if (rhs.m_type == obj_type::paper) {
        return result;
      }
      return result + 6;
    }

    if (m_type == obj_type::paper) {
      if (rhs.m_type == obj_type::scissor) {
        return result;
      }
      return result + 6;
    }

    if (m_type == obj_type::scissor) {
      if (rhs.m_type == obj_type::rock) {
        return result;
      }
      return result + 6;
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
    obj o(input_line[2]);
    result += o.get_result(obj(input_line[0]));
  }

  std::cout << result;

  input_file.close();
}