/*
** mrb_pointer.c - Pointer class
**
** Copyright (c) MATSUMOTO Ryosuke 2016
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mrb_pointer.h"

typedef struct mrb_ud_struct_t {

  mrb_state *mrb;
  void *data;

} mrb_ud_struct;

void mrb_ud_ptr_init(mrb_state *mrb)
{
  mrb_ud_struct *ud = (mrb_ud_struct *)mrb_malloc(mrb, sizeof(mrb_ud_struct));

  ud->mrb = mrb;
  ud->data = NULL;
  mrb->ud = ud;
}

void mrb_ud_ptr_set(mrb_state *mrb, void *ptr)
{
  mrb_ud_struct *ud = mrb->ud;
  ud->data = ptr;
}

void *mrb_ud_ptr_get(mrb_state *mrb)
{
  mrb_ud_struct *ud = mrb->ud;
  return ud->data;
}

void mrb_ud_ptr_copy(mrb_state *src, mrb_state *dst)
{
  dst->ud = src->ud;
}

void mrb_ud_ptr_free(mrb_state *mrb)
{
  if (mrb->ud != NULL) {
    mrb_free(mrb, mrb->ud);
  }
}

void mrb_mruby_pointer_gem_init(mrb_state *mrb)
{
}

void mrb_mruby_pointer_gem_final(mrb_state *mrb)
{
}

