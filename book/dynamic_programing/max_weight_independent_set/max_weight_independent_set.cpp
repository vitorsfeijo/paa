/*
Problema: Conjunto Independente de Peso Máximo em Grafo Linear
--------------------------------------------------------------
Dado um grafo linear G = (V, E) onde cada vértice v ∈ V possui um peso não-negativo w_v,
o objetivo é encontrar um conjunto independente (um conjunto de vértices onde nenhum par
é adjacente) cuja soma dos pesos seja máxima.

Definições:
- Seja V = {v_1, v_2, ..., v_n} a sequência de vértices do grafo linear, ordenados ao longo do caminho.
- Seja w_i = peso do vértice v_i, com w_i >= 0.
- Seja OPT(i) o peso máximo de um conjunto independente para o subgrafo induzido pelos vértices {v_1, ..., v_i}.

Equação de Recorrência (Programação Dinâmica):
- Casos Base:
  OPT(0) = 0          (grafo vazio)
  OPT(1) = w_1        (grafo com apenas o primeiro vértice)

- Passo Indutivo (para i >= 2):
  OPT(i) = max(OPT(i - 1), OPT(i - 2) + w_i)

Prova de Corretude (por indução):
- Base:
  Se n = 0, o único conjunto independente é o vazio, de peso 0. Correto.
  Se n = 1, o conjunto independente de peso máximo contém apenas v_1, com peso w_1. Correto.
- Passo Indutivo:
  Suponha que OPT(k) esteja correto para todo k < i. Para calcular OPT(i), seja S o conjunto
  independente de peso máximo para {v_1, ..., v_i}. Existem dois casos mutuamente exclusivos:
  1. v_i não pertence a S: Nesse caso, S também é um conjunto independente ótimo para os primeiros
     i-1 vértices. Logo, o peso de S é OPT(i - 1).
  2. v_i pertence a S: Como S é independente, v_{i-1} não pode pertencer a S. Portanto, S \ {v_i}
     deve ser um conjunto independente ótimo para os primeiros i-2 vértices. O peso total de S será
     o peso de v_i mais o ótimo para os primeiros i-2 vértices, ou seja, OPT(i - 2) + w_i.
  Como queremos maximizar o peso, escolhemos a melhor opção entre as duas: OPT(i) = max(OPT(i - 1), OPT(i - 2) + w_i).
  Logo, por indução, a recorrência está correta.

Análise de Complexidade:
- Tempo: O(n) - Preenchemos uma tabela unidimensional de tamanho n+1. Cada entrada i é computada em tempo O(1).
- Espaço: O(n) - Para armazenar a tabela OPT. Pode ser otimizado para O(1) se precisarmos apenas do peso máximo,
  mas mantemos O(n) se quisermos reconstruir os vértices que formam o conjunto ótimo.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> graph(n);
  for(int i = 0; i < n; i++){
    cin >> graph[i];
  }

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> opt(n + 1, 0);
  opt[0] = 0;
  opt[1] = graph[0];

  for(int i = 2; i < n; i++){
    opt[i] = max{opt[i-1], opt[i-2] + graph[i - 2]};
  }

  cout << opt[n] << endl;

  return 0;
}