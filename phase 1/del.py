from typing import List, Tuple

def get_d(s: int, e: int, v: List[Tuple[int, int]]) -> int:
    return abs(v[s][0] - v[e][0]) + abs(v[s][1] - v[e][1])

def is_possible(d: int, v: List[Tuple[int, int]]) -> bool:
    for i in range(1, len(v) - 1):
        dist = get_d(i - 1, i + 1, v)
        if dist >= d:
            return False
    for i in range(1, len(v) - 1):
        dist = get_d(i, i + 1, v)
        if dist >= d:
            return False
    for i in range(len(v) - 1):
        dist = get_d(i, i + 1, v)
        if dist >= d:
            return False

    return True

def main():
    n = int(input())
    v = []
    for _ in range(n):
        x, y = map(int, input().split())
        v.append((x, y))

    v.sort()

    s = 0
    e = get_d(0, n - 1, v)
    while s <= e:
        mid = s + (e - s) // 2
        if is_possible(mid, v):
            e = mid - 1
        else:
            s = mid + 1

    print(s)

if __name__ == "__main__":
    main()

