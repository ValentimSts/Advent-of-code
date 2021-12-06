#include <iostream>
#include <array>
#include <string>
#include <sstream>

#define BOARD_SIZE 5

class Board {

    private:
        std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> _table = {};
        std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> _marked = {};

    public:

        Board(std::array<std::string, BOARD_SIZE> &table)
        {
            for(int row = 0; row < BOARD_SIZE; row++) {
                fillRow(row, table[row]);
            }
        }


        void fillRow(int row, std::string &line)
        {
            std::stringstream stream;
            stream << line;

            int val, counter = 0;
            std::string temp;

            while(!stream.eof()) {
                stream >> temp;

                if (std::stringstream(temp) >> val) {
                    _table[row][counter] = val;
                    counter++;
                }
                temp = "";
            }
        }

        void printTable()
        {
            for(std::array<int, 5> values: _table) {

                std::cout << "[ ";

                for(int val: values) {
                    std::cout << val << " ";
                }
                std::cout << "]" << std::endl;
            }
        }
};


int main()
{
    std::array<std::string, 5> v = {"1 12 3 1 4", "65 3 42 5 7", "1 2 3 4 5", " 6 6 6 6 6", "2 2 2 2 2"};
    Board b = Board(v);

    b.printTable();

    return 0;
}
