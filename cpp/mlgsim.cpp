#include <iostream>

#include "stdafx.h"

int main() {
	std::cout
		<< "MLG SIMULATOR - By Alex Pawelko based off of ideas from Minikloon.\n\n"
		<< "You have 15 turns.\n"
		<< "You start with 0 doritos.\n"
		<< "You start with 0 litres of Mountain Dew.\n"
		<< "You start with 10 MLG Points.\n"
		<< "Each dorito costs 5 MLG Points but gives 4 per turn.\n"
		<< "Each litre of Mountain Dew costs 20 MLG Points but gives 15 per turn.\n"
		<< "Each litre of Red Dew costs 30 MLG Points but gives 23 points per turn.\n"
		<< "The goal of the game is to get as many MLG Points as possible.\n"
		<< "Good Luck!\n"
		<< std::endl;

	int turn = 1;
	int doritos = 0;
	int mtnDew = 0;
	int mlgPoints = 10;
	int mtnDewRed = 0;

	const int mlgpptPerDorito = 4;
	const int mlgpptMtnDew = 15;
	const int costMtnDew = 20;
	const int costDoritos = 5;
	const int totalTurns = 15;
	const int costMtnDewRed = 30;
	const int mlgpptPerDewRed = 23;

	while (turn <= totalTurns) {
		std::cout << std::endl << std::endl;
		std::cout << "You're at turn " << turn << "!" << std::endl;
		std::cout << "You have " << doritos << " Doritos." << std::endl;
		std::cout << "You have " << mtnDew << " litres of Mountain DEWWWWWWWWW!" << std::endl;
		std::cout << "You have " << mtnDewRed << " litres of Red Dew!" << std::endl;
		std::cout << "Each Dorito costs " << costDoritos << " MLG Points." << std::endl;
		std::cout << "Each litre of Mountain Dew costs " << costMtnDew << " MLG Points." << std::endl;
		std::cout << "You currently are earning " << doritos * mlgpptPerDorito + mtnDew * mlgpptMtnDew + mtnDewRed * mlgpptPerDewRed << " points per turn." << std::endl;
		std::cout << "You have " << mlgPoints << " MLG Points.\n" << std::endl;


		std::cout << "How many litres of Mountain Dew do you want to buy?\n";

		int mtnDewToBuy = 0;
		std::cin >> mtnDewToBuy;

		int mtnDewCostTotal = mtnDewToBuy * costMtnDew;
		if (mtnDewCostTotal < 0) {
			std::cout << "Stop trying to scam the system!, the programmer isn't an idiot! You can't buy negative MLG stuff! YOU LOSE YOUR TURN!\n";
		}
		std::cout << "How many doritos do you want to buy?\n";

		int doritosToBuy = 0;
		std::cin >> doritosToBuy;

		int doritosCostTotal = doritosToBuy * costDoritos;
		if (doritosCostTotal < 0) {
			std::cout << "Stop trying to scam the system!, the programmer isn't an idiot! You can't buy negative MLG stuff! YOU LOSE YOUR TURN!\n";
		}
		std::cout << "How many litres of Red Dew do you wanna buy?\n";

		int mtnDewRedToBuy = 0;
		std::cin >> mtnDewRedToBuy;

		int mtnDewRedCostTotal = mtnDewRedToBuy * costMtnDewRed;
		if (mtnDewCostTotal < 0) {
			std::cout << "Stop trying to scam the system!, the programmer isn't an idiot! You can't buy negative MLG stuff! YOU LOSE YOUR TURN";
			continue;
		}


		if (mlgPoints >= mtnDewCostTotal + doritosCostTotal + mtnDewRedCostTotal) {
			mlgPoints -= mtnDewCostTotal + doritosCostTotal + mtnDewRedCostTotal;
			doritos += doritosToBuy;
			mtnDew += mtnDewToBuy;
			mtnDewRed += mtnDewRedToBuy;
			std::cout << "You earned " << mtnDewToBuy << " litres of Mountain Dewwwwwwwwww!\n";
			std::cout << "You earned " << doritosToBuy << " 'ritos!\n";
			std::cout << "You earned " << mtnDewRedToBuy << " litres of that sweet red gush!\n";
		}
		else {
			std::cout << "You do not have enough MLG Points to buy any 'ritos or Mountain Dew, Red or not!" << std::endl;
			int missingPoints = mtnDewCostTotal + doritosCostTotal + mtnDewRedCostTotal - mlgPoints;
			std::cout << "You tried to buy " << mtnDewToBuy << " litres of mountain dew, " << doritosToBuy << " doritos and " << mtnDewRedToBuy << " litres of Red Dew but you were missing " << missingPoints << " MLG Points!" << std::endl;
		}

		++turn; /*advances turn of the player*/
		mlgPoints += doritos * mlgpptPerDorito;
		mlgPoints += mtnDew * mlgpptMtnDew;
		mlgPoints += mtnDewRed * mlgpptPerDewRed;
		/*amount of currency player generates per turn via each currency generator*/
	}

	std::cout << std::endl;
	std::cout << "You ended with " << mlgPoints << " MLG Points!" << std::endl;

	std::cin.ignore(100000);
	std::cin.get();
	return 0;
}
