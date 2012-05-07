


typedef struct vslackpkg{
 Evas_Object *win;
 Evas_Object *bg;
 Evas_Object *bigbox;
 Evas_Object *smallbox;
 Evas_Object *tb; //toolbar
 Elm_Object_Item *list_it; //list item
 Evas_Object *bt_ok; //button ok
 Evas_Object *bt_cancel; //button cancel
 Evas_Object *li;//list
 Evas_Object *label;
} vslackpkg;


void init (vslackpkg *X){

// create a new window

   X->win = elm_win_add(NULL, "vslack_pkg", ELM_WIN_BASIC);
   elm_win_title_set(X->win, "vslack_pkg");


// add a standard background

   X->bg = elm_bg_add(X->win);
   elm_win_resize_object_add(X->win, X->bg);
   evas_object_size_hint_weight_set(X->bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_show(X->bg);

// add a bigbox object

   X->bigbox = elm_box_add(X->win);
   elm_win_resize_object_add(X->win, X->bigbox);
   evas_object_size_hint_weight_set(X->bigbox, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(X->bigbox, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(X->bigbox);


//add a toolbar object with buttons

   X->tb = elm_toolbar_add(X->win);
   elm_toolbar_shrink_mode_set(X->tb, ELM_TOOLBAR_SHRINK_SCROLL);
   evas_object_size_hint_weight_set(X->tb, 0.0, 0.0);
   evas_object_size_hint_align_set(X->tb, EVAS_HINT_FILL, 0.0);
   evas_object_show(X->tb);

   elm_toolbar_homogeneous_set(X->tb, EINA_FALSE);

   elm_box_pack_end(X->bigbox, X->tb);
   //elm_box_pack_end(X->bigbox, X->bt);

   // pre-existing package list:
   X->li = elm_list_add(X->win);
   evas_object_size_hint_weight_set(X->li, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(X->li, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(X->bigbox, X->li);
   Eina_List *files = NULL;
   Eina_List *l;
   void *package;
   files = ecore_file_ls("/var/log/packages/");
   EINA_LIST_FOREACH(files, l , package)
   elm_list_item_append(X->li, package, NULL, NULL, NULL, NULL);
   evas_object_show(X->li);

//add horizontal smallbox inside bigbox

   X->smallbox = elm_box_add(X->win);
   elm_box_horizontal_set(X->smallbox, EINA_TRUE);
   evas_object_size_hint_weight_set(X->smallbox, EVAS_HINT_EXPAND, -0.2);
   evas_object_size_hint_align_set(X->smallbox, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_win_resize_object_add(X->win, X->smallbox);
   elm_box_pack_end(X->bigbox, X->smallbox);
   evas_object_show(X->smallbox);


//add ok button to smallbox

   X->bt_ok = elm_button_add(X->win);
   elm_object_text_set(X->bt_ok, "Ok");
   evas_object_size_hint_weight_set(X->bt_ok, EVAS_HINT_EXPAND, 0);
   evas_object_size_hint_align_set(X->bt_ok, EVAS_HINT_FILL, 0);
   elm_box_pack_end(X->smallbox, X->bt_ok);
   evas_object_show(X->bt_ok);


//add cancel button to smallbox

   X->bt_cancel = elm_button_add(X->win);
   elm_object_text_set(X->bt_cancel, "Cancel");
   evas_object_size_hint_weight_set(X->bt_cancel, EVAS_HINT_EXPAND, 0);
   evas_object_size_hint_align_set(X->bt_cancel, EVAS_HINT_FILL, 0);
   elm_box_pack_end(X->smallbox, X->bt_cancel);
   evas_object_show(X->bt_cancel);


   elm_list_go(X->li);

   evas_object_resize(X->win, 650, 520);
   evas_object_show(X->win);
}


