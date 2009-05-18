class RemoveUpdatedByFromQuestionsAndUsers < ActiveRecord::Migration
  def self.up
    remove_column :questions, :updated_by
    remove_column :answers, :updated_by
  end

  def self.down
  end
end
