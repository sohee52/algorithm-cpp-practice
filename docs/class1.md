### 문제 모음
- [문제](https://www.acmicpc.net/problem/10951)
- [문제](https://www.acmicpc.net/problem/11654)
- [문제](https://www.acmicpc.net/problem/25083)
- [문제](https://www.acmicpc.net/problem/2439)

### while(cin >> a >> b)
- [문제](https://www.acmicpc.net/problem/10951)
- a와 b가 입력되는 동안 계속해서 반복문이 실행된다.

### 아스키 코드
- [문제](https://www.acmicpc.net/problem/11654)
```cpp
char c;
cin >> c;
int a = c;
cout << a << "\n";
```
- char형 변수 c에 입력된 문자를 int형 변수 a에 저장하면, a에는 해당 문자의 아스키코드 값이 저장된다.

### R"()"
- [문제](https://www.acmicpc.net/problem/25083)
- `R"()"`는 C++11에서 도입된 raw string literal을 나타내는 구문입니다.
- `R"()"` 안에 있는 문자열은 그대로 출력됩니다.
- 예시:
    ```cpp
    cout << R"( /\_/\
    ( o.o )";
    ```
- 위 코드는 다음과 같이 출력됩니다:
    ```
    /\_/\
    ( o.o )
    ```

### string(개수, 문자)
- [문제](https://www.acmicpc.net/problem/2439)
- int와 char를 인자로 받아서, char를 int 개수만큼 반복하여 문자열을 만들어 반환하는 생성자입니다.
- 예를 들어 string(5, '*')는 '*' 문자를 5개 연속으로 포함하는 문자열을 생성합니다.