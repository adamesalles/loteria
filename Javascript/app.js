// const main_bt = document.getElementById("main_button")
let start = new Date().getTime();
let jogos = new Array();

function cria_jogo(numeros){
    let jogo = new Set();
    while (jogo.size < numeros){
        let numero_aleatorio = Math.floor(Math.random() * 60) + 1;
        jogo.add(numero_aleatorio);
    }
    return jogo;
}

function aposta(sorteio, numeros){
    let jogo_principal = cria_jogo(numeros);
    // while(jogos.includes(jogo_principal)){
    //     jogo_principal = cria_jogo(numeros);
    // }
    // jogos.push(jogo_principal)
    // console.log(jogo_principal)
    if (isSuperset(jogo_principal, sorteio)){
        return true;
    } else {
        return false;
    }
}

function isSuperset(set, subset) {
    for (let elem of subset) {
        if (!set.has(elem)) {
            return false;
        }
    }
    return true;
}

let ganhou = false;
let tentativas = 0;

function main() {
    let sorteio = cria_jogo(6);
    while (ganhou == false){
        tentativas++;
        ganhou = aposta(sorteio,6);
        console.log(tentativas)
    }
    console.log("O jogo era " + sorteio +` e foram necessárias ${tentativas}`)
}



main()
let end = new Date().getTime();
let time = end - start;
console.log('Tempo de execução: ' + time/1000)
console.log('Tempo médio por aposta: ' + (time/1000)/tentativas)