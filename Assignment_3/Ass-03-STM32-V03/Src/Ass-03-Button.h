//     $Date: 2018-05-10 10:07:15 +1000 (Thu, 10 May 2018) $
// $Revision: 1301 $
//   $Author: Peter $

// Assignment 3 include file

#ifndef ASS_03_BUTTON_H_
#define ASS_03_BUTTON_H_

#include "Ass-03.h"

#define num_buttons 12

typedef struct {
    int position[num_buttons][4];  // = {(x_min, x_max, y_min, y_max),  // Button 1
                                   //   (x_min, x_max, y_min, y_max)};  // Button 2
    int name[num_buttons];
    int symbol[num_buttons];
} button_t;
button_t button;

extern void button_init();

extern int draw_play(int index);
extern int draw_stop(int index);
extern int draw_blist_item(int index);
extern int draw_up(int index);
extern int draw_down(int index);
extern int draw_plist_item(int index);


extern int get_touch_pos(int display_x, int display_y, int popup);

#endif /* ASS_03_BUTTON_H_ */