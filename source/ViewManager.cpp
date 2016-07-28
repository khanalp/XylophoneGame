#include <string>
#include <Windows.h>
#include "ViewManager.h"


ViewManager* g_CurrentInstance;
extern "C"
{

	void displayCallback()
	{
		g_CurrentInstance->glutDisplay();
	}
	void reshapeCallback(int w, int h)
	{
		g_CurrentInstance->glutReshape(w, h);
	}

	void ViewManager::setupDrawCallback()
	{
		::g_CurrentInstance = this;
		::glutDisplayFunc(::displayCallback);
	}

	void ViewManager::setupReshapeCallback()
	{
		::g_CurrentInstance = this;
		::glutReshapeFunc(::reshapeCallback);
	}

}

int ChordInfo::getVal()
{
	return chordVal;
}

float ChordInfo::getTimeGap()
{
	return timeGap;
}

ViewManager::ViewManager()
{
	gameMode = 1;
	startPlay = 0;
	xTime = new XTimer();
	testOnce = true;
	min = sec = 0;
	//Twinkle twinkle little star
	/*
	0,0,4,4,5,5,4,
	3,3,2,2,1,1,0,
	4,4,3,3,2,2,1,
	4,4,3,3,2,2,1,
	0,0,4,4,5,5,4,
	3,3,2,2,1,1,0, 
	-1
	*/
	float timeShort = TIME_GAP - 0.5;
	float timeLong = TIME_GAP - 0.3;
	chords[0][0] = new ChordInfo(0,timeShort);
	chords[0][1] = new ChordInfo(0,timeLong);//0.7
	chords[0][2] = new ChordInfo(4, timeShort);
	chords[0][3]  =  new ChordInfo(4 , timeLong);
	chords[0][4]  =  new ChordInfo(5 , timeShort);
	chords[0][5]  =  new ChordInfo(5 , timeLong);
	chords[0][6]  =  new ChordInfo(4 , timeLong);
	chords[0][7]  =  new ChordInfo(3 , timeShort);
	chords[0][8]  =  new ChordInfo(3 , timeLong);
	chords[0][9]  =  new ChordInfo(2 , timeShort);
	chords[0][10] =  new ChordInfo(2 , timeLong);
	chords[0][11] =  new ChordInfo(1 , timeShort);
	chords[0][12] =  new ChordInfo(1 , timeLong);
	chords[0][13] =  new ChordInfo(0 , timeLong);
	chords[0][14] =  new ChordInfo(4 , timeShort);
	chords[0][15] =  new ChordInfo(4 , timeLong);
	chords[0][16] =  new ChordInfo(3 , timeShort);
	chords[0][17] =  new ChordInfo(3 , timeLong);
	chords[0][18] =  new ChordInfo(2 , timeLong);
	chords[0][19] =  new ChordInfo(2 , timeLong);
	chords[0][20] =  new ChordInfo(1 , timeShort);
	chords[0][21] =  new ChordInfo(4 , timeLong);
	chords[0][22] =  new ChordInfo(4 , timeShort);
	chords[0][23] =  new ChordInfo(3 , timeLong);
	chords[0][24] =  new ChordInfo(3 , timeShort);
	chords[0][25] =  new ChordInfo(2 , timeLong);
	chords[0][26] =  new ChordInfo(2 , timeShort);
	chords[0][27] =  new ChordInfo(1 , timeLong);
	chords[0][28] =  new ChordInfo(0 , timeShort);
	chords[0][29] =  new ChordInfo(0 , timeLong);
	chords[0][30] =  new ChordInfo(4 , timeShort);
	chords[0][31] =  new ChordInfo(4 , timeLong);
	chords[0][32] =  new ChordInfo(5 , timeShort);
	chords[0][33] =  new ChordInfo(5 , timeLong);
	chords[0][34] =  new ChordInfo(4 , timeShort);
	chords[0][35] =  new ChordInfo(3 , timeLong);
	chords[0][36] =  new ChordInfo(3 , timeShort);
	chords[0][37] =  new ChordInfo(2 , timeLong);
	chords[0][38] =  new ChordInfo(2 , timeShort);
	chords[0][39] =  new ChordInfo(1 , timeLong);
	chords[0][40] =  new ChordInfo(1 , timeShort);
	chords[0][41] =  new ChordInfo(0 , timeLong);
	chords[0][42] =  new ChordInfo(-1, timeShort); // denotes the end of the rhyme


	//Happy birthday
	/*
	0,0,1,0,3,2,
	0,0,1,0,4,3, 
	0,0,7,5,3,2,1,
	7,7,5,3,4,3,
	-1
	*/
	chords[1][0] = new ChordInfo( 0, timeShort);
	chords[1][1] = new ChordInfo( 0, timeLong);
	chords[1][2] = new ChordInfo( 1, timeLong);
	chords[1][3] = new ChordInfo( 0, timeLong);
	chords[1][4] = new ChordInfo( 3, timeLong);
	chords[1][5] = new ChordInfo( 2, timeLong*2);
	chords[1][6] = new ChordInfo( 0, timeShort);
	chords[1][7] = new ChordInfo( 0, timeLong);
	chords[1][8] = new ChordInfo( 1, timeLong);
	chords[1][9] = new ChordInfo( 0, timeLong);
	chords[1][10] =new ChordInfo( 4, timeLong);
	chords[1][11] =new ChordInfo( 3, timeLong*2);
	chords[1][12] =new ChordInfo( 0, timeShort);
	chords[1][13] =new ChordInfo( 0, timeLong);
	chords[1][14] =new ChordInfo( 7, timeLong);
	chords[1][15] =new ChordInfo( 5, timeLong);
	chords[1][16] =new ChordInfo( 3, timeLong);
	chords[1][17] =new ChordInfo( 2, timeLong);
	chords[1][18] =new ChordInfo( 1, timeLong*2);
	chords[1][19] =new ChordInfo( 7, timeShort);
	chords[1][20] =new ChordInfo( 7, timeLong);
	chords[1][21] =new ChordInfo( 5, timeLong);
	chords[1][22] =new ChordInfo( 3, timeLong*1.5);
	chords[1][23] =new ChordInfo( 4, timeLong*2);
	chords[1][24] =new ChordInfo( 3, timeLong);
	chords[1][25] =new ChordInfo(-1, timeShort);

	//Old McDonald
	/*
	3,3,3,0,1,1,0,5,5,4,4,3,0,
	3,3,3,0,1,1,0,5,5,4,4,3,
	3,3,3,
	3,3,3,
	3,3,3,3,
	3,3,3,0,1,1,0,5,5,4,4,3,
	-1	
	*/
	chords[2][0]  = new ChordInfo( 3, timeShort);
	chords[2][1]  = new ChordInfo( 3, timeShort);
	chords[2][2]  = new ChordInfo( 3, timeShort);
	chords[2][3]  = new ChordInfo( 0, timeShort);
	chords[2][4]  = new ChordInfo( 1, timeShort);
	chords[2][5]  = new ChordInfo( 1, timeShort);
	chords[2][6]  = new ChordInfo( 0, timeLong);
	chords[2][7]  = new ChordInfo( 5, timeShort);
	chords[2][8]  = new ChordInfo( 5, timeShort);
	chords[2][9]  = new ChordInfo( 4, timeShort);
	chords[2][10] = new ChordInfo( 4, timeShort);
	chords[2][11] = new ChordInfo( 3, timeShort);
	chords[2][12] = new ChordInfo( 0, timeShort);
	chords[2][13] = new ChordInfo( 3, timeShort);
	chords[2][14] = new ChordInfo( 3, timeShort);
	chords[2][15] = new ChordInfo( 3, timeShort);
	chords[2][16] = new ChordInfo( 0, timeShort);
	chords[2][17] = new ChordInfo( 1, timeShort);
	chords[2][18] = new ChordInfo( 1, timeShort);
	chords[2][19] = new ChordInfo( 0, timeLong);
	chords[2][20] = new ChordInfo( 5, timeShort);
	chords[2][21] = new ChordInfo( 5, timeShort);
	chords[2][22] = new ChordInfo( 4, timeShort);
	chords[2][23] = new ChordInfo( 4, timeShort);
	chords[2][24] = new ChordInfo( 3, timeLong);
	chords[2][25] = new ChordInfo( 3, timeShort);
	chords[2][26] = new ChordInfo( 3, timeLong);
	chords[2][27] = new ChordInfo( 3, timeLong);
	chords[2][28] = new ChordInfo( 3, timeLong);
	chords[2][29] = new ChordInfo( 3, timeLong);
	chords[2][30] = new ChordInfo( 3, timeLong);
	chords[2][31] = new ChordInfo( 3, timeLong);
	chords[2][32] = new ChordInfo( 3, timeLong);
	chords[2][33] = new ChordInfo( 3, timeLong);
	chords[2][34] = new ChordInfo( 3, timeShort);
	chords[2][35] = new ChordInfo( 3, timeShort);//old mcdonald
	chords[2][36] = new ChordInfo( 3, timeShort);
	chords[2][37] = new ChordInfo( 3, timeShort);
	chords[2][38] = new ChordInfo( 0, timeShort);
	chords[2][39] = new ChordInfo( 1, timeShort);
	chords[2][40] = new ChordInfo( 1, timeShort);
	chords[2][41] = new ChordInfo( 0, timeLong);
	chords[2][42] = new ChordInfo( 5, timeShort);
	chords[2][43] = new ChordInfo( 5, timeShort);
	chords[2][44] = new ChordInfo( 4, timeShort);
	chords[2][45] = new ChordInfo( 4, timeShort);
	chords[2][46] = new ChordInfo( 3, timeShort);
	chords[2][47] = new ChordInfo(-1, timeShort);

	RHYME = 0;
	score = 0;
	miss = 0;
	percent = 0;
	curIndex = 0;
	rhymeCompleted = 0;

	bChangeColor = false;
	for (int i = 0; i < NUM_CHORDS; i ++)
	{
		setTouch(i, false);
	}

	sound = 0;
	bitmap_fonts[0]= GLUT_BITMAP_TIMES_ROMAN_24;
	bitmap_fonts[1]= GLUT_BITMAP_TIMES_ROMAN_10;
	mode = MODE_BITMAP;
	fontIndex = 0;
}

