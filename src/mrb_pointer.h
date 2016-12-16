/*
** mrb_pointer.h - Pointer class
**
** See Copyright Notice in LICENSE
*/

#ifndef MRB_POINTER_H
#define MRB_POINTER_H

void mrb_ud_ptr_init(mrb_state *mrb);
void mrb_ud_ptr_set(mrb_state *mrb, void *ptr);
void *mrb_ud_ptr_get(mrb_state *mrb);
void mrb_ud_ptr_copy(mrb_state *mrb_src, mrb_state *mrb_dst);
void mrb_ud_ptr_free(mrb_state *mrb);

#endif
