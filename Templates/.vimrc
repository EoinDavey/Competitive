set nocompatible
set autoindent		" always set autoindenting on
set cindent
filetype indent on
filetype plugin on

set backup
set undofile

set history=50
set laststatus=2
imap jj <ESC>
nnoremap <CR> :noh<CR><CR>
set wildmenu

" Tabs"
set tabstop=8
set softtabstop=0
set expandtab
set shiftwidth=4
set smarttab
