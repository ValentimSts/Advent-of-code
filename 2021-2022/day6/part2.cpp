#include <iostream>
#include <vector>
#include <unordered_map>

#define GENERATIONS 256

int main()
{   
    int temp;
    auto lanternfish_count = uint64_t{0}, new_fish = uint64_t{0};
    
    std::unordered_map<uint64_t, uint64_t> lanternfish = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0},
                                                          {5, 0}, {6, 0}, {7, 0}, {8, 0}};

    while(scanf("%d,", &temp) == 1) {
        lanternfish[temp]++;
        lanternfish_count++;
    }

    std::cout << lanternfish_count << " initial lanternfish." << std::endl;

    for(int i = 0; i < GENERATIONS; i++) {

        for(int key = 0; key <= 8; key++) {

            auto value = lanternfish[key];

            if(key == 0) {
                lanternfish[0] = 0;
                lanternfish_count += value;
                new_fish = value;
            }
            else {
                lanternfish[key-1] += value;
                lanternfish[key] = 0;
            }
        }
        lanternfish[6] += new_fish;
        lanternfish[8] += new_fish;

        new_fish = 0;
    }

    std::cout << lanternfish_count << " total lanternfish." << std::endl; 
}
