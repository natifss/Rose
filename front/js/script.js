document.addEventListener('DOMContentLoaded', function () {

    const ip = '192.168.137.146'
    var ligaLamp = document.getElementById('ligaLamp');
    var desligaLamp = document.getElementById('desligaLamp');
    var ligaLedVerde = document.getElementById('ligaLedVerde');
    var ligaLedVermelho = document.getElementById('ligaLedVermelho');
    var ligaLedAzul = document.getElementById('ligaLedAzul');
    var ligaLedBranco = document.getElementById('ligaLedBranco');
    var ligaBrilho = document.getElementById('ligaBrilho');
    var desligaBrilho = document.getElementById('desligaBrilho');
    var ligaFlash = document.getElementById('ligaFlash');
    var ligaFade = document.getElementById('ligaFade');
    

    ligaLamp.addEventListener('click', function () {
        fetch(`http://${ip}/liga-lamp`, { method: 'POST' })
            .then(response => response.json())
            .then(data => {
                console.log(data);
            })
            .catch(error => {
                console.error('Erro na chamada à API:', error);
            });
    });

    desligaLamp.addEventListener('click', function () {
        fetch(`http://${ip}/desliga-lamp`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaLedVerde.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-verde`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaLedVermelho.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-vermelho`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaLedAzul.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-azul`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaLedBranco.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-branco`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaBrilho.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-brilho`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    desligaBrilho.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/desliga-brilho`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaFlash.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-flash`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });

    ligaFade.addEventListener('click', function () {
        // Faça a chamada à API usando a função fetch
        fetch(`http://${ip}/liga-fade`, { method: 'POST' }) // Substitua pela URL real da sua API
            .then(response => response.json())
            .then(data => {
                // Faça algo com os dados recebidos da API
                console.log(data);
            })
            .catch(error => {
                // Trate os erros
                console.error('Erro na chamada à API:', error);
            });
    });
});
