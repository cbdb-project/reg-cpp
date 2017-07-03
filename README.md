# reg-cpp

This program can run a list of regular expressions to replace texts. You can put all your text files in input folder, reg-cpp will automatically apply your regular expressions to all text files, and output them to output folder.

---

## Getting start

### Prerequisites

```
c++11

boost
```

### Installing

you can download the pre-compiled program from ./bin, and run it(reg-cpp-win.exe for windows, reg-cpp-mac for mac). If you got new files in ./bin/output. That's it.

If you got any mistake. You can try to compile it by yourself. (./reg-cpp-mac.cpp for mac, ./reg-cpp-win.cpp for windows)

My sublime3 compile script was listed here FYI:

g++ -std=c++11 -I \"C:/Program Files/boost_1_64_0/\" -L \"C:/Program Files/boost_1_64_0/libs/\" -static-libgcc -static-libstdc++ \"${file}\" -o \"${file_path}/${file_base_name}\"

After you compile it by your own, you can put your file into ./bin and run it.

### Usage

1. you can write your own
