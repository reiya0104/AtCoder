import re
S = input("英文を入力してください: ")
S = re.sub(r"\s+", " ", S)
S = S.replace(" ", "_").replace(":", "_").replace("-", "_")
S = re.sub(r"_+", "_", S)
print(S)
