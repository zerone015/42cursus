## 랜덤한 숫자들을 두 개의 스택과 특정 명령어로만 정렬하는 과제입니다.
랜덤한 숫자들을 두 개의 스택과 특정 명령어만을 사용해서 최소 O(nlogn)의 시간 복잡도로 정렬해야 하는 과제입니다.  
여러 알고리즘들을 응용하여 커스텀 알고리즘으로 해결함으로써 시간 복잡도에 대해 이해하고 다양한 알고리즘을 학습할 수 있는 과제입니다.   
[관련 지식을 정리한 블로그](https://velog.io/@zerone015/series/pushswap)
### 인원
- 1인
### 사용 언어
- C언어
### 실행
```shell
# Download
$ git clone https://github.com/zerone015/42seoul.git push_swap
$ cd push_swap/07_push_swap

# build
$ make       

# execute
./push_swap [random numbers]
ex ) ./push_swap 9 3 2 -9 17
```
### 명령어 목록
- sa: A의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
- sb: B의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
- ss: sa와 sb를 동시에 실행한다.
- pa: B에서 가장 위(탑)에 있는 원소를 가져와서 A의 맨 위(탑)에 넣는다. B가 비어 있으면 아무 것도 하지 않는다.
- pb: A에서 가장 위(탑)에 있는 원소를 가져와서 B의 맨 위(탑)에 넣는다. A가 비어 있으면 아무 것도 하지 않는다.
- ra: A의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
- rb: B의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
- rr: ra와 rb를 동시에 실행한다.
- rra: A의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
- rrb: B의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
- rrr: rra와 rrb를 동시에 실행한다.
### 구현 목록
- 양방향 연결리스트
- 퀵 정렬
- 이진 탐색 알고리즘
- 그리디 알고리즘
- 정렬에 사용할 명령어들
### 학습 내용
- 시간복잡도
- 분할정복
- 알고리즘
- 자료구조