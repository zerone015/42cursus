## libc의 printf를 구현하는 과제입니다.  
```c
int ft_printf(const char *, ...);
```
libc의 printf를 구현하고 이전에 제작했던 libft 라이브러리에 추가하여 향후 과제에서 활용할 수 있게 됩니다.  
mandatory에서는 서식 지정자만 구현하고 bonus에서 플래그, 폭, 정밀도를 추가로 구현하였습니다.   
[관련 지식을 정리한 블로그](https://velog.io/@zerone015/series/ftprintf)

### 인원
- 1인
### 사용 언어
- C언어
### 빌드
```shell
# Download
$ git clone https://github.com/zerone015/42seoul.git ft_printf
$ cd ft_printf/03_ft_printf

# build
$ make bonus
```
### 구현 내용
- 서식 지정자(%c, %s, %p, %d, %i, %u, %x, %X, %%)
- 플래그('-', '0', '#', ' ', '+')
- 폭
- 정밀도
### 학습 내용
- 가변 인자
- printf의 구조
- 함수 포인터 배열을 활용한 성능 최적화
- 구현
