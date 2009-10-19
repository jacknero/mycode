" "マウスモード有効
" set mouse=a
" " screen対応
" if &term == "screen"
"    set ttymouse=xterm2
"    endif
syntax on


filetype plugin on
au BufRead,BufNewFile *.txx set filetype=cpp

" rails.vim
let g:rails_level=4
let g:rails_default_file="app/controllers/application.rb"
let g:rails_default_database="sqlite3"

" rubycomplete.vim
autocmd FileType ruby,eruby set omnifunc=rubycomplete#Complete
autocmd FileType ruby,eruby let g:rubycomplete_buffer_loading = 1
autocmd FileType ruby,eruby let g:rubycomplete_rails = 1
autocmd FileType ruby,eruby let g:rubycomplete_class_in_global = 1

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

"mini buffer exploer
":let g:miniBufExplMapWindowNavVim = 1
":let g:miniBufExplMapWindowNavArrows = 1
":let g:miniBufExplMapCTabSwitchBuffs = 1

nmap ,y :YRShow<CR>

".vimrcに
""括弧の自動補完
""inoremap { {}<LEFT>
""inoremap [ []<LEFT>
""inoremap ( ()<LEFT>
""inoremap " ""<LEFT>
""inoremap ' ''<LEFT>
"""vnoremap { "zdi^V{<C-R>z}<ESC>
"vnoremap [ "zdi^V[<C-R>z]<ESC>
"vnoremap ( "zdi^V(<C-R>z)<ESC>
"vnoremap " "zdi^V"<C-R>z^V"<ESC>
"vnoremap ' "zdi'<C-R>z'<ESC>


"gaushe
autocmd FileType scheme :let is_gauche=1

function GoshRunAll()
  " とりあえず保存をする。あと現在のファイル名を保存しておく
  w%
  let fname = expand("%")

  " 5行のバッファを「gosh_out」という名前でウィンドウの下に作る
  below 5new gosh_out

  " 前の出力があるかも知れんので削除する
  execute ":0,%delete"

  " goshを起動する。pathは設定してない。(!!!ここを直した)
  execute "r !gosh -i <".fname

  " 出力結果を保存しておく
  "w ~/gosh_out

endfunction

"nmap <c-s> :call GoshRunAll()<cr>
nmap ,X :call GoshRunAll()<cr>

" encoding
nmap ,U :set encoding=utf-8<CR>
nmap ,E :set encoding=euc-jp<CR>
nmap ,S :set encoding=cp932<CR>

"" カレントバッファを評価
"let g:FtEvalCommand = {
"      \   'scheme' : 'system("gosh"  , "(display (begin\n" . a:expr . "\n))")', 
"      \   'gauche' : 'system("gosh"  , "(display (begin\n" . a:expr . "\n))")', 
"      \   'gosh'   : 'system("gosh"  , "(display (begin\n" . a:expr . "\n))")', 
"      \   'perl'   : 'system("perl"  , "print eval{use Data::Dumper;$Data::Dumper::Terse = 1;$Data::Dumper::Indent = 0;Dumper " . a:expr . " }")',
"      \   'python' : 'system("python", "print(" . a:expr . ")")', 
"      \   'ruby'   : 'system("ruby " , "p proc {\n" . a:expr . "\n}.call")', 
"      \   'vim'    : 'eval(a:expr)', 
"      \ }
"
"function g:FtEval(expr, filetype)
"  unlet! g:FtEvalResult
"  let g:FtEvalResult = eval(a:filetype !~ '\S' ? g:FtEvalCommand[&filetype] : g:FtEvalCommand[a:filetype]) 
"  return g:FtEvalResult
"endfunction
"
"function <SID>GetVisualText()
"  let p0 = getpos('''<')
"  let p1 = getpos('''>')
"
"  if p0[1] == p1[1]
"    return getline(p0[1])[ p0[2] - 1 : p1[2] - 1 ]
"  endif
"  return join([ getline(p0[1])[ p0[2] - 1 : ] ] +  getline(p0[1] + 1, p1[1] - 1) + [ getline(p1[1])[ : p1[2] - 1 ] ] , "\n")
"endfunction
"
"command -narg=? -range FtEvalLine   echo g:FtEval(getline('.'),                <q-args>)
"command -narg=? -range FtEvalBuffer echo g:FtEval(join(getline(0, '$'), "\n"), <q-args>)
"command -narg=? -range FtEvalVisual echo g:FtEval(<SID>GetVisualText(),        <q-args>)
"
"nnoremap <Space>e :FtEvalLine<CR>
"nnoremap <Space>E :FtEvalBuffer<CR>
"vnoremap <Space>e :FtEvalVisual<CR>
"vnoremap <Space>E :FtEvalVisual vim<CR>



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

"" MiniBufExplorer で GNU screen likeなキーバインド
let mapleader = "" 
nnoremap <Leader>f :last<CR>
nnoremap <Leader><C-f> :last<CR>
"nmap <Space> :MBEbn<CR>
"nmap <F3> :MBEbp<CR>
"nmap <F4> :MBEbn<CR>
"nnoremap <Leader><Space> :MBEbn<CR>
"nnoremap <Leader>n       :MBEbn<CR>
nnoremap <Leader><Space> :bn<CR>
nnoremap <Leader>n       :bn<CR>
"nnoremap <Leader><C-n>   :MBEbn<CR>
"nnoremap <Leader>p       :MBEbp<CR>
"nnoremap <Leader><C-p>   :MBEbp<CR>
nnoremap <Leader>c       :new<CR>
nnoremap <Leader><C-c>   :new<CR>
nnoremap <Leader>k       :bd<CR>
nnoremap <Leader><C-k>   :bd<CR>
"nnoremap <Leader>s       :IncBufSwitch<CR>
"nnoremap <Leader><C-s>   :IncBufSwitch<CR>
"nnoremap <Leader><Tab>   :wincmd w<CR>
"nnoremap <Leader>Q       :only<CR>
"nnoremap <Leader>w       :ls<CR>
"nnoremap <Leader><C-w>   :ls<CR>
"nnoremap <Leader>a       :e #<CR>
"nnoremap <Leader><C-a>   :e #<CR>
"nnoremap <Leader>"       :BufExp<CR>
"nnoremap <Leader>1   :e #1<CR>
"nnoremap <Leader>2   :e #2<CR>
"nnoremap <Leader>3   :e #3<CR>
"nnoremap <Leader>4   :e #4<CR>
"nnoremap <Leader>5   :e #5<CR>
"nnoremap <Leader>6   :e #6<CR>
"nnoremap <Leader>7   :e #7<CR>
"nnoremap <Leader>8   :e #8<CR>
"nnoremap <Leader>9   :e #9<CR>
"
"nnoremap ,<Space> :MBEbn<CR>
"nnoremap ,n       :MBEbn<CR>
"nnoremap ,<C-n>   :MBEbn<CR>
""nnoremap ,p       :MBEbp<CR>
"""nnoremap ,<C-p>   :MBEbp<CR>
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
"set itk path
set path+=,/usr/local/include/InsightToolkit/*
filetype on
filetype indent on

"set fdm=syntax
"set nu

"c++の関数を強調表示
autocmd FileType c,cpp syntax match CFunction /[a-zA-Z_]\w*(\@=/
autocmd FileType c,cpp hi CFunction ctermfg=darkcyan

"gtsgs
map  :GtagsCursor<CR>
map  :Gtags -r <CR>

colorscheme  torte

let plugin_minibufexpl_disable = 1
let plugin_lookupfile_disable = 1


"" Ctrl-Tを押した時にバッファの一覧を開く
""":map <silent> <C-T> :call BufferList()<CR>

"ウィンドウズのペースト
"map o "+gP
"imap o <ESC><ESC>"+gPa
map <A+x> "+gP

"クリップボードにもコピー
if has('win32')
  " ヤンクしたときにもクリップボードへもヤンク
  set clipborad=unnamed
  " ヴィジュアルモードでヤンクしたときにも同様
  set guioptions+=a
else
  function! SyncClipboard()
    let cliptext = substitute(getreg(), "'", "'\"'\"'", 'g')
    let cmd = "echo '" . cliptext . "' | vmw copy"
    call system(cmd)
  endfunction
  nmap ,c :call SyncClipboard()<CR>
  nmap yy yy,c
endif

set viminfo+=!

"minibuffrer用
"let g:miniBufExplMapWindowNavVim = 1
"let g:miniBufExplMapWindowNavArrows = 1
"let g:miniBufExplMapCTabSwitchBuffs = 1

"setlocal spell spelllang=en

"" Tabs
nnoremap <Space>t t
nnoremap <Space>T T
nnoremap t <Nop>
nnoremap <silent> tc :<C-u>tabnew<CR>:tabmove<CR>
nnoremap <silent> tk :<C-u>tabclose<CR>
nnoremap <silent> tn :<C-u>tabnext<CR>
nnoremap <silent> tp :<C-u>tabprevious<CR>

" FuzzyFinder.vim
nnoremap <Space>f f
nnoremap <Space>F F
nnoremap f <Nop>
nnoremap <silent> fb :<C-u>FuzzyFinderBuffer!<CR>
nnoremap <silent> ff :<C-u>FuzzyFinderFile!  <C-r>=expand('%:~:.')[:-1-len(expand('%:~:.:t'))]<CR><CR>
nnoremap <silent> fm :<C-u>FuzzyFinderMruFile!<CR>
nnoremap <silent> tb :<C-u>tabnew<CR>:tabmove<CR>:FuzzyFinderBuffer!<CR>
nnoremap <silent> tf :<C-u>tabnew<CR>:tabmove<CR>:FuzzyFinderFile!  <C-r>=expand('#:~:.')[:-1-len(expand('#:~:.:t'))]<CR><CR>
nnoremap <silent> tm :<C-u>tabnew<CR>:tabmove<CR>:FuzzyFinderMruFile!<CR>


"neocomplcache
"Don't use autocomplpop.
let g:AutoComplPop_NotEnableAtStartup = 0
" Use neocomplcache.
let g:NeoComplCache_EnableAtStartup = 0
" partialcomplete
let g:NeoComplCache_PartialMatch = 2
" MaxList
let g:NeoComplCache_MaxList = 10
" Use smartcase.
let g:NeoComplCache_SmartCase = 1
" disabpleautocomple
let g:NeoComplCache_DisableAutoComplete = 1
" Use previous keyword completion.
let g:NeoComplCache_PreviousKeywordCompletion = 1
" Use preview window.
let g:NeoComplCache_EnableInfo = 1
" Use camel case completion.
let g:NeoComplCache_EnableCamelCaseCompletion = 1
" Use underbar completion.
let g:NeoComplCache_EnableUnderbarCompletion = 1
" Set minimum syntax keyword length.
let g:NeoComplCache_MinSyntaxLength = 3
" Set skip input time.
let g:NeoComplCache_SkipInputTime = '0.1'
" AlphabeticalOrder
let g:NeoComplCache_AlphabeticalOrder = 1
" Define dictionary.
let g:NeoComplCache_DictionaryFileTypeLists = {
      \ 'default' : '',
      \ 'vimshell' : $HOME.'/.vimshell_hist',
      \ 'scheme' : $HOME.'/.gosh_completions'
      \ }

" Define keyword.
if !exists('g:NeoComplCache_KeywordPatterns')
  let g:NeoComplCache_KeywordPatterns = {}
endif
let g:NeoComplCache_KeywordPatterns['default'] = '\v\h\w*'

" Plugin
"key-mappings.
imap <silent><C-l> <Plug>(neocomplcache_snippets_expand)
smap <silent><C-l> <Plug>(neocomplcache_snippets_expand)
nmap <silent><C-e> <Plug>(neocomplcache_keyword_caching)
imap <expr><silent><C-e> pumvisible() ?  "\<C-e>" : "\<Plug>(neocomplcache_keyword_caching)"

" VimShell
" Initialize execute file list.
let g:VimShell_ExecuteFileList = {}
let g:VimShell_ExecuteFileList['txt'] = 'vim'
let g:VimShell_ExecuteFileList['vim'] = 'vim'
let g:VimShell_ExecuteFileList['rb'] = 'ruby'
let g:VimShell_ExecuteFileList['pl'] = 'perl'
let g:VimShell_ExecuteFileList['py'] = 'python'

let g:VimShell_EnableInteractive = 1
let g:VimShell_EnableSmartCase = 1

if has('win32') || has('win64') 
  " Display user name on Windows.
  let g:VimShell_Prompt = $USERNAME."% "

  " Use ckw.
  let g:VimShell_UseCkw = 1
else
  " Display user name on Linux.
  let g:VimShell_Prompt = $USER."% "

  call vimshell#set_execute_file('bmp,jpg,png,gif', 'bg eog')
  call vimshell#set_execute_file('mp3,m4a,ogg', 'bg amarok')
  let g:VimShell_ExecuteFileList['zip'] = 'zipinfo'
  call vimshell#set_execute_file('tgz,gz', 'gzcat')
  call vimshell#set_execute_file('tbz,bz2', 'bzcat')
endif
map <C-U> <C-Y>2<C-Y>2<C-Y>2<C-Y>2<C-Y><C-Y>
"map <C-D> <C-E>2<C-E>2<C-E>2<C-E>2<C-E><C-E>
map <C-D> 2j2j2j2j2j2j

"Autocomple.vim
"autocmd Filetype * let g:AutoComplPop_CompleteOption='.,w,b,u,t'

"a.vim
let g:alternateExtensions_h = "c,cpp,cxx,cc,CC,txx"
let g:alternateExtensions_H = "C,CPP,CXX,CC"
let g:alternateExtensions_cpp = "h,hpp"
let g:alternateExtensions_CPP = "H,HPP"
let g:alternateExtensions_txx = "h,hpp"
let g:alternateExtensions_c = "h"
let g:alternateExtensions_C = "H"
let g:alternateExtensions_cxx = "h"


" !: vimshell interactive execute.
nnoremap !  :<C-u>VimShellInteractive<Space>
" &: vimshell background execute.  
nnoremap & :<C-u>VimShellExecute<Space>

if exists('plugin_minibufexpl_disable')
  finish
endif
