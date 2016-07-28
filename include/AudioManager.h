/* 
Class name: AudioManager
Manages audio buffers and audio playback from the Xylophone app.
*/
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <AL/al.h>
#include <AL/alut.h>
#include <string>

#define NUM_BUFFERS 24 // Number of audio buffers/sounds currently available
class AudioManager
{
private:
	int octave;
	int rhyme;
	ALuint soundClip[NUM_BUFFERS];
	char* audioFiles[NUM_BUFFERS];

public:
	AudioManager();
	
	//Initialize required audio library parameters and buffers
	void initAL();
	
	void playSoundClip(ALuint soundClip); 
	
	ALuint getSound(int i); 
	
	// Set the different notes
	void setOctave(int);
	
	// Get the current note
	int getOctave(); 
};

#endif
