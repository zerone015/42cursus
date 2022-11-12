## bash를 모방한 나만의 셸 프로그램을 만드는 과제입니다.
이번 과제는 42seoul 이너 서클의 첫 번째 팀 프로젝트입니다. 팀원과 함께 협업하는 방법을 배우고 bash를 직접 구현하면서 Windows가 존재하지 않았을 시절 사람들이 겪었던 문제를 마주해볼 수 있었습니다.     
[관련 지식을 정리한 블로그](https://velog.io/@zerone015/series/minishell)  
### 인원
- 2인
### 사용 언어
- C언어
### 실행
```shell
# Download
$ git clone https://github.com/zerone015/42seoul.git minishell
$ cd minishell/09_minishell

# build
$ brew install readline
$ make        

# execute
./minishell
```
### 구현 내용
- 셸 프로그램
### 학습 내용
- 협업
- 쉘 구조
- 멀티 프로세싱
- 복잡한 문자열 파싱
- 파일 디스크립터 관리
- 파이프, 리다이렉션, 시그널, 환경변수
- 컴파일러 또는 인터프리터 동작 방식
