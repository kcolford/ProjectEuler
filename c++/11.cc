// Project Euler: problem 11

#include "util.hh"
#include "config.h"

int main () {
    fstream file (INFILE_DIRECTORY "11.in");

    int f[20][20];
    for (int i = 0; i < 20; i++)
	for (int j = 0; j < 20; j++)
	    file >> f[i][j];

    int m = 0;
    for (int i = 0; i < 20; i++)
	for (int j = 0; j < 16; j++)
	    m = max(m, f[i][j] * f[i][j + 1] * f[i][j + 2] * f[i][j + 3]);
    for (int i = 0; i < 16; i++)
	for (int j = 0; j < 20; j++)
	    m = max(m, f[i][j] * f[i + 1][j] * f[i + 2][j] * f[i + 3][j]);
    for (int i = 0; i < 16; i++)
	for (int j = 0; j < 16; j++)
	    m = max(m, f[i][j] * f[i + 1][j + 1] * f[i + 2][j + 2] * f[i + 3][j + 3]);
    for (int i = 3; i < 20; i++)
	for (int j = 0; j < 16; j++)
	    m = max(m, f[i][j] * f[i - 1][j + 1] * f[i - 2][j + 2] * f[i - 3][j + 3]);

    cout << m << endl;
}
