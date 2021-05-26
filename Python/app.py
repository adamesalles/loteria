import loteria
import os
import time
zero_time = time.time()
ganhou = False
tentativas = 0


def main():
    global ganhou
    global tentativas
    sorteio = loteria.cria_jogo(6)
    while ganhou == False:
        tentativas += 1
        ganhou = loteria.sorteia(sorteio)
        print(tentativas)
    print(
        f"Foram necessárias {tentativas} tentativas. E demorou {(time.time() - zero_time)/60} minutos.")


if __name__ == "__main__":
    main()