void ViewManager::setTouch(int id, bool flag)
{
	bTouched[id] = flag;
}

bool ViewManager::getTouch(int i)
{
	return bTouched[i];
}

void ViewManager::changeColor(unsigned char key, bool b)
{
	bChangeColor = b;
}

void ViewManager::setHeight(int h)
{
	this->height = h;
}

void ViewManager::setWidth(int w)
{
	this->width = w;
}

int ViewManager::getSound()
{
	return sound;
}

void ViewManager::setSound(int val)
{
	sound = val;
}

int ViewManager::getGameMode()
{
	return gameMode;
}

void ViewManager::setGameMode(int mode)
{
	gameMode = mode;
}

void ViewManager::resetTime()
{
	xTime->resetBeginTime();
	sec = 0;
	min = 0;
}

int ViewManager::getHeight()
{
	return this->height;
}

int ViewManager::getWidth()
{
	return this->width;
}

void ViewManager::initScene()
{
	this->initGL();
}

void ViewManager::openglMainLoop()
{
	glutMainLoop();
}

void ViewManager::initGL()
{
	const GLfloat light_model_ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};
	const GLfloat light0_diffuse[] = {0.9f, 0.9f, 0.9f, 0.9f};   
	const GLfloat light0_direction[] = {0.0f, -0.4f, 1.0f, 0.0f};    

	/* Enable depth buffering for hidden surface removal. */
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	/* Cull back faces. */
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	/* Other misc features. */
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);    
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_model_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
	glEnable(GL_LIGHT0);   
}

