class CreateItemsUsers < ActiveRecord::Migration
  def self.up
    create_table :items_users do |t|
      t.column :answer, :text
      t.column :item_id, :integer
      t.column :user_id, :integer
    end
  end

  def self.down
    drop_table :items_users
  end
end
