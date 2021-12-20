#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void compute_input(std::string filename, std::vector<int> &crab_positions, const char delim)
{
    std::ifstream ifs(filename);

    if(ifs.is_open()) {
        std::string crab_pos = "";

        while(std::getline(ifs, crab_pos, delim)) {

            if(!crab_pos.empty()) {
                int temp = std::stoi(crab_pos);
                crab_positions.push_back(temp);
            }

            crab_pos = "";
        }
    }
    else
        std::cerr << "ERROR: compute_input / FAILED_TO_OPEN_FILE: " << filename << std::endl;
}


int main()
{
    int max = 0, fuel_cost = 0, min_fuel;

    std::vector<int> crab_positions;
    compute_input("day7.txt", crab_positions, ',');

    for(int crab_pos: crab_positions) {
        if(crab_pos > max)
            max = crab_pos;
    }

    std::cout << "number of crab positions: " << crab_positions.size() << std::endl;

    // the same as moving every crab to the position 0
    for(int crab_pos: crab_positions)
        min_fuel += crab_pos;

    for(int new_pos = 1; new_pos <= max; new_pos++) {

        for(int crab_pos: crab_positions)
            fuel_cost += abs(crab_pos - new_pos);

        if(fuel_cost < min_fuel)
            min_fuel = fuel_cost;
        
        fuel_cost = 0;
    }

    std::cout << "minimum ammount of fuel necessary: " << min_fuel << std::endl;
}
