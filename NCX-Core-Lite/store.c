//NCX-Core-Lite "store.c"
//Copyright (C) 2021 NinjaCheetah
//Copyright (C) 2021 NCX-Programming
#include "store.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
// Declare variables
int storeChoice;     
void ldsifd(){
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
void vaultc(){
    clrScrn();
    printf("theVaultC\nBy NCX-Programming/NinjaCheetah\n\n");
    printf("An updated and upgraded version of theVault, now in C. Available for Windows, Linux, and Intel Macs. \n\n");
    printf("Requirements: macOS: 10.12 or later, Linux: 64-bit version of Linux, Windows: 32 or 64-bit version of Windows\n\n");
    printf("Options:\n1. Download\n2. Return to Store\n");
    storeChoice=0;
    while(storeChoice==0||storeChoice=='\n'){
        storeChoice=0;
        storeChoice=fgetc(stdin);
        // Get choice
        if(storeChoice==49){
            clrScrn();
            printf("Downloading...\n");
            if(!Download("https://github.com/NCX-Programming/theVaultC/releases/latest/download/theVault-ALL.zip", "theVault-ALL.zip")){printf("Done.\n");};
            sleep(1);
            vaultc(); }
        if(storeChoice==50)Store();}
}
void fkapt(){
    clrScrn();
    printf("fakeApt\nBy NinjaCheetah\n\n");
    printf("A fun little program made in C# with .NET 5, just goes through a fake apt install process to 'install' any package you could think up.\n\n");
    printf("Requirements: .NET 5.0 on macOS, Windows, or Linux\n\n");
    printf("Options:\n1. Download\n2. Return to Store\n");
    storeChoice=0;
    while(storeChoice==0||storeChoice=='\n'){
        storeChoice=0;
        storeChoice=fgetc(stdin);
        // Get choice
        if(storeChoice==49){
            clrScrn();
            printf("Downloading...\n");
            if(!Download("https://github.com/NinjaCheetah/fake-apt/releases/latest/download/fakeApt-latest-stable.zip", "fakeApt-latest-stable.zip")){printf("Done.\n");};
            sleep(1);
            fkapt(); }
        if(storeChoice==50)Store();}
}
void fkpcmn(){
    clrScrn();
    printf("fake-pacman\nBy Jonatan6\n\n");
    printf("fake-pacman is a terminal program for macOS and Linux that will make it look like you are installing a pacman package.\n\n");
    printf("Requirements: macOS: 10.12 or later, Linux: 64-bit version of Linux\n\n");
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
                if(!Download("https://github.com/Jonatan6/fake-pacman/releases/latest/download/fake-pacman-linux.zip", "fake-pacman-linux.zip")){printf("Done.\n");};
                sleep(1);
                fkpcmn();
            #endif
            #ifdef __APPLE__
                clrScrn();
                printf("Downloading...\n");
                if(!Download("https://github.com/Jonatan6/fake-pacman/releases/latest/download/fake-pacman-mac.zip", "fake-pacman-mac.zip")){printf("Done.\n");};
                sleep(1);
                fkpcmn();
            #endif 
            }
        if(storeChoice==50)Store();}
}
void c64tl(){
    clrScrn();
    printf("C64-Title-Loader\nBy IanSkinner1982\n\n");
    printf("A program to load all of my C64 projects.\n\n");
    printf("Requirements: VICE Emulator on macOS, Windows, or Linux\n\n");
    printf("Options:\n1. Download\n2. Return to Store\n");
    storeChoice=0;
    while(storeChoice==0||storeChoice=='\n'){
        storeChoice=0;
        storeChoice=fgetc(stdin);
        // Get choice
        if(storeChoice==49){
            clrScrn();
            printf("Downloading...\n");
            if(!Download("https://github.com/IanSkinner1982/C64-title-loader/releases/latest/download/loader.d64", "loader.d64")){printf("Done.\n");};
            sleep(1);
            c64tl(); }
        if(storeChoice==50)Store();}
}