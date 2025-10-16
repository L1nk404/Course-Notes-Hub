/*
 O candidato deve criar um pequeno programa que simule um gerenciador de tarefas. O programa deve realizar as seguintes operações:
 1. Adicionar uma tarefa
 2. Listar todas as tarefas
 3. Marcar uma tarefa como concluída
 4. Remover uma tarefa
 5. Filtrar tarefas por status (pendente, concluída)
 Requisitos:
 - Cada tarefa deve ser um objeto com as seguintes propriedades:
      id (gerado automaticamente, único),
      titulo (string),
      descricao (string, opcional),
      status (pendente ou concluída)
 - O programa deve ser feito em JavaScript (Node.js) e pode ser executado via linha de comando (não precisa de interface gráfica).
 - O candidato pode usar qualquer recurso do JavaScript, mas não deve usar bibliotecas externas (apenas módulos nativos do Node.js, como `readline` para entrada de dados).
 - O código deve ser modular, com funções separadas para cada operação.
 - Deve tratar erros, como tentar marcar uma tarefa que não existe como concluída, ou remover uma tarefa que não existe.
 - O programa deve ter um menu interativo no terminal, onde o usuário pode escolher as opções.
 - O estado das tarefas (dados) deve persistir apenas durante a execução (em memória).
 Como bônus (opcional, mas desejável):
 - Usar async/await e readline.promises para o menu interativo.
 - Escrever testes unitários para as funções principais (usando, por exemplo, Jest).
 - Separar o código em módulos (por exemplo, um arquivo para as funções de manipulação de tarefas e outro para a interface de linha de comando).
*/

function calculator(){
    var var1 = prompt("Type a int number:");
    var var2 = prompt("Type another int number:");
    document.getElementById("result").innerHTML
    = var1 + '+' + var2 + ' = ' + (1*var1 + 1*var2) + '<br>'; 
    // We multiply var1 and var2 because we want a int type of data, and prompts takes strings.
}

calculator()