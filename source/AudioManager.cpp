#include "AudioManager.h"

AudioManager::AudioManager()
{
	octave = 0;
	rhyme = 0;
}

void AudioManager::initAL()
{
	ALfloat listenerPos[]={0.0,0.0,0.0};
	ALfloat listenerVel[]={0.0,0.0,0.0};
	ALfloat listenerOri[]={0.0,0.0,0.0, 0.0,0.0,0.0}; // "at", then "up"
	ALsizei size,freq;
	ALenum	format;
	ALvoid	*data;
	ALboolean loop;

	//Load sound files which are stored insided "sound" folder in the current directory
	char* audioFiles[NUM_BUFFERS] = {

		".\\sound\\1.wav", ".\\sound\\2.wav", ".\\sound\\3.wav", ".\\sound\\4.wav", 
		".\\sound\\5.wav", ".\\sound\\6.wav", ".\\sound\\7.wav", ".\\sound\\8.wav",
		".\\sound\\9.wav", ".\\sound\\10.wav", ".\\sound\\11.wav", ".\\sound\\12.wav", 
		".\\sound\\13.wav", ".\\sound\\14.wav", ".\\sound\\15.wav", ".\\sound\\16.wav",
		".\\sound\\17.wav", ".\\sound\\18.wav", ".\\sound\\19.wav", ".\\sound\\20.wav", 
		".\\sound\\21.wav", ".\\sound\\22.wav", ".\\sound\\23.wav", ".\\sound\\24.wav"

	};

	ALuint g_Buffers[NUM_BUFFERS];

	// Initialize OpenAL
	alutInit(0, 0);
	int alError = alGetError();

	// Generate Buffers
	alGenBuffers(NUM_BUFFERS, g_Buffers);

	//audio buffers for each chord
	for (ALuint k=0; k < NUM_BUFFERS; k++) {
		alutLoadWAVFile(audioFiles[k],&format,&data,&size,&freq,&loop);
		alBufferData(g_Buffers[k],format,data,size,freq);
		alutUnloadWAV(format,data,size,freq);
	}

	// Generate Sources
	alGenSources(NUM_BUFFERS,soundClip);
	for (ALuint r=0; r < NUM_BUFFERS; r++) {
		alSourcei(soundClip[r], AL_BUFFER, g_Buffers[r]);
	}

}

int AudioManager::getOctave()
{
	return octave;
}

void AudioManager::setOctave(int val)
{
	if(octave >= 16) // 0, 8, 16 for 3 different sounds. switch to first octave after the third
		octave = 0;
	else
		octave = val;
}

void AudioManager::playSoundClip(ALuint sound)
{
	alSourcePlay(sound);
}

ALuint AudioManager::getSound(int i)
{
	return soundClip[i];
}