import os
import json
from ClassWrite206 import main_file_dir, Pessoa


with open(f"{main_file_dir}/pessoa.json", "r") as file:
    pessoas = json.load(file)
    p1 = Pessoa(**pessoas[0])


print(p1.nome)
