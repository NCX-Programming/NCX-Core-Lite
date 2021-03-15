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
#include <gtk/gtk.h>
#include "store.h"
#include "functions.h"
#include "cli.h"
// Declare functions
// Declare variables
int guiChoice;
// Start code
static void print_hello(GtkWidget *widget,gpointer data){
    g_print("Hello World!\n");
}
int main(int argc,char *argv[]){
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

    printf("Use classic CLI interface? y/n \n");
    while(guiChoice==0){
        guiChoice=0;
        guiChoice=fgetc(stdin);
        if(guiChoice==89||guiChoice==121) Store();
        if(guiChoice==78||guiChoice==110) {}}
    
    GtkBuilder *builder;
    GObject *window;
    GObject *button;
    GError *error = NULL;

    gtk_init (&argc, &argv);
    // Construct a GtkBuilder instance and load our UI description
    builder = gtk_builder_new ();
    if(gtk_builder_add_from_file(builder, "builder.ui", &error) == 0){
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }
    // Connect signal handlers to the constructed widgets.
    window = gtk_builder_get_object (builder, "window");
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    button = gtk_builder_get_object (builder, "button1");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

    button = gtk_builder_get_object (builder, "button2");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

    button=gtk_builder_get_object(builder,"button3");
    g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);

    button=gtk_builder_get_object(builder,"button4");
    g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);

    button=gtk_builder_get_object(builder,"button5");
    g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);

    button=gtk_builder_get_object(builder,"button6");
    g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);

    button=gtk_builder_get_object(builder,"aboutBtn");
    g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);

    button = gtk_builder_get_object (builder, "quit");
    g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

    gtk_main();

    return 0;
}