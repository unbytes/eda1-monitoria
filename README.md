# MONITORIA DE EDA1

## :book: Ementa

<div>
    <details>
        <summary>Ponteiros e alocação dinâmica de memória.</summary>
    </details>
    <details>
        <summary>Princípios da análise de algoritmos</summary>
        <ul>
            <li>Complexidade computacional.</li>
            <li>Análise assintótica: notação Big-O.</li>
        </ul>
    </details>
    <details>
        <summary>Recursão</summary>
        <ul>
            <li>Algoritmos recursivos</li>
            <li>Método da divisão e conquista</li>
        </ul>
    </details>
    <details>
        <summary>Estrutura de dados</summary>
        <ul>
            <li>Elementares (lineares):</li>
                <ul>
                    <li>Arrays e listas</li>
                    <li>Listas encadeadas.</li>
                </ul>
            <li>Tipos abstratos de dados</li>
                <ul>
                    <li>Filas</li>
                    <li>Pilhas</li>
                    <li>Árvores binárias</li>
                </ul>
        </ul>
    </details>
    <details>
        <summary>Algoritmos de ordenação</summary>
        <ul>
            <li>Métodos elementares:</li>
                <ul>
                    <li>Selection Sort</li>
                    <li>Insertion Sort</li>
                    <li>Bubble Sort</li>
                </ul>
            <li>Quicksort</li>
            <li>Mergesort</li>
            <li>Filas de prioridades e heapsort</li>
            <li>Radix sorting</li>
        </ul>
    </details>
    <details>
        <summary>Algoritmos de busca</summary>
        <ul>
            <li>Busca sequencial</li>
            <li>Busca binária</li>
            <li>Árvores de busca binária</li>
        </ul>
    </details>
</div>

## :computer: Monitorias

<div>
    <details>
        <summary>2024.1</summary>
        <ul>
            <li>10/04</li>
            <ul>
                <li>Exercício: <a target='_self' href='https://github.com/unbytes/eda1-monitoria/tree/main/base/2024.1/code/04-10/move-os-xs.c'>Move Os Xs</a> + <a target='_self' href='https://github.com/unbytes/eda1-monitoria/tree/main/base/2024.1/docs/04-10/move-os-xs.c.pdf'>PDF</a></li>
                <li>Anotações da aula - <a target='_self' href='https://github.com/unbytes/eda1-monitoria/tree/main/base/2024.1/docs/04-10/annotations.pdf'>PDF</a></li>
                <li>Gravação da aula - <a target='_self' href='https://drive.google.com/file/d/1TIDngIPs7yGTWyzi380gF4WiGyJ60E8-/view?usp=drive_link'>Drive</a></li>
            </ul>
        </ul>
    </details>
</div>

## :package: Pacotes (Algoritmos)

## :man_teacher: Professora

- [Rose Yuri Shimizu](https://sigaa.unb.br/sigaa/public/docente/portal.jsf?siape=1276557)

## :books: Referências

- [Plano de Ensino](https://fga.rysh.com.br/eda1/)
- Robert Sedgewick Algorithms in C, Addison Wesley, 3nd ed.
- [Algorithms, 4th Edition - Robert Sedgewick e Kevin Wayne](https://algs4.cs.princeton.edu/home/)
- [Prof. Bruno Ribas](https://www.brunoribas.com.br/)
- [Prof. Paulo Feofiloff](https://www.ime.usp.br/~pf/algoritmos/index.html#C-language)
- Thomas H. Cormen et al Algoritmos - Teoria e Prática, Elsevier, 3nd ed.

## :dart: Observações

Para compilar os códigos que utilizam as bibliotecas customizadas da pasta `libs` é necessário utilizar o seguinte comando:

```bash
mkdir "listas/XX/code/output"
gcc -I libs -o "listas/XX/code/output/YY" "listas/XX/code/YY.c"

"./listas/XX/code/output/YY"
```

Em que `XX` é o número da lista e `YY` é o número do exercício.
