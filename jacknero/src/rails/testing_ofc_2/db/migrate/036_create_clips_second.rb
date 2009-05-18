class CreateClipsSecond < ActiveRecord::Migration
  def self.up
    create_table :clips do |t|
      t.column :user_id, :integer
      t.column :description, :text
      t.column :content_type, :string
      t.column :content_id, :integer
    end
  end

  def self.down
    drop_table :clips
  end
end
