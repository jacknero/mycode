class Bookmark < ActiveRecord::Base
  belongs_to :user
  belongs_to :page
  
  #acts_as_taggable
  
  
  validates_presence_of :page_id
  validates_uniqueness_of :page_id, :scope => :user_id
end
