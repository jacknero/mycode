class DropDictionaries < ActiveRecord::Migration
  def self.up
     drop_table :dictionaries
  end

  def self.down
  end
end