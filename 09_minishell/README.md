## bash처럼 동작하는 나만의 셸 프로그램을 만드는 과제입니다.
GNU bash 매뉴얼을 참고해서 bash처럼 동작하는 셸 프로그램을 만드는 과제입니다.  
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
09_minishell$ (echo hello && (echo world | cat asdf)) | tr a-z A-Z
09_minishell$ ls *.c
09_minishell$ cat notexistsfile || echo hello
09_minishell$ echo $?
```
### 구현 내용
- 실행파일 실행 (cat, ls, grep, wc, head, tail, cut, ...)
- builtins (echo, cd, pwd, export, unset, env, exit)
- 닫힌 싱글 쿼터('') 및 더블 쿼터("")
- 파이프, 시그널, 리다이렉션, 히어독
- 환경 변수($)
- $?
- bash 기준 에러 메시지 및 exit status
- 괄호를 이용해 우선순위를 표현한 &&, ||
- 와일드카드 *

### 학습 내용
- bash 구조
- 복잡한 문자열 파싱
- 추상 구문 트리
- 토크나이징
- 멀티 프로세싱
- 파일 디스크립터 관리
- 파이프, 리다이렉션, 시그널, 환경변수
