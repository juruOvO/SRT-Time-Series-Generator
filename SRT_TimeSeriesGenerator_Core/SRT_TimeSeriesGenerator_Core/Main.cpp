#include "Generation.h"
#include <windows.h>


int main() {
	SetConsoleTitle(L"SRT Time Series Generator (CORE) - v1.0");
	std::vector<Condition*> Conditions;
	int mode;
	int num;
	mode = 0;
	std::string output;

	std::ifstream fin;
	fin.open("Conditions.txt");
	std::ofstream fout;
	fout.open("res.txt");

	std::cout << std::setw(55) << std::setfill('=') << "NOTE" << std::setw(55) << std::setfill('=') << '\n' <<
		"PLEASE INPUT BASED ON PROMPTS\n"
		"Conditions should be written in Conditions.txt.\n"
		"Mode = 0 (Default): Base Random Generation.\n"
		"Mode = 1: Harmonic Random Generation\n"
		"In Mode 1, *Weight* requires weights of conditions.\n"
		"\t*Phases* requires initial phases of conditions.\n"
		"\t*Frequencies* requires frequencies of conditions.\n"
		"\tMake sure inputs of *Weight*, *Phases*, and *Frequencies* are accordinated with conditions in number.\n"
		<< std::setw(110) << std::setfill('=') << '\n';
	system("Pause");
	system("cls");
	Sleep(200);

	std::cout << "+++Mode+++\n";
	std::cin >> mode;
	system("cls");
	std::cout << "+++Working Conditions+++\n";
	std::string line;
	num = 0;
	while (std::getline(fin, line)) {
		std::stringstream ss;
		ss << line;
		float fx, fy, fz;
		ss >> fx >> fy >> fz;
		Condition* newCondition = new Condition;
		newCondition->Fx = fx;
		newCondition->Fy = fy;
		newCondition->Fz = fz;
		Conditions.push_back(newCondition);
		num++;
	}
	std::cout << "+++Reading Complete+++\n";
	fin.close();
	system("cls");

	fout << "Time\tFx\tFy\tTz\t\n[s]\t[N]\t[N]\t[N]\t\n";
	
	if (mode == 0) {
		output = BaiscRandom_MT19937U(num, Conditions);
		fout << output;
	}
	else if (mode == 1) {
		output = HarmonicRandom(num, Conditions);
		fout << output;
	}
	fout.close();
	return 0;
}