#include "Decoder.h"
#include <fstream>
#include <iostream>

std::string Decoder::decodeString(const std::string &encodedTxt) {
  std::string decoded;
  std::string number;

  for (size_t i = 0; i < encodedTxt.size(); ++i) {
    if (std::isdigit(encodedTxt[i])) {
      number += encodedTxt[i];
    } else {
      int count = std::stoi(number);
      decoded += std::string(count, encodedTxt[i]);
      number.clear();
    }
  }
  return decoded;
}

void Decoder::decodeFile(const std::string &fileName) {
  std::ifstream fileToRead(fileName);
  std::string decodedContent;

  if (fileToRead.is_open()) {
    std::string line;
    while (getline(fileToRead, line)) {
      std::string decodedLine = decodeString(line);
      decodedContent += decodedLine;
      decodedContent += "\n";
    }
    fileToRead.close();

    if (!decodedContent.empty()) {
      decodedContent.pop_back();
    }

    std::ofstream fileToWrite(fileName, std::ios::trunc);
    if (fileToWrite.is_open()) {
      fileToWrite << decodedContent;
      fileToWrite.close();
      std::cout << "Successfully decoded and wrote back to " << fileName << "." << std::endl;
    } else
      std::cerr << "Failed to open the file for writing: " << fileName << std::endl;
  } else
    std::cerr << "Failed to open the file for reading: " << fileName << std::endl;
}