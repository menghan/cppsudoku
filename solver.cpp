#include <iostream>
#include <fstream>
using namespace std;


class Puzzle {
public:
        Puzzle() {}
        ~Puzzle() {}

        short slot_count() {return this->n_slot;}
        void print();
        void init_from_file(const string);
private:
        short n_slot;
        short grid[9][9];
        short candidates[9][9];
};

void Puzzle::print()
{
        for (int x = 0; x < 9; ++x) {
                for (int y = 0; y < 9; ++y) {
                        short v = grid[x][y];
                        if (v == 0) {
                                cout << "_";
                        } else {
                                cout << v;
                        }
                }
                cout << endl;
        }
}

void Puzzle::init_from_file(const string filename)
{
        ifstream ifile;
        ifile.open(filename.c_str());
        char c;
        for (int x = 0; x < 9; ++x) {
                for (int y = 0; y < 9; ++y) {
                        ifile.read(&c, 1);
                        if (c == '_') {
                                this->grid[x][y] = 0;
                        } else {
                                this->grid[x][y] = c - '0';
                        }
                }
                ifile.read(&c, 1);  // '\n'
        }
        ifile.close();
}

int main(int argv, char *argc[])
{
        Puzzle p;
        p.init_from_file("puzzle1");
        p.print();
}
