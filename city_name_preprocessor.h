#ifndef CITYNAME_PREPROCESSOR_H
#define CITYNAME_PREPROCESSOR_H

#include <algorithm>
#include <string>

using namespace std;

bool isForbiddenWord(string & str)
    {
        
        return true;
        //return std::find(std::begin(forbiddenWords), std::end(forbiddenWords), str) == std::end(forbiddenWords);
    }


class CityNamePreprocessor
{
private:
    void stripNonAlphabeticCharacters(string &str)
    {
        cout << "stripNonAlphabeticCharacters " << str << endl;
        auto first_illegal_char = std::remove_if(str.begin(), str.end(), [](unsigned char c) { return !std::isalpha(c) && !std::isblank(c); });
        str.erase(first_illegal_char, str.end());
    }

    void stripBlanks(string &str)
    {
        cout << "stripBlank " << str << endl;
        auto first_illegal_char = std::remove_if(str.begin(), str.end(), [](unsigned char c) { return std::isblank(c); });
        str.erase(first_illegal_char, str.end());
    }

    void stripUntilCapital(string &str)
    {
        cout << "stripUntilCapital " << str << endl;
        auto first_capital_it = std::find_if(str.begin(), str.end(),
                                             [](unsigned char c) { return std::isupper(c); } // correct
        );

        if (first_capital_it != str.end())
        {
            str.erase(str.begin(), first_capital_it);
        }
    }

    void convertToUppercase(string &str)
    {
        cout << "convertToUppercase " << str << endl;
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c); });
    }

    void stripForbiddenWords(string &str)
    {
         cout << "stripForbiddenWords " << str << endl;

        std::vector<string> forbiddenWords = {" DE ", " EN ", " HET ", "HET ", "DE "};
        for (auto & forbiddenWord: forbiddenWords)
        {
            cout << "Searching forbidden: " << forbiddenWord << " in " << str << endl;
            auto pos = str.find(forbiddenWord);
            while ( pos != string::npos) {
                cout << "Found forbidden: " << forbiddenWord;
                str.erase(pos, forbiddenWord.length());
                cout << "Updated name: " << str;
                pos = str.find(forbiddenWord);
            }
            
        }        
    }

    

public:
    void prepare(string &cityName)
    {
        stripUntilCapital(cityName);
        convertToUppercase(cityName);
        stripNonAlphabeticCharacters(cityName);
        stripForbiddenWords(cityName);
        stripBlanks(cityName);
    }
};

#endif
