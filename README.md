# engg1340comp2113
class project of comp2113

works to be done:
Identification of the team members.
A description of your game and introduce the game rules.
A list of features that you plan to implement, and explain how each coding element 1 to 5 listed under the coding requirements aforementioned support your features.

1. Identification of the team members.
Zhang Yuhan (3035771672)
Chen Jingyan (3035827940)

2. Description and game rules.

A knight saving a princess from the dragon. There are three traps/barriers for the knight to pass and a final battle between the knight and the dragon. 
The knight has Hit point (HP), Mana point (MP), and golden coins. He can get to a higher level of HP, MP, and earn more coins by the previous battles. Higher MP leads to a higher damage to his enemies. The coins can be used to buy medicines and weapons in the store. 

The knight will start from the noice village to learn some basic skills. On his road to the black castle, he will first meet some little monsters in the forest, some traps left by the hunter, and some guards from the castle. The difficulty of passing the barriers will increase, and the last one with the dragon is the hardest. Finally, if he has cleared all the stages, he can meet the princess, but he still has to answer some questions to take her away. 

Rules:
If the knight loses all his HP on his way, the player loses the game.
If the knight is still alive after beating the dragon and answer the princess's question correctly, the player wins the game.

3. Features
Our game will be a text-based adventure game. The player can tell his or her current situations through texts and make several actions to reach their final goal.
This game will be a PvE game with player and NPC take turns to fight.
A.Player's situation and actions generating
  The function will be able to calculate and store the current situations of the player. For example, for the HP of the player, every actions he made will possible affect his HP. Regarding different action commands, we'll call different calculation function to increase or decrease or do no change to the player's HP, and returned the new value to the main memory.
The player will also be provided with a list of actions he could do when he call's out either the main menu or fighting menu and so on. Different action commands will lead to several funtions to achieve different goals.
B.Game NPC's situation and actions generating
  Each Game NPC will have his or her own list of functions and attributes. For example during the fight with the player, we'll provide a list of actions the NPC can do and randomly generating actions from their list. 



