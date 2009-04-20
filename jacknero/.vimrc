" "マウスモード有効
" set mouse=a
" " screen対応
" if &term == "screen"
"    set ttymouse=xterm2
"    endif
syntax on

" rails.vim
let g:rails_level=4
let g:rails_default_file="app/controllers/application.rb"
let g:rails_default_database="sqlite3"

" rubycomplete.vim
autocmd FileType ruby,eruby set omnifunc=rubycomplete#Complete
autocmd FileType ruby,eruby let g:rubycomplete_buffer_loading = 1
autocmd FileType ruby,eruby let g:rubycomplete_rails = 1
autocmd FileType ruby,eruby let g:rubycomplete_class_in_global = 

set laststatus=2
"インデントはスマートインデント
set smartindent
""検索文字列が小文字の場合は大文字小文字を区別なく検索する
set ignorecase
"検索文字列に大文字が含まれている場合は区別して検索する
set smartcase
""検索時に最後まで行ったら最初に戻る
set wrapscan
"検索文字列入力時に順次対象文字列にヒットさせない
set noincsearch
""タブの左側にカーソル表示
"set listchars=tab:\\ 
set nolist
""入力中のコマンドをステータスに表示する
set showcmd
"括弧入力時の対応する括弧を表示
set showmatch
""検索結果文字列のハイライトを有効にしない
set nohlsearch
"ステータスラインを常に表示
set laststatus=2


function! GetB()
	let c = matchstr(getline('.'), '.', col('.') - 1)
	let c = iconv(c, &enc, &fenc)
return String2Hex(c)
	endfunction
	" :help eval-examples
	" The function Nr2Hex() returns the Hex string of a number.
func! Nr2Hex(nr)
	let n = a:nr
	let r = ""
	while n
	let r = '0123456789ABCDEF'[n % 16] . r
	let n = n / 16
	endwhile
	return r
	endfunc

func! String2Hex(str)
	let out = ''
	let ix = 0
	while ix < strlen(a:str)
let out = out . Nr2Hex(char2nr(a:str[ix]))
	let ix = ix + 1
	endwhile
	return out
	endfunc

	"ステータスラインに文字コードと改行文字を表示する
	"" set statusline=%<[%n]%m%r%h%w%{'['.(&fenc!=''?&fenc:&enc).':'.&ff.']['.&ft.']'}\ %F%=%l,%c%V%8P
	if winwidth(0) >= 120
	set statusline=%<[%n]%m%r%h%w%{'['.(&fenc!=''?&fenc:&enc).':'.&ff.']'}%y\ %F%=[%{GetB()}]\ %l,%c%V%8P
	else
	set statusline=%<[%n]%m%r%h%w%{'['.(&fenc!=''?&fenc:&enc).':'.&ff.']'}%y\ %f%=[%{GetB()}]\ %l,%c%V%8P
	endif

	"set statusline=%{GetB()}



	" コマンドライン補完するときに強化されたものを使う(参照 :help wildmenu)
	" set wildmenu
	" コマンドライン補間をシェルっぽく
	set wildmode=list:longest
	" バッファが編集中でもその他のファイルを開けるように
	set hidden
	" 外部のエディタで編集中のファイルが変更されたら自動で読み直す
	set autoread

" 文字コード関連
" from ずんWiki http://www.kawaz.jp/pukiwiki/?vim#content_1_7
if &encoding !=# 'utf-8'
  set encoding=japan
endif
set fileencoding=japan
if has('iconv')
  let s:enc_euc = 'euc-jp'
  let s:enc_jis = 'iso-2022-jp'
  " iconvがJISX0213に対応しているかをチェック
  if iconv("\x87\x64\x87\x6a", 'cp932', 'euc-jisx0213') ==# "\xad\xc5\xad\xcb"
    let s:enc_euc = 'euc-jisx0213'
    let s:enc_jis = 'iso-2022-jp-3'
  endif
  " fileencodingsを構築
  if &encoding ==# 'utf-8'
    let s:fileencodings_default = &fileencodings
    let &fileencodings = s:enc_jis .','. s:enc_euc .',cp932'
    let &fileencodings = &fileencodings .','. s:fileencodings_default
    unlet s:fileencodings_default
  else
    let &fileencodings = &fileencodings .','. s:enc_jis
    set fileencodings+=utf-8,ucs-2le,ucs-2
    if &encoding =~# '^euc-\%(jp\|jisx0213\)$'
      set fileencodings+=cp932
      set fileencodings-=euc-jp
      set fileencodings-=euc-jisx0213
      let &encoding = s:enc_euc
    else
      let &fileencodings = &fileencodings .','. s:enc_euc
    endif
  endif
  " 定数を処分
  unlet s:enc_euc
  unlet s:enc_jis
endif


" set tags
if has("autochdir")
  set autochdir
  set tags=tags;
