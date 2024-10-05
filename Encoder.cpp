#include "Encoder.h"
#include <string>
#include <fstream>

void Encoder::encodeLines(const std::vector<std::string> &lines, const std::string &fileName){
  std::ofstream fileToWrite(fileName, std::ios::trunc);
  std::string encodedLine;
  if(fileToWrite.is_open()){
    if(!lines.empty()){
      for (size_t i = 0; i < lines.size(); i++) {
        encodedLine = encodeString(lines[i]);
        if (i < lines.size() - 1)
          fileToWrite << encodedLine << "\n";
        else
          fileToWrite << encodedLine;
      }
      std::cout << "Successfully encoded and wrote to " << fileName << std::endl;
    } else
        std::cout << "File is empty!" << std::endl;
    fileToWrite.close();
  }
}

std::string Encoder::encodeString(const std::string &txtToEncode)
{
  std::string encoded;
  int counter = 1;

  for(int i = 0; i < txtToEncode.size(); i++){
    if (txtToEncode[i] == txtToEncode[i+1])
      counter++;
    else{
      encoded += std::to_string(counter);
      encoded += txtToEncode[i];
      counter = 1;
    } 
  }
  return encoded;
}