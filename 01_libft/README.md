## 나만의 C 라이브러리를 만드는 과제입니다.

42seoul에서 사용할 라이브러리를 만드는 과제입니다. libc에 포함된 함수들, 포함되지 않았거나 다른 형태로 포함된 함수들, 연결 리스트를 다루는 함수들을 구현하고 정적 라이브러리로 만들어서 계속 사용하게 됩니다.
### 인원
- 1인
### 사용 언어
- C언어
### 학습 내용
- C언어 기본기 (헤더파일, Makefile, 포인터, 메모리 할당 및 해제, 예외처리, 구조체 등)
- C 라이브러리의 종류 및 사용법
- 연결 리스트 구현
### 빌드
```shell
# Download
$ git clone https://github.com/zerone015/42seoul.git libft
$ cd libft/01_libft

# build
$ make bonus
```
### 구현 함수 목록
- part 1 - libc functions
  - ft_isalpha
  - ft_isdigit
  - ft_isalnum
  - ft_isascii
  - ft_isprint
  - ft_strlen
  - ft_memset
  - ft_bzero
  - ft_memcpy
  - ft_memmove
  - ft_strlcpy
  - ft_strlcat
  - ft_strncmp
  - ft_toupper
  - ft_tolower
  - ft_strchr
  - ft_strrchr
  - ft_memchr
  - ft_memcmp
  - ft_strnstr
  - ft_atoi
  - ft_strdup
  - ft_calloc
- part 2 - additional functions
  - ft_substr
  - ft_strjoin
  - ft_strtrim
  - ft_split
  - ft_itoa
  - ft_strmapi
  - ft_striteri
  - ft_putchar_fd
  - ft_putstr_fd
  - ft_putendl_fd
  - ft_putnbr_fd
- bonus part - linked list functions
  - ft_lstnew
  - ft_lstadd_front
  - ft_lstsize
  - ft_lstlast
  - ft_lstadd_back
  - ft_lstdelone
  - ft_lstclear
  - ft_lstiter
  - ft_lstmap
  
  
