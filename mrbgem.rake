MRuby::Gem::Specification.new('mruby-pointer') do |spec|
  spec.license = 'MIT'
  spec.authors = 'MATSUMOTO Ryosuke'
  spec.version = '0.0.1'
  spec.summary = 'Provide mruby C API which shared pointer between two mrb_states'
  spec.mruby.cc.include_paths << "#{spec.dir}/include"
end
