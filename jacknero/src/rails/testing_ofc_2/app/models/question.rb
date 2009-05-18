class Question < ActiveRecord::Base
  acts_as_loggables
  belongs_to :user
  has_many :read_logs
  has_many :read_users, :through => :read_logs, :class_name => 'User'
  has_many :answers, :dependent => :destroy
  has_many :clips
  has_many :word_locations
  attr_accessor :richbody

  validates_presence_of :title
  set_field_names :title=>"タイトル", :body => '質問', :richbody => '質問'

  def public_answers
    if RAILS_ENV == 'development'
      return Answer.find(:all, :conditions => ['question_id = ? and public = "t"', self.id])
    else
      return Answer.find(:all, :conditions => ['question_id = ? and public', self.id])
    end
  end
  
  def latest_public_answer
      return Answer.find(:first, :conditions => ['question_id = ? and public', self.id], 
                         :order => 'updated_at desc')
  end
  def to_richbody
    if self.format_type == 'richtext'
      self.richbody = self.body
      self.body = nil
    end
  end
  def to_body
    self.body = self.richbody if self.format_type == 'richtext'
  end
  
  
  protected
  def validate
    errors.add('body', 'を入力して下さい') if self.format_type != 'richtext' && self.body.empty?
    errors.add('richbody', 'を入力して下さい') if self.format_type == 'richtext' && self.richbody == '<br>'
  end
  
  
  private
  def unread_question
    Read.delete_all(:question_id => self.id)
  end
end
