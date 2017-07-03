# reg-cpp

reg-cpp can execute a list of regular expressions to replace your texts. You can put all your text files into input folder. reg-cpp will automatically apply your regular expressions to all text files, and output them to output folder.

---

## Getting start

### Prerequisites

```
c++11

boost
```

### Installing

You can download the pre-compiled program from ./bin, and run it(reg-cpp-win.exe for windows, reg-cpp-mac for mac). If you can get new files in ./bin/output. That's it.

If you got any mistakes, you can try to compile it by yourself. (./reg-cpp-mac.cpp for mac, ./reg-cpp-win.cpp for windows)

My sublime3 compile script was listed here for your reference:

g++ -std=c++11 -I \"C:/Program Files/boost_1_64_0/\" -L \"C:/Program Files/boost_1_64_0/libs/\" -static-libgcc -static-libstdc++ \"${file}\" -o \"${file_path}/${file_base_name}\"

After you compile it by your own, you can put your file into ./bin and run it.

## Usage

1. You can write your own regular expressions in ./bin/reg.txt

I am using TAB(\t) in reg.txt to sepreate the target expression and the replace expression

2. Put your text files in ./bin/input

If you want to replace line breaks. Please notice that reg-cpp did not automatically deal with \r\n \n \r, you have to figure out that which one is the correct line break in your texts

3. Run reg-cpp-win.exe / reg-cpp-mac

4. You will get your results in ./bin/output

## License

This project is licensed under the MIT License
