
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


static void
_item_1_pressed(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
   Evas_Object *bt = data;
   elm_object_text_set(bt, "Install");
}


static void
_item_2_pressed(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
   Evas_Object *bt = data;
   elm_object_text_set(bt, "Remove");
}


static void
_item_3_pressed(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
   Evas_Object *bt = data;
   elm_object_text_set(bt, "About");
}


static void
list_install(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
	Evas_Object *li = data;
	elm_list_clear(li);
	Eina_List *files ;
	Eina_List *l;
	char *package;
	files = ecore_file_ls("/var/log/packages/");
	EINA_LIST_FOREACH(files, l , package)
	elm_list_item_append(li,package, NULL, NULL, NULL, NULL);
	eina_list_free(files);	
}


static void
list_remove(void *data, Evas_Object *obj __UNUSED__, void *event_info __UNUSED__)
{
	Evas_Object *li = data;
	elm_list_clear(li);
	Eina_List *files ;
	Eina_List *l;
	char *package;
	files = ecore_file_ls("/var/log/packages/");
	EINA_LIST_FOREACH(files, l , package)
	elm_list_item_append(li,package, NULL, NULL, NULL, NULL);
	eina_list_free(files);	
}


EAPI_MAIN int
elm_main(int argc __UNUSED__, char **argv __UNUSED__)
{

   vslackpkg V; 
   init (&V);

   evas_object_smart_callback_add(V.win, "delete,request", _on_done, NULL);

   elm_run();
   return 0;
}

ELM_MAIN()

