#!/usr/bin/python

import os;
import shutil;
import re;
import sys;

if len(sys.argv) != 3 :
    print("Usage replaceWord.py <word to find> <word to replace>");

blah = os.walk(".");

for root, dirs, files in blah:
    for f in files:
        if re.match("[a-zA-Z0-9]*\.[chCH]([pP][pP])?", f) != None :
            openfile = open(f, "r");
            newfile = open(str(f)+"tmp", "w");
            for line in openfile:
                line = re.sub(sys.argv[1], sys.argv[2], line);
                newfile.write(line);
            openfile.close();
            newfile.close();
            os.remove(f);
            shutil.move(str(f)+"tmp", str(f));
