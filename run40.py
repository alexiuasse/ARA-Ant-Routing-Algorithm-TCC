# -*- coding: iso-8859-1 -*-
import os, sys
from mensagens import *

if __name__ == "__main__":
    n = int(sys.argv[1])

    print msg_controle("...")+cor("Rodando simulação com 1 dia e 50 nós","verde")
    for i in range(n):
        os.system("./miximexamples -u Cmdenv -c N401 -r %i"%i)

    print msg_controle("...")+cor("Rodando simulação com 2 dia e 50 nós","verde")
    for i in range(n):
        os.system("./miximexamples -u Cmdenv -c N402 -r %i"%i)

    print msg_controle("...")+cor("Rodando simulação com 3 dia e 50 nós","verde")
    for i in range(n):
        os.system("./miximexamples -u Cmdenv -c N403 -r %i"%i)

