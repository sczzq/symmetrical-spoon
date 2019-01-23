syntax on
filetype on

set magic

set autowrite

set cmdheight=1
set laststatus=2
set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)\

set noeb
set autoindent
set cindent
set noexpandtab

set smarttab
set tabstop=4
set shiftwidth=4
set softtabstop=4

set cursorline
set ruler

set hlsearch

set gdefault
set number
set wildmenu
set report=0
set fillchars=vert:\ ,stl:\ ,stlnc:\ 
set scrolloff=3
au BufRead,BufNewFile * setfiletype txt
set completeopt=longest,menu

let NERDSpaceDelims=1
let NERDCompactSexyComs=1

"----------------------------------------
" ctags
"

let Tlist_Ctags_Cmd = '/usr/bin/ctags'

let Tlist_Show_One_File=1
let Tlist_Auto_Open = 0
let Tlist_Hightlight_Tag_On_BufEnter = 1
let Tlist_Enable_Fold_Column = 0
let Tlist_Process_File_Always = 1
let Tlist_Display_Prototype = 0
let Tlist_Compact_Format = 1

"-----------------------------------------


