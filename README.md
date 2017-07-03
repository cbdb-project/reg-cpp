# reg-cpp

This program can execute a list of regular expressions to replace texts. You can put all your text files in input folder. reg-cpp will automatically apply your regular expressions to all text files, and output them to output folder.

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

## Usage

1. You can write your own regular expressions in ./bin/reg.txt

The expression to find the target text, and the expression to replace the target text were sepereated by a Tab(\t)

2. Put the text files in ./bin/input

Please notice that, reg-cpp did not automatically deal with \r\n \n \r,

you have to figure out that which one is the correct line break in your text

3. Run reg-cpp-win.exe / reg-cpp-mac

4. You will get your results in ./bin/output

## License

This project is licensed under the MIT License
