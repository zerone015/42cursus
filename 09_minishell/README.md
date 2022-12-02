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

$ brew install readline

# build
$ make        

# execute
./minishell

# example
./minishell
09_minishell$ env | grep PATH | cat -e > outfile
09_minishell$ export PATH=$PATH:$PWD
09_minishell$ echo $PATH
09_minishell$ < /dev/urandom cat | head -1 >> outfile
09_minishell$ << hi cat | sleep 5 | << EOF cat
09_minishell$ exit | exit
09_minishell$ exit
```
### 구현 내용
- 실행파일 실행 (cat, ls, grep, wc, head, tail, cut, ...)
- builtins (echo, cd, pwd, export, unset, env, exit)
- 싱글 쿼터('') 및 더블 쿼터("")
- 파이프, 시그널, 리다이렉션, here document
- 환경 변수($)
- $? (최근 실행한 명령어의 종료 상태를 가진 변수)
- 에러 처리
### 학습 내용
- 협업
- 셸 구조
- 멀티 프로세싱
- 복잡한 문자열 파싱
- 파일 디스크립터 관리
- 파이프, 리다이렉션, 시그널, 환경변수
- 컴파일러 또는 인터프리터 동작 방식
