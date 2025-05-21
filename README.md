# clear-vscode-cache
VS Code Cache clear C++ code frees up valuable memory after it is run.
This utility is useful when you are using  VS Code to develop C++ code and Python code on a dual-boot laptop that runs both Windows and Ubuntu 24.04. The VS Code IDE eats up a lot of memory when you are working in the Ubuntu 24.04 OS.

The cache files are stored n ./confg/code and a few more subdirectoies under this path. This clear_vscode_cache_general.cpp program when compiled deletes these VS Code Cache directories, while displaying their respective sizes.
