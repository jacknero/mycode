class CreateReads < ActiveRecord::Migration
  def self.up
    create_table :read_logs do |t|
      t.column :user_id, :integer
      t.column :question_id, :integer
    end
  end

  def self.down
    drop_table :read_logs
  end
end
