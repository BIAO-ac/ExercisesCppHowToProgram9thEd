// 21.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>       
#include <string>         
#include <locale>
#include <vector>
#include <algorithm>

class CoderRot
{
public:

    explicit CoderRot(const int key = 13)
        :nKey(key)
    {
        for (char c = 'A'; c <= 'Z'; ++c)
        {
            UpperLetters.push_back(c);
        }

        for (char c = 'a'; c <= 'z'; ++c)
        {
            LowerLetters.push_back(c);
        }
    }

    char rot(const char c)
    {
        std::locale loc;
        if (std::isupper(c, loc))
        {
            if (c - 'A' + nKey <= 25)
            {
                return UpperLetters[c - 'A' + nKey];
            }
            else
            {
                return UpperLetters[c - 'A' - nKey];
            }
        }
        else if (std::islower(c, loc))
        {
            if (c - 'a' + nKey <= 25)
            {
                return LowerLetters[c - 'a' + nKey];
            }
            else
            {
                return LowerLetters[c - 'a' - nKey];
            }
        }
        return '*';
    }

    char rrot(const char c)
    {
        std::locale loc;
        if (std::isupper(c, loc))
        {
            if (c - 'A' - nKey >= 0)
            {
                return UpperLetters[c - 'A' - nKey];
            }
            else
            {
                return UpperLetters[c - 'A' + nKey];
            }
        }
        else if (std::islower(c, loc))
        {
            if (c - 'a' - nKey >= 0)
            {
                return LowerLetters[c - 'a' - nKey];
            }
            else
            {
                return LowerLetters[c - 'a' + nKey];
            }
        }
        return '*';
    }

private:
    int nKey;
    std::vector<char> UpperLetters;
    std::vector<char> LowerLetters;
};

void rot13Encrypt(const std::string& inputWord, std::string& outputWord);
void rot13Decrypt(const std::string& inputWord, std::string& outputWord);

int main()
{
    std::locale loc;
    
    std::string plainText = "Make Humans Great!";

    std::string encryptedText;

    std::string decryptedText;

    std::cout << plainText << std::endl;

    rot13Encrypt(plainText, encryptedText);
   
    std::cout << encryptedText << std::endl;

    rot13Decrypt(encryptedText, decryptedText);

    std::cout << decryptedText << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void rot13Encrypt(const std::string& input, std::string& output)
{
    CoderRot coder(13);
    std::locale loc;
    for (auto& v : input)
    {
        if (std::isalpha(v, loc))
        {
            output += coder.rot(v);
        }
        else
        {
            output += v;
        }
    }
}

void rot13Decrypt(const std::string& input, std::string& output)
{
    CoderRot coder(13);
    std::locale loc;
    for (auto& v : input)
    {
        if (std::isalpha(v, loc))
        {
            output += coder.rrot(v);
        }
        else
        {
            output += v;
        }
    }
}

