class CreateClips < ActiveRecord::Migration
  def self.up
    create_table :clips do |t|
      t.column :user_id, :integer
      t.column :question_id, :integer
      t.column :description, :text
    end
  end

  def self.down
    drop_table :clips
  end
end
