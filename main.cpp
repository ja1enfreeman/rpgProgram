/*
Jalen Freeman
CS 221 Fall 2023
Nov 05, 2023

RPG Program
*/

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

ofstream outputFile; // Define a custom output stream for the file

// Function to print to both console and file
void printToConsoleAndFile(const std::string& message) {
    cout << message;
    outputFile << message;
}

/* Structure to represent a player */
struct Player {
    string name;
    int health;
    string weapon;
    int potions = 3;
    int topHealth;
};

/* Function to handle 3 main player actions */
void fight(Player& attacker, Player& defender, int min, int max) {
    int attackerPoints = rand() % (max - min + 1) + min;
    int defenderPoints = rand() % (max - min + 1) + min;    // Generate random fight points for the attacker and defender

    // Determine the winner
    printToConsoleAndFile(attacker.name + "'s fight: " + std::to_string(attackerPoints) + " | " + defender.name + "'s fight: " + std::to_string(defenderPoints) + "\n\n");
    if (attackerPoints > defenderPoints) {
        int damage = attackerPoints - defenderPoints;
        defender.health -= damage;
        printToConsoleAndFile(attacker.name + " attacks " + defender.name + " for " + std::to_string(damage) + " damage!\n\n");
    } else if (attackerPoints < defenderPoints) {
        int damage = defenderPoints - attackerPoints;
        attacker.health -= damage;
        printToConsoleAndFile(defender.name + " attacks " + attacker.name + " for " + std::to_string(damage) + " damage!\n\n");
    } else {
        printToConsoleAndFile("It's a draw! No one takes damage.\n");
    }
}


/* Function to attack with weapon */
void useWeapon(Player& attacker, Player& defender, int min, int max) {
    int weaponDamage = rand() % (max - min + 1) + min;
    defender.health -= weaponDamage;
    printToConsoleAndFile(attacker.name + " uses " + attacker.weapon + " on " + defender.name + " for " + std::to_string(weaponDamage) + " damage!\n");
}

