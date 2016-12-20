assert('mruby-pointer bin test') do
  assert_equal "I am pter\n", `../bintest/shared_ptr`
end

assert('mruby-pointer bin test for redis') do
  assert_equal "\"foo\"\n", `../bintest/shared_redis_ctx`
end
