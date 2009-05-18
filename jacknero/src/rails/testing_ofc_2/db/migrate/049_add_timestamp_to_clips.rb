class AddTimestampToClips < ActiveRecord::Migration
  def self.up
    add_column(:clips, :created_at, :datetime)
    add_column(:clips, :updated_at, :datetime)
  end

  def self.down
    delete_column(:clips, :created_at)
    delete_column(:clips, :updated_at)
  end
end
