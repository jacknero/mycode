class CreateVideos < ActiveRecord::Migration
  def self.up
    create_table :videos do |t|
      t.string :path
      t.string :title
      t.text :description
      t.integer :user_id

      t.timestamps
    end
  end

  def self.down
    drop_table :videos
  end
end
