# -*- coding: utf-8 -*-
from googletrans import Translator

S = input("翻訳する文を入力してください: ")

translator = Translator()
trans_en = translator.translate(S)
trans_jp = translator.translate(trans_en.text, dest="ja")
trans_filename = trans_en.text.replace(" ", "_")
print(f"英訳: {trans_en.text}")
print(f"再翻訳: {trans_jp.text}")
print(f"英訳ファイル名: {trans_filename}")

