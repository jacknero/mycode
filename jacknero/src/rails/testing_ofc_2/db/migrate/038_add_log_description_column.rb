class AddLogDescriptionColumn < ActiveRecord::Migration
  def self.up
    add_column :logs, :description, :text
  end

  def self.down
    remove_column :logs, :description
  end
end
