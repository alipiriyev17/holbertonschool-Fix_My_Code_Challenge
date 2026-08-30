#!/usr/bin/ruby

puts ARGV.select { |arg| arg.match?(/\A-?\d+\z/) }.sort_by(&:to_i)
