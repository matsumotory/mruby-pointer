/*
** mrb_pointer.c - Pointer class
**
** Copyright (c) MATSUMOTO Ryosuke 2016
**
** See Copyright Notice in LICENSE
*/

#include "mrb_pointer.h"
#include "mruby.h"

typedef struct mrb_udptr_struct_t {

  mrb_state *mrb_src;
  mrb_state *mrb_dst;
  void *data;

} mrb_udptr_struct;

void mrb_udptr_init(mrb_state *mrb)
{
  mrb_udptr_struct *ud = (mrb_udptr_struct *)mrb_malloc(mrb, sizeof(mrb_udptr_struct));

  ud->mrb_src = mrb;
  ud->mrb_dst = NULL;
  ud->data = NULL;
  mrb->ud = ud;
}

void mrb_udptr_set(mrb_state *mrb, void *ptr)
{
  mrb_udptr_struct *ud = mrb->ud;

  if (ud == NULL) {
    mrb_raise(mrb, E_RUNTIME_ERROR, "can not set, mrb ud pointer was not initialized");
  }

  ud->data = ptr;
}

void *mrb_udptr_get(mrb_state *mrb)
{
  mrb_udptr_struct *ud = mrb->ud;

  if (ud == NULL) {
    mrb_raise(mrb, E_RUNTIME_ERROR, "can not get. mrb ud pointer was not initialized");
  }

  return ud->data;
}

mrb_state *mrb_udptr_src_mrb(mrb_state *mrb)
{
  mrb_udptr_struct *ud = mrb->ud;

  if (ud == NULL) {
    mrb_raise(mrb, E_RUNTIME_ERROR, "not found src mrb. mrb ud pointer was not initialized");
  }

  return ud->mrb_src;
}

mrb_state *mrb_udptr_dst_mrb(mrb_state *mrb)
{
  mrb_udptr_struct *ud = mrb->ud;

  if (ud == NULL) {
    mrb_raise(mrb, E_RUNTIME_ERROR, "not found dst mrb. mrb ud pointer was not initialized");
  }

  return ud->mrb_dst;
}

void mrb_udptr_copy(mrb_state *src, mrb_state *dst)
{
  mrb_udptr_struct *ud = src->ud;

  if (ud == NULL) {
    /* oops
    ** #define E_RUNTIME_ERROR             (mrb_class_get(mrb, "RuntimeError"))
    */
    mrb_state *mrb = src;
    mrb_raise(mrb, E_RUNTIME_ERROR, "can not copy. mrb ud pointer was not initialized");
  }

  ud->mrb_dst = dst;
  dst->ud = ud;
}

void mrb_udptr_free(mrb_state *mrb)
{
  mrb_udptr_struct *ud = mrb->ud;

  if (ud != NULL) {
    if (ud->mrb_src == mrb) {
      mrb_free(mrb, mrb->ud);
    } else {
      mrb_raise(mrb, E_RUNTIME_ERROR, "mrb ud pointer was initialized by another mrb_state");
    }
  }
}

void mrb_mruby_pointer_gem_init(mrb_state *mrb)
{
}

void mrb_mruby_pointer_gem_final(mrb_state *mrb)
{
}
