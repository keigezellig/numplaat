#ifndef UTILS_H
#define UTILS_H


using namespace std;

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

bool is_vowel(const char p_char)
{
    constexpr char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    return std::find(std::begin(vowels), std::end(vowels), p_char) != std::end(vowels);
}

bool is_consonant(const char p_char)
{
    constexpr char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    return std::find(std::begin(vowels), std::end(vowels), p_char) == std::end(vowels);
}

bool is_upper(const char ch) {
    return isupper(ch);
}

string getVowels(const std::string & st) {
    // Moves all the characters for which `is_vowel` is true to the back
    //  and returns an iterator to the first such character
    string result = st;
    auto first_consonant = std::remove_if(result.begin(), result.end(), is_consonant);
    result.erase(first_consonant, result.end());
    cout << "Vowels: " << result << endl;
    return result;
}

string getConsonants(const std::string & st) {
    // Moves all the characters for which `is_vowel` is true to the back
    //  and returns an iterator to the first such character
    string result = st;
    auto first_vowel = std::remove_if(result.begin(), result.end(), is_vowel);
    result.erase(first_vowel, result.end());
    cout << "Consonants: " << result << endl;
    
    
    return result;
}


auto split(const std::string& str, char delimiter) -> std::vector<std::string>
{
    std::stringstream input(str);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(input, segment, delimiter))
    {
        seglist.push_back(segment);    
    }
    return seglist;
}


#endif