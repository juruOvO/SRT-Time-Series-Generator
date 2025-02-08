#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>

class Condition {
public:
	double Fx, Fy, Fz;
	Condition() :Fx(0), Fy(0), Fz(0) {}
};
std::string BaiscRandom_MT19937U(int num, std::vector<Condition*> Conditions);

class Harmonic {
public:
	int n;
	Condition baseCondition;
	double coeff;
	double phase;
	double freq;
	Harmonic():n(0),coeff(0.0),phase(0.0),freq(0){}
};
std::string HarmonicRandom(int num, std::vector<Condition*> Conditions);