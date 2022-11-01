## Unix pipe, redirection, here document 매커니즘을 구현하는 과제입니다.
IPC란 무엇이며 운영체제는 어떤 역할을 하는지, 리다이렉션, here document가 무엇이며 어떻게 동작하는지에 대해 직접 구현하며 학습하는 과제입니다.   
Unix 매커니즘과 파일 디스크립터가 무엇인지에 대해서도 더 자세히 알 수 있게 됩니다.  
#### mandatory
```
$> ./pipex file1 cmd1 cmd2 file2

위의 명령어는 다음에 상응해야 합니다.

$> < file1 cmd1 | cmd2 > file2
```  
mandatory part에서는 두 개의 프로세스의 파이프를 통한 통신, 입출력 리다이렉션을 구현해야 합니다.  

#### bonus
```
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

위의 명령어는 다음에 상응해야 합니다.

< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

./pipex here_doc limitString cmd1 cmd2 cmd3 ... cmdn file2

위의 명령어는 다음에 상응해야 합니다.

<< limitString cmd1 | cmd2 | cmd3 ... | cmdn >> file
```  
bonus part에서는 시스템에 한정된 max user processes만큼의 파이프를 통한 통신을 처리할 수 있어야 하며 here document, >> 리다이렉션을 추가로 구현해야 합니다.  
[관련 지식을 정리한 블로그](https://velog.io/@zerone015/series/pipex)  

### 인원
- 1인
### 사용 언어
- C언어
### 빌드
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
- pipe를 통한 프로세스간 통신
- redirection
- here document
- bash
### 학습 내용

