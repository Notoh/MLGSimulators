package io.notoh.mlgsim;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.System.out;

public class MLGSimulator {

    private Scanner scanner = new Scanner(System.in);

    private List<Dorito> doritos;
    private List<MtnDew> dew;
    private int mlgPoints;

    public static void main(String[] args) {
        boolean playAgain = true;
        while(playAgain) {
            MLGSimulator simulator = new MLGSimulator();
            playAgain = simulator.init();
        }
    }

    private boolean init() {
        scanner.useDelimiter("\\n");
        doritos = new ArrayList<>();
        dew = new ArrayList<>();
        mlgPoints = 100;
        return doGame();
    }

    private boolean doGame() {
        out.print("\n\t------MLG Simulator by Alex Pawelko-----\t\n");
        for (int i = 1; i < 16; i++) {
            out.print("\n\tYou are on turn " + i + ".");
            if (i > 1) {
                out.print("\n\tYou earned " + CalcPtsTurn() + " MLG Points this turn!");
                mlgPoints += CalcPtsTurn();
            }
            out.print("\n\tYou have " + mlgPoints + " MLG Points.");
            out.print("\n\tCurrently you have " + doritos.size() + " Dorito(s) and " + dew.size() + " " +
                    "litre(s) of Mountain Dew.");

            out.print("\n\tHow many Doritos do you want to buy? Doritos cost " + Dorito.COST + " MLG " +
                    "Points " +
                    "and earn " + Dorito.PTS_TURN + " MLG Points per turn!");
            int amount = scanner.nextInt();
            if (amount > 0) {
                for (int attempt = 0; attempt < amount; attempt++) {
                    if (mlgPoints - Dorito.COST >= 0) {
                        doritos.add(new Dorito());
                        mlgPoints -= Dorito.COST;
                    } else {
                        out.print("\n\tYou didn't have enough MLG Points to buy all those. " + (attempt > 0 ? attempt - 1 : attempt) + " were successfully bought.");
                        break;
                    }
                }
                out.print("\n\tYou now have " + doritos.size() + " Dorito(s)!");
            } else if (amount < 0) {
                out.print("\n\tTHIS PERSON RIGHT HERE IS THE NEXT MATH PRODIGY, TRYING TO BUY " + amount + "THINGS");
            }


            out.print("\n\tHow many litres of Mountain Dew do you want to buy? Dew costs " + MtnDew.COST
                    + " MLG Points per litre and earns " + MtnDew.PTS_TURN + " per turn.");
            amount = scanner.nextInt();
            if (amount > 0) {
                for (int attempt = 0; attempt < amount; attempt++) {
                    if (mlgPoints - MtnDew.COST >= 0) {
                        dew.add(new MtnDew());
                        mlgPoints -= MtnDew.COST;
                    } else {
                        out.print("\n\tYou didn't have enough MLG Points to buy all those. " + (attempt > 0 ? attempt - 1 : attempt) + " were successfully bought.");
                        break;
                    }
                }
                out.print("\n\tYou now have " + dew.size() + " litre(s) of Mountain Dew!");
            } else if (amount < 0) {
                out.print("THIS PERSON RIGHT HERE IS THE NEXT MATH PRODIGY, TRYING TO BUY " + amount + "THINGS");
            }
            out.print("\n\tTurn " + i + " has ended.");
            out.print("\n\t------------------------------------------------");
        }
        out.print("\n\tThe game has ended with you scoring " + mlgPoints + ", " + doritos.size() + " " +
                "Dorito(s) and " + dew.size() + " litre(s) of Mountain Dew.");
        out.print("\n\tDo you want to play again? (y/n)");
        return scanner.next().equalsIgnoreCase("y");
    }

    private int CalcPtsTurn() {
        return (doritos.size() * Dorito.PTS_TURN) + (dew.size() * MtnDew.PTS_TURN);
    }
}
