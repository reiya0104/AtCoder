# -*- coding: utf-8 -*-
from googletrans import Translator
import sys

args= sys.argv
if len(args) < 2:
    print('Command should be like')
    print('python3 translate.py textfile.txt')
else:
    print('open '+args[1])
    f = open(args[1])
    lines = f.readlines()
    f.close()
    print(lines)

    translator = Translator()
    for line in lines:
        translated = translator.translate(line, dest="ja")
        print(line) # English
        print(translated.text) # Japanese
        print()
    print('finished')
