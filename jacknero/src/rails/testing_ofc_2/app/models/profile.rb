class Profile < ActiveRecord::Base
  belongs_to :post
  belongs_to :section
  belongs_to :position
  belongs_to :layout
  belongs_to :user
end
