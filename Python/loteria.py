import random


def cria_jogo(numeros):
    jogo = set()
    for index in range(0, numeros):
        numero = random.randint(1, 60)
        while numero in jogo:
            numero = random.randint(1, 60)
        jogo.add(numero)
    return jogo


def sorteia(sorteio):
    jogo_principal = cria_jogo(6)
    if jogo_principal.issuperset(sorteio):
        print(jogo_principal, 'era o jogo.', sorteio, 'era o sorteio.')
        return True
    else:
        return False
