class CreateWordLocations < ActiveRecord::Migration
  def self.up
    create_table :word_locations do |t|
      t.integer :noun_word_id
      t.integer :question_id
      t.integer :location

      t.timestamps
    end
  end

  def self.down
    drop_table :word_locations
  end
end
