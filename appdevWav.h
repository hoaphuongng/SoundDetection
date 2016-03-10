#ifndef __WAVE_H__
#define __WAVE_H__
#define SAMPLE_PER_SEC 16000	//constant declaration
#define FASTSIZE 8

typedef struct{		//user defined data for waveHDR
	unsigned char chunkID[4];
	unsigned int chunkSize;
	unsigned char format[4];
	unsigned char subchunk1ID[4];
	unsigned subchunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned sampleRate;
	unsigned byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	unsigned char subchunk2ID[4];
	unsigned subchunk2Size;
}waveHDR;

//function declaration given after the struct
void displayHDRinfo(waveHDR w);
void displayWave(signed short int [], double []);
void send_dBfast(double []);
#endif
