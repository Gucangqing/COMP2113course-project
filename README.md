# engg1340comp2113
class project of COMP2113

Works to be done:

1. Identification of the team members.

  Zhang Yuhan (3035771672)
  Chen Jingyan (3035827940)

2. An improved description of your game and introduce the game rules.

  The princess of the Maigic Kindom was captured by the evil Dragon, the King announced that whoever can save the princess can marry her. 
  The player will act as a challenger trying to save the princess. He will first be given HP(health points), AP(attack points), and a random gift. More HP means higher chance to survive, and more AP means more attack skills with higher damage to the enemies. 
  On the way to the Dragon's castle, there are two Critters. The player has to beat the Critters for the final battle with the Dragon. The difficulty of the three battles is increasing. If the player lose all his HP, he will die and he has to restart the battle. If the player can beat the Dragon and answer the princess's question correctly, he will win the game. 

3. A list of features that you have implemented, and explain how each coding element 1 to 5 listed under the coding requirements aforementioned support your features.

 Coding element:
  1. Generation of random game sets or events: The player's skill points(HP & AP) and gift will be generated randomly, and the the skill that the player and his enemies play in the game will also be generated randomly.
  2. Data structures for storing game status: The player's and NPC's attack skills are all stored in structs.
  3. Dynamic memory management: Every time when the AP changes, the attack skills are added.
  4. File input/output (e.g., for loading/saving game status): The player's life and shield is saved at the beginning, and will be used during the game.
  5. Program codes in multiple files: The main function and the self-defined functions are written in separated files. There is a function.h files saving the functions, and a function.cpp file defining the functions.
  
  Features: 
  Our game will be a text-based adventure game. The player can tell his or her current situations through texts and make several actions to reach their final goal. This game will be a PvE game with player and NPC take turns to fight.
  
  A. Player's situation and actions generating
  The function will be able to calculate and store the current situations of the player. For example, for the HP of the player, every actions he made will possible affect his HP. Regarding different action commands, we'll call different calculation function to increase or decrease or do no change to the player's HP, and returned the new value to the main memory.
  The player will also be provided with a list of actions he could do when he call's out either the main menu or fighting menu and so on. Different action commands will lead to several funtions to achieve different goals.
  
  B. Game NPC's situation and actions generating
  Each Game NPC will have his or her own list of functions and attributes. For example during the fight with the player, we'll provide a list of actions the NPC can do and randomly generating actions from their list. 

4. A list of non-standard C/C++ libraries, if any, that are used in your work and integrated to your code repo. Please also indicate what features in your game are supported by these libraries.

  We didn't use any non-standard C/C++ library.

5. Compilation and execution instructions. Simply put, this serves like a "Quick start" of your game.

   First of all, our program will introduce the background of the story. After the player agrees to start the challenge, he will be randomly given a number of skill points. The skill points are composed of HP(health points) and AP(attack points), and the player can assign his skill points to these two aspects. One HP means ten drop of blood, and one AP means a new attack skill. Next, the player will be given a chance to get a random gift.
   After the prepare work, the game is on. The player will meet two Critters and a Dragon, and he has to beat all of them. The skills played by the player and his enemies are all randomly selected. If the player is dead in a fight, he will be asked if he wants to restart it. And after each battle, the player will be given some additional skill points, which he can assign by himself.
   After three battles, the player has to answer a question correctly to win the game.

