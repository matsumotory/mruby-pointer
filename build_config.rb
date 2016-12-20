MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'full-core'
  conf.gem File.expand_path(File.dirname(__FILE__))
  conf.gem :mgem => 'mruby-redis'
  conf.enable_test
  conf.enable_bintest
end

