# mruby-pointer   [![Build Status](https://travis-ci.org/matsumotory/mruby-pointer.svg?branch=master)](https://travis-ci.org/matsumotory/mruby-pointer)


shared pointer between two mrb_states


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

## License
under the MIT License:
- see LICENSE file
