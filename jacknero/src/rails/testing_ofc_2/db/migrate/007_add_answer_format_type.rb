class AddAnswerFormatType < ActiveRecord::Migration
  def self.up
    add_column :answers, :format_type, :string
  end

  def self.down
    remove_column :answers, :format_type
  end
end
