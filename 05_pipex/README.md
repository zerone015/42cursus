## Unix pipe, redirection, here document 매커니즘을 구현하는 과제입니다.
IPC란 무엇이고 운영체제는 어떤 역할을 하는지와 파이프, 리다이렉션, here document가 무엇이며 어떻게 동작하는지를 직접 구현하면서 학습하는 과제입니다.   
Unix 매커니즘과 파일 디스크립터가 무엇인지에 대해서도 더 자세히 알 수 있게 됩니다.  

### 인원
- 1인
### 사용 언어
- C언어
### 실행
```shell
# Download
$ git clone https://github.com/zerone015/42seoul.git pipex
$ cd pipex/05_pipex

# build
$ make        # mandatory
$ make bonus  # bonus

# execute
./pipex [infile] [cmd1] [cmd2] [outfile]                                    # mandatory
./pipex [infile] [cmd1] [cmd2] [cmd3] ... [cmdn] [outfile]                  # bonus
./pipex here_doc [limit string] [cmd1] [cmd2] [cmd3] ... [cmdn] [outfile]   # bonus
```
### 구현 내용
- 파이프를 통한 프로세스간 통신
- redirection
- here document
- bash를 기준으로 한 에러처리 및 exit code
### 학습 내용
- IPC (Inter-Process Communication)
- 파이프 동작 원리 이해 및 구현
- 부모 - 자식 프로세스, 좀비 프로세스, 고아 프로세스
- fork / exec 동작 이해
- 리다이렉션, 히어독
- errno, exit status
- 환경변수 (특히 ls, cat과 같은 프로그램들이 어떻게 경로를 지정하지 않아도 실행되는지 알 수 있었습니다.)
- 파일 디스크립터 (STDERR가 왜 필요한지 실감할 수 있었습니다.)
- 병렬 프로그래밍  
