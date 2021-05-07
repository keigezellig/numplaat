#include <iostream>
#include <fstream>
#include <memory>
#include "license_plate_generator.h"
#include "city.h"
#include "utils.h"

using namespace std;


auto readFile(string filename) {
  vector<City> cities;

  string line;
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        auto splitted = split(line, ';');
        if (splitted.size() == 2) {
            cities.push_back(City(splitted[0], stoi(splitted[1])));
        }
        
        
    }
    myfile.close();
  }
  else 
  { 
      cerr << "Unable to open file"; 
      exit(1);
      

  }

  return cities;


}
 
int main()
{
    
    LicensePlateGenerator generator;

    auto cities = readFile("pop.csv");
    generator.generate(cities);

    cout << "License plate overview:" << endl;
    for (const auto & entry: cities) {
        
        cout << entry << endl;
    }

    int nonAssignedCitiesCount = std::count_if(cities.begin(), cities.end(), [](const City & c) -> bool { return c.getCombination() == ""; });
    double perc = (static_cast<double>(nonAssignedCitiesCount) / cities.size()) * 100;
    

    cout << "# cities without assigned combinations: " << nonAssignedCitiesCount << " (" << perc << "%)" << endl;



    return 0;
    
} 





