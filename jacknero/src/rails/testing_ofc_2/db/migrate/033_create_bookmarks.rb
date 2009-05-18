class CreateBookmarks < ActiveRecord::Migration
  def self.up
    create_table :bookmarks do |t|
      t.column :user_id, :integer
      t.column :page_id, :integer
      t.column :comment, :string
      t.column :created_at, :datetime
    end
  end

  def self.down
    drop_table :bookmarks
  end
end
