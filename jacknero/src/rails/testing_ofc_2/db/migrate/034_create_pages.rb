class CreatePages < ActiveRecord::Migration
  def self.up
    create_table :pages do |t|
      t.column :uri, :string
      t.column :title, :string
    end
  end

  def self.down
    drop_table :pages
  end
end
