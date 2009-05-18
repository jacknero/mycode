class RelatedWordManagement < ActiveRecord::Base
  belongs_to :word
  belongs_to :another_word

  def another_word
   SearchWord.find(another_word_id) 
  end

  def word
    SearchWord.find(word_id)
  end

  def self.save_relation(relation_id, relations)
    if relations.include?(relation_id.to_s)
      return false
    end
   relations.each do |relation|
    relat = RelatedWordManagement.new 
    relat.word_id = relation_id
    relat.another_word_id = relation.to_i
    relat.save
    end
    true
  end
end
