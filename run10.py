# -*- coding: iso-8859-1 -*-
import os, sys
from mensagens import *

if __name__ == "__main__":
    n = int(sys.argv[1])

    print msg_controle("...")+cor("Rodando simulação com 1 dia e 10 nós","amarelo")
    for i in range(n):
        os.system("./miximexamples -u Cmdenv -c N101 -r %i"%i)

    print msg_controle("...")+cor("Rodando simulação com 2 dia e 10 nós","amarelo")
    for i in range(n):
        os.system("./miximexamples -u Cmdenv -c N102 -r %i"%i)

    print msg_controle("...")+cor("Rodando simulação com 3 dia e 10 nós","amarelo")
    for i in range(n):
        os.system("./miximexamples -u Cmdenv -c N103 -r %i"%i)

