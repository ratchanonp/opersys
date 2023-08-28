# Process

Code ต่อไปนี้จะ fork process ออกมา 4 process

ให้นิสิตแก้โค้ดเพื่อให้ print child_list ออกมาแค่ครั้งเดียว และแสดง pid ของ process ลูกทั้งหมดที่เกิดขึ้น

เช่น หาก process 10 แตกออกมาเป็น process 11 12 13 14 ให้ print child_list ครั้งเดียวเป็น

```c
child_list[0] = 11
child_list[1] = 12
child_list[2] = 13
child_list[3] = 14
```

# How to run

1. Compile the code

```
gcc -o process process.c
```

2. Run the code

```
./process
```
