# -*- coding: utf-8 -*-
import re
from googletrans import Translator

S = input("翻訳する文を入力してください: ")
S = re.sub(r"\s+", " ", S)
S = S.replace(" - ", "_")

translator = Translator()
trans_en = translator.translate(S)
trans_jp = translator.translate(trans_en.text, dest="ja")
trans_filename = trans_en.text.replace(" ", "_")
trans_filename = re.sub(r"_+", "_", trans_filename)
# trans_filename = trans_filename[0] + "_" + trans_filename[2:]
print(f"英訳: {trans_en.text}")
print(f"再翻訳: {trans_jp.text}")
print(f"英訳ファイル名: {trans_filename}")
