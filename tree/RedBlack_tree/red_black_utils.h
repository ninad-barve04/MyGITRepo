#ifndef RED_BLACK_UTILS_H
#define RED_BLACK_UTILS_H (1)

#include "red_black.h"

void recolor(rbnode *node);
rbnode *get_uncle(RBtree *tree, rbnode *curr_node);

#endif /* ifndef RED_BLACK_UTILS_H */
