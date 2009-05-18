class CreateSearchWords < ActiveRecord::Migration
  def self.up
    create_table :search_words do |t|
      t.string :name

      t.timestamps
    end
  end

  def self.down
    drop_table :search_words
  end
end