void ViewManager::createWindow(char* title)
{
	glutCreateWindow(title);
}

void ViewManager::glutDisplay()
{
	glutFullScreen();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	drawSceneGraphics();
	glutSwapBuffers();
	glutPostRedisplay();
}

void ViewManager::glutIdle()
{
	glutPostRedisplay();
}

void ViewManager::drawSceneGraphics()
{
	void * chordName[NUM_CHORDS]= { "C", "D", "E", "F", "G", "A", "B", "C" };
	void *chordKeys[NUM_CHORDS] = { "1", "2", "3", "4", "5", "6", "7", "8" };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	printChords(0, chordName);		// y-offset - print chords ABOVE the keys
	printChords(0.45, chordKeys);	// y-offset - print the numbers ON the keys
	
	drawHUD();
	
	float gap = 0.3;
	float x = -1.0;
	if (getGameMode() && (getChord(getRhyme(),getCurIndex())!= -1))
	{
		if(startPlay)
		{
			float timeElapsed = (float)(xTime->getCurrentTime() - xTime->getPreviousTime())/1000;
			float timeMap = (float) getTime(getRhyme(),getCurIndex());
			if (timeElapsed > timeMap)
			{
 				setCurIndex(getCurIndex()+1);
				xTime->setPreviousTime(xTime->getCurrentTime());
			}
		}
	}
	if (getChord(getRhyme(),getCurIndex()) == -1)
	{
		setRhymeCompleted(1);
	}

	for (int i = 0; i<NUM_CHORDS; i++)
	{
		drawBlock(x, i, getTouch(i));
		x = x+0.3;
	}
}

void ViewManager::setCurIndex(int index)
{
	curIndex = index;
}

