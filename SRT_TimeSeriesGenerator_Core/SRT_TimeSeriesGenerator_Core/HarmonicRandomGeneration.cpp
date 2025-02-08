#include "Generation.h"
#define M_PI 3.14159265358979323846

std::string HarmonicRandom(int num, std::vector<Condition*> Conditions) {
	std::vector<double> mix_percentages;
	std::vector<double> phases;
	std::vector<double> freqs;
	int numSamples;
	double f0;
	std::cout << "+++Num of samples+++\n";
	std::cin >> numSamples;
	std::cout << "+++Basic Frequency+++\n";
	std::cin >> f0;
	system("cls");
	std::cout << "+++Weight+++\n";
	for (int i = 0; i < num; ++i) {
		double temp;
		std::cin >> temp;
		mix_percentages.push_back(temp);
	}
	system("cls");
	std::cout << "+++Phases+++\n";
	for (int i = 0; i < num; ++i) {
		double temp;
		std::cin >> temp;
		phases.push_back(temp);
	}
	system("cls");
	std::cout << "+++Frequencies+++\n";
	for (int i = 0; i < num; ++i) {
		double temp;
		std::cin >> temp;
		freqs.push_back(temp);
	}
	system("cls");

	std::string output;
	double duration = 1 / f0;
	std::vector<Harmonic*> harmonics;

	for (int n = 1; n <= num; ++n) {
		double percent = mix_percentages[n - 1];
		Harmonic* newHarmonic = new Harmonic;
		newHarmonic->baseCondition = *Conditions[n - 1];
		newHarmonic->coeff = percent;
		newHarmonic->phase = phases[n - 1];
		newHarmonic->freq = freqs[n - 1];
		newHarmonic->n = n;
		harmonics.push_back(newHarmonic);
	}

	std::vector<double> time(numSamples);
	for (int i = 0; i < numSamples; ++i) {
		double t = duration * i;
		time[i] = t;
		Condition* newCondition = new Condition;
		for (const auto& h : harmonics) {
			double angularFrequency = 2 * M_PI * h->freq * h->n;
			newCondition->Fx += h->baseCondition.Fx * sin(angularFrequency * t + h->phase) * h->coeff;
			newCondition->Fy += h->baseCondition.Fy * sin(angularFrequency * t + h->phase) * h->coeff;
			newCondition->Fz += h->baseCondition.Fz * sin(angularFrequency * t + h->phase) * h->coeff;
		}
		output += (
			std::to_string(time[i]) + '\t' + std::to_string(newCondition->Fx) + '\t'
			+ std::to_string(newCondition->Fy) + '\t'
			+ std::to_string(newCondition->Fz) + '\n'
			);
		delete newCondition;
	}

	return output;
}