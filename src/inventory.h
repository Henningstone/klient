#ifndef _inventory_h_
#define _inventory_h_

#include "konstructs.h"

typedef struct {
    int id;
    int num;
    int show;
} Item;

typedef struct {
    Item *items;
    int selected;
} Inventory;

typedef struct {
    int use;
    int index;
} MoveItem;

void render_belt_background(Attrib *inventory_attrib, int selected);
void render_belt_text_blocks(Attrib *text_attrib, Attrib *block_attrib);
void render_ext_inventory_background(Attrib *attrib);
void render_ext_inventory_text_blocks(Attrib *text_attrib, Attrib *block_attrib);
void render_hand_blocks(Attrib *attrib);
void render_mouse_block(Attrib *attrib);

extern Inventory inventory;
extern Inventory ext_inventory;
extern MoveItem move_item;

#endif
