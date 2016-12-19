/*
** mrb_pointer.h - Pointer class
**
** See Copyright Notice in LICENSE
*/

#ifndef MRB_POINTER_H
#define MRB_POINTER_H

#include "mruby.h"

/* create shared ptr object */
void mrb_udptr_init(mrb_state *mrb_src);

/* set ptr on mrb_src into shared ptr object */
void mrb_udptr_set(mrb_state *mrb_src, void *ptr);

/* get ptr from shared ptr object */
void *mrb_udptr_get(mrb_state *mrb);

/* copy ptr from mrb_src to mrb_dst */
void mrb_udptr_copy(mrb_state *mrb_src, mrb_state *mrb_dst);

/* get src/dst mrb_state from shared ptr object */
mrb_state *mrb_udptr_src_mrb(mrb_state *mrb);
mrb_state *mrb_udptr_dst_mrb(mrb_state *mrb);

/* free shared ptr object */
void mrb_udptr_free(mrb_state *mrb);

#endif
