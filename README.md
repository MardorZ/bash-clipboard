# bash-clipboard  
A simple clipboard tool for copying and pasting file contents in bash using a temporary file.

## 🛠️ Build

### Option 1: Manual build

```bash
g++ -o clipboard bash-clipboard/bashclipboard.cpp
```

Move the binary to a global location:

```bash
sudo mv clipboard /usr/local/bin/clipboard
```

### Option 2: Using Makefile

```bash
make          # builds clipboard
make install  # moves it to /usr/local/bin/clipboard
make clean    # removes the binary
```

Ensure `/usr/local/bin` is in your PATH (if not already):

```bash
echo 'export PATH=$PATH:/usr/local/bin' >> ~/.bashrc
source ~/.bashrc
```

## 📋 Usage

Copy a file:

```bash
cat file.txt | clipboard -c
```

Paste the contents:

```bash
clipboard -p > file.txt
```

Show help:

```bash
clipboard --help
```

## 🧼 Notes

- Clipboard content is stored in `/tmp/clipboard_buffer`.
- Works for binary files too.
- Temp data is not encrypted — use with care.
