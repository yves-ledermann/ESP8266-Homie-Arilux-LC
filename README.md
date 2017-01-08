# arduino_esp8266_homie_sonoff
Firmware for the esp8266 based Itead Sonoff

PlatformIO build enviroment.

According to Xose Pérez http://tinkerman.cat/mqtt-led-matrix-display/ thanks for this hint / input.
|The “src” folder contains the firmware files (C++ code). Lately I’m splitting my code in different files (wifi, webserver, mqtt, ota,…), each for one functionality with extension “.ino”. This way I |benefit from the preprocessing of ino files that prepend the declarations of all the defined functions, so I can mostly forget about dependencies between them. Splitting the files gives me a way to handle |the code easily, which is a major benefit.

*** need to write more text***
