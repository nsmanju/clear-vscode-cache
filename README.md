
# clear-vscode-cache utility
```
VS Code Clear Cache C++ code frees up valuable memory after it is run.
This utility is useful when you are using the VS Code tool to develop C++ programs and Python code
on a dual-boot laptop that runs both Windows and Ubuntu 24.04. The VS Code IDE eats up a lot of
memory when you are working on multiple C++ programs while using the Ubuntu 24.04 OS.
```
## How it works
```
The VS Code cache files are stored in the $HOME/./confg/code and under a few subdirectoies under this path. 
This clear_vscode_cache_general.cpp program when compiled and run deletes these VS Code Cache directories, 
while displaying their respective sizes.
```