/* Function to drink healing potion */
void drinkHealingPotion(Player& player, int min, int max) {
    int healing = rand() % (max - min + 1) + min;
    if (player.health + healing <= player.topHealth) {
        player.health += healing;
    } else {
        player.health = player.topHealth;
    }
    printToConsoleAndFile(player.name + " drinks a healing potion and regains " + std::to_string(healing) + " amount of health.\n");
}

  int main() {
      outputFile.open("rpg-results.txt"); // Open an output file stream for the results

      if (!outputFile.is_open()) {
          std::cerr << "Error: Could not open rpg-results.txt" << std::endl;
          return 1; // Exit the program with an error code
      }

      // Declare player variables
        string gameLocation;
        int minFight, maxFight, maxWeapon, minWeapon, minHeal, maxHeal;

      // Read input from data file
        ifstream inputFile("rpg-data.txt");

        if (!inputFile.is_open()) {
            cout << "Error: Could not open rpg-data.txt" << endl;
            return 1; // Exit the program with an error code
        }

        Player player1, player2;

        inputFile >> gameLocation;
        inputFile >> player1.name >> player1.health >> player1.weapon;
        inputFile >> player2.name >> player2.health >> player2.weapon;
        inputFile >> minFight >> maxFight;
        inputFile >> minWeapon >> maxWeapon;
        inputFile >> minHeal >> maxHeal;


        inputFile.close(); // Close the input file


        player1.topHealth = player1.health; // Set upper limit for health 
        player2.topHealth = player2.health; // Set upper limit for health

        srand(static_cast<unsigned>(time(0))); // Seed the random number generator

       // Game loop
    printToConsoleAndFile("====== WELCOME TO THE BATTLE OF " + gameLocation + " ======\n\nFIGHTER INFORMATION:\n");
    printToConsoleAndFile(player1.name + " ---- Health: " + std::to_string(player1.health) + ", Weapon: " + player1.weapon + ", Potions: " + std::to_string(player1.potions) + "\n");
    printToConsoleAndFile(player2.name + " ---- Health: " + std::to_string(player2.health) + ", Weapon: " + player2.weapon + ", Potions: " + std::to_string(player2.potions) + "\n\n");

      bool player1Turn = true; // Initialize with Player 1's turn

      while (player1.health > 0 && player2.health > 0) {
          if (player1Turn) {
              // Display player information
              printToConsoleAndFile("--------------------------------\n");
              printToConsoleAndFile(player1.name + ": " + std::to_string(player1.health) + " | " + player2.name + ": " + std::to_string(player2.health) + "\n");
              printToConsoleAndFile("--------------------------------\n\n");

              // Player 1's turn
              printToConsoleAndFile("It's " + player1.name + "'s move. Current Health is " + std::to_string(player1.health) + "\n");
              printToConsoleAndFile("1. Fight\n");
              printToConsoleAndFile("2. Use '" + player1.weapon + "'\n");
              printToConsoleAndFile("3. Drink a Healing Potion (" + std::to_string(player1.potions) + " remaining)\n");
              int action;
              printToConsoleAndFile("\nAction: ");
              std::cin >> action;
              printToConsoleAndFile("\n\n");

              bool validInput = false;
              while (!validInput) {
                  switch (action) {
                      case 1:
                          fight(player1, player2, minFight, maxFight);
                          validInput = true;
                          break;
                      case 2:
                          useWeapon(player1, player2, minWeapon, maxWeapon);
                          validInput = true;
                          break;
                      case 3:
                          if (player1.potions > 0) {
                              drinkHealingPotion(player1, minHeal, maxHeal);
                              player1.potions--;
                          } else {
                              printToConsoleAndFile("You are out of healing potions.\n");
                          }
                          validInput = true;
                          break;
                      default:
                          printToConsoleAndFile("Invalid action. " + player1.name + ", please try again.\nEnter an action: ");
                          std::cin >> action;
                  }
                if (player2.health <= 0 || player1.health <= 0) {
                    printToConsoleAndFile("\nGame over! " + player1.name +  " has defeated " + player2.name + "\n");
                }
              }
          }

          // Player 2's turn
          // Display player information
          printToConsoleAndFile("--------------------------------\n");
          printToConsoleAndFile(player1.name + ": " + std::to_string(player1.health) + " | " + player2.name + ": " + std::to_string(player2.health) + "\n");
          printToConsoleAndFile("--------------------------------\n\n");
          printToConsoleAndFile("It's " + player2.name + "'s move. Current Health is " + std::to_string(player2.health) + "\n");
          printToConsoleAndFile("1. Fight\n");
          printToConsoleAndFile("2. Use '" + player2.weapon + "'\n");
          printToConsoleAndFile("3. Drink a Healing Potion (" + std::to_string(player2.potions) + " remaining)\n");
          printToConsoleAndFile("Action: ");
          int action;
          std::cin >> action;
          printToConsoleAndFile("\n\n");

          bool validInput = false;
          while (!validInput) {
              switch (action) {
                  case 1:
                      fight(player2, player1, minFight, maxFight);
                      validInput = true;
                      break;
                  case 2:
                      useWeapon(player2, player1, minWeapon, maxWeapon);
                      validInput = true;
                      break;
                  case 3:
                      if (player2.potions > 0) {
                          drinkHealingPotion(player2, minHeal, maxHeal);
                          player2.potions--;
                      } else {
                          printToConsoleAndFile("You are out of healing potions.\n");
                      }
                      validInput = true;
                      break;
                  default:
                      printToConsoleAndFile("Invalid action. " + player2.name + ", please try again.\nEnter an action: ");
                      std::cin >> action;
              }
            if (player2.health <= 0 || player1.health <= 0) {
              printToConsoleAndFile("\nGame over! " + player1.name +  " has defeated " + player2.name + "\n");
            }
          }
      }

      // Check for a winner
      if (player1.health <= 0) {
          printToConsoleAndFile("\nGame over! " + player2.name +  " has defeated " + player1.name + "\n");
      }
      if (player2.health <= 0) {
          printToConsoleAndFile("\nGame over! " + player1.name +  " has defeated " + player2.name + "\n");
      }

      // Close the output file
      outputFile.close();

      return 0;
  }

