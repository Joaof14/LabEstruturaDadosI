/*Implemente um escalonador de processos baseado no algoritmo
Round-Robin utilizando filas.
● Cada processo tem um tempo de execução.
● Cada processo recebe um quantum de tempo fixo.
● Se um processo não for concluído dentro do quantum, ele retorna ao final
da fila.
Entrada: Adicionar "Processo A" (tempo: 8s)
Adicionar "Processo B" (tempo: 4s)
Adicionar "Processo C" (tempo: 6s)
Quantum: 3s
Saída: Executando Processo A por 3s
Executando Processo B por 3s
Executando Processo C por 3s
Executando Processo A por 3s
Executando Processo C por 3s
Executando Processo A por 2s (finalizado)
Executando Processo B por 1s (finalizado)
Executando Processo C por 3s (finalizado)*/