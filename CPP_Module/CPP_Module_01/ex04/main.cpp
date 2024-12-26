#include <iostream>
#include <fstream>

using namespace std;

class Solution
{
    private: 
        std::string s1, s2;

    public:
        Solution(std::string s1, std::string s2){
            this->s1 = s1;
            this->s2 = s2;
        }

        void processFile(std :: string fileName);
        void processFile(std::string result, std::fstream& fileReplace);
        void displayFile(std::ifstream& file);
        std :: string parsLine(std :: string line);
};

std::string replaceWord(std::string line, int findIndex, int endOfFindingWord, std::string s2) {
    std::string result;
    
    for(int i = 0; i < findIndex; i++) {
        result += line[i];
    }
    
    for(size_t i = 0; i < s2.length(); i++) {
        result += s2[i];
    }
    
    for(size_t i = endOfFindingWord; i < line.length(); i++) {
        result += line[i];
    }
    
    return result;
}

std::string Solution::parsLine(std :: string line) {
    std :: string returnLine = "";
    size_t i = 0;
    while(line[i]){
        size_t index = line.find(s1, i);
        if (index != line.npos){
            returnLine += line.substr(i, index - i);
            i = index + s1.size();
            returnLine += s2;
        }
        else
        {
            returnLine += line.substr(i, line.size());
            break;
        }
    }
    return returnLine;
}

void Solution::processFile(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }
    std::string fileNameReplace = fileName + ".replace";
    std::fstream fileReplace(fileNameReplace.c_str(), std::ios::out);
    std::string buffer;

    std::string line;
    while (std::getline(file, line))
    {
        line = parsLine(line);
        buffer += line + "\n";
    }
    file.close();
    processFile(buffer, fileReplace);
    std::ifstream file1(fileNameReplace.c_str());
}

void Solution::processFile(std::string buffer, std::fstream& fileReplace)
{
    if (!fileReplace.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    fileReplace << buffer;
    fileReplace.close();
}

void Solution::displayFile(std::ifstream& file)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.clear();
    file.seekg(0, std::ios::beg);
}

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        std::cerr << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
        return 1;
    }
    if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
    {
        std::cerr << "Error: Empty string" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    Solution solution(s1, s2);

    solution.processFile(filename);
}
