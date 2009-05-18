#
# ActiveHeart
# 日本語化するのに便利そうなのごちゃまぜplugin
#
# 現在はこの手法での日本語化はお進めできないので、
# 日本語化には Ruby-GetText で、
# モバイルでの trans_sid の機能では jpmobile の利用を
# 推奨します。
#
# MIT License
# gorou <hotchpotch@gmail.com>
# 
warn 'ActiveHeart is obsolute plugin!'
warn 'Please use Ruby-GetText or jpmobile'

require_dependency 'active_record_messages_ja'if defined? ActiveRecord::Base
require_dependency 'trans_sid'
require_dependency 'iso2022jp_mailer' if defined? ActionMailer::Base
