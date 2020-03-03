# 이산수학 (Discrete Mathematics)

## 1. 관계 및 위상정렬

### 1. 관계

- 집합에 대한 관계
  - A = {0,1,2}, B = {1,2,3} 라 하자 A의 원소 x와 B의 원소 y에 대해서, x가 y보다 작을때만 x와 y가 관계가 있다고 하자. 이때 "x와 y는 관계가 있다"는 문장을 줄여서 x R y 로 표기함. → 0 R 1, 0 R 2, 0 R 3, 1 R 2, 1 R 3, 2 R 3

- 이항관계 (Binary Relations)
  - A와 B를 집합이라고 할 때, A에서 B로의 이항관계는 A×B(데카르트의곱)의 부분집합이다.
  - 관계 R의 순서쌍에서 모든 첫 번째 원소의 집합을 정의역(domain)이라고 하고, 모든 두 번째 원소의 집합을 치역(range)이라고 한다.

- 역관계 (Inverse Relations)
  - 집합 A에서 B로의 관계 R에 대한 역관계는 R<sup>-1</sup>로 나타내며, 다음과 같이 정의된다.
  - R<sup>-1</sup>= { (y, x) ∈ B×A | (x, y) ∈ R }

### 2. 이항관계 (Binary Relations)

- R이 반사적(reflexive) 이면 모든 x∈A 에 대해 x R x 이다.
- R이 대칭적(symmetric) 이면 모든 x,y∈A 에 대해, x R y 이면 y R x 이다.
- R이 반대칭적(antisymmetric) 이면 모든 x,y∈A 에 대해, x R y 이고 y R x 이면 x = y 이다.
- R이 전이적(또는추이적, 이행적transitive) 이면 모든 x,y,z∈A 에 대해, x R y 이고 y R z 이면 x R z 이다.

### 3. 동치관계 (Equivalence Relations)

- 동치관계
  - 집합 A에 관한 관계가 반사적, 대칭적, 전이적이면 동치관계라 부른다.
  - 동치관계로 두 원소 a 와 b 가 관계되어 있을 때, 그들을 동치라고 부른다.
  - a 와 b 가 특정 동치관계에 의한 동치원소임을 표시하기 위해 a ~ b로 표시한다.

- 동치류 및 분할
  - R을 집합 A에 관한 동치관계라 하자. A의 원소 a와 관련된 모든 원소의 집합을 a의 동치류라 부른다. a의 동치류를 [a]로 표시한다.
  - R7 = {(1,1), (1,4), (2,2), (2,3), (3,2), (3,3), (4,1), (4,4)} 는 동치관계이다. 동치류는 [1] = [4] = {1, 4}, [2] = [3] = {2, 3}

### 4. 부분순서관계

- 부분순서관계 (partial order relation)
  - 집합 A에 관한 관계 R이 반사적, 반대칭적, 전이적이면 부분순서라고 부른다.
  - 부분순서 R과 더불어 집합 A를 부분순서 집합(partially ordered set) 이라 부르고, (A, R)로표시한다.
  - 집합 A에 대한 관계 R이 부분순서관계일 때 (a, b) ∊ R을 나타내기 위해서 '≼'를 사용하여 a ≼ b 라고 나타낸다.만일 a ≼ b 이고 a ≠ b 이면 a ≺ b라고 나타내며, 이것은 "a 가 b 보다 우선한다." 라고 말한다. (a precedes b)

- 선형순서관계 (linear order relation)
  - (A, ≼) 가 부분순서집합이고 A의 모든 두 원소가 비교가능 하면, R을 완전순서관계(total order relation) 또는 선형순서관계라고 하며,A를 전체순서집합 또는 선형순서집합이라 부르고, ≼ 를 전체순서 또는 선형순서라고 부른다.

### 5. 하세도표 (Hasse Diagram)

부분순서집합을 그림으로 나타낼 때 쓰는 방법, 방향그래프를 단순화한 도표

### 6. 부분순서집합

