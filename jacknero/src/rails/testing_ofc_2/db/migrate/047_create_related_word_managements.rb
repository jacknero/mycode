class CreateRelatedWordManagements < ActiveRecord::Migration
  def self.up
    create_table :related_word_managements do |t|
      t.integer :word_id
      t.integer :another_word_id
      t.integer :search_multi_word_score

      t.timestamps
    end
  end

  def self.down
    drop_table :related_word_managements
  end
end
