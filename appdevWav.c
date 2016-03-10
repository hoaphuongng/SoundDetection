#include "appdevWav.h"
#include <stdio.h>
#include "screen.h"
#include <math.h>	//for round function
#include <curl/curl.h>
//#define DEBUG_INFO

//Display Sound Wave
void displayWave(signed short int s[], double df[]){
        int i, j;
        double sum, rms, dBrms, sumdf;
#ifdef DEBUG_INFO
        for(i=0; i<80;i++){
                for(j=0, sum=0.0; j<200;j++){
                        sum+=s[i*200+j]*s[i*200+j];
                }
                rms=sqrt(sum)/200;
		dBrms = 20*log10(rms);
                printf("Chunk %d: rms:%.3f in dB: %.3f\n", i, rms, dBrms);
        }
#else //not define DEBUG_INFO
	for(i=0;i<80;i++){
		for(j=0, rms=0,sum=0;j<200;j++){
			sum+=s[i*200+j]*s[i*200+j];
		}
		rms=sqrt(sum)/200;	//calculate rms value of sound
                dBrms = 20*log10(rms);	//change to dB value
		if(dBrms>40) setColors(YELLOW, bg(BLACK));	//if dBrms value is more than 40, change color to Yellow
		else setColors(WHITE, bg(BLACK));	//else keep White default color
		dispBar(i+1, 30-round(dBrms/2.5),30);	//display Bar chart with gained parameters
		resetColors();
		puts("");
	}
#endif
	for(i=0;i<FASTSIZE;i++){
                for(j=0,sumdf=0.0;j<SAMPLE_PER_SEC/FASTSIZE;j++){	//8 values for rms
                        sumdf += s[i*2000+j]*s[i*2000+j];
                }
                rms = sqrt(sumdf)/2000;
                df[i]=20*log10(rms);
        }
}

//Send 8 values to URL
void send_dBfast(double df[]){
        int i;  //loop i
#ifdef DEBUG_INFO
        printf("---------------------------\n");
        for(i=0;i<FASTSIZE; i++)
                printf("dB(%d)=%5.2f\n",i+1,df[i]);
        printf("---------------------------\n");
#else	//not define DEBUG_INFO
        CURL *curl;	//start curl session with curl handle
        CURLcode res;
        char postdata[200];     //http post value
        sprintf(postdata, "df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f&df%d=%6.2f",1,df[0],2,df[1],3,df[2],4,df[3],5,df[4],6,df[5],7,df[6],8,df[7]);
        curl_global_init(CURL_GLOBAL_ALL);	//global libcurl initialization
        curl = curl_easy_init();	//curl session
        if(curl){
                curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e1400468/SoundDetection/soundwave.php");	//URL to work on
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);	//send a POST with this data
                res = curl_easy_perform(curl);	//perform blocking file transfer
                if(res != CURLE_OK) printf("Cannot send!\n");	//CURLE_OK: file process successful
                curl_easy_cleanup(curl);	//end libcurl easy handle
        }
        curl_global_cleanup();	//clean
#endif
}       //end of function

//Display information
void displayHDRinfo(waveHDR w){
	int i;
#ifdef DEBUG_INFO
	for(i=0;i<4;i++){
		printf("%c", w.chunkID[i]);
	}
	puts("");
	printf("Chunk size: %d\n", w.chunkSize);

	for(i=0;i<4;i++) printf("%c", w.format[i]);
	puts("");
	for(i=0;i<4;i++) printf("%c",w.subchunk1ID[i]);
	puts("");
	printf("subchunk1 size: %d\n",w.subchunk1Size);
	printf("Audio Format: %d\n", w.audioFormat);
	printf("No. of channels: %d\n", w.numChannels);
	printf("Sample rate: %d\n", w.sampleRate);
	printf("Byte rate: %d\n", w.byteRate);
	printf("Block align: %d\n", w.blockAlign);
	printf("Bit per sample: %d\n", w.bitsPerSample);
	printf("Subchunk2ID: ");

	for(i=0;i<4;i++) printf("%c",w.subchunk2ID[i]);
	puts("");
	printf("subchunk2Size: %d\n",w.subchunk2Size);
	printf("Duration of this soundtrack : %.2f\n",(double)w.subchunk2Size/w.byteRate);
#else
	clearScreen();
	gotoxy(1,1);
	setColors(YELLOW,bg(BLUE));
	printf("sample.wav");
	gotoxy(11,1);
	setColors(RED,bg(GREEN));
	printf("FS:%6d",w.sampleRate);
#endif
}
