/*NCX-Core-Lite "main.c"
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <gtk/gtk.h>
#include "../include/store.h"
#include "../include/functions.h"
#include "../include/cli.h"
// Declare functions
// Declare variables
int guiChoice;
char usr[32];
gchar dwnldStr[32]="Ready.";
char dwnldDirM[64]="/Users/";
char dwnldDirU[64]="/home/";
// Start code
typedef struct{
    // Labels
    GtkWidget *w_lbl_status;
} app_widgets;
static void print_hello(GtkWidget *widget,gpointer data){
    g_print("Hello World!\n");
}
static void show_about(GtkWidget *widget,gpointer data){
  GdkPixbuf *logo=gdk_pixbuf_new_from_file("./logo.png",NULL);
  gtk_show_about_dialog(NULL,"program-name","NCX-Core-Lite","logo",logo,"version","v0.3","title","About NCX-Core-Lite","license-type",GTK_LICENSE_GPL_3_0,"website","https://ncx-programming.github.io/site/programs/ncxcorelite","copyright","Copyright (c) 2021 NCX-Programming/NinjaCheetah",NULL);
}
void download_software(int selection){
  #ifdef unix
    chdir(dwnldDirU);
  #endif
  #ifdef __APPLE__
    chdir(dwnldDirM);
  #endif
  if(!Download("https://github.com/NCX-Programming/theVaultC/releases/latest/download/theVault-ALL.zip", "theVault-ALL.zip")){g_print("Done.\n");};
}
void button1_download(GtkButton *button,app_widgets *wdgts){
  app_widgets *widgets = g_slice_new(app_widgets);
  gchar dwnldStr2[15]="Downloading...";
  gtk_label_set_text(GTK_LABEL(widgets->w_lbl_status),dwnldStr2);
  //gtk_widget_show(GTK_WIDGET(widgets->statuslabel));
  //while(gtk_events_pending())
	 //gtk_main_iteration();
  //download_software(1);
  g_slice_free(app_widgets,widgets);
}
static void activate(GtkApplication *app,app_widgets *wdgts){
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *box;
  GtkWidget *button;
  GtkWidget *menubar;
  GtkWidget *fileMenu;
  GtkWidget *fileMi;
  GtkWidget *quitMi;
  GtkWidget *helpMenu;
  GtkWidget *helpMi;
  GtkWidget *aboutMi;
  GtkWidget *title=gtk_label_new(NULL);
  app_widgets *widgets=g_slice_new(app_widgets);
  //GtkWidget *status=gtk_label_new("Ready.");
  // Create a new window and set title
  window=gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window),"NCX-Core-Lite");
  gtk_window_set_default_size(GTK_WINDOW(window),440,250);
  gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
  // Make a menu bar and menu items
  menubar=gtk_menu_bar_new();
  fileMenu=gtk_menu_new();
  fileMi=gtk_menu_item_new_with_label("File");
  quitMi=gtk_menu_item_new_with_label("Quit");
  helpMenu=gtk_menu_new();
  helpMi=gtk_menu_item_new_with_label("Help");
  aboutMi=gtk_menu_item_new_with_label("About");
  // Set up menu bar
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi),fileMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),quitMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar),fileMi);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(helpMi),helpMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu),aboutMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar),helpMi);
  g_signal_connect_swapped(G_OBJECT(quitMi),"activate",G_CALLBACK(gtk_widget_destroy),window);
  g_signal_connect_swapped(G_OBJECT(aboutMi),"activate",G_CALLBACK(show_about),NULL);
  // Make a new box to hold a menu bar and the grid
  box=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  // Here we construct the container that is going pack our buttons
  grid=gtk_grid_new();
  gtk_container_set_border_width(GTK_CONTAINER(grid),8);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid),true);
  gtk_grid_set_row_spacing(GTK_GRID(grid),6);
  gtk_grid_set_column_spacing(GTK_GRID(grid),6);
  // Pack the box in the window
  gtk_container_add(GTK_CONTAINER(window),box);
  // Pack the menu bar inside the box
  gtk_box_pack_start(GTK_BOX(box),GTK_WIDGET(menubar),false,false,0);
  // Create and pack labels (BEFORE THE GRID!)
  // main title label
  const char *str="NCX-Core-Lite";
  const char *format="<span font-size=\"17000\">\%s</span>";
  char *markup;
  markup=g_markup_printf_escaped(format,str);
  gtk_label_set_markup(GTK_LABEL(title),markup);
  g_free(markup);
  gtk_widget_set_margin_top(GTK_WIDGET(title),8);
  gtk_widget_set_margin_bottom(GTK_WIDGET(title),3);
  gtk_box_pack_start(GTK_BOX(box),GTK_WIDGET(title),false,false,0);
  // small status label
  widgets->w_lbl_status=gtk_label_new(dwnldStr);
  gtk_box_pack_start(GTK_BOX(box),GTK_WIDGET(widgets->w_lbl_status),false,false,0);
  // Pack the grid inside the box
  gtk_box_pack_start(GTK_BOX(box),GTK_WIDGET(grid),false,false,0);
  // Button 1, Place at cell (0,0) and take up 1 space vertically and horizontally
  button=gtk_button_new_with_label("theVaultC");
  g_signal_connect(button,"clicked",G_CALLBACK(button1_download),NULL);
  gtk_grid_attach(GTK_GRID(grid),button,0,0,1,1);
  // Button 2, place at cell (1,0) and take up 1 space vertically and horizontally
  button=gtk_button_new_with_label("Button 2");
  g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);
  gtk_grid_attach(GTK_GRID(grid),button,1,0,1,1);
  // Button 3, place at cell (0,1) and take up 1 space vertically and horizontally
  button=gtk_button_new_with_label("Button 3");
  g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);
  gtk_grid_attach(GTK_GRID(grid),button,0,1,1,1);
  // Button 4, place at cell (1,1) and take up 1 space vertically and horizontally
  button=gtk_button_new_with_label("Button 4");
  g_signal_connect(button,"clicked",G_CALLBACK(print_hello),NULL);
  gtk_grid_attach(GTK_GRID(grid),button,1,1,1,1);
  // Quit button, place at cell (0,2) and take up 1 space vertically and 2 spaces horizontally
  button=gtk_button_new_with_label("Quit");
  g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),window);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 2, 1);
  // Show all of the widgets now that they're set up
  gtk_widget_show_all(window);
  g_slice_free(app_widgets,widgets);
}
int main(int argc,char *argv[]){
    getlogin_r(usr,32);
    #ifdef unix
      strcat(dwnldDirU,usr);
      strcat(dwnldDirU,"/Downloads");
    #endif
    #ifdef __APPLE__
      strcat(dwnldDirM,usr);
      strcat(dwnldDirM,"/Downloads");
    #endif
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

    GtkApplication *app;
    int status;

    app=gtk_application_new("org.ncx-programming.ncx-core-lite",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app,"activate",G_CALLBACK(activate),NULL);
    status=g_application_run(G_APPLICATION(app),argc,argv);
    g_object_unref(app);

    return status;
}
