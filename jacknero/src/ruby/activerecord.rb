require 'active_record'

ActiveRecord::Base.establish_connection(
	:adapter => "mysql",
	:host 	 => "localhost",
	:username => "root",
	:password => "",
	:database => "test"
)

