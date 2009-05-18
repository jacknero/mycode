class CreateQuestionAndAnswer < ActiveRecord::Migration
  def self.up
    create_table "questions", :force => true do |t|
      t.column "body",       :text
      t.column "user_id",    :integer
      t.column "updated_by", :integer
      t.column "created_at", :datetime
      t.column "updated_at", :datetime
    end
    
    create_table "answers", :force => true do |t|
      t.column "body",       :text
      t.column "user_id",    :integer
      t.column "updated_by", :integer
      t.column "created_at", :datetime
      t.column "updated_at", :datetime      
    end
  end

  def self.down
  end
end
