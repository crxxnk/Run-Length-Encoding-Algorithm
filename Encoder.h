#include <iostream>
#include <vector>

class Encoder
{
public:
  std::string encodeString(const std::string &txtToEncode);
  void encodeLines(const std::vector<std::string> &lines, const std::string &fileName);
  std::string encodedTxt;
};