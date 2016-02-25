/*
 * demo_optimized.cpp
 *
 *  Created on: 2016年1月10日
 *      Author: qq95538
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "MPU6050_4Edison.hpp"

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_signal(int signo)
{
    printf("receive a signal\n");
    exit(0);
}



MPU6050 mpu_head;
//MPU6050 mpu_body;




//#define OUTPUT_READABLE_QUATERNION
#define OUTPUT_READABLE_EULER
#define OUTPUT_READABLE_YAWPITCHROLL
#define OUTPUT_READABLE_REALACCEL
#define OUTPUT_READABLE_WORLDACCEL
//#define OUTPUT_TEAPOT

// MPU control/status vars
bool dmpHeadReady = false;  // set true if DMP init was successful
//bool dmpBodyReady = false;  // set true if DMP init was successful

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================
void setup() {
    dmpHeadReady = mpu_head.dmpStartDevice(0x68, 0, 0, 0);

    //dmpBodyReady = mpu_body.dmpStartDevice(0x69, 0, 0, 0);
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================
void loop() {
    //if(mpu_head.dmpGetData())
    float ret = mpu_head.dmpGetFirstYPRData();
    if( int(ret) )
    {
	printf("%7.2f\n", ret);

        //printf("quat %7.2f %7.2f %7.2f %7.2f    ", dmpQuat.w,dmpQuat.x,dmpQuat.y,dmpQuat.z);
        //printf("accell %6d %6d %6d    ", dmpAccel.x, dmpAccel.y, dmpAccel.z);
        //printf("areal %6d %6d %6d    ", dmpAccelReal.x, dmpAccelReal.y, dmpAccelReal.z);
        //printf("aworld %6d %6d %6d    ", dmpAccelWorld.x, dmpAccelWorld.y, dmpAccelWorld.z);
        //printf("gravity %7.2f %7.2f %7.2f    ", dmpGravity.x, dmpGravity.y, dmpGravity.z);
        //printf("euler %7.2f %7.2f %7.2f    ", dmpEuler[0], dmpEuler[1], dmpEuler[2]);
        //printf("ypr  %7.2f %7.2f %7.2f    ", dmpYawPitchRoll[0], dmpYawPitchRoll[1], dmpYawPitchRoll[2]);
        //printf("\n");
    }

   // if(mpu_body.dmpGetData())
    //{
        /*
        //printf("quat %7.2f %7.2f %7.2f %7.2f    ", dmpQuat.w,dmpQuat.x,dmpQuat.y,dmpQuat.z);
        //printf("accell %6d %6d %6d    ", dmpAccel.x, dmpAccel.y, dmpAccel.z);
        //printf("areal %6d %6d %6d    ", dmpAccelReal.x, dmpAccelReal.y, dmpAccelReal.z);
        printf("aworld %6d %6d %6d    ", dmpAccelWorld.x, dmpAccelWorld.y, dmpAccelWorld.z);
        //printf("gravity %7.2f %7.2f %7.2f    ", dmpGravity.x, dmpGravity.y, dmpGravity.z);
        printf("euler %7.2f %7.2f %7.2f    ", dmpEuler[0], dmpEuler[1], dmpEuler[2]);
        printf("ypr  %7.2f %7.2f %7.2f    ", dmpYawPitchRoll[0], dmpYawPitchRoll[1], dmpYawPitchRoll[2]);
        printf("\n");
          */
    //}
}



int main(int argc, char *argv[]){

        int c;  
        opterr = 0;   

        while((c = getopt(argc, argv, "Oo:W:all")) != -1){  
                printf("option char: %c\n", c);  
                switch(c){  
                case 'O':  
                        printf("optimization flag is open.\n\n");  
                        break;  
                case 'o':  
                        printf("the obj is: %s\n\n", optarg);  
                        break;  
                case 'W':  
                        printf("optarg: %s\n\n", optarg);  
                        break;          
                case '?':  
                        fprintf(stderr, "Usage: %s [-Wall] [-O] [-o arg] arg\n", argv[0]);  
                        break;  
                case ':':  
                        fprintf(stderr, "miss option char in optstring.\n");  
                        break;  
                }  
        }  

    signal(SIGINT,handler_signal); 

    setup();
    usleep(100000);

    for (;;)
        loop();

    return 0;
}




