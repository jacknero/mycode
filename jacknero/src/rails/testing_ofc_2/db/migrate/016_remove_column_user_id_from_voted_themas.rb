class RemoveColumnUserIdFromVotedThemas < ActiveRecord::Migration
  def self.up
    remove_column :voted_themas, :user_id
  end

  def self.down
    add_column :voted_themas, :user_id, :integer
  end
end
