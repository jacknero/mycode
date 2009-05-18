class WordLocation < ActiveRecord::Base
  belongs_to :noun_word
  belongs_to :question
end
