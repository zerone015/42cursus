#include <fstream>
#include <iostream>

std::string readFile(std::ifstream &inputStream)
{
    std::string buf;
    std::string ret;

    std::getline(inputStream, ret);
    while (!inputStream.eof())
    {
        ret.append("\n");
        std::getline(inputStream, buf);
        ret.append(buf);
    }
    return (ret);
}

void replaceStr(std::string &str, std::string s1, std::string s2)
{
    size_t      idx;

    idx = str.find(s1);
    while (idx != std::string::npos)
    {
        str.erase(idx, s1.length());
        str.insert(idx, s2);
        idx = str.find(s1, idx + s2.length());
    }
}

int main(int argc, char *argv[])
{
    std::string     filename;
    std::ifstream   inputStream;
    std::ofstream   outputStream;
    std::string     str;

    if (argc != 4)
    {
        std::cout << "Invalid arguments" << std::endl;
        return (1);
    }
    inputStream.open(argv[1], std::ios::in);
    filename.append(argv[1]).append(".replace");
    outputStream.open(filename.c_str(), std::ios::out | std::ios::trunc);
    if (inputStream.fail() || outputStream.fail())
    {
        std::cout << "Failed to open file" << std::endl;
        return (1);
    }
    str = readFile(inputStream);
    replaceStr(str, argv[2], argv[3]);
    outputStream << str;
    inputStream.close();
    outputStream.close();
    return (0);
}
