
#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int SimpleHashWord(const std::string& Word)
{
    int Hash = 0;
    for (size_t i = 0; i < Word.size(); i++)
    {
        Hash += Word[i];
    }

    return Hash;
}

bool IsAnagram(const std::string& A, const std::string& B)
{
    if (A.size() != B.size())
        return false;
    int Alphabet[26] = { 0 };
    for (size_t i = 0; i < A.size(); i++)
    {
        Alphabet[A[i] % 97]++;
    }
    for (size_t i = 0; i < B.size(); i++)
    {
        Alphabet[B[i] % 97]--;
    }
    for (size_t i = 0; i < 26; i++)
    {
        if (Alphabet[i] != 0)
            return false;
    }
}


int CountValidLines(std::ifstream& File)
{
    std::string Line;

    int ValidLines = 0;

    while (std::getline(File, Line))
    {
        bool Continue = true;
        auto Words = split(Line, ' ');
        for (size_t i = 0; i < Words.size() && Continue; i++)
        {
            for (size_t j = i + 1; j < Words.size() && Continue; j++)
            {
                if (Words[i] == Words[j] || IsAnagram(Words[i], Words[j]))
                {
                    Continue = false;
                }
            }
        }
        if (Continue)
        {
            ValidLines++;
        }

    }

    return ValidLines;
}

int main()
{
    std::ifstream InputFile;
    InputFile.open("Input.txt");
    int ValidLinesCount = CountValidLines(InputFile);
    std::cout << "Valid Passphrases: " << ValidLinesCount << std::endl;
    InputFile.close();

    //std::cout << IsAnagram("allo", "aoll") << std::endl;



    system("pause");

}

