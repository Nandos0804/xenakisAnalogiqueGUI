#include <gtk/gtk.h>
#include "csound.h"

const char *orc_text =
 "instr 1 \n"
 " out(linen(oscili(p4,p5),0.1,p3,0.1)) \n"
 "endin \n";
const char *sco_text = "i1 0 5 1000 440 \n";


static void print_hello(GtkWidget *widget, gpointer data)
{
  g_print("xenakis Analogique GUI\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{

  GtkWidget *window;
  GtkWidget *button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "xenakisGUI");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  button = gtk_button_new_with_label("xenakisGUI");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  gtk_window_set_child(GTK_WINDOW(window), button);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
  //GtkApplication *app;
  //int status;

  //app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  //g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  //status = g_application_run(G_APPLICATION(app), argc, argv);
  //g_object_unref(app);

  //return status;
  
  void *csound = csoundCreate(0);
  int result = csoundSetOption(csound, "-d");
  result = csoundSetOption(csound, "-odac");
  result = csoundStart(csound);
  result = csoundCompileOrc(csound, orc_text);
  result = csoundReadScore(csound, sco_text);
  while (1) {
     result = csoundPerformKsmps(csound);
     if (result != 0) {
        break;
     }
  }
  result = csoundCleanup(csound);
  csoundReset(csound);
  csoundDestroy(csound);
 
 return result;
}
