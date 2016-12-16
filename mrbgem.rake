MRuby::Gem::Specification.new('mruby-pointer') do |spec|
  spec.license = 'MIT'
  spec.authors = 'MATSUMOTO Ryosuke'
  spec.mruby.cc.include_paths << "#{spec.dir}/src"
end
