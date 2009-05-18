class AddQuestionsTitleAndFormatType < ActiveRecord::Migration
  def self.up
    add_column :questions, :title, :text
    add_column :questions, :format_type, :string
  end

  def self.down
    remove_column :questions, :title
    remove_column :questions, :format_type
  end
end
