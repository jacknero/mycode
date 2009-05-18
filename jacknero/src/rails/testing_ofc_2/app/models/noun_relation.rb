class NounRelation < ActiveRecord::Base
  belongs_to :word
  belongs_to :another_word

  def another_word
   NounWord.find(another_word_id) 
  end

  def word
    NounWord.find(word_id)
  end

  def self.save_relation(relation_id, relations)
    if relations.include?(relation_id.to_s)
      return false
    end
   relations.each do |relation|
    noun = NounRelation.new 
    noun.word_id = relation_id
    noun.another_word_id = relation.to_i
    noun.save
    end
    true
  end
end
