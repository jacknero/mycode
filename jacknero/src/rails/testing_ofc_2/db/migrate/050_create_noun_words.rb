class CreateNounWords < ActiveRecord::Migration
  def self.up
    create_table :noun_words do |t|
      t.string :name

      t.timestamps
    end
  end

  def self.down
    drop_table :noun_words
  end
end
