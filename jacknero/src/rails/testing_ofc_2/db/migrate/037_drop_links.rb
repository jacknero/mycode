class DropLinks < ActiveRecord::Migration
  def self.up
     drop_table :links
  end

  def self.down
  end
end