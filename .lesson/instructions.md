<p><strong>Assignment Description</strong></p>
<p>You have been tasked to write a <strong>C++</strong> program for a simple text-based 2-person role-playing game (RPG). Read all these instructions carefully and completely before starting to write any code.</p>
<p><strong>Input File and Game Setup</strong></p>
<p>The character data and game parameters will be specified in an input text file named <code>rpg-data.txt</code>. The input file will contain 6 lines with the following format. Note that in the template below "P1" refers to Player 1 and "P2" refers to Player 2.</p>

```
Game_Location
P1_Name P1_Health P1_Weapon
P2_Name P2_Health P2_Weapon
Min_Fight Max_Fight
Min_Weapon Max_Weapon
Min_Heal Max_Heal
```

<ul>
    <li>Line 1 represents the game location as a string. You can assume that the location will not contain any spaces.</li>
    <li>Line 2 represents Player 1's name (string), starting health (integer) and weapon (string) separated by spaces. Player names will not contain spaces.</li>
    <li>Line 3 represents Player 2's name (string), starting health (integer) and weapon (string) separated by spaces. Player names will not contain spaces.</li>
    <li>Line 4 is the game's min/max values for damage when players fight without weapons (see below)</li>
    <li>Line 5 is the game's min/max values for damage when players use their weapons (see below)</li>
    <li>Line 6 is the game's min/max values for healing when players use a healing potion (see below)</li>
</ul>
<p>Example Input file:</p>

```
Moon_of_Endor
Widget 90 Bola
Storm_Trooper 85 Blaster
10 25
5 10
1 10    
```

<p>This represents a game that takes place on the "Moon_of_Endor" between Widget (starting health of 90 with a 'Bola' weapon) and Storm_Trooper (starting health of 85 with a 'Blaster' weapon).</p>
<ul>
<li>When the two fight, their fight points will be random numbers between 10 and 25 (inclusive)</li>
<li>When either attacks with their weapon the damage dealt will be a random number between 5 and 10 (inclusive)</li>
<li>When either drinks a healing potion, they will gain a random number of health points between 1 and 10 (inclusive)</li>
  </ul>
<p><strong>Playing the Game and Output</strong></p>
<p>All output regarding the game play must be printed to the console <strong>and </strong>to an output file called rpg-results.txt. The identical messages must be printed to both the console and the output file. Your program should output a message at the beginning of the game stating the location and the names of the two characters, their health points and weapons (see sample output below). At the end of the game should be the final health points and who the winner was.</p>
<p>The game proceeds in turns, with Player 1 always starting first. On each player's turn, the program will display a menu with three options representing the three moves the player can take. Note: the menu should <strong>not</strong> be printed to the output file, only to the console. It should be clear which player's turn it is and their current health.</p>
<p>Next, the program will print out which character's turn it is and their health. Then the program will display a menu with three options representing the actions each character can take. The hero always goes first. For example,</p>

```
It's Widget's move. Current Health is 90
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (3 remaining )
Action:
```

<p>Notes:</p>
<ul>
    <li>Option 2 includes the weapon for this character.&nbsp; This must be unique to each player (as read from the input file)</li>
    <li>Option 3 shows how many potions are remaining. Each player receives 3 potions to begin with (see details on healing below)</li>
</ul>
<p>Once the user enters an action, use a <code>switch</code> statement to take one of the following actions:</p>
<ul>
    <li><strong>Fight</strong>: Generate two random integer value between <code>Min_Fight</code> and <code>Max_Fight</code>, <em>one for each player. </em>Use the two random values to determine who wins the fight: <br />
        <ul>
            <li>If one of the numbers is larger than the other, the player with the larger number wins and the <strong>difference </strong>between the two values is deducted from the loser's health.</li>
            <li>If the numbers are the same, it's a draw and neither player loses any health points.</li>
        </ul>
    </li>
    <li><strong>Use a Weapon</strong>: Generate a random integer between <code>Min_Weapon</code> and <code>Max_Weapon</code> and subtract that amount from the other player's health.</li>
    <li><strong>Healing</strong>: Generate a random value between <code>Min_Heal</code> and <code>Max_Heal</code> and add that amount to the current player's health. Rules:
        <ul>
            <li>A player's health should never exceed the starting health read from the input file.</li>
            <li>A player can only drink a healing potion a total of 3 times during a game. The action menu should display the number of remaining potions when a player is up. If a player tries to heal with no remaining motions there must be a message indicating they are out.</li>
        </ul>
    </li>
