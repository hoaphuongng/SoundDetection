#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "appdevWav.h"

int main(){
	int i;
	waveHDR mywav;	//struct call
	signed short int samples[SAMPLE_PER_SEC];	//define of constant data
	double dBfast[FASTSIZE];
	FILE *fp;	//open file
	for(i=0; i<5; i++){
		system("arecord -r16000 -c1 -d1 -f S16_LE -q Alo.wav");
		fp=fopen("Alo.wav", "rb");
        	if(fp==NULL){
                	printf("Cannot open the file make sure you give the correct file name");
                	exit(1);
		}
		fread(&mywav, sizeof(mywav), 1, fp);	//read file
        	displayHDRinfo(mywav);	//display information of sound
		fread(&samples, sizeof(mywav), SAMPLE_PER_SEC, fp);
		displayWave(samples, dBfast);	//display soundawave
                send_dBfast(dBfast);	//send information of sound to
		fclose(fp);
        }
}
