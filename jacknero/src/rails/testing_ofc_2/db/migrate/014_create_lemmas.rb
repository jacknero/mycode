class CreateLemmas < ActiveRecord::Migration
  def self.up
    create_table :lemmas do |t|
      t.column :title, :string
      t.column :description, :text
      t.column :result_style, :integer
      t.column :show_to, :integer
      t.column :voted_by, :integer
      t.column :created_at, :datetime
      t.column :updated_at, :datetime
      t.column :user_id, :integer
    end
  end

  def self.down
    drop_table :lemmas
  end
end
