#include "Generation.h"


std::string BaiscRandom_MT19937U(int num, std::vector<Condition*> Conditions) {
	double TotalTime;
	double DeltaTime;
	double seed;
	std::cout << "+++TotalTime+++\n";
	std::cin >> TotalTime;
	std::cout << "+++DeltaTime+++\n";
	std::cin >> DeltaTime;
	std::cout << "+++Seed+++\n";
	std::cin >> seed;
	system("cls");
	std::string output;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distrib(0, seed);
	double curTime = 0;
	while (curTime <= TotalTime) {
		int select = distrib(gen);
		select %= num;
		//std::cout << select << '\n';
		output += (std::to_string(curTime) + '\t' + std::to_string(Conditions[select]->Fx) + '\t' + std::to_string(Conditions[select]->Fy) + '\t' + std::to_string(Conditions[select]->Fz) + '\n');
		curTime += DeltaTime;
	}
	return output;
}