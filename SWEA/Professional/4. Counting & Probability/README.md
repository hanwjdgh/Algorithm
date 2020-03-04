# Counting & Probability

## 1. 표본 공간과 사건

### 1. 표본 공간 (Sample Space) 과 사건 (Events)

- 표본 공간
  - 통계적 실험에서 나올 수 있는 모든 결과들의 집합

- 사건
  - 표본공간에 포함된 임의의 결과

### 2. 확률의 공리 (Axioms)

- 확률의 공리
  - 공리 1 : for any event E, 0 <= P[E] <= 1
  - 공리 2 : P[S] = 1
  - 공리 3 : SWEA → LEARN → Course → Programming Professional → Counting & Probability → 20차시 Counting & Probability - PDF (p.9) 참고

- 두 사건 E와 F합에 대하여
  - P(E ∪ F) = P(E) + P(F) - P(EF)

- 상호배타적 (mutually exculsive) 사건 E와 F에 대하여
  - P (E | F) = 0

- 출현 확률이 동일한 산출물 (Outcomes)
  - 두 개의 실험이 독립적일 때 실험 1이 m개의 가능한 산출물이 있고, 실험 2가 n개의 가능한 산출물이 있을 때, 두 개의 실험에는 mn개의 가능한 산출물이 있다.

## 2. 순열 / 조합

### 1. 순열 (Permutaion)

- 순열 (Permutation)
  - 서로 다른 n개의 원소 중에서 중복이 허락하지 않고 r(r<= n)개를  뽑아 한 줄로 늘여 놓는 경우의 수이다. → P(n, r)
  - 순열 예제는 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 20차시 Counting & Probability - PDF (p.12 ~ 14) 참고

- 중복 순열 (Permutation with Repetition)
  - 중복을 허락하는 순열 → Π (n, r) = n<sup>r</sup>

- 기타 순열들
  - 원 순열
    - 열을 회전시킬 수 있어 중복 요소가 있는 순열
    - 5명이 원탁에 앉을 경우 (1, 2, 3, 4, 5) 와 (2, 3, 4, 5, 1)은 이웃이같아 같은 경우로 취급
    - 이 경우 n명이 있을 때 경우의 수 는 n!/n= (n-1)!
  - 염주 순열
    - n 개의 구슬로 염주를 만들 듯이 뒤집어도 같은 것으로 취급
    - (1, 2, 3, 4, 5) 와(2, 3, 4, 5, 1)이 같을 뿐 아니라 (5, 4, 3, 2, 1), (1, 5, 4, 3, 2)도 같은 것임
    - 이 경우 n명이 있을 때 경우의 수 는 n!/n/2= (n-1)! /2
  - 완전 순열 (Complete Permutation or Derangement)
    - 완전 순열에 대한 자세한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 20차시 Counting & Probability - PDF (p.17 ~ 20) 참고

### 2. 조합 (Combinatorics)

- 조합 (Combinatorics)
  - n개의 원소를 가진 집합에서 r(r<= n)개를 중복을 허락하지 않고 뽑는 경우의 수 → C(n, r)

- 조합의 성질
  - C(n, k) = C(n, n-k)
  - C(n, k) = C(n-1, k-1) + C(n-1, k)

- 중복 조합
  - 중복을 허용하는 조합 → H(n, r)
  - H(n, k) = C(n+k-1, k)

- 이항계수 (Binomical Coefficient)
  - 이항계수는 (x + y)<sup>n</sup> 를 전개하였을 때 각 항들의 계수이다.
  - 이항계수의 성질은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 20차시 Counting & Probability - PDF (p.27 ~ 29) 참고

- 카탈란 수 (Catalan Number)
  - 오일러가 (n+2)각형을 n개의 삼각형으로 나눌 수 있는 경우의 수
  - 카탈란 수에 대한 자세한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 20차시 Counting & Probability - PDF (p.30 ~ 37) 참고

## 3. 조건확률 / Bayes의 정리

### 1. 조건부 확률 (Conditional Probabilty)

- 정의
  - 사건 F가 일어났을 때, 사건 E가 발생할 조건부 확률은 다음과 같이 정의된다.
  - P[E|F] = P[EF]/P[F] where P[F] > 0
  - P[F] = a priori (사전)확률, P[E|F] = a posteriori (사후)확률

### 2. 베이스 정리 (Bayes' Formula)

- 조건 확률의 유용한 정리
  - E = EF ∪ EF<sup>C</sup>
  - P(E) = P(EF) + P(EF<sup>C</sup>)
  - = P(E | F)P(F) + P(E | F<sup>C</sup>)P(F<sup>C</sup>) 
  - = P(E | F)P(F) + P(E | F<sup>C</sup>)[1-P(F)]

- 사건 E의 확률은 다음의 가중평균으로 주어진다.
  - 사건 F가 발생하였을 때 사건 E가 발생할 확률
  - 사건 F가 발생하지 않았을 때 사건 E가 발생할 확률

## 4. 각종 Counting 문제

- Inversion Counting
  - a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> 이 1, 2, 3, ..., n의 순열이라고 할 때 i < j 인데 a<sub>i</sub> > a<sub>j</sub>라면 ( a<sub>i</sub>, a<sub>j</sub>) 를 Inversion이라 한다.
  - 방법 1 : 첫 번째 부터 끝까지, 두 번째 부터 끝까지 등으로 비교하는 O(n<sup>2</sup>)
  - 방법 2 : merge sort과정을 통해 비교 하는 O(nlogn)

- Crossing Counting
  - 주어진 점이 다각형의 내부에 있는지를 결정하는 기하문제
  - 주어진 점에서 광선을 발사하여, 다각형과 만나는 개수를 센다. 이것이 홀수면 주어진 점은 다각형의 내부, 짝수면 외부에 존재한다.

- String Repeat Counting

- Tree Path Counting
  - 이진 트리의 두 단말 노드간 합의 최대를 구하는 문제
  - Binary Tree의 종류
    - 정 이진 트리 (Full Binary Tree) : 단말노드가 아닌 모든 노드가 2개의 지식을 갖는 이진트리
    - 완전 이진 트리 (complete Binary Tree) : 포화 이진 트리의 각 노드에 부모에서 자식으로, 왼쪽에서 오른쪽으로 번호를 매겼을 때 포화 이진 트리는 아니지만 그 번호가 연속되어 있는 경우
    - 포화 이진 트리 (Perfect Binary Tree) : 모든 단말 노드의 깊이가 같은 정 이진 트리

## 5. 확률적 알고리즘 또는 무작위 (Randomized) 알고리즘

- 확률적 알고리즘(probabilistic) 또는 무작위 알고리즘
  - 난수를 발생시켜 진행과정을 결정하는 알고리즘

- 라스베가스 (Las Vegas) 알고리즘
  - 옳은 답을 얻지만 수행과정이 오래 걸릴 확률이 약간 존재한다.

- 몬테칼로 (Monte Carlo) 알고리즘
  - 수행시간이 빠르지만 답이 옳지 않을 확률이 약간 존재한다.

무작위 알고리즘에 대한 자세한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 20차시 Counting & Probability - PDF (p.53 ~ 55) 참고

## 6. 예제

- [3993. Pole](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/4.%20Counting%20%26%20Probability/3993.cpp)
- [3996. Poker](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/4.%20Counting%20%26%20Probability/3996.cpp)
- [3998. Inversion Counting](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/4.%20Counting%20%26%20Probability/3998.cpp)

개념에 대한 더 자세한 설명, 증명과정 및 예제와 문제에 대한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability 참고
