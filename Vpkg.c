#include <Elementary.h>

EAPI int
elm_main (int argc, char **argv)

{

	Evas_Object *win, *bg, *bt, *bx, *bx2;
	
/* create new window with name and title */	
	win = elm_win_add(NULL, "Vpkg", ELM_WIN_BASIC);
	elm_win_title_set(win, "Vpkg");
	elm_win_autodel_set(win, EINA_TRUE);
	
/* background */	
	bg = elm_bg_add(win);
	evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(win,bg);
	evas_object_show(bg);
	
/* box object */	
	bx = elm_box_add(win);
	evas_object_size_hint_weight_set(bx, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(win, bx);
	evas_object_show(bx);
	
/* add horizontal box */	
	bx2 = elm_box_add(win);
	elm_box_horizontal_set(bx2, EINA_TRUE);
	evas_object_size_hint_weight_set(bx2, EVAS_HINT_EXPAND, 0.0);
	elm_box_pack_end(bx, bx2);
	evas_object_show(bx2);
	
/* add Install button to box */	
	bt = elm_button_add(win);
	elm_button_label_set(bt, "Install");
	elm_box_pack_end(bx2, bt);
	evas_object_show(bt);


	/* add Remove button to box */	
	bt = elm_button_add(win);
	elm_button_label_set(bt, "Remove");
	elm_box_pack_end(bx2, bt);
	evas_object_show(bt);



/* add Directory button to box */	
	bt = elm_button_add(win);
	elm_button_label_set(bt, "Directory");
	elm_box_pack_end(bx2, bt);
	evas_object_show(bt);



/* add Ok button to box */	
	bt = elm_button_add(win);
	elm_button_label_set(bt, "Ok");
	elm_box_pack_end(bx2, bt);
	evas_object_show(bt);
	

/* add Cancel button to box */	
	bt = elm_button_add(win);
	elm_button_label_set(bt, "Cancel");
	elm_box_pack_end(bx2, bt);
	evas_object_show(bt);
	

/* add Exit button to box */
	bt = elm_button_add(win);
	elm_button_label_set(bt, "Exit");
	elm_box_pack_end(bx2, bt);
	evas_object_show(bt);
	

/* show the size the window */
	evas_object_resize(win, 300, 550);

/* show the window */	
	evas_object_show(win);


	 


	elm_run();
	elm_shutdown();
	return 0;
}
ELM_MAIN();
