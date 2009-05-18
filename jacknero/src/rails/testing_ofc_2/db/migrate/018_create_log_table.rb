class CreateLogTable < ActiveRecord::Migration
  def self.up
    create_table :logs do|t|
      t.column :remote_addr, :string
      t.column :http_user_agent, :string
      t.column :http_x_forwarded_for, :string
      t.column :loggable_type, :string
      t.column :loggable_id, :integer
      t.column :action, :string
      t.column :user_id, :integer
      t.column :created_at, :datetime
    end
  end

  def self.down
    drop_table :logs
  end
end
