
// compile with :
// gcc vslackpkg.c -o vslackpkg -Wall `pkg-config --cflags --libs elementary`

#include <Elementary.h>
#ifdef HAVE_CONFIG_H
#include "elementary_config.h"
#else
#define __UNUSED__
#endif


#include "graphics.h"


static void
_on_done(void *data __UNUSED__,
		Evas_Object *obj __UNUSED__,
		void *event_info __UNUSED__)
{
	elm_exit();
}

//_sel_cb(void *data, Evas_Object *obj, void *event_info)
//{
   // Elm_Object_Item *list_it = event_info;
   // printf("Selected label: %s\n", elm_object_item_text_get(list_it));
//}

static void
_item_1_pressed(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
  	// Evas_Object *bt_ok = data;
  	// elm_object_text_set(bt_ok, "Install");
  	Evas_Object *li = data;
	elm_list_clear(li);
	Eina_List *files = NULL;
	Eina_List *l;
	void *package;
	files = ecore_file_ls("/home/vasilisslack/Downloads/PKG/");
	EINA_LIST_FOREACH(files, l , package)
	elm_list_item_append(li,package, NULL, NULL, NULL, NULL);
	eina_list_free(files);
}


static void
_item_2_pressed(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
    //Evas_Object *bt_ok = data;
    //elm_object_text_set(bt_ok, "Remove");
	Evas_Object *li = data;
 	elm_list_clear(li);
 	Eina_List *files = NULL ;
 	Eina_List *l;
 	void *package;
 	files = ecore_file_ls("/var/log/packages/");
 	EINA_LIST_FOREACH(files, l , package)
 	elm_list_item_append(li, package, NULL, NULL, NULL, NULL);
 	eina_list_free(files);
}


static void
_item_3_pressed(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
   Evas_Object *bt_ok = data;
   elm_object_text_set(bt_ok, "About");
}

EAPI_MAIN int
elm_main(int argc __UNUSED__, char **argv __UNUSED__)
{

   vslackpkg V;
   init (&V);

   elm_toolbar_item_append(V.tb, NULL, "Install", _item_1_pressed, V.li);
   elm_toolbar_item_append(V.tb, NULL, "Remove", _item_2_pressed , V.li);
   elm_toolbar_item_append(V.tb, NULL, "About", _item_3_pressed, V.bt_ok);

   evas_object_smart_callback_add(V.win, "delete,request", _on_done, NULL);
   evas_object_smart_callback_add(V.bt_cancel, "clicked", _on_done, NULL);

   elm_run();
   return 0;
}

ELM_MAIN()

