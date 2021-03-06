//NCX-Core-Lite "main.c"
//Copyright (C) 2021 NinjaCheetah
//Copyright (C) 2021 NCX-Programming
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include "store.h"
#include "functions.h"
// Declare functions
void Store();
int Download();
// Declare variables
int menuChoice;
// Start code
void Update(){
    #ifdef _WIN32
    #endif
    #ifdef unix
        clrScrn();
        printf("Downloading...");
        if(!Download("https://github.com/NCX-Programming/NCX-Core-Lite/releases/latest/download/NCX-Core-Lite-linux.zip", "NCX-Core-Lite-linux.zip")){printf("error\n");};
        clrScrn();
        printf("Self-updating is still a WIP. A zip file containing the latest release has been downloaded, however you will have to extract it yourself.\n\n");
        printf("Press ENTER to return to the store.\n");
        getchar();
        getchar();
        menuChoice=0;
        Store();
    #endif
    #ifdef __APPLE__
        clrScrn();
        printf("Downloading...");
        if(!Download("https://github.com/NCX-Programming/NCX-Core-Lite/releases/latest/download/NCX-Core-Lite-X86.zip", "NCX-Core-Lite-X86.zip")){printf("error\n");};
        clrScrn();
        printf("Self-updating is still a WIP. A zip file containing the latest release has been downloaded, however you will have to extract it yourself.\n\n");
        printf("Press ENTER to return to the store.\n");
        getchar();
        menuChoice=0;
        Store();
    #endif
}
void Store(){
    clrScrn();
    printf("*====================================*\n");
    printf("| \e[1;97mXStore-Lite\e[0m                        |\n");
    printf("*=======*============================*\n");
    printf("|       |                            |\n");
    printf("|  (1)  |   Exit Program             |\n");
    printf("|       |                            |\n");
    printf("|  (2)  |   Update NCX-Core-Lite     |\n");
    printf("|       |                            |\n");
    printf("|       | Programs:                  |\n");
    printf("|       |                            |\n");
    printf("|  (3)  |   theVaultC                |\n");
    printf("|       |                            |\n");
    printf("|  (4)  |   fakeApt                  |\n");
    printf("|       |                            |\n");
    printf("|  (5)  |   fake-pacman              |\n");
    printf("|       |                            |\n");
    printf("|  (6)  |   lazy-dsi-file-downloader |\n");
    printf("|       |                            |\n");
    printf("|  (7)  |   C64-Title-Loader         |\n");
    printf("|       |                            |\n");
    printf("|  (8)  |   Empty Slot               |\n");
    printf("|       |                            |\n");
    printf("*=======*============================*\n");
    menuChoice=0;
    while(menuChoice==0||menuChoice=='\n'){
        menuChoice=0;
        menuChoice=fgetc(stdin);
        // Get store menu choice
        if(menuChoice==49){
            clrScrn();
            exit(0);}
        if(menuChoice==50)Update();
        if(menuChoice==51)vaultc();
        if(menuChoice==52)fkapt();
        if(menuChoice==53)fkpcmn();
        if(menuChoice==54)ldsifd();
        if(menuChoice==55)c64tl();
        if(menuChoice==56)Store();}
}
int main(void){
    printf("Loading...\n");
    DIR* dir = opendir("tmp");
    if (dir) {
        // Directory already exists, just continue
        closedir(dir);
    }else if (ENOENT == errno) {
        // Directory doesn't exist, so make it
        mkdir("tmp/",0777); }
    if(!Download("https://raw.githubusercontent.com/NinjaCheetah/NCX-Installer-news/master/newsLatest.txt", "tmp/news.txt")){printf("error\n");}
    clrScrn();
    printf("Welcome to NCX-Core-Lite!\n\n");
    printf("NCX-Core-Lite,  Copyright (C) 2021  NCX-Programming/NinjaCheetah\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it\nunder certain conditions; view the full license in the repo.\n\n");
    // Read news file
    FILE *fp;
    char news[2048];
    fp=fopen("tmp/news.txt","r");
    if (!fp)
        return 1;
    while (fgets(news,2048, fp)!=NULL)
    printf("NCX-News: %s\n\n", news);
    // conclude the news reading session (news is for old people anyway)
    fclose(fp);
    // Prompt to continue to the store (currently you have no choice- *you must shop*)
    printf("Press ENTER to view available software");
    getchar();
    Store();
}