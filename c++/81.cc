// Project Euler Problem 81

#include "util.hh"
#include <config.h>
#include <limits>

int table[80][80];

int get(unsigned x, unsigned y) {
    static int cache[80][80] = { { 0 } };
    if (x > 79 or y > 79)
	return numeric_limits<int>::max();
    if (x == 79 and y == 79)
	return table[x][y];
    if (cache[x][y] == 0)
	cache[x][y] = table[x][y] + min(get(x + 1, y), get(x, y + 1));
    return cache[x][y];
}

int main() {
    ifstream in(INFILE_DIRECTORY "81.in");
    
    for (int i = 0; i < 80; i++) {
	for (int j = 0; j < 80; j++) {
	    in >> table[i][j];
	}
    }

    cout << get(0, 0) << endl;

    return 0;
}

