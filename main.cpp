#include "Encoder.cpp"
#include "Decoder.cpp"
#include <fstream>
#include <string>

std::string fileName = "file.txt";

int selection(){
  int choice;
  std::cout << "Choose an option:\n";
  std::cout << "1. Encode a file\n";
  std::cout << "2. Decode a file\n";
  std::cout << "3. Exit\n";
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  return choice;
}

void encode(){
  Encoder file;
  std::vector<std::string> lines;
  std::ifstream fileToRead;
  fileToRead.open(fileName, std::ios::in);
  if(fileToRead.is_open()){
    std::string line;
    while(getline(fileToRead, line))
      lines.push_back(line);
    fileToRead.close();

    file.encodeLines(lines, fileName);
  }
}

void decode(){
  Decoder dec;
  dec.decodeFile(fileName);
}

int main()
{
  int choice;
  choice = selection();
  if(choice == 1)
    encode();
  else if(choice == 2)
    decode();
  else if(choice == 3)
    exit(0);

  return 0;
}