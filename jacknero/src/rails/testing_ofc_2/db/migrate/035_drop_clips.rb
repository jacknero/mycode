class DropClips < ActiveRecord::Migration
  def self.up
     drop_table :clips
  end

  def self.down
  end
end