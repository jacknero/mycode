class AddRootUser < ActiveRecord::Migration
  def self.up
    admin = User.new
    admin.login ="admin"
    admin.role = "administrator"
    admin.email="admin@kindai.ac.jp"
    admin.password="admin"
    admin.password_confirmation="admin"
    admin.save!
  end

  def self.down
    
  end
end