</ul>
<p>After a player chooses an action, perform the action then show the result. Then print the menu again for the next player. See the sample output below.</p>
<p>Continue the game until one player's health is less than or equal to 0. Print the results of the game then exit the program.</p>
<p><strong>Assumptions, Other Requirements and Tips</strong></p>
<ul>
    <li>If the file <code>rpg-results.txt</code> does not exist, print a message and exit the game. The <code>ifstream</code> function <code>is_open</code> can help here.</li>
    <li>You do not need to do any error checking or input validation on <code>rpg-results.txt.</code>You can assume the file format is correct and all lines are formatted correctly. You can also assume that for each range the min/max values are integers and min &lt; max.</li>
    <li>The action input by the user must be validated. An incorrect action should result in an error message and prompt the same player to try again.</li>
    <li>Don't forget to close your files when you are done with them! If you don't close your output file, it's possible nothing will be written to it when your program ends.</li>
    <li>You must use a <code>switch</code> structure to determine which option was selected.</li>
    <li>All messages that detail the results of an action must include the name of the players involved.</li>
    <li>It may be helpful, though not required, to write functions/methods to help organize your code. Make sure that each method has a clear single purpose. For example, you don't want a method that both prints the menu and deals with potions.</li>
    <li>While we haven't covered structs or object classes yet, you are free to use those in your solution if you choose. This program does not require them and can be done only with basic looping and conditional constructs, and variables.</li>
    <li>While the starting project will contain my sample input file, <strong>you must change the names of the characters, the weapons, the starting health and the min/max values for each range in your input file</strong>. Feel free to be creative!</li>
</ul>
<p><strong>Formatting and Programming Guidelines</strong></p>
<p>Review the <a title="Programming Assignment Guidelines" href="https://eou.instructure.com/courses/37980/pages/programming-assignment-guidelines" data-api-endpoint="https://eou.instructure.com/api/v1/courses/37980/pages/programming-assignment-guidelines" data-api-returntype="Page">Programming Assignment Guidelines</a> to ensure you don't lose any points for simple things like missing headers or formatting mistakes.</p>
<p><strong>Sample Output</strong></p>
<p>Note: Your output<strong> does not</strong> have to match this exactly. Feel free to be creative with your display messages and output format. Your output must contain the messages described in the requirements above (e.g. the starting character names, health value and weapons, the result of each action, and the health points for each player before each move).</p>