int ViewManager::getCurIndex()
{
	return curIndex ;
}

int ViewManager::getRhyme()
{
	return RHYME;
}

void ViewManager::setRhymeCompleted(int val)
{
	rhymeCompleted = val;
}

int ViewManager::getRhymeCompleted()
{
	return rhymeCompleted;
}

int ViewManager::getScore()
{
	return score;
}

int ViewManager::getMisses()
{
	return miss;
}

void ViewManager::setRhyme(int val)
{
	RHYME = val;
}

void ViewManager::setScore(int val)
{
	score = val;
}

void ViewManager::setMisses(int val)
{
	miss = val;
}

int ViewManager::getChord(int r, int c)
{
	return chords[r][c]->getVal();
}

float ViewManager::getTime(int r, int c)
{
	return chords[r][c]->getTimeGap();
}


void ViewManager::drawBlock(float x, int blockID, bool pressed)
{
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	//Highlight and raise the key for next chord
	if (getChord(RHYME,curIndex) == blockID)
	{
		glColor3f(1.0,0,0);
		glTranslatef(x, -0.68, -0.35);
	}
	else
	{
		glColor3f(0.2, 0.2, 1.0);
		glTranslatef(x, -0.7, -0.35);
	}
	
	//Highlight pressed key and simulate "pressed" action visually
	if(pressed)
	{
		glColor3f(0.0,1.0,0);
		glTranslatef(0, -0.02, 0);
	}

	glScalef(1.0,0.2,1.0);

	GLUquadricObj *qobj1 = 0;
	qobj1 = gluNewQuadric();

	gluCylinder(qobj1, 0.14, 0.14, 1, 15, 15);
	glTranslatef(-0.0,0.07,1);
	gluQuadricOrientation(qobj1,GLU_OUTSIDE);
	gluDisk( qobj1, 0.0, 0.14, 15, 1);
	glTranslatef(0.0, 0.0, -1.0);
	gluQuadricOrientation(qobj1,GLU_INSIDE);
	gluDisk( qobj1, 0.0, 0.14, 15, 1);

	gluDeleteQuadric(qobj1);
	glPopMatrix();
}

void ViewManager::displayMode(unsigned int mode)
{
	glutInitDisplayMode(mode);
}

void ViewManager::displaySize(int w, int h)
{
	glutInitWindowSize(w, h);
}

void ViewManager::glutReshape(int width, int height)
{
	static const double kPI = 3.1415926535897932384626433832795;
	static const double kFovY = 40;

	double nearDist, farDist, aspect;

	glViewport(0, 0, width, height);

	/* Compute the viewing parameters based on a fixed fov and viewing
	* a canonical box centered at the origin */

	nearDist = 1.0 / tan((kFovY / 2.0) * kPI / 180.0);
	farDist = nearDist + 2.0;
	aspect = (double) width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(kFovY, aspect, nearDist, farDist);

	/* Place the camera down the Z axis looking at the origin */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();            
	gluLookAt(0, 0, nearDist + 1.0,
		0, 0, 0,
		0, 1, 0);
}

void print_bitmap_string(void* font, char* s)
{
	//Generate bitmat for a given string.
	if (s && strlen(s)) {
		while (*s) {
			glutBitmapWidth(font, 64);
			glutBitmapCharacter(font, *s);
			s++;
		}
	}
}

void ViewManager::printChords(float yDiff, void *chord[])
{
	unsigned int i, j;
	unsigned int count;

	GLfloat x, y, ystep, yild, stroke_scale;

	x = -1.03;
	y = 0.3;

	/* Draw the strings, according to the current mode and font. */
	glDisable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	for (int i = 0; i<8; i++)
	{
		if(getTouch(i)) // when a block/key is hit
			drawHUDText(1.0, 0.0, 0.0, x, y-0.5 - yDiff, 0.0, (char *) chord[i]); 
		else
			drawHUDText(1.0, 1.0, 1.0, x, y-0.5 - yDiff, 0.0, (char *) chord[i]);
		
		x = x + y;
	}

}

void drawBox()
{
	glLineWidth(2.5); 
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-1.25, 0.7, 0.0);
	glVertex3f(1.25, 0.7, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(1.25, 0.7, 0);
	glVertex3f(1.25,1.32,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.25, 0.7, 0);
	glVertex3f(-1.25,1.32,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.25, 1.32, 0);
	glVertex3f(1.25,1.32,0);
	glEnd();
}

void ViewManager::drawHUDText(float r, float g, float b, float x, float y, float z, char* text)
{
	glColor3f(r, g, b);
	glRasterPos3f(x,y,z);
	print_bitmap_string(bitmap_fonts[fontIndex],text);
}

