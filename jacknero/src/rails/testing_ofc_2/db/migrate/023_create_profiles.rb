class CreateProfiles < ActiveRecord::Migration
  def self.up
    create_table :profiles do |t|
      t.column :name, :string
      t.column :post_id, :integer
      t.column :section_id, :integer
      t.column :position_id, :integer
      t.column :layout_id, :integer
      t.column :description, :text
      t.column :user_id, :integer
    end
 end

  def self.down
    drop_table :profiles
  end
end
