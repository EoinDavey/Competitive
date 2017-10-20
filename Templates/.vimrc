set nocompatible
set backspace=indent,eol,start

set backup
set undofile

set history=50
set ruler
set showcmd
set incsearch
set laststatus=2
set number
set relativenumber
set cursorline
set grepprg=grep\ -nH\ $*
let g:tex_flavor='latex'
imap jj <ESC>
nnoremap <CR> :noh<CR><CR>
colo slate
filetype indent on
set wildmenu

" Tabs"
set tabstop=8
set softtabstop=0
set expandtab
set shiftwidth=4
set smarttab

set autoindent		" always set autoindenting on