void ViewManager::drawTimeElapsed()
{
	char bufSec[5];
	char bufMin[5];
	long int after = GetTickCount(); 
	sec = (int) ((xTime->getCurrentTime() - xTime->getBeginTime())/1000);
	
	min = (int) (sec / 60);
	sec = (int) (sec % 60);

	drawHUDText(0.2, 1.0, 1.0,0.615,0.9,0.0,"Time Elapsed: ");
	 
	drawHUDText(0.2, 1.0, 1.0,1.0,0.9,0.0,itoa(min,bufMin,10));
	drawHUDText(0.2, 1.0, 1.0,1.02,0.9,0.0," :");
	drawHUDText(0.2, 1.0, 1.0,1.06,0.9,0.0,itoa(sec,bufSec,10));
}
void ViewManager::drawHUD()
{
	char bufHit[5], bufMiss[5];
	drawBox(); // render the green box

	//Quit instruction
	drawHUDText(1.0, 0.5, 0.5,-0.65,1.25,0.0,"To exit: Press ESC or Right click -> click on Quit. ");
	drawHUDText(1.0, 0.7, 0.5,-0.45,1.17,0.0,"Press 9 to toggle game mode.");
	//Show this for only five key presses
	if(getCurIndex() < 5)
	{
		drawHUDText(1.0, 0.5, 0.5,-0.35,1.10,0.0,"Press 0 to change sound.");
	}

	//Hits
	drawHUDText(0.2, 1.0, 1.0,-1.2,1.0,0.0,"Hits: ");
	drawHUDText(0.2, 1.0, 1.0,-1.0,1.0,0.0,itoa(this->getScore(),bufHit,10));

	//Misses
	drawHUDText(0.2, 1.0, 1.0,-1.2,0.90,0.0,"Misses: ");
	drawHUDText(0.2, 1.0, 1.0,-1.0,0.90,0.0,itoa(this->getMisses(),bufMiss,10));

	//Game mode
	char * gameMode= "";
	if(getGameMode() == 0)
		gameMode = "Free style";
	else
		gameMode = "Time constrained";
	drawHUDText(0.2, 1.0, 1.0,-1.2,0.80,0.0,"Mode: ");
	drawHUDText(0.2, 1.0, 1.0,-1.0,0.80,0.0,gameMode);

	if (getRhymeCompleted() == 1)
	{
		char bufRhyme[2], bufScore[5];
		int currentIndex = getCurIndex();
		//Score
		drawHUDText(1.0, 1.0, 0.2,-0.18,1.0,0.0,"Score: ");
	    if (testOnce )//= true;
		{
			if (!getGameMode())
				percent = (int)(100*getScore()/(getScore()+getMisses()));
			else
				if ((getScore() <= 0) || (getScore() < getMisses()))
					percent = 0;
				else
					percent = (int)(100*2*(getScore() - getMisses())/(getScore() + getMisses() + currentIndex));
			testOnce = false;
		}
		drawHUDText(1.0, 1.0, 0.2,0.05,1.0,0.0,itoa(percent,bufScore,10));

		// Rhyme completed
		drawHUDText(1.0, 1.0, 0.2,-0.3,0.9,0.0,"Rhyme ");
		drawHUDText(1.0, 1.0, 0.2,-0.1,0.9,0.0,itoa(getRhyme()+1,bufRhyme,10));
		drawHUDText(1.0, 1.0, 0.2,-0.06,0.9,0.0,"Completed!");

		//Next rhyme
		drawHUDText(1.0, 0.5, 0.6,-0.5,0.8,0.0,"Right click to select different rhyme. ");

	}
	else
	{
		if(getRhyme() == 0)
		{
			drawHUDText(1.0, 0.5, 0.6,-0.35,0.45,0.0,"Twinkle twinkle little star ");
		}
		else if(getRhyme() == 1)
		{
			drawHUDText(1.0, 0.5, 0.6,-0.28,0.45,0.0,"Happy birthday to you");
		}
		else if(getRhyme() == 2)
		{
			drawHUDText(1.0, 0.5, 0.6,-0.32,0.45,0.0,"Old McDonald has a farm");
		}
	}	
	char bufOct[5];
	drawHUDText(0.2, 1.0, 1.0,0.8,1.0,0.0,"Sound: ");
	drawHUDText(0.2, 1.0, 1.0,1.0,1.0,0.0,itoa(getSound()+1,bufOct,10));
	
	drawTimeElapsed();
}

