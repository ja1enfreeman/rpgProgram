# RPG Battle Simulator

This C++ program simulates a turn-based battle between two players in a role-playing game (RPG). Players take turns to fight, use weapons, and drink healing potions until one of them emerges victorious.

## Features:

- **Player Structure:** Represents a player with attributes such as name, health, weapon, and potions.
- **Fight Function:** Determines the winner of a fight based on randomly generated points and inflicts damage accordingly.
- **Weapon Use Function:** Allows a player to use their weapon, dealing damage to the opponent.
- **Healing Potion Function:** Enables a player to drink a healing potion, restoring a random amount of health.
- **Game Loop:** Alternates between the turns of Player 1 and Player 2 until one of them runs out of health.

## File Operations:

- **Output File:** Results of the RPG battles are recorded in a file named `rpg-results.txt`.
- **Input Data:** Player attributes and game settings are read from a data file named `rpg-data.txt`.

## Usage:

1. Ensure that the program is provided with the correct data files (`rpg-data.txt`).
2. Players take turns choosing actions: Fight, Use Weapon, or Drink Healing Potion.
3. The battle results are displayed in both the console and the output file.

## Usage Instructions:

1. Compile and run the program.
2. Follow the prompts to enter actions during each player's turn.
3. Monitor the console for battle updates and check the `rpg-results.txt` file for detailed results.

## Game Over:

The game concludes when one of the players' health drops to zero or below. The winner is declared in the console and output file.

## Important Notes:

- This program utilizes both standard output (console) and a custom output stream to write results to a file simultaneously.
- Ensure that the input data file (`rpg-data.txt`) is correctly formatted for the program to execute successfully.

Feel free to explore the code for a deeper understanding of the RPG battle simulation. Enjoy the game!
