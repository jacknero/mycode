class CreateItems < ActiveRecord::Migration
  def self.up
    create_table :items do |t|
      t.column :body, :string
      t.column :voted_thema_id, :integer
      t.column :input_type_id, :integer
    end
  end

  def self.down
    drop_table :items
  end
end
