#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
// Declare functions
int Store();
int Download();
// Declare variables
int menuChoice;
// Not really sure what this code does but it helps with downloading stuff so its important
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
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
int Download(const char *url, const char *file){
    // Download code
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(file,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        // Cleanup stuff
        curl_easy_cleanup(curl);
        fclose(fp); }
}
int Store(){
    clrScrn();
    printf("*====================================*\n");
    printf("| \e[1;97mXStore-Lite\e[0m                        |\n");
    printf("*=======*============================*\n");
    printf("|       |                            |\n");
    printf("|  (1)  |   Exit Program             |\n");
    printf("|       |                            |\n");
    printf("|       | Prodcuts:                  |\n");
    printf("|       |                            |\n");
    printf("|  (2)  |   theVaultC                |\n");
    printf("|       |                            |\n");
    printf("|  (3)  |   fakeApt                  |\n");
    printf("|       |                            |\n");
    printf("|  (4)  |   NCX-Core (Win)           |\n");
    printf("|       |                            |\n");
    printf("|  (5)  |   CSharpCollection (Win)   |\n");
    printf("|       |                            |\n");
    printf("|  (6)  |   C64-Title-Loader         |\n");
    printf("|       |                            |\n");
    printf("|  (7)  |   lazy-dsi-file-downloader |\n");
    printf("|       |                            |\n");
    printf("*=======*============================*\n");
    while(menuChoice==0){
        menuChoice=0;
        menuChoice=fgetc(stdin);
        // Get settings menu choice
        if(menuChoice==49) exit(0);
        if(menuChoice==50){}
        if(menuChoice==51){}
        if(menuChoice==52){}
        if(menuChoice==53) exit(0); }
}
int main(){
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