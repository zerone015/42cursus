#include <fstream>
#include <iostream>

int displayErrorMsg(std::string errorMsg)
{
    std::cout << errorMsg << std::endl;
    return 1;
}

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
    return ret;
}

void replaceStr(std::string &str, std::string s1, std::string s2)
{
    size_t      idx;

    if (s1.empty())
        return ;
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
    std::ifstream   inputStream;
    std::ofstream   outputStream;
    std::string     fileContent;

    if (argc != 4)
        return displayErrorMsg("Invalid arguments");
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open())
        return displayErrorMsg("Failed to open file");
    outputStream.open((std::string(argv[1]) + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!outputStream.is_open())
        return displayErrorMsg("Failed to open file");
    fileContent = readFile(inputStream);
    replaceStr(fileContent, argv[2], argv[3]);
    outputStream << fileContent;
    inputStream.close();
    outputStream.close();
    return 0;
}
