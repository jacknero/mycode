class AddToVotedThemas < ActiveRecord::Migration
  def self.up
    add_column :voted_themas, :order_number, :integer
    add_column :voted_themas, :lemma_id, :integer
  end

  def self.down
    remove_column :voted_themas, :order_number
    remove_column :voted_themas, :lemma_id
  end
end
