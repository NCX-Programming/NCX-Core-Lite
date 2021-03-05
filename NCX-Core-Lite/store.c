#include "store.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
// Declare variables
int storeChoice;     
void ldsifd() {
    clrScrn();
    printf("lazy-dsi-file-downloader\nBy YourKalamity\n\n");
    printf("Automatically downloads, extracts and places files used for DSi modding.\n\n");
    printf("Requirements: At least Python 3.5 with the Tkinter library\n\n");
    printf("Options:\n1. Download\n2. Return to Store\n");
    storeChoice=0;
    while(storeChoice==0||storeChoice=='\n'){
        storeChoice=0;
        storeChoice=fgetc(stdin);
        // Get choice
        if(storeChoice==49){
            #ifdef unix
                clrScrn();
                printf("Downloading...\n");
                if(!Download("https://github.com/YourKalamity/lazy-dsi-file-downloader/releases/download/3.1.2/lazy-dsi-file-downloader-3.1.2-Python3.zip", "lazy-dsi-file-downloader-3.1.2-Python3.zip")){printf("Done.\n");};
                sleep(1);
                ldsifd();
            #endif
            #ifdef __APPLE__
                clrScrn();
                printf("Downloading...\n");
                if(!Download("https://github.com/YourKalamity/lazy-dsi-file-downloader/releases/download/3.1.2/lazy-dsi-file-downloader-3.1.2-macOS.zip", "lazy-dsi-file-downloader-3.1.2-macOS.zip")){printf("Done.\n");};
                sleep(1);
                ldsifd();
            #endif 
            }
        if(storeChoice==50)Store();}
}