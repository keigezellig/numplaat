#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>

using namespace std;
class City 
{
    private:
      string m_name;
      string m_combination;
      uint m_weight;
      
    
    public:
        string getName() const
        {
            return m_name;
        }

        uint getWeight() const 
        {
            return m_weight;
        }

        string getCombination() const 
        {
            return m_combination;
        }

        bool hasCombination() const 
        {
            return m_combination != "";
        }

        void setCombination(const string & combination) 
        {
            m_combination = combination;
        }
        
        explicit City(const string & name, uint weight): m_name(name), m_weight(weight), m_combination("") 
        {
        }

        City(const City& )= default;
        

        friend std::ostream & operator<< (std::ostream & os, const City & city) {            
            os << city.m_name << "," << city.m_weight << "," << (city.m_combination != "" ? city.m_combination : "N/A");
            return os;
        }
      
};

#endif