- 집합 A가 관계 ≼ 에 관한 부분순서 집합
  - A의 원소 a가 A의 모든원소 b에 대해 b ≼ a 이거나 b와 a가 비교 불가능하면 a를 A의 극대원소(maximal element)라 한다.
  - A의 원소 a가 A의 모든원소 b에 대해 b ≼ a 이면 a를 A의 최대원소(greatest element)라 한다.
  - A의 원소 a가 A의 모든원소 b에 대해 a ≼ b 이거나 b와 a가 비교 불가능하면 a를 A의 극소원소(minimal element)라 한다.
  - A의 원소 a가 A의 모든원소 b에 대해 a ≼ b 이면 a를 A의 최소원소(least element)라 한다.
  
  - 최대원소는 극대원소이다. 하지만 극대원소는 반드시 최대원소이지는 않는다.
  - 최소원소는 극소원소이다. 하지만 극소원소는 반드시 최소원소이지는 않는다.
  - 최대원소와 최소원소는 많아야 하나씩이다. 하지만 극대원소와 극소원소는 하나 이상일 수 있다.

### 7. 위상정렬 (Topological Sorting)

- 집합 A에 대한 부분순서 관계 ≼ 와 ≼’ 을 고려하자.

- A에 속한 모든 원소 a, b에 대해 a ≼ b 일때 a ≼’ b가 되면 ≼’ 이 ≼ 에 부합하다(compatible)고한다.

- 집합 A에 대한 부분순서 관계 ≼와 ≼’이 있을 때, ≼’이 ≼에 부합하는 완전순서이면 ≼’을 ≼에 대한 위상정렬(topological sorting)이라고 한다.

## 2. 논리기초 및 추론 기법

### 1. 명제 (Proposition)

명제란 참 또는 거짓으로 판명이 분명하게 가능한 선언적 문장

### 2. 논리연산자

- 부정 (negation opertor) : ¬
- 논리곱 (conjunction) : ∧ (둘 다 참일 경우 참, 둘 중에 하나라도 거짓이 있으면 거짓)
- 논리합 (disjuncion) : ∨ (둘 중에 하나만 참이면 참, 둘다 거짓일 경우 거짓)
- 배타적 논리합 (exclusive-or) : ⊕ (서로 다를 경우 참, 서로 같을 경우 거짓)
- 함축 (implication) 또는 조건문 (conditional statement) : p → q (p가 참이고 q가 거짓이면 거짓, 이외의 경우 모두 참)
- 상호조건문 (biconditional statement) : p ↔ q (서로 같을 경우 참, 서로 다를 경우 거짓)

### 3. 명제의 동치

- 항진명제 (Tautology)
  - 진리값이 항상 참인 명제

- 논리적 동치
  - 두 복합명제 p, q에 대하여, p ↔ q가 항진이면, p와 q는 논리적으로 동치(logical equivalence)이며, p ≡ q 는 p와 q가 논리적으로 동치임을 나타낸다.

- 조건 명제 p → q 에 대해
  - 역 (converse) : q → p (≠ p → q)
  - 이 (inverse) : ¬p → ¬q (≠ p → q)
  - 대우 (contrapositive) : ¬q → ¬p (≡ p → q)

### 4. 논리적 동치식

자세한 논리적 동치식은 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.26 ~ 27) 참고

### 5. 술어 논리

- 명제의 한계
  - 한 문장이나 식에서, 변수를 포함하면 참 과 거짓을 판별할 수 없기 때문에 명제가 아니지만, 변수에 어떤 값이 할당되면 참 과 거짓을 판별할 수 있어, 명제가 된다.

- 술어 (Predicate)
  - "x는 3보다 크다"
  - 'x'는 변수, "x는 3보다 크다"는 술어라고 한다.

- 명제함수 (Proposition Functions)
  - 변수를 x, 술어를 P라고 했을때, 명제함수는 P(x)로 나타낸다.
  - n-변수술어(n-place predicate)
    - n개의 변수를 포함하는 명제함수
    - x1, x2, ... , xn을 포함하는 명제함수는 P(x1, x2, ... , xn) 이다.

- 술어논리
  - 한정기호: ∀,∃
    - 예) P(x) : 학생 x는 미적분을 수강한다.
    - 이 반 안의 모든학생은 미적분을 수강한다. → ∀xP(x)
    - 이 반의 어떤 학생은 미적분을 수강한다. → ∃xP(x)
  - 한정 표현의 부정
    - 전칭 한정기호의 부정
      - ∀xP(x)의 부정 : "어떤학생은 미적분을 듣지 않는다." → ∃x¬P(x)
      - ¬∀xP(x) ≡ ∃x¬P(x)
    - 존재 한정기호의 부정
      - ∃xP(x)의 부정: "모든학생은 미적분을 듣지 않는다." → ∀x¬P(x)
      - ¬∃xP(x) ≡ ∀x¬P(x)

