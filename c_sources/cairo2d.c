
#include <gtk/gtk.h>

// export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/mingw64/lib/pkgconfig # Add pkg-config path in .bashrc of MSYS2/Mingw-w64

// gcc -o cairo2d c_sources/*.c* $(pkgconf --cflags --libs gtk+-3.0) -mwindows && ./cairo2d # -mwindows only in Windows

static gboolean draw_rectangle(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    // Set rectangle properties (e.g., position, size, color)
    cairo_set_source_rgb(cr, 0.5, 0.7, 0.9); // RGB color
    cairo_rectangle(cr, 50, 50, 100, 80);    // Rectangle coordinates and dimensions
    cairo_fill(cr);                          // Fill the rectangle

    return FALSE; // Return FALSE to allow other handlers to draw
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *drawing_area = gtk_drawing_area_new();

    g_signal_connect(drawing_area, "draw", G_CALLBACK(draw_rectangle), NULL);

    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    /* Quit form main if got delete event */
    g_signal_connect(G_OBJECT(window), "delete-event",
                     G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

// gcc -o cairo2d cairo2d.c $(pkgconf --cflags --libs gtk+-3.0) -mwindows && ./cairo2d
