#include <fstream>
#include <iostream>
#include <cstdio>

int printPerror()
{
    std::perror("");
    return (EXIT_FAILURE);
}

int printError(std::string error_msg)
{
    std::cout << error_msg << std::endl;
    return (EXIT_FAILURE);
}

std::string readFile(std::ifstream &inputStream)
{
    std::string buf;
    std::string ret;

    std::getline(inputStream, ret);
    while (!inputStream.eof())
    {
        ret += "\n";
        std::getline(inputStream, buf);
        ret += buf;
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

bool isValidArguments(int argc, char *argv[])
{
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (argc != 4 || s1.empty() || s2.empty())
        return (false);
    return (true);
}

int main(int argc, char *argv[])
{
    std::ifstream   inputStream;
    std::ofstream   outputStream;
    std::string     str;

    if (!isValidArguments(argc, argv))
        return (printError("Invalid arguments"));
    inputStream.open(argv[1], std::ios::in);
    if (inputStream.fail())
        return (printPerror());
    outputStream.open(std::string(argv[1]) + ".replace", std::ios::out | std::ios::trunc);
    if (outputStream.fail())
        return (printPerror());
    str = readFile(inputStream);
    replaceStr(str, argv[2], argv[3]);
    outputStream << str;
    return (0);
}
