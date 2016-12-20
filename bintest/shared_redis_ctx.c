#include <stdio.h>
#include "mrb_pointer.h"
#include "mruby.h"
#include "mruby/compile.h"

int main(int argc, char *argv[])
{
  mrb_state *mrb_src = mrb_open();
  mrb_state *mrb_dst = mrb_open();

  /* create a shared ptr object */
  mrb_udptr_init(mrb_src);

  /* set ptr on mrb_src into the shared ptr object */
  mrb_load_string(mrb_src, "Redis.connect_set_raw '127.0.0.1', 6379");

  /* copy the shared ptr object from mrb_src to mrb_dst */
  mrb_udptr_copy(mrb_src, mrb_dst);

  /* get ptr on mrb_src from shared ptr object on mrb_dst */
  mrb_load_string(mrb_dst, "redis = Redis.new; redis['hoge'] = 'foo'; p redis['hoge']");

  mrb_udptr_free(mrb_src);

  mrb_close(mrb_src);
  mrb_close(mrb_dst);

  return 0;
}
