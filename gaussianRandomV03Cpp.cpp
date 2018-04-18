/// @file gaussianRandomV02Cpp
///
/// @brief Illustrate the usage of Gaussian random number
/// generator and html graphics libraries.
///
/// Generate a lot of random numbers, once using the Gaussian
/// random number generator and once using the built-in rand()
/// function. Bin the results for a histogram plot. Print out
/// a summary of the results to the terminal and to an html
/// graphics object.
///
///
/// Created 10 Aug 2017
/// Modified 6 Jan 2018
/// -include file
/// -graphics
///
/// @author Mustafa Ghazi

#include <stdio.h>
#include <time.h>


#include "gaussRand3.h"
#include "htmlGraphics.h"


#define HOWMANY 100000


// Bin the number into bins from -4 through +4.
void assignBin(double x, int bin[]);

int main() {

    int i = 0;
    time_t t; // for seeding random number
    srand((unsigned) time(&t)); // initialize random number generator
    int bins[9] = {0,0,0,0,0,0,0,0,0}; // gaussRand3()
    int bins2[9] = {0,0,0,0,0,0,0,0,0}; // rand()
    double x, y;
    int p, q, pWidth=300, pHeight=300, s;

    // Step 1: generate random numbers using the two types of functions
    // ****************************************************************
	for(i=0;i<HOWMANY;i++){
        x = gaussRand3();
        y = (double)(rand()%(5000+5000)-5000)/1000.0; // in rnage of +-5.0
        //printf("%f\n",gaussRand3());
        assignBin(x, bins);
        assignBin(y, bins2);
    }

	// Step 2: output the results on the terminal
	// ******************************************
	printf("generated %d numbers\n",HOWMANY);
	printf("rand max is %li\n", RAND_MAX);

	printf("\ngaussRand()\nbin:\t-4\t-3\t-2\t-1\t0\t1\t2\t3\t4\ncount:\t");
    for(i=0; i<9; i++){
        printf("%d\t", bins[i]);
    }
    printf("\n");

	printf("\nrand()\nbin:\t-4\t-3\t-2\t-1\t0\t1\t2\t3\t4\ncount:\t");
    for(i=0; i<9; i++){
        printf("%d\t", bins2[i]);
    }
    printf("\n");

    // Step 3: show the results in a graphic
    // *************************************
    graphicsOpen(400,800); // must be called first
    // draw gaussRand3()
    p = 50; q = 80;
    s = 110; // scale
    for(i=0; i<9; i++){
        graphicsLine(i*pWidth/9+p, pHeight-(bins[i]/s)+q, i*pWidth/9+p, pHeight+q, 200, 20, 20);
    }
    // draw rand()
    p = 50; q = 480;
    s = 110; // scale
    for(i=0; i<9; i++){
        graphicsLine(i*pWidth/9+p, pHeight-(bins2[i]/s)+q, i*pWidth/9+p, pHeight+q, 20, 20, 200);
    }
    graphicsPrintString("gaussRand3()", 20, 0+20, 20, 200, 20, 20);
    graphicsPrintString("rand()", 20, 400+20, 20, 20, 20, 200);

    graphicsUpdate(); // must be called after the drawing functions
    graphicsDisplay(); // optional, opens the drawing in a web browser


    return 0;
}


// Bin the number into bins from -4 through +4.
void assignBin(double x, int bin[]) {
    if(x>=-4.5 && x<-3.5){
        bin[0] = bin[0] + 1;
    } else if(x>=-3.5 && x<-2.5){
        bin[1] = bin[1] + 1;
    } else if(x>=-2.5 && x<-1.5){
        bin[2] = bin[2] + 1;
    } else if(x>=-1.5 && x<-0.5){
        bin[3] = bin[3] + 1;
    } else if(x>=-0.5 && x<0.5){
        bin[4] = bin[4] + 1;
    } else if(x>=0.5 && x<1.5){
        bin[5] = bin[5] + 1;
    } else if(x>=1.5 && x<2.5){
        bin[6] = bin[6] + 1;
    } else if(x>=2.5 && x<3.5){
        bin[7] = bin[7] + 1;
    } else if(x>=3.5 && x<4.5){
        bin[8] = bin[8] + 1;
    }
}

