class AddQuestionsPublicColumn < ActiveRecord::Migration
  def self.up
    add_column :questions, :public, :boolean
  end

  def self.down
#    remove_column :questions, :public
  end
end
