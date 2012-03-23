// Compile with: 
// gcc Vpkg.c -o Vpkg -Wall `pkg-config --cflags --libs elementary`

#include <Elementary.h>
#ifdef HAVE_CONFIG_H
# include "elementary_config.h"
#else
# define __UNUSED__
#endif

typedef struct
{
	Eina_List *transitions;
	Evas_Object *box;
	Evas_Object_Box_Layout last_layout;
}

Transitions_Data;
static void
_clear_cb(void *data, Evas_Object *obj __UNUSED__, void *ev __UNUSED__)
{
 Transitions_Data *tdata = data;
 elm_box_clear(tdata->box);
}


int
elm_main(int argc __UNUSED__, char *argv[] __UNUSED__)
{
   Evas_Object *win, *bg, *bigbox, *bx, *bt;
   static Transitions_Data tdata = {
        .transitions = NULL,
        .box = NULL,
        .last_layout = NULL
   };

   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);


// Create a new window with name and title
   win = elm_win_add(NULL, "Vpkg1", ELM_WIN_BASIC);
   elm_win_title_set(win, "Vpkg1");
   elm_win_autodel_set(win, EINA_TRUE);
   
   
// Background
   bg = elm_bg_add(win);
   elm_win_resize_object_add(win, bg);
   evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_show(bg);
   
   
// Box object
   bigbox = elm_box_add(win);
   evas_object_size_hint_weight_set(bigbox, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_win_resize_object_add(win, bigbox);
   evas_object_show(bigbox);
   
   
// Box object
   bx = elm_box_add(win);
   elm_box_horizontal_set(bx, EINA_TRUE);
   elm_box_pack_end(bigbox, bx);
   evas_object_show(bx);
   
   
// Add Install button
   bt = elm_button_add(win);
   elm_button_label_set(bt, "Install");
   elm_box_pack_end(bx, bt);
   evas_object_show(bt);
   
   
// Add Remove button
   bt = elm_button_add(win);
   elm_button_label_set(bt, "Remove");
   elm_box_pack_end(bx, bt);
   evas_object_show(bt);
   evas_object_smart_callback_add(bt, "clicked", _clear_cb, &tdata);
   
   
// Box object
   bx = elm_box_add(win);
   elm_box_horizontal_set(bx, EINA_TRUE);
   evas_object_size_hint_weight_set(bx, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bx, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bigbox, bx);
   evas_object_show(bx);
   
	 
// Add Ok button
   bt = elm_button_add(win);
   elm_button_label_set(bt, "Ok");
   elm_box_pack_end(bx, bt);
   evas_object_show(bt);
   
   
// Add Cancel button
   bt = elm_button_add(win);
   elm_button_label_set(bt, "Cancel");
   elm_box_pack_end(bx, bt);
   evas_object_show(bt);
   
   
// Show the size of window
   evas_object_resize(win, 400, 420);


// Show the window
   evas_object_show(win);
   

   elm_run();
   elm_shutdown();
   return 0;

}
ELM_MAIN();
