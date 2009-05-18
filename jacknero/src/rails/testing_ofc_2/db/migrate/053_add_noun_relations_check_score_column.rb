class AddNounRelationsCheckScoreColumn < ActiveRecord::Migration
  def self.up
    add_column :noun_relations, :check_score, :integer
  end

  def self.down
    remove_column :noun_relations, :check_score
  end
end
