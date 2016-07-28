/********************************************************************************
Xylophone.cpp 

Date updated: 2016-05-15

Author: Prabal Khanal

*********************************************************************************
DESCRIPTION:
------------
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
---------
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
-----------------
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

You may use a part of or this entire code for non-commercial usage only.
*********************************************************************************/

#include "Xylophone.h"

//The version of the GLUT used here is a C library. So, it is not possible
//to initialize them from a user-defined class. In order to access methods
//from GLUT callback functions, a static function must be used/passed. 
//The glut callback functions used here are:glutKeyboardFunc, 
//glutKeyboardUpFunc, and glutCreateMenu

Xylophone* x_CurrentInstance;
extern "C"
{
	void keyDownCallback(unsigned char key, int x, int y)
	{
		x_CurrentInstance->keyboardPress(key, x, y);
	}

	void keyUpCallback(unsigned char key, int x , int y)
	{
		x_CurrentInstance->keyUp(key, x, y);
	}

	void displayMenuCallback(int id)
	{
		x_CurrentInstance->glutMenu(id);
	}

	void Xylophone::setupKeyDownCallback()
	{
		::x_CurrentInstance = this;
		::glutKeyboardFunc(::keyDownCallback);
	}

	void Xylophone::setupKeyUpCallback()
	{
		::x_CurrentInstance = this;
		::glutKeyboardUpFunc(::keyUpCallback);
	}

	void Xylophone::setupGlutMenuCallback()
	{
		::x_CurrentInstance = this;
		::glutCreateMenu(::displayMenuCallback);
	}
}

void Xylophone::displayMenu()
{
	glutAddMenuEntry("Twinkle Twinkle", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Happy Birthday", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Old McDonald", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Xylophone::setGamePlay(int rhyme)
{
	getDisplayManager()->resetTime();
	getDisplayManager()->setRhyme(rhyme); 
	getDisplayManager()->setCurIndex(0); 
	getDisplayManager()->setRhymeCompleted(0); 
	getDisplayManager()->setScore(0); 
	getDisplayManager()->setMisses(0);
}

void Xylophone::glutMenu(int ID)
{
	if (0 == ID)
		exit(0);

	setGamePlay(ID-1);
}

void Xylophone::moveNext()
{
	if(!getDisplayManager()->getGameMode())
		getDisplayManager()->setCurIndex(getDisplayManager()->getCurIndex()+1);
}

void Xylophone::finishRhyme()
{
	if(getDisplayManager()->getChord(getDisplayManager()->getRhyme(),getDisplayManager()->getCurIndex()) == -1) 
	{ 
		getDisplayManager()->startPlay = 0;
		getDisplayManager()->setRhymeCompleted(1); 
		getDisplayManager()->setCurIndex(0);
	}	
}

void Xylophone::calculateScore(int b)
{
	if(getDisplayManager()->getChord(getDisplayManager()->getRhyme(),getDisplayManager()->getCurIndex()) ==  b) 
	{
		if(!getDisplayManager()->getRhymeCompleted()) // don't count once rhyme is completed
			getDisplayManager()->setScore(getDisplayManager()->getScore() +1);		// hits
	}
	else
	{
		if(!getDisplayManager()->getRhymeCompleted())
			getDisplayManager()->setMisses(getDisplayManager()->getMisses() +1);	// misses
	}
}

void Xylophone::keyPressed(int blockID, bool pressed)
{
	getDisplayManager()->setTouch(blockID, pressed);
}

void Xylophone::keyboardPressEvents(int blockID)
{
	getAudioManager()->playSoundClip(getAudioManager()->getSound(getAudioManager()->getOctave()+blockID));
	calculateScore(blockID);
	keyPressed(blockID, true);
	moveNext();
	finishRhyme();
}

void Xylophone::keyboardPress(unsigned char key, int x, int y)
{
	//Start time constrained play when pressed the first key of a rhyme
	if(getDisplayManager()->getCurIndex() == 0) 
		getDisplayManager()->startPlay = 1;
	int keyInt = int(key) -49; // 49 is ASCII of '1'
	int sound;
	if (keyInt == -1) // 0 key
	{
		getAudioManager()->setOctave(getAudioManager()->getOctave() + 8);
		getDisplayManager()->setSound( (int) (getAudioManager()->getOctave()/8 ));
	}
	else if (keyInt == -22) // ESC key
	{
		exit(0);
	}
	else if(keyInt >= 0 && keyInt < 8) // keys 1-8
	{
		keyboardPressEvents(keyInt);
	}
	else if (keyInt == 8)
	{
		getDisplayManager()->setGameMode(!getDisplayManager()->getGameMode());
	}
}

void Xylophone::keyUp(unsigned char key, int x, int y)
{
	resetKeyPress();
}

void Xylophone::resetKeyPress()
{
	for(int i = 0; i < 8; i ++)
		getDisplayManager()->setTouch(i,false);
}

///*******************************************************************************
//Initializes GLUT for displaying a simple scene
//*******************************************************************************/
int main(int argc, char *argv[])
{
	ViewManager *vm = new ViewManager();
	AudioManager *am = new AudioManager();
	Xylophone *game = new Xylophone(vm, am);

	glutInit(&argc, argv);
	game->getDisplayManager()->displayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	game->getDisplayManager()->displaySize(800,500);
	game->getDisplayManager()->createWindow("Xylophone");
	game->getDisplayManager()->setupDrawCallback();
	game->getDisplayManager()->setupReshapeCallback();
	game->getDisplayManager()->glutIdle();
	game->setupKeyDownCallback();
	game->setupKeyUpCallback();
	game->setupGlutMenuCallback();
	game->displayMenu();

	game->getAudioManager()->initAL();
	game->getDisplayManager()->initScene();

	game->getDisplayManager()->openglMainLoop();

	return 0;
}