### 6. 추론

자세한 추론개념은 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.30 ~ 33) 참고

## 3. 정수론

### 1. 정수론 - 서론

- 소수 (prime number)
  - 약수가 1 또는 자기자신의 수

- 서로수 (coprime, relatively prime)
  - 두 정수 a와 b의 공약수가 1인 경우

- 약수와 배수
  - b = a∙c → a|b 또는 c|b 로 나타냄

- 공배수
  - a|b 이고 c|b → b는 a와 c의 공배수 (common multiple)
  - 최소공배수 : lcm (least common multiple)

- 공약수
  - a|b 이고 a|c → a는 b와 c의 공약수 (common divisor)
  - 최대공약수 : gcd (greastestcommon divisor)

- 정리 1
  - m, n, c가 정수일 때,
  - (a) 만약 c가 m, n의 공약수이면 c|(m+n)
  - (b) 만약 c가 m, n의 공약수이면 c|(m-n)
  - (c) 만약 c|m 이면 c|m∙n

- 정리 2
  - 두 정수 a(≥0)와 b(>0) 가 있을 때, a = b∙q + r (0 ≤r <b) 이면 gcd(a,b) = gcd(b,r) 이다.

### 2. 유클리드 알고리즘

- 유클리드 알고리즘 (Euclid algorithm)
  - 정리 2에 근거하여 gcd를 빠르게 찾는 알고리즘
  - gcd(a,b) = gcd(b, a mod b)

처리 과정 및 알고리즘은 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.42) 참고

### 3. 확장된 유클리드 알고리즘

- 정리 3
  - a, b가 양의 정수이면 gcd(a,b) = a∙s + b∙t를 만족하는 정수 s, t가 존재한다.

처리 과정 및 알고리즘은 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.43 ~ 47) 참고

### 4. 일차 디오판토스 방정식 (Linear Diophantine Equation)

- 정리 4
  - a, b, c가 정수일 때, a∙x + b∙y = c 를 만족하는 정수 x, y가 존재 ↔ gcd(a,b)|c

- 예 : 85∙x + 34∙y = 51 을 만족하는 x, y를 구하라.
  - 확장된 유클리드 알고리즘을 이용하여 gcd(85, 34) = 17 = (85)∙(1) + 34∙(-2)
  - 17|51 이다. 즉, 51 / 17 = 3
  - 따라서, (85)∙(1)∙(3) + 34∙(-2)∙(3) = (17)∙(3) 이 만족됨
  - 따라서 x = (1)∙(3) = 3, y = (-2)∙(3) = -6

### 5. 모듈러 연산 (Modular Operations)

- 모듈러 연산 (modular operation)
  - a (mod n) 은 a를 n으로 나누었을 때 나머지를 의미한다.
  - a (mod n) = b (mod n) 을 만족하면 a와 b는 'congruent modulo n' 이라고 함

- 모듈러 연산의 표기
  - n|(a-b) 라면                            → a ≡ b (mod n)
  - a (mod n) ≡ b (modn)                    → a ≡ b (mod n)
  - a ≡ b (mod n)                           → b ≡ a (mod n)
  - a ≡ b (mod n) 그리고 b ≡ c (mod n) 은   → a ≡ c (mod n)

- 모듈러 산술연산
  - [a (mod n) + b (mod n)] (mod n) = ( a + b ) (mod n)
  - [a (mod n) - b (mod n)] (mod n) = ( a - b ) (mod n)
  - [a (mod n) × b (mod n)] (mod n) = ( a × b ) (mod n)

- [ a + b ] = [ a + c ] (mod n) 이면 b ≡ c (mod n)

- [ a x b ] = [ a x c ] (mod n) 이면 b ≡ c (mod n) (a와 n이 서로소일 때만 가능하다)

- Z<sub>n</sub> = { 0, 1, 2, 3, ..., (n-1) } (임의의 Z(정수)를 n으로 나누었을 때의 나머지 집합)

- 덧셈의 역원
  - 두 정수 a, b가 다음을 만족하면 Z<sub>n</sub> 상에서 서로가 덧셈에 대한 역원이다. a + b ≡ 0 (mod n)

