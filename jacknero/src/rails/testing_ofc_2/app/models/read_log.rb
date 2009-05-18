class ReadLog < ActiveRecord::Base
  belongs_to :user
  belongs_to :question
  belongs_to :read_question, :foreign_key => :question_id
  belongs_to :read_user, :foreign_key => :user_id
end
