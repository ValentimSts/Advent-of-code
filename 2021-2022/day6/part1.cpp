#include <iostream>
#include <vector>

int main()
{    
    int temp, fish_to_add = 0;

    std::vector<int> lanternfish;

    while(scanf("%d,", &temp) == 1)
        lanternfish.push_back(temp);

    int aux_size = lanternfish.size(), curr_size;

    std::cout << lanternfish.size() << " initial lanternfish." << std::endl; 

    for(int i = 0; i < 80; i++) {

        curr_size = aux_size;

        for(int fish = 0; fish < curr_size; fish++) {

            if(lanternfish[fish] == 0) {
                aux_size++;
                lanternfish.push_back(8);
                lanternfish[fish] = 6;
            }
            else {
                lanternfish[fish]--;
            }

        }
    }
    
    std::cout << lanternfish.size() << " total lanternfish." << std::endl; 
}
