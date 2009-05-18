class Clip < ActiveRecord::Base
  acts_as_loggables

  belongs_to :user
  belongs_to :content, :polymorphic => true
end
