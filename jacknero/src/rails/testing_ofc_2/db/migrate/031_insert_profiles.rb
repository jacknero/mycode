class InsertProfiles < ActiveRecord::Migration
  def self.up
#    users = User.find(:all, :include => :profile, :conditions => 'profiles.id is null')
#    users.each{|u| u.profile = Profile.new }
  end

  def self.down
  end
end
