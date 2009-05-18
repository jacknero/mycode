class CreateVotedThemas < ActiveRecord::Migration
  def self.up
    create_table :voted_themas do |t|
      t.column :body, :string
      t.column :select_or_selects, :boolean
      t.column :user_id, :integer
    end
  end

  def self.down
    drop_table :voted_themas
  end
end
