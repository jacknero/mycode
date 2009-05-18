class AddUserRoleAndMobileMail < ActiveRecord::Migration
  def self.up
    add_column :users, :role, :string
    add_column :users, :mobile_email, :string
  end

  def self.down
    remove_column :users, :role
    remove_column :users, :mobile_email
  end
end
