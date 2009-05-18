class AddAnswersPublicColumn < ActiveRecord::Migration
  def self.up
    add_column :answers, :public, :boolean
  end

  def self.down
    remove_column :answers, :public
  end
end
