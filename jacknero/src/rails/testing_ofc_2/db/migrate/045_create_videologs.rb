class CreateVideologs < ActiveRecord::Migration
  def self.up
    create_table :videologs do |t|
      t.integer :user_id
      t.integer :video_id
      t.string  :videoaction
      t.float :seektime
      t.datetime :created_at

      t.timestamps
    end
  end

  def self.down
    drop_table :videologs
  end
end
