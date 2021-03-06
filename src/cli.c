/*NCX-Core-Lite "cli.c"
Copyright (C) 2021 NinjaCheetah
Copyright (C) 2021 NCX-Programming
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.*/
#include "../include/cli.h"
#include "../include/store.h"
#include "../include/functions.h"
#include <stdio.h>
#include <stdlib.h>
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
        Store();
    #endif
}
void Store(){
    menuChoice=0;
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
