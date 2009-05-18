class NounWord < ActiveRecord::Base
  has_one :noun_relation
  has_many :word_locations
end
