class CreateVideoAttributes < ActiveRecord::Migration
  def self.up
    create_table :video_attributes do |t|
      t.integer :video_id
      t.datetime :permited_at

      t.timestamps
    end
  end

  def self.down
    drop_table :video_attributes
  end
end
