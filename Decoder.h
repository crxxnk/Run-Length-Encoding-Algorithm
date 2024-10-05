#include <string>

class Decoder {
public:
  std::string decodeString(const std::string &encodedTxt);
  void decodeFile(const std::string &fileName);
};