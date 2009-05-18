class CreateAdditionalQuestions < ActiveRecord::Migration
  def self.up
    create_table :additional_questions do |t|
      t.column :question_id, :integer
      t.column :other_question_id, :integer
      t.column :value, :integer
    end
  end

  def self.down
    drop_table :additional_questions
  end
end
