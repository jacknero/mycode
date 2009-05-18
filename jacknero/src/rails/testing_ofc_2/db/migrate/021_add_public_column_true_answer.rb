class AddPublicColumnTrueAnswer < ActiveRecord::Migration
  def self.up
    answers = Answer.find(:all)
    for answer in answers
      answer.public = true
      answer.save
    end
  end

  def self.down
  end
end
