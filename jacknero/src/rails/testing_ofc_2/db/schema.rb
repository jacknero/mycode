# This file is auto-generated from the current state of the database. Instead of editing this file, 
# please use the migrations feature of Active Record to incrementally modify your database, and
# then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your database schema. If you need
# to create the application database on another system, you should be using db:schema:load, not running
# all the migrations from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended to check this file into your version control system.

ActiveRecord::Schema.define(:version => 54) do

  create_table "additional_questions", :force => true do |t|
    t.integer "question_id"
    t.integer "other_question_id"
    t.integer "value"
  end

  create_table "answers", :force => true do |t|
    t.text     "body"
    t.integer  "user_id"
    t.datetime "created_at"
    t.datetime "updated_at"
    t.integer  "question_id"
    t.string   "format_type"
    t.boolean  "public"
  end

  create_table "bookmarks", :force => true do |t|
    t.integer  "user_id"
    t.integer  "page_id"
    t.string   "comment"
    t.datetime "created_at"
  end

  create_table "clips", :force => true do |t|
    t.integer  "user_id"
    t.text     "description"
    t.string   "content_type"
    t.integer  "content_id"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "items", :force => true do |t|
    t.string  "body"
    t.integer "voted_thema_id"
    t.integer "input_type_id"
  end

  create_table "items_users", :force => true do |t|
    t.text    "answer"
    t.integer "item_id"
    t.integer "user_id"
  end

  create_table "layouts", :force => true do |t|
    t.string "name"
  end

  create_table "lemmas", :force => true do |t|
    t.string   "title"
    t.text     "description"
    t.integer  "result_style"
    t.integer  "show_to"
    t.integer  "voted_by"
    t.datetime "created_at"
    t.datetime "updated_at"
    t.integer  "user_id"
  end

  create_table "logs", :force => true do |t|
    t.string   "remote_addr"
    t.string   "http_user_agent"
    t.string   "http_x_forwarded_for"
    t.string   "loggable_type"
    t.integer  "loggable_id"
    t.string   "action"
    t.integer  "user_id"
    t.datetime "created_at"
    t.text     "description"
  end

  create_table "messages", :force => true do |t|
    t.string   "body"
    t.datetime "created_at"
  end

  create_table "noun_relations", :force => true do |t|
    t.integer  "word_id"
    t.integer  "another_word_id"
    t.integer  "user_id"
    t.datetime "created_at"
    t.datetime "updated_at"
    t.integer  "check_score"
  end

  create_table "noun_words", :force => true do |t|
    t.string   "name"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "pages", :force => true do |t|
    t.string "uri"
    t.string "title"
  end

  create_table "positions", :force => true do |t|
    t.string "name"
  end

  create_table "posts", :force => true do |t|
    t.string "name"
  end

  create_table "profiles", :force => true do |t|
    t.string  "name"
    t.integer "post_id"
    t.integer "section_id"
    t.integer "position_id"
    t.integer "layout_id"
    t.text    "description"
    t.integer "user_id"
  end

  create_table "questions", :force => true do |t|
    t.text     "body"
    t.integer  "user_id"
    t.datetime "created_at"
    t.datetime "updated_at"
    t.text     "title"
    t.string   "format_type"
    t.integer  "resolved_or"
    t.boolean  "public"
  end

  create_table "read_logs", :force => true do |t|
    t.integer "user_id"
    t.integer "question_id"
  end

  create_table "related_word_managements", :force => true do |t|
    t.integer  "word_id"
    t.integer  "another_word_id"
    t.integer  "search_multi_word_score"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "search_relations", :force => true do |t|
    t.integer  "word_id"
    t.integer  "another_word_id"
    t.integer  "score"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "search_words", :force => true do |t|
    t.string   "name"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "sections", :force => true do |t|
    t.string "name"
  end

  create_table "sessions", :force => true do |t|
    t.string   "session_id"
    t.text     "data"
    t.datetime "updated_at"
  end

  add_index "sessions", ["session_id"], :name => "index_sessions_on_session_id"
  add_index "sessions", ["updated_at"], :name => "index_sessions_on_updated_at"

  create_table "uploadable_users", :force => true do |t|
    t.integer  "user_id"
    t.string   "content"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "users", :force => true do |t|
    t.string   "login"
    t.string   "email"
    t.string   "crypted_password",          :limit => 40
    t.string   "salt",                      :limit => 40
    t.datetime "created_at"
    t.datetime "updated_at"
    t.string   "remember_token"
    t.datetime "remember_token_expires_at"
    t.string   "role"
    t.string   "mobile_email"
  end

  create_table "video_attributes", :force => true do |t|
    t.integer  "video_id"
    t.datetime "permited_at"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "videologs", :force => true do |t|
    t.integer  "user_id"
    t.integer  "video_id"
    t.string   "videoaction"
    t.float    "seektime"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "videos", :force => true do |t|
    t.string   "path"
    t.string   "title"
    t.text     "description"
    t.integer  "user_id"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "voted_themas", :force => true do |t|
    t.string  "body"
    t.boolean "select_or_selects"
    t.integer "order_number"
    t.integer "lemma_id"
  end

  create_table "word_locations", :force => true do |t|
    t.integer  "noun_word_id"
    t.integer  "question_id"
    t.integer  "location"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

end
