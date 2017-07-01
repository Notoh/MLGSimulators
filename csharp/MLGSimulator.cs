using System;

namespace MLGSim {
    internal class MLGSimulator {
        private static int MLGPoints = 100;
        private static int Doritos = 0;
        private static int MTNDew = 0;
        private const int DewPtsTurn = 20;
        private const int DoritosPtsTurn = 10;
        private const int DoritosCost = 30;
        private const int DewCost = 60;


        public static void Main(string[] args) {
            Console.WriteLine("\n\t------MLG Simulator by Alex Pawelko------\t\n");
            for (int turns = 1; turns < 16; turns++) {
                Console.WriteLine("\n\tYou are on turn " + turns + ".");
                Console.WriteLine("\n\tYou earned " + CalcPtsTurn() + " MLG Points this turn!");
                MLGPoints += CalcPtsTurn();
                Console.WriteLine("\n\tYou have " + MLGPoints + " MLG Points.");
                Console.WriteLine("\n\tYou are earning " + CalcPtsTurn() + " MLG Points per turn.");
                Console.WriteLine("\n\tCurrently you have " + Doritos + " Doritos and " + MTNDew + " litres of Mountain Dew.");

                Console.WriteLine("\n\tDo you want to buy any Doritos? Doritos earn " + DoritosPtsTurn + " and cost " + DoritosCost + " MLG Points. If you do not wish to buy any, type 0.");
                int wannaBuy;
                string attempt = Console.ReadLine();
                bool noError = Int32.TryParse(attempt, out wannaBuy);
                if (noError) {
                    if (wannaBuy > 0) {
                        int buyAttempt = 0;
                        for (; buyAttempt < wannaBuy; buyAttempt++) {
                            if (MLGPoints - DoritosCost >= 0) {
                                ++Doritos;
                                MLGPoints -= DoritosCost;
                            } else {
                                Console.WriteLine("\n\tYou didn't have enough MLG Points to buy all those. You bought " + buyAttempt + " Doritos before you ran out of MLG Points.");
                                break;
                            }
                        }
                        Console.WriteLine("\n\tYou successfully bought " + buyAttempt + " Dorito(s).");

                    }
                    else if (wannaBuy < 0) {
                        Console.WriteLine("\n\tDid you fail grade 2 math? You can't buy " + wannaBuy +
                                          " Doritos. Just to make you mad I'm going to make you lose all your money.");
                        MLGPoints = 0;
                    }
                } else {
                    Console.WriteLine("\n\tHAH. You're glad this isn't C++, or the program would've crashed because you didn't type a number.");
                }

                Console.WriteLine("\n\tDo you want to buy any Mountain Dew? Mountain Dew earns " + DewPtsTurn + " pts"+
                                  "/turn and costs " + DewCost + " MLG Points. If you do not wish to buy any, type 0.");
                attempt = Console.ReadLine();
                noError = Int32.TryParse(attempt, out wannaBuy);
                if (noError) {
                    if (wannaBuy > 0) {
                        int buyAttempt = 0;
                        for (; buyAttempt < wannaBuy; buyAttempt++) {
                            if (MLGPoints - DewCost >= 0) {
                                ++MTNDew;
                                MLGPoints -= DewCost;
                            } else {
                                Console.WriteLine("\n\tYou didn't have enough MLG Points to buy all those. You bought " + buyAttempt + " litres of Mountain Dew before you ran out of MLG Points.");
                                break;
                            }
                        }
                        Console.WriteLine("\n\tYou successfully bought " + buyAttempt + " litre(s) of Mountain Dew.");

                    }
                    else if (wannaBuy < 0) {
                        Console.WriteLine("\n\tDid you fail grade 2 math? You can't buy " + wannaBuy +
                                          " litres of Mountain Dew. Just to make you mad I'm going to make you lose all your money.");
                        MLGPoints = 0;
                    }
                } else {
                    Console.WriteLine("\n\tHAH. You're glad this isn't C++, or the program would've crashed because you didn't type a number.");
                }

                Console.WriteLine("\n\tTurn " + turns + " has ended.");
                Console.WriteLine("\n\t------------------------------------------------");
            }
            Console.WriteLine("The game has ended with you scoring " + MLGPoints + " MLG Points with " + Doritos + " Doritos and " + MTNDew + " litres of Mountain Dew!");
        }

        private static int CalcPtsTurn() {
            return Doritos * DoritosPtsTurn + MTNDew * DewPtsTurn;
        }
    }
}
