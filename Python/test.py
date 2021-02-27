# -*- coding: utf-8 -*-
from googletrans import Translator

S = input("翻訳する文を入力してください: ")

translator = Translator()
trans_en = translator.translate(S)
# print(trans_en.text)
trans_filename = trans_en.text.replace(" ", "_")
print(trans_filename)
