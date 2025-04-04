# bash-clipboard
A clipboard for copy and pasting files in bash.

## Build

Build it from source:
```bash
g++ -o bash-clipboard bashclipboard.cpp
```

move the binary to /usr/local/bin/clipboard
```bash
sudo mv bash-clipboard /usr/local/bin/clipboard
```

add /usr/local/bin to path (if missing)
```bash
echo 'export PATH=$PATH:/usr/local/bin' >> ~/.bashrc
source ~/.bashrc
```

## Usage

Copy file
```bash
cat file.txt | clipboard -c 
```

Paste file
```bash
clipboard -p > file.txt
```






