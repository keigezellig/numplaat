#ifndef LICENSE_PLATE_GENERATOR_H
#define LICENSE_PLATE_GENERATOR_H


#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <map>
#include "base_rule.h"
#include "city.h"
#include "utils.h"
#include "city_name_preprocessor.h"


class LicensePlateGenerator 
{
    private:        
        std::vector<std::unique_ptr<BaseRule>> rules;
        
        void initializeRules() {
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterRule()));
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterSecondLetterRule()));
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterLastLetterRule()));
            rules.push_back(unique_ptr<BaseRule>(new FirstThreeLettersRule()));
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterSecondLetterLastLetterRule()));            
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterAndFirstConsonantAndLastLetterRule()));
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterThirdLetterFourthLetterRule()));
            rules.push_back(unique_ptr<BaseRule>(new FirstLetterAndFirstVowelAndLastLetterRule()));            
        }    

    
        std::map<std::string, std::string> generateCombinations(std::vector<City> cities) const {

            CityNamePreprocessor preprocessor;
        
            std::map<std::string, std::string> result;
            
            //Sort cities according to weight from large to small
            std::sort(cities.begin(), cities.end(),[](City & a, City & b ) {return a.getWeight() > b.getWeight(); });
    
            for (const auto & city: cities) {
                bool cityAssigned = false;
                auto preparedName = string(city.getName());
                preprocessor.prepare(preparedName);
                std::cout << "City: " << city << " (" << preparedName << ") " << std::endl;
                for (const auto & rule: rules) {
                    
                    std::cout << "Finding available combination by rule " << rule->getRuleName() << ": ";
                    auto letterCombination = rule->getCombination(preparedName);
                    std::transform(letterCombination.begin(), letterCombination.end(),letterCombination.begin(), ::toupper);
                    auto it = result.find(letterCombination);
                    if (it == result.end()) {
                        //Combination is still available
                        result[letterCombination] = city.getName();
                        std::cout << "YES -> " << letterCombination << std::endl;                        
                        cityAssigned = true;
                        break;
                    }                  
                    else {
                         std::cout << "NO" << std::endl;                        
                    }

                }
                if (!cityAssigned) {
                    std::cout << "WARNING: No combination could be assigned to " << city.getName() << std::endl;
                }
            }

                        
            return result;
        }
        
        
    public:        
        void generate(std::vector<City> & cities) {
            std::cout << "Generating license plates.." << std::endl;
            
            
            auto combinations = generateCombinations(cities);            
            for (const auto & combination : combinations)             
            {
                auto cityIt = std::find_if(cities.begin(), cities.end(), [&combination](const City& obj) {return obj.getName() == combination.second;});
                cityIt->setCombination(combination.first);                
            }
        }
        LicensePlateGenerator(): rules() {
            initializeRules();
        }

};

#endif