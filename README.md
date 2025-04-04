# bash-clipboard
A clipboard for copy and pasting files in bash.

## Installation

Build it from source:
```bash
g++ -o bash-clipboard bashclipboard.cpp
```

## Usage

Copy file
```bash
cat file.txt | bash-clipboard -c 
```

Paste file
```bash
bash-clipboard -p > file.txt
```
