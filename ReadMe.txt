#Xylophone game

#Author: Prabal Khanal

#Please read this file before compiling the solution.

*********************************************************************************
HOW TO BUILD THE PROGRAM
************************
To compile the code, you need the following dependencies

1. alut
2. OpenAL32
3. glut32

Header files are placed in include folder
Source files are placed in source folder
Static libraries are placed in lib folder
Dynamic libraries are placed in bin/$(Configuration) folder.
Sounds are placed in sound folder

You will also need to install OpenAL SDK installer from 
	https://www.openal.org/downloads/oalinst.zip

You can download OpenAL core SDK from https://www.openal.org/downloads/ page.


*********************************************************************************
DESCRIPTION:
************
This application simulates a xylophone game using OpenGL. Instead of just hitting
keys, this provides different rhymes that users can play with. They have to hit 
the right keys (and right time, depending on game mode) to get score. 

Key press events are used to simulate "hitting" keys (and chords). The key-chord
assignments are as follows:

	1 - C
	2 - D
	3 - E
	4 - F
	5 - G
	6 - A
	7 - B
	8 - C

In addition to the rhymes, this game also allows to change sounds during gameplay.

*********************************************************************************
FEATURES:
*********
The app provides:
  1. 3 rhymes that are built into it (can be changed by right clicking and selecting
     a rhyme
		- Twinkle twinkle little star
		- Happy birthday to you
		- Old McDonalds had a farm

  2. 3 different sounds (which can be changed by pressing '0' key)

  3. 2 game modes
		- Freestyle - hit the right keys to get points, time is not a factor
		- Time constrained - hit the right keys at the right time to get points


*********************************************************************************
HOW TO PLAY:
************
This game is very simple to play. You have to follow and hit the highlighted key 
(with red color) with the assigned key. 

In freestyle mode, you just have to hit the right keys, take as long as you want, 
no pressure at all. 

In time constrained mode, you have to hit the right keys at the right time as well.
Otherwise, the hit does not count towards your score.

You can switch between the game modes by pressing '9'.

You can change the rhymes by right clicking and selecting/clicking any of the 
rhymes listed. 

You can switch to a different sound by pressing '0'

And when you want to exit, just hit ESC key or right click and click on Quit.

*********************************************************************************
KEY ASSIGNMENTS:
****************
KEY - What it does
1   - Plays chord C
2   - Plays chord D
3   - Plays chord E
4   - Plays chord F
5   - Plays chord G
6   - Plays chord A
7   - Plays chord B
8   - Plays chord C (next octave)
9	- Switches game mode between freestyle and time constrained
0	- Switches between sounds
ESC	- Exits the program

*********************************************************************************
DISCLAIMER:
***********
The versions of OpenAL and OpenGL used are free and open for non commercial purpose.

You may use a part of or this entire code for non-commercial usage only.
*********************************************************************************/