else
  set tags=./tags,./../tags,./*/tags,./../../tags,./../../../tags,./../../../../tags,./../../../../../tags
endif


" CD.vim example:// は適用しない
autocmd BufEnter * if bufname("") !~ "^\[A-Za-z0-9\]*://" | lcd %:p:h | endif


",e でそのコマンドを実行
nmap ,e :execute '!' &ft ' %'<CR>
"nmap ,e :execute 'set makeprg=' . expand(&ft) . '\ ' . expand('%')<CR>:make<CR>


:let g:miniBufExplMapWindowNavVim = 1
:let g:miniBufExplMapWindowNavArrows = 1
:let g:miniBufExplMapCTabSwitchBuffs = 1

nmap ,y :YRShow<CR>


" encoding
nmap ,U :set encoding=utf-8<CR>
nmap ,E :set encoding=euc-jp<CR>
nmap ,S :set encoding=cp932<CR>


" command mode 時 tcsh風のキーバインドに
 cmap <C-A> <Home>
 cmap <C-F> <Right>
 cmap <C-B> <Left>
 cmap <C-D> <Delete>
 cmap <Esc>b <S-Left>
 cmap <Esc>f <S-Right>

"フレームサイズを怠惰に変更する
map <kPlus> <C-W>+
map <kMinus> <C-W>-
"
" 前回終了したカーソル行に移動
autocmd BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$") | exe "normal g`\"" | endif

" MiniBufExplorer で GNU screen likeなキーバインド
 let mapleader = "" 
 "nnoremap <Leader>f :last<CR>
 "nnoremap <Leader><C-f> :last<CR>
 nmap <Space> :MBEbn<CR>
 nmap <F3> :MBEbp<CR>
 nmap <F4> :MBEbn<CR>
nnoremap <Leader><Space> :MBEbn<CR>
nnoremap <Leader>n       :MBEbn<CR>
nnoremap <Leader><C-n>   :MBEbn<CR>
nnoremap <Leader>p       :MBEbp<CR>
nnoremap <Leader><C-p>   :MBEbp<CR>
nnoremap <Leader>c       :new<CR>
nnoremap <Leader><C-c>   :new<CR>
nnoremap <Leader>k       :bd<CR>
nnoremap <Leader><C-k>   :bd<CR>
nnoremap <Leader>s       :IncBufSwitch<CR>
nnoremap <Leader><C-s>   :IncBufSwitch<CR>
nnoremap <Leader><Tab>   :wincmd w<CR>
nnoremap <Leader>Q       :only<CR>
nnoremap <Leader>w       :ls<CR>
nnoremap <Leader><C-w>   :ls<CR>
nnoremap <Leader>a       :e #<CR>
nnoremap <Leader><C-a>   :e #<CR>
nnoremap <Leader>"       :BufExp<CR>
nnoremap <Leader>1   :e #1<CR>
nnoremap <Leader>2   :e #2<CR>
nnoremap <Leader>3   :e #3<CR>
nnoremap <Leader>4   :e #4<CR>
nnoremap <Leader>5   :e #5<CR>
nnoremap <Leader>6   :e #6<CR>
nnoremap <Leader>7   :e #7<CR>
nnoremap <Leader>8   :e #8<CR>
nnoremap <Leader>9   :e #9<CR>

nnoremap ,<Space> :MBEbn<CR>
nnoremap ,n       :MBEbn<CR>
nnoremap ,<C-n>   :MBEbn<CR>
"nnoremap ,p       :MBEbp<CR>
""nnoremap ,<C-p>   :MBEbp<CR>
nnoremap ,c       :new<CR>
nnoremap ,<C-c>   :new<CR>
nnoremap ,k       :bd<CR>
nnoremap ,<C-k>   :bd<CR>
nnoremap ,s       :IncBufSwitch<CR>
nnoremap ,<C-s>   :IncBufSwitch<CR>
nnoremap ,<Tab>   :wincmd w<CR>
nnoremap ,Q       :only<CR>
nnoremap ,w       :ls<CR>
nnoremap ,<C-w>   :ls<CR>
nnoremap ,a       :e #<CR>
nnoremap ,<C-a>   :e #<CR>
nnoremap ,"       :BufExp<CR>
nnoremap ,1   :e #1<CR>
nnoremap ,2   :e #2<CR>
nnoremap ,3   :e #3<CR>
nnoremap ,4   :e #4<CR>
nnoremap ,5   :e #5<CR>
nnoremap ,6   :e #6<CR>
nnoremap ,7   :e #7<CR>
nnoremap ,8   :e #8<CR>
nnoremap ,9   :e #9<CR>
" Taglist用
 nnoremap <Leader>l       :Tlist<CR>
 nnoremap <Leader><C-l>       :Tlist<CR>
 nnoremap <Leader>o       :TlistClose<CR>
 nnoremap <Leader><C-o>       :TlistClose<CR>

 let mapleader = '\' 

 set tabstop=2
 set shiftwidth=2
 set expandtab
 set nocompatible
filetype on
filetype indent on
filetype plugin on
