/*
Class name: ViewManager
Visually reenders various objects (keys, texts, HUD) on the screen. 
*/
#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

# include <GL/glut.h>
# include <math.h>
# include "Timer.h"


class ChordInfo
{
	int chordVal;
	float timeGap;
public:
	ChordInfo (int chord, float timeSpan){chordVal = chord; timeGap = timeSpan;}
	int getVal();
	float getTimeGap();
};


#define TIME_GAP 1
#define NUM_CHORDS 8 // number of chords being used in this app.
					 // C D E F G B A C
#define NUM_FONTS 2  // number of fonts being used

#define RHYMES		3	// number of rhymes 
#define MAX_LENGTH	50	// maximum number of chords that can be played

//#define GAMEMODE 1		// get points only keys are pressed on specified time

class ViewManager
{
protected:
	//initilize required openGL parameters to display various 
	//objects on the screen
	XTimer *xTime ; 
	void initGL(); 
	
public:
	ViewManager();
	
	XTimer* getTimeManager()
	{
		return xTime;
	}

	void initScene();

	void glutDisplay();
	
	void glutReshape(int width, int height);
	
	void glutIdle(void);    
	
	void displayMode(unsigned int);
	
	void displaySize(int, int);
	
	//create window with title
	void createWindow(char *);
	
	// calls glut mainloop
	void openglMainLoop(); 

	// calls openGL display function
	void setupDrawCallback(); 
	
	// calls openGL reshape function
	void setupReshapeCallback();
	
	// draws and displays objects on the screen
	void drawSceneGraphics();
	
	int getWidth();
	void setWidth(int);
	
	int getHeight();
	void setHeight(int);

	int getCurIndex();
	void setCurIndex(int);
	
	// get/set rhymes (twinkle twinkle, happy birthday, old mcdonald)
	int getRhyme();
	void setRhyme(int); 
	
	//writes text starting at (x,y,z) with (r,g,b) color.
	void drawHUDText(float r, float g, float b, float x, float y, float z, char* text);
	void printChords(float, void**);
	void drawHUD();

	void changeColor(unsigned char, bool);
	
	// sets block[i] flag status
	void setTouch(int id, bool flag); 
	
	void setRhymeCompleted(int);
	int getRhymeCompleted(); 
	
	void setMisses(int); 
	int getMisses();

	int getScore();// get correct hits
	void setScore(int); // track correct hits and score
	
	// return the chord[rhyme][curIndex]
	int getChord(int rhyme, int curIndex);

	float getTime(int r, int c);

	//Get the touched/pressed status of a block "i" 
	bool getTouch(int i);

	int getSound();
	void setSound(int );

	int getGameMode();
	void setGameMode(int mode);

	int startPlay;
	void drawTimeElapsed();
	void resetTime();
private:
	ChordInfo *chordInfo;
	int gameMode;
	bool testOnce;
	int sound;
	bool bTouched[NUM_CHORDS]; 
	ChordInfo * chords[RHYMES][MAX_LENGTH];
	int RHYME ;
	int score ;
	int miss ;
	int percent ;
	int rhymeCompleted ;
	int curIndex ;
	int sec;
	int min;

	typedef enum {
		MODE_BITMAP,
		MODE_STROKE
	} modeType;

	modeType mode;
	int fontIndex;
	void* bitmap_fonts[NUM_FONTS];
	bool bChangeColor;
	int width, height;
	void drawBlock(float, int, bool);
};

#endif

