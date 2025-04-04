# bash-clipboard  
A simple clipboard tool for copying and pasting file contents in bash using a temporary file.

## 🛠️ Build

Compile the source:

```bash
g++ -o bash-clipboard bashclipboard.cpp
```

Move the binary to a global location:

```bash
sudo mv bash-clipboard /usr/local/bin/clipboard
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

## 🧼 Notes

- Clipboard content is stored in `/tmp/clipboard_buffer`.
- Works for binary files too.
- Temp data is not encrypted — use with care.
