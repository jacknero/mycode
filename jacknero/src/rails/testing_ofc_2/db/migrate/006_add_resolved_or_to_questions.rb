class AddResolvedOrToQuestions < ActiveRecord::Migration
  def self.up
    add_column :questions, :resolved_or, :integer
    questions = Question.find(:all)
    for q in questions
      q.resolved_or = 0
      q.save!
    end
  end

  def self.down
    delete_column :questions, :resolved_or
  end
end
