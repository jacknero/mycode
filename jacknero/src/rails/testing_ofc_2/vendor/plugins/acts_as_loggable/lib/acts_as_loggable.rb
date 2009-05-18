# moduleを追加したときはinit.rbを編集するべし
module Ecl
  module Acts #:nodoc:
    module Loggable #:nodoc:
      def self.included(base)
        # baseを拡張、ClassMethodモジュールを追加
        base.extend(ClassMethods)  
      end
      
      module ClassMethods
        # 一対多の場合
        def acts_as_loggable(options = {})
          # 定数の宣言　定数名、ハッシュで値を指定(User上で呼び出すとUserと入る)
          write_inheritable_attribute(:acts_as_loggable_options, {
            :loggable_type => ActiveRecord::Base.send(:class_name_of_active_record_descendant, self).to_s
          })
          
          # ゲッター
          class_inheritable_reader :acts_as_loggable_options
          
          # 呼ばれたときの追加されるコード
          has_one :log, :foreign_key => 'loggable_id', :dependent => :nullify
          
          include Ecl::Acts::Loggable::InstanceMethods
        end
        
        # 多対多の場合
        def acts_as_loggables(options = {})
          write_inheritable_attribute(:acts_as_loggable_options, {
            :loggable_type => ActiveRecord::Base.send(:class_name_of_active_record_descendant, self).to_s
          })
          
          class_inheritable_reader :acts_as_loggable_options
          
          has_many :logs, :foreign_key => 'loggable_id', :dependent => :nullify
          
          include Ecl::Acts::Loggable::InstanceMethods
        end
      end
      
      module InstanceMethods
        
        def set_log(opts)
          Log.create(:remote_addr=>opts[:remote_addr],
                     :http_user_agent=>opts[:http_user_agent],
                     :http_x_forwarded_for=>opts[:http_x_forwarded_for],
                     :action=>opts[:action],
                     :loggable_type => self.class.name,
                     :loggable_id => self.id,
                     :user_id => opts[:user_id], 
                     :description => opts[:description])
        end
      end
    end
  end
end