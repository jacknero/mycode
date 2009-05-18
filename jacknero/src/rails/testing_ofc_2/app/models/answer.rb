class Answer < ActiveRecord::Base
  acts_as_loggables
  belongs_to :user
  belongs_to :question
  attr_accessor :richbody
  
  set_field_names :body => '回答'
  

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
end
