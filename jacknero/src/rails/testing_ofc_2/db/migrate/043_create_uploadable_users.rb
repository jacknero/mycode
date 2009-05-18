class CreateUploadableUsers < ActiveRecord::Migration
  def self.up
    create_table :uploadable_users do |t|
      t.integer :user_id
      t.string :content

      t.timestamps
    end
  end

  def self.down
    drop_table :uploadable_users
  end
end
