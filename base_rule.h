#ifndef BASE_RULE_H
#define BASE_RULE_H


#include <string>
#include <vector>
#include <iostream>
#include "utils.h"

class BaseRule 
{
    public:
       virtual std::string getCombination(const std::string & cityName) = 0;       
       virtual ~BaseRule() = default;

       string getRuleName() {
           return typeid(*this).name();
       }

};
 

class FirstLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {
            return std::string(1, cityName.at(0));
        }
};

class FirstLetterAndFirstConsonantAndLastLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {

            std::string consonants = getConsonants(cityName);
            std::string result = std::string(1, cityName.at(0));
            
            if (consonants.at(0) != cityName.at(0)) {
                result += consonants.at(0);
            }
            else {
                result += consonants.at(1);
            }
            result += cityName.at(cityName.length() - 1);
            
            
            return result;
        }        
};

class FirstLetterAndFirstVowelAndLastLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {

            std::string vowels = getVowels(cityName);
            
            std::string result = std::string(1, cityName.at(0));
            
            if (vowels.at(0) != cityName.at(0)) {
                result += vowels.at(0);
            }
            else {
                result += vowels.at(1);
            }
            result += cityName.at(cityName.length() - 1);
            
            
            return result;
        }
};

class FirstLetterLastLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {
            std::string result = std::string(1, cityName.at(0));            
            result += cityName.at(cityName.length() - 1);
                        
            return result;
        }
};


class FirstLetterSecondLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {

            std::string result = std::string(1, cityName.at(0));                        
            result += cityName.at(1);
                        
            return result;
        }
};

class FirstLetterThirdLetterFourthLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {

            std::string result = std::string(1, cityName.at(0));                        
            result += cityName.at(2);
            result += cityName.at(3);
                        
            return result;
        }
};

class FirstThreeLettersRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {

            std::string result = std::string(1, cityName.at(0));                        
            result += cityName.at(1);
            result += cityName.at(2);
                        
            return result;
        }
};

class FirstLetterSecondLetterLastLetterRule: public BaseRule
{
    public:
        virtual std::string getCombination(const std::string & cityName) {

            std::string result = std::string(1, cityName.at(0));                        
            result += cityName.at(1);
            result += cityName.at(2);
                        
            return result;
        }
};
#endif