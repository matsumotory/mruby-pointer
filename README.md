# mruby-pointer   [![Build Status](https://travis-ci.org/matsumotory/mruby-pointer.svg?branch=master)](https://travis-ci.org/matsumotory/mruby-pointer)


Provide mruby C-API which shared pointer between two mrb_states


## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'matsumotory/mruby-pointer'
end
```
## Test

```
rake
```

## example

Please see [bintest/shared_ptr.c](bintest/shared_ptr.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mrb_pointer.h"
#include "mruby.h"
#include "mruby/compile.h"

static mrb_value mrb_pter_set(mrb_state *mrb, mrb_value self)
{ 
  char *str;

  mrb_get_args(mrb, "z", &str);

  mrb_udptr_set(mrb, (void *)strdup(str));

  return self;
}

static mrb_value mrb_pter_get(mrb_state *mrb, mrb_value self)
{ 
  char *str;

  str = (char *)mrb_udptr_get(mrb);

  return mrb_str_new_cstr(mrb, str);
}

const char *pter_set_code = "Pter.set('I am pter')";
const char *pter_get_code = "puts Pter.get";

int main(int argc, char *argv[])
{ 
  mrb_state *mrb_src = mrb_open();
  mrb_state *mrb_dst = mrb_open();
  struct RClass *pter_src = mrb_define_class(mrb_src, "Pter", mrb_src->object_class);
  struct RClass *pter_dst = mrb_define_class(mrb_dst, "Pter", mrb_dst->object_class);

  mrb_define_class_method(mrb_src, pter_src, "set", mrb_pter_set, MRB_ARGS_REQ(1));

  mrb_define_class_method(mrb_dst, pter_dst, "get", mrb_pter_get, MRB_ARGS_NONE());

  /* create a shared ptr object */
  mrb_udptr_init(mrb_src);

  /* set ptr on mrb_src into the shared ptr object */
  mrb_load_string(mrb_src, pter_set_code);

  /* copy the shared ptr object from mrb_src to mrb_dst */
  mrb_udptr_copy(mrb_src, mrb_dst);

  /* get ptr on mrb_src from shared ptr object on mrb_dst */
  mrb_load_string(mrb_dst, pter_get_code);

  mrb_udptr_free(mrb_src);

  mrb_close(mrb_src);
  mrb_close(mrb_dst);

  return 0;
}
```

- run

```
$ ./bintest/shared_ptr 
I am pter
```

### More example for redis

```c
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
```

## License
under the MIT License:
- see LICENSE file
