class CreateSearchRelations < ActiveRecord::Migration
  def self.up
    create_table :search_relations do |t|
      t.integer :word_id
      t.integer :another_word_id
      t.integer :score
      t.timestamps
    end

  end

  def self.down
    drop_table :search_relations
  end
end
