<h1 align="center">Get Next Line</h1>

<div align="center">Reading a line from a fd is way too tedious</div>

<br/>

### [Summary](#Summary-1)

### [Mandatory part](#Mandatory-part-1)

- [버퍼: 정적 할당 vs 동적 할당](#버퍼-정적-할당-vs-동적-할당)
- [바이너리 파일](#바이너리-파일)

### [Bonus part](#Bonus-part-1)

- [정적 변수: 배열 vs 연결 리스트](#정적-변수-배열-vs-연결-리스트)

<br/>

# Summary

> This project is about programming a function that returns a line  
> read from a file descriptor.
> 
> Version: 10

| Function name        | get_next_line                                                                             |
| -------------------- | ----------------------------------------------------------------------------------------- |
| **Prototype**        | char *get_next_line(int fd);                                                              |
| **Turn in files**    | get_next_line.c, get_next_line_utils.c, get_next_line.h                                   |
| **Parameters**       | fd: The file descriptor to read from                                                      |
| **Return value**     | Read line: correct behavior<br/>NULL: there is nothing else to read, or an error occurred |
| **External functs.** | read, malloc, free                                                                        |
| **Description**      | Write a function that returns a line read from a file descriptor                          |

<br/>

<h1 align="center">Mandatory Part</h1>

## 버퍼: 정적 할당 vs 동적 할당

버퍼를 고정된 크기의 배열로 선언하는 정적 할당은 컴파일 단계에서 메모리의 스택 영역에 할당된다.  
정적 할당된 메모리는 함수가 종료될 때 자동으로 해제되기 때문에 메모리 누수를 걱정할 필요가 없다는 장점이 있지만,  
할당된 메모리의 크기가 고정되어 있기 때문에 할당된 크기 중 사용하지 않는 메모리 공간이 낭비되기 쉽다는 단점이 존재한다.  
또한 스택 영역의 크기가 힙 영역에 비해 상대적으로 작아 최대 할당 크기가 제한적이다.

`malloc`을 통해 버퍼를 동적으로 할당하는 경우 실행 단계에서 메모리 공간이 할당되며, 포인터를 사용해서 메모리의 힙 영역을 가리킨다.  
원하는 만큼의 메모리를 할당하고 필요에 따라 크기를 조절할 수 있어 경제적이지만, 힙 영역은 스택 영역에 비해 엑세스 속도가 느리다.  
최근의 운영 체제들은 프로세스 종료 시 동적 할당된 메모리를 자동으로 해제해 주기 때문에 메모리 누수가 발생하지 않는다.  
하지만 프로세스가 지속적으로 유지되어야 하거나 호환성을 고려한다면, `free` 함수를 통해 명시적으로 메모리를 해제해 주는 것이 좋다.

일반적인 경우 `open`된 파일로부터 한 줄을 읽을 때 스택 오버플로우가 발생할 정도로 큰 사이즈의 버퍼를 사용할 필요가 없으므로,  
높은 비용을 지불해야 하는 동적 할당보다는 정적 할당을 이용하는 것이 유리하다.

## 바이너리 파일

텍스트 파일의 경우 개행 문자 `\n`를 통해 행이 구분되고, `NUL` 문자가 EOF(End of File)임을 나타낸다.  
반면에 바이너리 파일의 경우 행의 개념과 EOF가 존재하지 않기 때문에, `0x0A`든 `0x00`이든 데이터의 일부일 뿐이다.

`get_next_line`의 prototype에서 파일 디스크립터만을 인자로 받는 이상,  
해당 파일이 텍스트 파일인지 바이너리 파일인지 구분할 수 없기 때문에 바이너리 파일까지 올바르게 읽도록 처리하는 것은 불가능하다.

<br/>

<h1 align="center">Bonus Part</h1>

## 정적 변수: 배열 vs 연결 리스트

여러 개의 파일 디스크립터에 각각 대응하는 정적 변수를 배열로 선언할 경우,  
잘못된 인덱스에 접근하는 것을 막기 위해 해당 환경에서 `open` 가능한 최대 파일 개수를 알아야 한다.  
이는 `ulimit` 명령어를 통해 직접 확인하거나  
`<limits.h>` 헤더를 `include`하여 `OPEN_MAX`로 정의되어 있는 매크로 상수를 사용하는 것으로 해결할 수 있다.

정적 변수를 배열로 선언할 경우 사용하지 않는 파일 디스크립터의 수만큼 메모리를 낭비하게 되지만,  
인덱스를 통해 랜덤 액세스가 가능하기에 속도가 빠르다는 장점이 있다.  
연결 리스트를 사용할 경우 파일 개수에 구애되지 않아 잘못된 인덱스에 접근할 우려가 없지만,  
랜덤 액세스가 불가능하기 때문에 배열에 비해 속도가 느리다는 단점이 존재한다.