- 곱셈의 역원
  - 두 정수 a, b가 다음을 만족하면 Z<sub>n</sub> 상에서 서로가 곱셈에 대한 역원이다. a x b ≡ 1 (mod n)

### 6. 합동식 (Congruence Equation)

- 정리 5
  - a ≡ b (mod n) and c ≡ d (mod n) → a + c ≡ b + d (mod n) and ac ≡ bd (mod n)
  - ac ≡ bc(mod n) and gcd(c, n) = 1 → a ≡ b (mod n)
  - a ≡ b (mod n) → a<sup>m</sup> ≡ b<sup>m</sup> (mod n) for all positive integers m.
  - a ≡ b (mod mn) → a ≡ b (mod m) and a ≡ b (mod n)
  - For c ≠ 0, ac ≡ bc(mod n) ↔ a ≡ b (mod (n / gcd(c, n))
  - a ≡ b (mod m), a ≡ b (mod n), and gcd(m, n)=1 → a ≡ b (mod mn)

- 정리 6
  - ax ≡ b (mod n) 을 만족하는 x가 존재 ↔ gcd(a, n) | b

### 7. 중국인 나머지 정리 (Chinese Remember Theorem)

x ≡ a<sub>1</sub> (mod m<sub>1</sub>)

x ≡ a<sub>2</sub> (mod m<sub>2</sub>)

. . . . . .

x ≡ a<sub>r</sub> (mod m<sub>r</sub>)

- m<sub>1</sub>, m<sub>2</sub>, ..., m<sub>r</sub>이 양의 정수이면서 서로소라고 하자. 임의의 정수 a<sub>1</sub>, a<sub>2</sub>, ...,a<sub>r</sub>에 대하여 다음 r개의 합동식 x = a<sub>i</sub> (mod m<sub>i</sub>) (i = 1, 2, ..., r) 은 공통해를 같고 서로 다른 두 해의 차이는 m<sub>1</sub> * m<sub>2</sub> * ... * m<sub>r</sub> 로 나누어 떨어진다.

중국인 나머지 정리 예제는 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.54 ~ 56) 참고

### 8. 오일러 함수 (Euler Function)

- 오일러 함수 Φ(n) (Euler Φ function)
  - n 보다 작고 n과 서로소인 양의 정수의 개수. Φ(1) = 1로 정의됨.

- 정리 7
  - n과 m이 서로소라면 Φ(nm) = Φ(n)Φ(m)

- 정리 8
  - p가 소수이면 Φ(p<sup>k</sup>) = p<sup>k</sup> - p<sup>k-1</sup>

- 정리 9 (정리 8의 따름 정리)
  - p가 소수 ↔ Φ(p) = p–1
  - Φ(2<sup>k</sup>) = 2<sup>k-1</sup>

- 정리 10
  - SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.58) 참고

- 정리 11 (오일러 정리)
  - 양수 m에 대해 gcd(a, m) = 1 이면 a<sup>Φ(m)</sup> ≡ 1 (mod m)

- 정리 12 (페르마의 소정리)
  - p가 소수이면, (0 < a < p) 인 모든 a에 대해 a<sup>p-1</sup> ≡ 1 (mod p)

### 9. RSA 알고리즘

- RSA 알고리즘
  - 서로 다른 두 개의 소수 p, q를 선택한다.
  - n = p∙q
  - Φ(n) = Φ(p)Φ(q) = (p-1)(q-1)을 계산
  - gcd(e, Φ(n)) = 1 (1 < e < Φ(n)) 인 e를 선택한다.
  - d ≡ e<sup>-1</sup> (mod Φ(n)) 을 계산. 즉, d∙e ≡ 1(mod Φ(n)) 인 d를 찾음

RSA 알고리즘 예제는 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학 - PDF (p.60 ~ 61) 참고

- 예제 : [3951. CRT](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/3.%20%EC%9D%B4%EC%82%B0%EC%88%98%ED%95%99/3951.cpp) , [3952. 줄 세우기](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/3.%20%EC%9D%B4%EC%82%B0%EC%88%98%ED%95%99/3952.cpp) , [3954. 파이의 합](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/3.%20%EC%9D%B4%EC%82%B0%EC%88%98%ED%95%99/3954.cpp)

개념에 대한 더 자세한 설명, 증명과정 및 예제와 문제에 대한 설명은 SWEA → LEARN → Course → Programming Professional → 이산수학 → 9차시 이산수학을 참고
