//NCX-Core-Lite "functions.c"
//Copyright (C) 2021 NinjaCheetah
//Copyright (C) 2021 NCX-Programming
#include "functions.h"
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
// Not really sure what this code does but it helps with downloading stuff so its important
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
void clrScrn() {
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
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        // Cleanup stuff
        curl_easy_cleanup(curl);
        fclose(fp); }
}