```
======== The Battle of Moon_of_Endor ========

Widget (90 Health) with a Bola
    vs.
Storm_Trooper (85 Health) with a Blaster


--------------------------------
Widget: 90 | Storm_Trooper: 85
--------------------------------

It's Widget's move. Current Health is 90
1. Fight 
2. Use 'Bola' <span style="color: #e69e9e;">// Note the weapon for this player is shown</span>
3. Drink a Healing Potion (3 remaining)
Action: 1

Widget has challenged Storm_Trooper to fight
    Widget: 17 | Storm_Trooper: 16
Widget deals 1 damage to Storm_Trooper

--------------------------------
Widget: 90 | Storm_Trooper: 84
--------------------------------

It's Storm_Trooper's move. Current Health is 84
1. Fight 
2. Use 'Blaster'
3. Drink a Healing Potion (3 remaining)
Action: 2

Storm_Trooper uses a Blaster to attack Widget for 8 damage

--------------------------------
Widget: 82 | Storm_Trooper: 84
--------------------------------

It's Widget's move. Current Health is 82
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (3 remaining)
Action: 3

Widget drinks a healing potion and regains 6 health points

--------------------------------
Widget: 88 | Storm_Trooper: 84
--------------------------------

It's Storm_Trooper's move. Current Health is 84
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (3 remaining)
Action: 4

4 is an invalid entry. Please select 1-3

--------------------------------
Widget: 88 | Storm_Trooper: 84
--------------------------------
<span style="color: #e69e9e;">// Note that it is still Storm_Trooper's move</span>

It's Storm_Trooper's move. Current Health is 84
1. Fight 
2. Use 'Blaster'
3. Drink a Healing Potion (3 remaining)
Action: 3

Storm_Trooper drinks a healing potion and regains 4 health points

--------------------------------
Widget: 88 | Storm_Trooper: 85   
--------------------------------
<span style="color: #e69e9e;">// Note Storm_Trooper's health does not exceed that player's starting health</span>

It's Widget's move. Current Health is 88
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (2 remaining) <span style="color: #e69e9e;">// Note the remaining potions</span>
Action: . . .

--------------------------------
Widget: 88 | Storm_Trooper: 73
--------------------------------

It's Widget's move. Current Health is 88
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (0 remaining)
Action: 3

Widget is out of healing potions!
<span style="color: #e69e9e;">// Show a message if a player goes over their potion limit</span>

. . .

--------------------------------
Widget: 22 | Storm_Trooper: 1
--------------------------------

It's Storm_Trooper's move. Current Health is 1
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (2 remaining)
Action: 1

Storm_Trooper has challenged Widget to fight
    Widget: 17 | Storm_Trooper: 17
The fight is a draw. Neither player loses any health points
<span style="color: #e69e9e;">// The random fight values were equal so the fight is a draw</span>

--------------------------------
Widget: 22 | Storm_Trooper: 1
--------------------------------

It's Widget's move. Current Health is 22
1. Fight 
2. Use 'Bola'
3. Drink a Healing Potion (0 remaining)
Action: 2

Widget uses a Bola to attack Storm_Trooper for 6 damage

--------------------------------
Widget: 22 | Storm_Trooper: -5
--------------------------------

Widget has defeated Storm_Trooper!
```
   
The output file for this game, <code>rpg-results.txt</code>
    
```    
    ======== The Battle of Moon_of_Endor ========
    
    Widget (90 Health) with a Bola
        vs.
    Storm_Trooper (85 Health) with a Blaster
    
    --------------------------------
    Widget: 90 | Storm_Trooper: 85
    --------------------------------
    Widget has challenged Storm_Trooper to fight
    	Widget: 17 | Storm_Trooper: 16
    Widget deals 1 damage to Storm_Trooper
    --------------------------------
    Widget: 90 | Storm_Trooper: 84
    --------------------------------
    Storm_Trooper uses a Blaster to attack Widget for 8 damage
    --------------------------------
    Widget: 82 | Storm_Trooper: 84
    --------------------------------
    Widget drinks a healing potion and regains 6 health points
    --------------------------------
    Widget: 88 | Storm_Trooper: 84
    --------------------------------
    Storm_Trooper drinks a healing potion and regains 4 health points
    --------------------------------
    Widget: 88 | Storm_Trooper: 85
    --------------------------------
    . . .
    --------------------------------
    Widget: 88 | Storm_Trooper: 73
    --------------------------------
    Widget is out of healing potions!
    . . . 
    --------------------------------
    Widget: 22 | Storm_Trooper: 1
    --------------------------------
    Storm_Trooper has challenged Widget to fight
        Widget: 17 | Storm_Trooper: 17
    The fight is a draw. Neither player loses any health points
    --------------------------------
    Widget: 22 | Storm_Trooper: 1
    --------------------------------
    Widget uses a Bola to attack Storm_Trooper for 6 damage
    --------------------------------
    Widget: 22 | Storm_Trooper: -5
    --------------------------------
    
    Widget has defeated Storm_Trooper!
```
<p><strong>Where to Start<br /></strong></p>
<p>After reading these instructions completely and carefully, start with this replit project and put all your code in <code>main.cpp</code>.</p>
<p>There are no automated tests for this project, other than to confirm your program will run and compile. Double-check each requirement before submitting your project in replit.</p>
<p><strong>Submit</strong></p>
<p>Besides submitting the project in replit, you must also submit the Canvas assignment with a link to your repl.it project.</p>
