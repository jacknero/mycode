class Page < ActiveRecord::Base
  has_many :users, :through => :bookmarks
  has_many :bookmarks, :order => "created_at desc"
  
#  acts_as_ratable :by => User
  acts_as_loggables
  
  attr_accessor :domain
  
  def validate
    begin
      parsed_uri = URI.parse(uri)
      raise unless parsed_uri.host
      raise unless %w(http https).include?(parsed_uri.scheme)
    rescue
      errors.add(:uri, "invalid URI")
    end
  end
  
  def title
    self[:title].blank? ? self[:uri] : self[:title]
    #self.titleを使用すると無限ループするので注意！
  end
end
