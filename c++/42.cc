// Project Euler 42

#include <iostream>
#include <cmath>

#include "util.hh"

const char *words[] = {
#include "42.in"
};

int calc[len(words)] = { 0 };

int main() {

#pragma omp parallel for
    for (int i = 0; i < len(words); i++) {
	while (*words[i]) {
	    calc[i] += *words[i] - 'A' + 1;
	    words[i]++;
	}

	// Check if calc[i] is a triangular number.

	// -1 \pm
	int t = 8 * calc[i] + 1;
	int s = std::sqrt(t);
	if (s * s == t && s % 2 == 1)
	    calc[i] = 1;
	else
	    calc[i] = 0;
    }

    int count = 0;
#pragma omp parallel for reduction(+:count)
    for (int i = 0; i < len(calc); i++)
	count = count + calc[i];

    std::cout << count << std::endl;

    return 0;
}

