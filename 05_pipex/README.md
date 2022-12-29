## Unix 파이프, 리다이렉션, 히어독 매커니즘을 구현하는 과제입니다.
Unix 파이프, 리다이렉션, 히어독을 구현하는 과제입니다.  
Unix 매커니즘과 파일 디스크립터가 무엇인지에 대해서 더 자세히 알 수 있게 됩니다.  

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
- 익명 파이프를 사용한 프로세스간 통신
- 리다이렉션, 히어독
- bash 기준 에러 처리
### 학습 내용
- IPC
- 익명 파이프
- 부모 - 자식 프로세스, 좀비 프로세스, 고아 프로세스
- fork / exec 동작 이해
- 리다이렉션, 히어독
- errno, exit status
- 환경변수
- 파일 디스크립터
- 병렬 프로그래밍  
