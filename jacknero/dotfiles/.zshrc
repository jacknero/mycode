if [ "$TERM" = "xterm" -o "$TERM" = "kterm" ]
then
  hostname=`hostname -s`
  function _setcaption() { echo -ne  "\e]1;${hostname}\a\e]2;${hostname}$1\a" > /dev/tty }

  # ディレクトリを移動したら、ウィンドウのタイトルを
  #   # ホスト名:現在地 のように変更
  function chpwd() {  print -Pn "\e]2; [%m] : %~\a" }
  #       # 初期設定してあげる(cd . でも可)
  chpwd
  #
  #           # 特定のコマンド実行中は、タイトルを ホスト名 (コマンド名) のように
  #             # 変更
  function _cmdcaption() { _setcaption " ($1)"; "$@"; chpwd }
  #
  for cmd in telnet slogin ssh rlogin rsh su sudo
  do
    alias $cmd="_cmdcaption $cmd"
  done
fi
# $Id: zshoptions 2 2006-02-27 16:31:19Z ryo $
#
echo "Loading $HOME/.zsh/zshoptions"
#
# # 複数の zsh を同時に使う時など history ファイルに上書きせず追加する
setopt append_history
#
# # 指定したコマンド名がなく、ディレクトリ名と一致した場合 cd する
setopt auto_cd
#
# # 補完候補が複数ある時に、一覧表示する
setopt auto_list

# デフォルトの補完機能を有効
autoload -U compinit
compinit 
# # 補完キー（Tab, Ctrl+I) を連打するだけで順に補完候補を自動で補完する
setopt auto_menu
#
# # カッコの対応などを自動的に補完する
# setopt auto_param_keys
#
# # ディレクトリ名の補完で末尾の / を自動的に付加し、次の補完に備える
# setopt auto_param_slash
#
# # 最後がディレクトリ名で終わっている場合末尾の / を自動的に取り除く
# #setopt auto_remove_slash
#
# # サスペンド中のプロセスと同じコマンド名を実行した場合はリジュームする
# #setopt auto_resume
#
# # ビープ音を鳴らさないようにする
setopt NO_beep
#
# # {a-c} を a b c に展開する機能を使えるようにする
# setopt brace_ccl
#
# # 内部コマンドの echo を BSD 互換にする
# setopt bsd_echo
#
# # シンボリックリンクは実体を追うようになる
# setopt chase_links
#
# # 既存のファイルを上書きしないようにする
# #setopt clobber
#
# # コマンドのスペルチェックをする
setopt correct
#
# # コマンドライン全てのスペルチェックをする
# #setopt correct_all
#
# # =command を command のパス名に展開する
# setopt equals
#
# # ファイル名で #, ~, ^ の 3 文字を正規表現として扱う
# setopt extended_glob
#
# # zsh の開始・終了時刻をヒストリファイルに書き込む
setopt extended_history
#
# # Ctrl+S/Ctrl+Q によるフロー制御を使わないようにする
# setopt NO_flow_control
#
# # 各コマンドが実行されるときにパスをハッシュに入れる
# #setopt hash_cmds
#
# # 直前と同じコマンドラインはヒストリに追加しない
# setopt hist_ignore_dups
#
# # コマンドラインの先頭がスペースで始まる場合ヒストリに追加しない
# #setopt hist_ignore_space
#
# # ヒストリを呼び出してから実行する間に一旦編集できる状態になる
# setopt hist_verify
#
# # シェルが終了しても裏ジョブに HUP シグナルを送らないようにする
# setopt NO_hup
#
# # Ctrl+D では終了しないようになる（exit, logout などを使う）
# #setopt ignore_eof
#
# # コマンドラインでも # 以降をコメントと見なす
# #setopt interactive_comments
#
# # auto_list の補完候補一覧で、ls -F のようにファイルの種別をマーク表示
# setopt list_types
#
# # 内部コマンド jobs の出力をデフォルトで jobs -l にする
# setopt long_list_jobs
#
# # コマンドラインの引数で --prefix=/usr などの = 以降でも補完できる
# setopt magic_equal_subst
#
# # メールスプール $MAIL が読まれていたらワーニングを表示する
# #setopt mail_warning
#
# # ファイル名の展開でディレクトリにマッチした場合末尾に / を付加する
# setopt mark_dirs
#
# # 補完候補が複数ある時、一覧表示 (auto_list) せず、すぐに最初の候補を補完する
# setopt menu_complete
#
# # 複数のリダイレクトやパイプなど、必要に応じて tee や cat の機能が使われる
# setopt multios
#
# # ファイル名の展開で、辞書順ではなく数値的にソートされるようになる
# setopt numeric_glob_sort
#
# # コマンド名に / が含まれているとき PATH 中のサブディレクトリを探す
# #setopt path_dirs
#
# # 8 ビット目を通すようになり、日本語のファイル名などを見れるようになる
# setopt print_eightbit
#
# # 戻り値が 0 以外の場合終了コードを表示する
# #setopt print_exit_value
#
# # ディレクトリスタックに同じディレクトリを追加しないようになる
# #setopt pushd_ignore_dups
#
# # pushd を引数なしで実行した場合 pushd $HOME と見なされる
# #setopt pushd_to_home
#
# # rm * などの際、本当に全てのファイルを消して良いかの確認しないようになる
# #setopt rm_star_silent
#
# # rm_star_silent の逆で、10 秒間反応しなくなり、頭を冷ます時間が与えられる
# #setopt rm_star_wait
#
# # for, repeat, select, if, function などで簡略文法が使えるようになる
# setopt short_loops
#
# # デフォルトの複数行コマンドライン編集ではなく、１行編集モードになる
# #setopt single_line_zle
#
# # コマンドラインがどのように展開され実行されたかを表示するようになる
# #setopt xtrace
#
# # ファイルの最終行をプロンプトが上書きするのを抑制する
# #unsetopt PROMPT_CR
#
#
# ###
# setopt INTERACTIVE_COMMENTS
# setopt HIST_NO_STORE
# setopt autopushd
PROMPT="%B%m%{[31m%}:%n%b%%  "
RPROMPT="[%~]"

HISTSIZE=100000
HISTFILE=~/.zsh_history
SAVEHIST=100000
function history-all { history -EEEE 1}
setopt share_history


setopt AUTO_PUSHD
alias gd='dirs -v; echo -n "select number: "; read newdir; cd +"$newdir"'

setopt PUSHD_IGNORE_DUPS
bindkey -e
#bindkey -v
LANG=ja_JP.UTF-8
if [ "$TERM" = "screen" ]; then
  preexec() {
    emulate -L zsh
    local -a cmd; cmd=(${(z)2})
    echo -n "k$cmd[1]:t\\"
  }
fi

#railsのgeneratorで補完

_generate () {
  if [ ! -f .generators ]; then
    ./script/generate --help | grep '^  [^ ]*: ' | sed 's/[^:]*:/compadd/' | sed 's/\,//g' > .generators
  fi
  `cat .generators`
}

compdef _generate generate
compdef _generate destroy

#alias
alias h=history
     alias h-a="history-all"
PAGER=less
alias -g L="| $PAGER"
alias -g G="| grep"
alias ls=ls --color
alias screen='screen -U -D -RR'

source ~/.cdd/cdd
function chpwd() {
_reg_pwd_screennum
     }

     alias ls="ls --color"
     xset r rate 150 100

     PATH=$PATH:/var/lib/gems/1.8/bin/
     #alias emacs="emacs -nw"
