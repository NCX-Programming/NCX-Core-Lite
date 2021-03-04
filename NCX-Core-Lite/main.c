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
        if(!Download("https://raw.githubusercontent.com/NinjaCheetah/ncx-core-files/master/NCX-Core-Lite-linux.zip", "NCX-Core-Lite-linux.zip")){printf("error\n");};
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
        if(!Download("https://raw.githubusercontent.com/NinjaCheetah/ncx-core-files/master/NCX-Core-LiteX86.zip", "NCX-Core-LiteX86.zip")){printf("error\n");};
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
    printf("|  (5)  |   NCX-Core (Win)           |\n");
    printf("|       |                            |\n");
    printf("|  (6)  |   CSharpCollection (Win)   |\n");
    printf("|       |                            |\n");
    printf("|  (7)  |   C64-Title-Loader         |\n");
    printf("|       |                            |\n");
    printf("|  (8)  |   lazy-dsi-file-downloader |\n");
    printf("|       |                            |\n");
    printf("*=======*============================*\n");
    while(menuChoice==0){
        menuChoice=0;
        menuChoice=fgetc(stdin);
        // Get settings menu choice
        if(menuChoice==49)exit(0);
        if(menuChoice==50)Update();
        if(menuChoice==51){}
        if(menuChoice==52){}
        if(menuChoice==53){}
        if(menuChoice==54){}
        if(menuChoice==55){}
        if(menuChoice==56)ldsifd();}
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