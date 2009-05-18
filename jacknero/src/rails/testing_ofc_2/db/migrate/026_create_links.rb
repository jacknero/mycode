class CreateLinks < ActiveRecord::Migration
  def self.up
    create_table :links do |t|
      t.column :url, :string
      t.column :title, :string
      t.column :user_id, :integer
    end
  end

  def self.down
    drop_table :links
  end
end
