/*
** mrb_pointer.h - Pointer class
**
** See Copyright Notice in LICENSE
*/

#ifndef MRB_POINTER_H
#define MRB_POINTER_H

#include "mruby.h"

void mrb_udptr_init(mrb_state *mrb);
void mrb_udptr_set(mrb_state *mrb, void *ptr);
void *mrb_udptr_get(mrb_state *mrb);
void mrb_udptr_copy(mrb_state *mrb_src, mrb_state *mrb_dst);
void mrb_udptr_free(mrb_state *mrb);

#endif
