class AddPublicColumnTrue < ActiveRecord::Migration
  def self.up
    questions = Question.find(:all)
    for question in questions
      question.public = true
      question.save
    end
  end

  def self.down
  end
end
