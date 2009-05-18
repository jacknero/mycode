class CreateNounRelations < ActiveRecord::Migration
  def self.up
    create_table :noun_relations do |t|
      t.integer :word_id
      t.integer :another_word_id
      t.integer :user_id

      t.timestamps
    end
  end

  def self.down
    drop_table :noun_relations
  end
end
