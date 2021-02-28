#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// Declare functions
int Menu();
// Start code
int clrScrn() {
    // Screen clear fucntion, checks OS first for compatibility:tm:
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef unix
        system("clear");
    #endif
    #ifdef __APPLE__
        system( "clear" );
    #endif
}
int Menu(){
    
}
int main(){
    printf("Hello World!\n");
}