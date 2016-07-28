/*
Class name: Xylophone
This is the main class of the program.
All the game play events and scoring is handled from this class
*/
#ifndef XYLOPHONE_H
#define XYLOPHONE_H

#include <stdlib.h>
#include "ViewManager.h"
#include "AudioManager.h"

class Xylophone
{
private:
	ViewManager *displayManager;
	AudioManager *audioManager;

public:

	Xylophone (ViewManager *vm, AudioManager *am)
	{ 
		displayManager = vm; 
		audioManager = am;
	}
	~Xylophone()
	{
		delete displayManager;
		delete audioManager;
	}
	ViewManager *getDisplayManager() {return displayManager;}
	AudioManager *getAudioManager() {return audioManager;}
	
	//openGL functions for key press and key up
	void keyboardPress(unsigned char, int, int);
	void keyUp(unsigned char , int , int);
	void setupKeyDownCallback();  
	void setupKeyUpCallback(); 

	//calculate hits and misses of the keys
	void calculateScore(int);

	// create and display menu on mouse right click
	void glutMenu(int); 
	void displayMenu(); 
	void setupGlutMenuCallback(); 

	//highlight the next key to be pressed (with red color)
	void moveNext(); 

	//performs various actions when a key is pressed
	void keyboardPressEvents(int );

	// called when a rhyme is finished
	void finishRhyme();

	//when key is "unpressed", this resets the flags for keys/blocks
	void resetKeyPress();
	void keyPressed(int, bool);

	//sets/resets various parameters for each rhyme
	void setGamePlay(int );
};
#endif
