class InsertLayouts < ActiveRecord::Migration
  def self.up
    drop_table :layouts
    create_table :layouts do |t|
      t.column :name, :string
    end
    array = ['none', 'ecl', 'daisuke', 'inoue', 'matsuda', 'matsui', 'okada', 'watanabe']
    for a in array
      Layout.new(:name => a).save!
    end
  end

  def self.down
  end
end
